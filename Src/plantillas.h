/*
 * plantillas.h
 *
 *  Created on: 6 ago 2026
 *      Author: jorge
 */

#ifndef PLANTILLAS_H_
#define PLANTILLAS_H_

#include <stdint.h>

/* Estructura de registros del RCC con offsets alineados */
typedef struct {
    volatile uint32_t CR;         /* 0x00: Clock control register */
    volatile uint32_t PLLCFGR;    /* 0x04: PLL configuration register */
    volatile uint32_t CFGR;       /* 0x08: Clock configuration register */
    volatile uint32_t CIR;        /* 0x0C: Clock interrupt register */
    volatile uint32_t AHB1RSTR;   /* 0x10: AHB1 peripheral reset register */
    volatile uint32_t AHB2RSTR;   /* 0x14: AHB2 peripheral reset register */
    volatile uint32_t AHB3RSTR;   /* 0x18: AHB3 peripheral reset register */
    uint32_t RESERVED0;           /* 0x1C: Reservado */
    volatile uint32_t APB1RSTR;   /* 0x20: APB1 peripheral reset register */
    volatile uint32_t APB2RSTR;   /* 0x24: APB2 peripheral reset register */
    uint32_t RESERVED1[2];        /* 0x28 - 0x2C: Reservado */
    volatile uint32_t AHB1ENR;    /* 0x30: AHB1 peripheral clock enable register */
    volatile uint32_t AHB2ENR;    /* 0x34: AHB2 peripheral clock enable register */
    volatile uint32_t AHB3ENR;    /* 0x38: AHB3 peripheral clock enable register */
    uint32_t RESERVED2;           /* 0x3C: Reservado */
    volatile uint32_t APB1ENR;    /* 0x40: APB1 peripheral clock enable register */
    volatile uint32_t APB2ENR;    /* 0x44: APB2 peripheral clock enable register */
    uint32_t RESERVED3[2];        /* 0x48 - 0x4C: Reservado */
    volatile uint32_t AHB1LPENR;  /* 0x50: AHB1 peripheral clock enable in low power mode */
    volatile uint32_t AHB2LPENR;  /* 0x54: AHB2 peripheral clock enable in low power mode */
    volatile uint32_t AHB3LPENR;  /* 0x58: AHB3 peripheral clock enable in low power mode */
    uint32_t RESERVED4;           /* 0x5C: Reservado */
    volatile uint32_t APB1LPENR;  /* 0x60: APB1 peripheral clock enable in low power mode */
    volatile uint32_t APB2LPENR;  /* 0x64: APB2 peripheral clock enable in low power mode */
    uint32_t RESERVED5[2];        /* 0x68 - 0x6C: Reservado */
    volatile uint32_t BDCR;       /* 0x70: Backup domain control register */
    volatile uint32_t CSR;        /* 0x74: Clock control & status register */
    uint32_t RESERVED6[2];        /* 0x78 - 0x7C: Reservado */
    volatile uint32_t SSCGR;      /* 0x80: Spread spectrum clock generation register */
    volatile uint32_t PLLI2SCFGR; /* 0x84: PLLI2S configuration register */
    volatile uint32_t PLLSAICFGR; /* 0x88: PLLSAI configuration register */
    volatile uint32_t DCKCFGR1;   /* 0x8C: Dedicated clocks configuration register 1 */
    volatile uint32_t DCKCFGR2;   /* 0x90: Dedicated clocks configuration register 2 */
} J_RCC_TypeDef;

