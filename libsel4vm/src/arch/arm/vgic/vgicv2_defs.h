/*
 * Copyright 2019, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

/*
 * GIC Distributor Register Map
 * ARM Generic Interrupt Controller (Architecture version 2.0)
 * Architecture Specification (Issue B.b)
 * Chapter 4 Programmers' Model - Table 4.1
 */
#define GIC_DIST_CTLR           0x000
#define GIC_DIST_TYPER          0x004
#define GIC_DIST_IIDR           0x008
#define GIC_DIST_IGROUPR0       0x080
#define GIC_DIST_IGROUPR1       0x084
#define GIC_DIST_IGROUPRN       0x0FC
#define GIC_DIST_ISENABLER0     0x100
#define GIC_DIST_ISENABLER1     0x104
#define GIC_DIST_ISENABLERN     0x17C
#define GIC_DIST_ICENABLER0     0x180
#define GIC_DIST_ICENABLER1     0x184
#define GIC_DIST_ICENABLERN     0x1fC
#define GIC_DIST_ISPENDR0       0x200
#define GIC_DIST_ISPENDR1       0x204
#define GIC_DIST_ISPENDRN       0x27C
#define GIC_DIST_ICPENDR0       0x280
#define GIC_DIST_ICPENDR1       0x284
#define GIC_DIST_ICPENDRN       0x2FC
#define GIC_DIST_ISACTIVER0     0x300
#define GIC_DIST_ISACTIVER1     0x304
#define GIC_DIST_ISACTIVERN     0x37C
#define GIC_DIST_ICACTIVER0     0x380
#define GIC_DIST_ICACTIVER1     0x384
#define GIC_DIST_ICACTIVERN     0x3FC
#define GIC_DIST_IPRIORITYR0    0x400
#define GIC_DIST_IPRIORITYR7    0x41C
#define GIC_DIST_IPRIORITYR8    0x420
#define GIC_DIST_IPRIORITYRN    0x7F8
#define GIC_DIST_ITARGETSR0     0x800
#define GIC_DIST_ITARGETSR7     0x81C
#define GIC_DIST_ITARGETSR8     0x820
#define GIC_DIST_ITARGETSRN     0xBF8
#define GIC_DIST_ICFGR0         0xC00
#define GIC_DIST_ICFGRN         0xCFC
#define GIC_DIST_NSACR0         0xE00
#define GIC_DIST_NSACRN         0xEFC
#define GIC_DIST_SGIR           0xF00
#define GIC_DIST_CPENDSGIR0     0xF10
#define GIC_DIST_CPENDSGIRN     0xF1C
#define GIC_DIST_SPENDSGIR0     0xF20
#define GIC_DIST_SPENDSGIRN     0xF2C

/*
 * ARM Generic Interrupt Controller (Architecture version 2.0)
 * Architecture Specification (Issue B.b)
 * 4.3.15: Software Generated Interrupt Register, GICD_SGI
 * Values defined as per Table 4-21 (GICD_SGIR bit assignments)
 */
#define GIC_DIST_SGI_TARGET_LIST_FILTER_SHIFT   24
#define GIC_DIST_SGI_TARGET_LIST_FILTER_MASK    0x3 << GIC_DIST_SGI_TARGET_LIST_FILTER_SHIFT
#define GIC_DIST_SGI_TARGET_LIST_SPEC           0
#define GIC_DIST_SGI_TARGET_LIST_OTHERS         1
#define GIC_DIST_SGI_TARGET_SELF                2

#define GIC_DIST_SGI_CPU_TARGET_LIST_SHIFT      16
#define GIC_DIST_SGI_CPU_TARGET_LIST_MASK       0xFF << GIC_DIST_SGI_CPU_TARGET_LIST_SHIFT

#define GIC_DIST_SGI_INTID_MASK                 0xF

#define GIC_ENABLE                              1

