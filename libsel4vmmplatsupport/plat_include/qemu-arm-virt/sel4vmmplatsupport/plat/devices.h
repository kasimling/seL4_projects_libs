/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#define GIC_VERSION_3

#define GIC_PADDR               0x8000000

#define GIC_DIST_PADDR          (GIC_PADDR + 0x00000000)
#define GIC_DIST_SIZE           0x10000

#define GIC_REDIST_PADDR        (GIC_PADDR + 0x000A0000)
#define GIC_REDIST_SIZE         0x10000

#define GIC_REDIST_SGI_PADDR    (GIC_REDIST_PADDR + 0x00010000)
#define GIC_REDIST_SGI_SIZE     0x10000