/* Estructura de registros del periférico GPIO */
typedef struct {
    volatile uint32_t MODER;   /* 0x00: Configuración de modo (Entrada/Salida/Alterno/Analógico) */
    volatile uint32_t OTYPER;  /* 0x04: Tipo de salida (Push-pull / Open-drain) */
    volatile uint32_t OSPEEDR; /* 0x08: Velocidad de salida (Baja/Media/Alta/Muy Alta) */
    volatile uint32_t PUPDR;   /* 0x0C: Resistencias de Pull-up / Pull-down */
    volatile uint32_t IDR;     /* 0x10: Registro de datos de entrada (Lectura) */
    volatile uint32_t ODR;     /* 0x14: Registro de datos de salida (Lectura/Escritura) */
    volatile uint32_t BSRR;    /* 0x18: Registro de Set/Reset de bits (Escritura atómica) */
    volatile uint32_t LCKR;    /* 0x1C: Registro de bloqueo de configuración */
    volatile uint32_t AFR[2];  /* 0x20 - 0x24: Registros de funciones alternas [0]=AFRL, [1]=AFRH */
} J_GPIO_TypeDef;

/* Estructura de registros del periférico USART/UART (Arquitectura STM32F7) */
typedef struct {
    volatile uint32_t CR1;      /* 0x00: Control register 1 */
    volatile uint32_t CR2;      /* 0x04: Control register 2 */
    volatile uint32_t CR3;      /* 0x08: Control register 3 */
    volatile uint32_t BRR;      /* 0x0C: Baud rate register */
    volatile uint32_t GTPR;     /* 0x10: Guard time and prescaler register */
    volatile uint32_t RTOR;     /* 0x14: Receiver timeout register */
    volatile uint32_t RQR;      /* 0x18: Request register */
    volatile uint32_t ISR;      /* 0x1C: Interrupt and status register */
    volatile uint32_t ICR;      /* 0x20: Interrupt flag clear register */
    volatile uint32_t RDR;      /* 0x24: Receive data register */
    volatile uint32_t TDR;      /* 0x28: Transmit data register */
} J_USART_TypeDef;

/* Estructura de registros del NVIC
   Cada arreglo maneja hasta 240 interrupciones (8 registros de 32 bits cada uno) */
typedef struct {
    volatile uint32_t ISER[8];      /* 0x000 - 0x01C: Interrupt Set-Enable Registers */
    uint32_t RESERVED0[24];         /* 0x020 - 0x07C: Reservado */
    volatile uint32_t ICER[8];      /* 0x080 - 0x09C: Interrupt Clear-Enable Registers */
    uint32_t RESERVED1[24];         /* 0x0A0 - 0x0FC: Reservado */
    volatile uint32_t ISPR[8];      /* 0x100 - 0x11C: Interrupt Set-Pending Registers */
    uint32_t RESERVED2[24];         /* 0x120 - 0x17C: Reservado */
    volatile uint32_t ICPR[8];      /* 0x180 - 0x19C: Interrupt Clear-Pending Registers */
    uint32_t RESERVED3[24];         /* 0x1A0 - 0x1FC: Reservado */
    volatile uint32_t IABR[8];      /* 0x200 - 0x21C: Interrupt Active Bit Registers */
    uint32_t RESERVED4[56];         /* 0x220 - 0x2FC: Reservado */
    volatile uint8_t  IP[240];      /* 0x300 - 0x3EF: Interrupt Priority Registers (Acceso por Byte) */
    uint32_t RESERVED5[644];        /* 0x3F0 - 0xE00: Reservado */
    volatile uint32_t STIR;         /* 0xE00: Software Trigger Interrupt Register */
} J_NVIC_TypeDef;

/* Estructura de registros para TIM6 y TIM7 */
typedef struct {
    volatile uint32_t CR1;      /* 0x00: Control register 1 */
    volatile uint32_t CR2;      /* 0x04: Control register 2 */
    uint32_t RESERVED0;         /* 0x08: Reservado */
    volatile uint32_t DIER;     /* 0x0C: DMA/Interrupt enable register */
    volatile uint32_t SR;       /* 0x10: Status register */
    volatile uint32_t EGR;      /* 0x14: Event generation register */
    uint32_t RESERVED1[3];      /* 0x18 - 0x20: Reservado */
    volatile uint32_t CNT;      /* 0x24: Counter register (Contador actual) */
    volatile uint32_t PSC;      /* 0x28: Prescaler register (Divisor de frecuencia) */
    volatile uint32_t ARR;      /* 0x2C: Auto-reload register (Valor máximo) */
} J_TIM_Basic_TypeDef;