/* Memory map for GIC distributer */
struct vgic_v2_dist_map {
    uint32_t enable;                                    /* 0x000 */
    uint32_t ic_type;                                   /* 0x004 */
    uint32_t dist_ident;                                /* 0x008 */
    uint32_t res1[29];                                  /* [0x00C, 0x080) */

    uint32_t irq_group[32];                             /* [0x080, 0x100) */

    uint32_t enable_set[32];                            /* [0x100, 0x180) */
    uint32_t enable_clr[32];                            /* [0x180, 0x200) */
    uint32_t pending_set[32];                           /* [0x200, 0x280) */
    uint32_t pending_clr[32];                           /* [0x280, 0x300) */
    uint32_t active[32];                                /* [0x300, 0x380) */
    uint32_t active_clr[32];                            /* [0x380, 0x400) */

    uint32_t priority[255];                             /* [0x400, 0x7FC) */
    uint32_t res3;                                      /* 0x7FC */

    uint32_t targets[255];                              /* [0x800, 0xBFC) */
    uint32_t res4;                                      /* 0xBFC */

    uint32_t config[64];                                /* [0xC00, 0xD00) */

    uint32_t spi[32];                                   /* [0xD00, 0xD80) */
    uint32_t res5[20];                                  /* [0xD80, 0xDD0) */
    uint32_t res6;                                      /* 0xDD0 */
    uint32_t legacy_int;                                /* 0xDD4 */
    uint32_t res7[2];                                   /* [0xDD8, 0xDE0) */
    uint32_t match_d;                                   /* 0xDE0 */
    uint32_t enable_d;                                  /* 0xDE4 */
    uint32_t res8[70];                                  /* [0xDE8, 0xF00) */

    uint32_t sgi_control;                               /* 0xF00 */
    uint32_t res9[3];                                   /* [0xF04, 0xF10) */

    uint32_t _sgi_pending_clr[4];                       /* [0xF10, 0xF20) */
    uint32_t _sgi_pending_set[4];                       /* [0xF20, 0xF30) */
    uint32_t res10[40];                                 /* [0xF30, 0xFC0) */

    uint32_t periph_id[12];                             /* [0xFC0, 0xFF0) */
    uint32_t component_id[4];                           /* [0xFF0, 0xFFF] */

    uint32_t irq_group0[CONFIG_MAX_NUM_NODES];
    uint32_t enable_set0[CONFIG_MAX_NUM_NODES];
    uint32_t enable_clr0[CONFIG_MAX_NUM_NODES];
    uint32_t pending_set0[CONFIG_MAX_NUM_NODES];
    uint32_t pending_clr0[CONFIG_MAX_NUM_NODES];
    uint32_t active0[CONFIG_MAX_NUM_NODES];
    uint32_t active_clr0[CONFIG_MAX_NUM_NODES];
    uint32_t priority0[CONFIG_MAX_NUM_NODES][8];
    uint32_t targets0[CONFIG_MAX_NUM_NODES][8];
    uint32_t sgi_pending_clr[CONFIG_MAX_NUM_NODES][4];
    uint32_t sgi_pending_set[CONFIG_MAX_NUM_NODES][4];
};

struct vgic_v2_registers {
    struct vgic_v2_dist_map distributor;
    uintptr_t dist_paddr;
    size_t dist_size;
};

enum gic_dist_action {
    ACTION_SGI_IRQ_GROUP = 0,
    ACTION_SGI_ENABLE_SET,
    ACTION_SGI_ENABLE_CLR,
    ACTION_SGI_PENDING_SET,
    ACTION_SGI_PENDING_CLR,
    ACTION_SGI_ACTIVE,
    ACTION_SGI_ACTIVE_CLR,
    ACTION_SGI_PRIORITY,
    ACTION_SGI_TARGETS,
    ACTION_NUM_SGI_ACTIONS,

    ACTION_ENABLE,
    ACTION_ENABLE_SET,
    ACTION_ENABLE_CLR,
    ACTION_PENDING_SET,
    ACTION_PENDING_CLR,

    ACTION_READONLY,
    ACTION_PASSTHROUGH
};
