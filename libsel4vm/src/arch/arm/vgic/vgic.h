/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <sel4vm/guest_vm.h>
#include <sel4vm/guest_irq_controller.h>

struct vgic_dist_device {
    uintptr_t pstart;
    size_t size;
    void *priv;
};

int vm_install_vgic_v2(vm_t *vm, struct vm_irq_controller_params *params);
int vm_install_vgic_v3(vm_t *vm, struct vm_irq_controller_params *params);
int vm_vgic_maintenance_handler(vm_vcpu_t *vcpu);