/* Estructura de registros para Temporizadores Generales (TIM2 a TIM5) */
typedef struct {
    volatile uint32_t CR1;      /* 0x00: Control register 1 */
    volatile uint32_t CR2;      /* 0x04: Control register 2 */
    volatile uint32_t SMCR;     /* 0x08: Slave mode control register */
    volatile uint32_t DIER;     /* 0x0C: DMA/Interrupt enable register */
    volatile uint32_t SR;       /* 0x10: Status register */
    volatile uint32_t EGR;      /* 0x14: Event generation register */
    volatile uint32_t CCMR1;    /* 0x18: Capture/compare mode register 1 (Canales 1 y 2) */
    volatile uint32_t CCMR2;    /* 0x1C: Capture/compare mode register 2 (Canales 3 y 4) */
    volatile uint32_t CCER;     /* 0x20: Capture/compare enable register */
    volatile uint32_t CNT;      /* 0x24: Counter register (Contador actual) */
    volatile uint32_t PSC;      /* 0x28: Prescaler register */
    volatile uint32_t ARR;      /* 0x2C: Auto-reload register */
    uint32_t RESERVED0;         /* 0x30: Reservado */
    volatile uint32_t CCR1;     /* 0x34: Capture/compare register 1 */
    volatile uint32_t CCR2;     /* 0x38: Capture/compare register 2 */
    volatile uint32_t CCR3;     /* 0x3C: Capture/compare register 3 */
    volatile uint32_t CCR4;     /* 0x40: Capture/compare register 4 */
    uint32_t RESERVED1;         /* 0x44: Reservado */
    volatile uint32_t DCR;      /* 0x48: DMA control register */
    volatile uint32_t DMAR;     /* 0x4C: DMA address for full transfer */
    volatile uint32_t OR;       /* 0x50: Option register */
} J_TIM_General_TypeDef;
/* Estructura de registros para una instancia individual de ADC */
typedef struct {
    volatile uint32_t SR;       /* 0x00: Status register */
    volatile uint32_t CR1;      /* 0x04: Control register 1 */
    volatile uint32_t CR2;      /* 0x08: Control register 2 */
    volatile uint32_t SMPR1;    /* 0x0C: Sample time register 1 (Canales 10 a 18) */
    volatile uint32_t SMPR2;    /* 0x10: Sample time register 2 (Canales 0 a 9) */
    volatile uint32_t JOFR1;    /* 0x14: Injected channel data offset register 1 */
    volatile uint32_t JOFR2;    /* 0x18: Injected channel data offset register 2 */
    volatile uint32_t JOFR3;    /* 0x1C: Injected channel data offset register 3 */
    volatile uint32_t JOFR4;    /* 0x20: Injected channel data offset register 4 */
    volatile uint32_t HTR;      /* 0x24: Watchdog higher threshold register */
    volatile uint32_t LTR;      /* 0x28: Watchdog lower threshold register */
    volatile uint32_t SQR1;     /* 0x2C: Regular sequence register 1 */
    volatile uint32_t SQR2;     /* 0x30: Regular sequence register 2 */
    volatile uint32_t SQR3;     /* 0x34: Regular sequence register 3 */
    volatile uint32_t JSQR;     /* 0x38: Injected sequence register */
    volatile uint32_t JDR1;     /* 0x3C: Injected channel data register 1 */
    volatile uint32_t JDR2;     /* 0x40: Injected channel data register 2 */
    volatile uint32_t JDR3;     /* 0x44: Injected channel data register 3 */
    volatile uint32_t JDR4;     /* 0x48: Injected channel data register 4 */
    volatile uint32_t DR;       /* 0x4C: Regular data register (Registro de datos regular) */
} J_ADC_TypeDef;



#endif /* PLANTILLAS_H_ */




