/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#define GIC_VERSION_2

#define GIC_PADDR   0x03880000

#define GIC_DIST_PADDR       (GIC_PADDR + 0x1000)
#define GIC_DIST_SIZE        0x1000

#define GIC_CPU_PADDR        (GIC_PADDR + 0x2000)
#define GIC_CPU_SIZE         0x1000

#define GIC_VCPU_CNTR_PADDR  (GIC_PADDR + 0x4000)
#define GIC_VCPU_CNTR_SIZE   0x1000

#define GIC_VCPU_PADDR       (GIC_PADDR + 0x6000)
#define GIC_VCPU_SIZE        0x1000
