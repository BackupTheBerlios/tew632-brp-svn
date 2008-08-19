/* gpio.h */
#ifndef _GPIO_H
#define _GPIO_H

typedef unsigned int	MV_U32;

#define MV_GPP_MAX_GROUP    1
#define MV_BAD_PARAM        0x04

#define INTER_REGS_BASE	0xF1000000

#define MV_16BIT_LE(X)  (X) 
#define MV_32BIT_LE(X)  (X)
#define MV_64BIT_LE(X)  (X)

/* No Fast Swap implementation (in assembler) for ARM */
#define MV_32BIT_LE_FAST(val)            MV_32BIT_LE(val)
#define MV_16BIT_LE_FAST(val)            MV_16BIT_LE(val) 

/* CPU architecture dependent 32, 16, 8 bit read/write IO addresses */
#define MV_MEMIO32_WRITE(addr, data)	\
    ((*((volatile unsigned int*)(addr))) = ((unsigned int)(data)))

#define MV_MEMIO32_READ(addr)       	\
    ((*((volatile unsigned int*)(addr))))

#define MV_MEMIO16_WRITE(addr, data)	\
    ((*((volatile unsigned short*)(addr))) = ((unsigned short)(data)))

#define MV_MEMIO16_READ(addr)       	\
    ((*((volatile unsigned short*)(addr))))

#define MV_MEMIO8_WRITE(addr, data) 	\
    ((*((volatile unsigned char*)(addr))) = ((unsigned char)(data)))

#define MV_MEMIO8_READ(addr)        	((*((volatile unsigned char*)(addr))))

/* 32bit read in little endian mode */
static __inline MV_U32 MV_MEMIO_LE32_READ(MV_U32 addr)
{
	MV_U32 data;
	data= (MV_U32)MV_MEMIO32_READ(addr);
	return (MV_U32)MV_32BIT_LE_FAST(data);
}

#define MV_MEMIO_LE32_WRITE(addr, data)		MV_MEMIO32_WRITE(addr, MV_32BIT_LE_FAST(data))
#define MV_REG_READ(offset)					(MV_MEMIO_LE32_READ(INTER_REGS_BASE | (offset)))
#define MV_REG_WRITE(offset, val)			(MV_MEMIO_LE32_WRITE((INTER_REGS_BASE | (offset)), (val)))

#define GPP_DATA_OUT_REG(grp)				0x10100
#define GPP_DATA_OUT_EN_REG(grp)			0x10104
#define GPP_BLINK_EN_REG(grp)				0x10108
#define GPP_DATA_IN_POL_REG(grp)			0x1010C
#define GPP_DATA_IN_REG(grp)				0x10110
#define GPP_INT_CAUSE_REG(grp)				0x10114
#define GPP_INT_MASK_REG(grp)				0x10118
#define GPP_INT_LVL_REG(grp)				0x1011c

#define NO_BIT      0x00000000
#define BIT0        0x00000001
#define BIT1        0x00000002
#define BIT2        0x00000004
#define BIT3        0x00000008
#define BIT4        0x00000010
#define BIT5        0x00000020
#define BIT6        0x00000040
#define BIT7        0x00000080
#define BIT8        0x00000100
#define BIT9        0x00000200
#define BIT10       0x00000400
#define BIT11       0x00000800
#define BIT12       0x00001000
#define BIT13       0x00002000
#define BIT14       0x00004000
#define BIT15       0x00008000
#define BIT16       0x00010000
#define BIT17       0x00020000
#define BIT18       0x00040000
#define BIT19       0x00080000
#define BIT20       0x00100000
#define BIT21       0x00200000
#define BIT22       0x00400000
#define BIT23       0x00800000
#define BIT24       0x01000000
#define BIT25       0x02000000
#define BIT26       0x04000000
#define BIT27       0x08000000
#define BIT28       0x10000000
#define BIT29       0x20000000
#define BIT30       0x40000000
#define BIT31       0x80000000


#define    MV_GPP0  BIT0
#define    MV_GPP1  BIT1
#define    MV_GPP2  BIT2
#define    MV_GPP3  BIT3
#define    MV_GPP4  BIT4
#define    MV_GPP5  BIT5
#define    MV_GPP6  BIT6
#define    MV_GPP7  BIT7
#define    MV_GPP8  BIT8
#define    MV_GPP9  BIT9
#define    MV_GPP10 BIT10
#define    MV_GPP11 BIT11
#define    MV_GPP12 BIT12
#define    MV_GPP13 BIT13
#define    MV_GPP14 BIT14
#define    MV_GPP15 BIT15
#define    MV_GPP16 BIT16
#define    MV_GPP17 BIT17
#define    MV_GPP18 BIT18
#define    MV_GPP19 BIT19
#define    MV_GPP20 BIT20
#define    MV_GPP21 BIT21
#define    MV_GPP22 BIT22
#define    MV_GPP23 BIT23
#define    MV_GPP24 BIT24
#define    MV_GPP25 BIT25
#define    MV_GPP26 BIT26
#define    MV_GPP27 BIT27
#define    MV_GPP28 BIT28
#define    MV_GPP29 BIT29
#define    MV_GPP30 BIT30
#define    MV_GPP31 BIT31


#endif
