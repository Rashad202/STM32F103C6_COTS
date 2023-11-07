/*
 *							     NCIC_private.h
 *
 *  Author  : Rashad
 *  Date    : 13 OCT 2023
 *  Layer   : MCAL
 *
 */
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* -------------------------------------------------------------------- */
/* Enable External interrupts from 0  to 31 */
#define NVIC_ISER0       *((volatile u32*)0xE000E100)
/* Enable External interrupts from 32 to 63  */
#define NVIC_ISER1       *((volatile u32*)0xE000E104)
/* Enable External interrupts from 64 to 95 */
#define NVIC_ISER2     	 *((volatile u32*)0xE000E108)


//----------------------------------------------------
#define NVIC_ICER0       *((volatile u32*)0xE000E180)
#define NVIC_ICER1       *((volatile u32*)0xE000E184)
#define NVIC_ICER2       *((volatile u32*)0xE000E188)

//----------------------------------------------------
#define NVIC_ISPR0       *((volatile u32*)0xE000E200)
#define NVIC_ISPR1       *((volatile u32*)0xE000E204)
#define NVIC_ISPR2       *((volatile u32*)0xE000E208)


//----------------------------------------------------
#define NVIC_ICPR0       *((volatile u32*)0xE000E280)
#define NVIC_ICPR1       *((volatile u32*)0xE000E284)
#define NVIC_ICPR2       *((volatile u32*)0xE000E288)


//----------------------------------------------------
#define NVIC_IABR0       *((volatile u32*)0xE000E300)
#define NVIC_IABR1       *((volatile u32*)0xE000E304)
#define NVIC_IABR2       *((volatile u32*)0xE000E308)


//----------------------------------------------------
/*  without Dereference	(u8 pointer)  */
#define NVIC_IPR_BASE_ADDRESS          ((volatile u32*)0xE000E400)

//----------------------------------------------------
/* 16 Priority Levels, No Sub-priority */
#define NVIC_16GROUP_0SUB   0x05FA0300UL
/*8 Priority Levels, 2 Sub-priority Levels */
#define NVIC_8GROUP_2SUB    0x05FA0400UL
/* 4 Priority Levels, 4 Sub-priority Levels */
#define NVIC_4GROUP_4SUB    0x05FA0500UL
/* 2 Priority Levels, 8 Sub-priority Levels */
#define NVIC_2GROUP_8SUB    0x05FA0600UL
/* No Grouping, 16 Sub-priority Levels */
#define NVIC_0GROUP_16SUB   0x05FA0700UL


#endif
