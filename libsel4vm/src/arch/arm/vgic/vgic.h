/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <sel4vm/guest_vm.h>
#include <sel4vm/guest_irq_controller.h>

#include "vdist.h"

#pragma once

#define MAX_LR_OVERFLOW 64
#define MAX_VIRQS   200
#define NUM_SGI_VIRQS   16
#define NUM_PPI_VIRQS   16
#define GIC_SPI_IRQ_MIN      NUM_SGI_VIRQS + NUM_PPI_VIRQS


struct virq_handle {
    int virq;
    irq_ack_fn_t ack;
    void *token;
};

struct lr_of {
    struct virq_handle irqs[MAX_LR_OVERFLOW]; /* circular buffer */
    size_t head;
    size_t tail;
    bool full;
};

struct vgic_device {
    enum vm_gic_version version;

    /* Mirrors the vcpu list registers */
    struct virq_handle *irq[CONFIG_MAX_NUM_NODES][MAX_LR_OVERFLOW - 1];
    /* IRQs that would not fit in the vcpu list registers */
    struct lr_of lr_overflow[CONFIG_MAX_NUM_NODES];
    /* Complete set of virtual irqs */
    struct virq_handle *sgi_ppi_irq[CONFIG_MAX_NUM_NODES][NUM_SGI_VIRQS + NUM_PPI_VIRQS];
    struct virq_handle *virqs[MAX_VIRQS];

    struct vgic_dist_map distributor;
    uintptr_t dist_paddr;
};

int vm_install_vgic_v2(vm_t *vm, struct vm_irq_controller_params *params);
int vm_install_vgic_v3(vm_t *vm, struct vm_irq_controller_params *params);
int vm_vgic_maintenance_handler(vm_vcpu_t *vcpu);

void vgic_dist_reset(struct vgic_dist_map *gic_dist);
memory_fault_result_t handle_vgic_dist_fault(vm_t *vm, vm_vcpu_t *vcpu, uintptr_t fault_addr,
                                             size_t fault_length,
                                             void *cookie);

int vgic_dist_enable(struct vgic_device *vgic, vm_t *vm);
int vgic_dist_disable(struct vgic_device *vgic, vm_t *vm);
int vgic_dist_enable_irq(struct vgic_device *vgic, vm_vcpu_t *vcpu, int irq);
int vgic_dist_disable_irq(struct vgic_device *vgic, vm_vcpu_t *vcpu, int irq);
int vgic_dist_set_pending_irq(struct vgic_device *vgic, vm_vcpu_t *vcpu, int irq);
int vgic_dist_clr_pending_irq(struct vgic_device *vgic, vm_vcpu_t *vcpu, int irq);
