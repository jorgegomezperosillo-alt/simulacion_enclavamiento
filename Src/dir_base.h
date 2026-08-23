/*
 * dir_base.h
 *
 *  Created on: 6 ago 2026
 *      Author: jorge
 */

#ifndef DIR_BASE_H_
#define DIR_BASE_H_


#include <stdint.h>
#include "plantillas.h"



/* direcciones base */
#define RCC_BASE_ADDR       (0x40023800UL)
#define GPIOA_BASE_ADDR     (0x40020000UL)
#define GPIOB_BASE_ADDR     (0x40020400UL)
#define GPIOC_BASE_ADDR     (0x40020800UL)
#define GPIOD_BASE_ADDR     (0x40020C00UL)
#define GPIOE_BASE_ADDR     (0x40021000UL)
#define GPIOF_BASE_ADDR     (0x40021400UL)
#define NVIC_BASE_ADDR      (0xE000E100UL)
#define TIM2_BASE_ADDR      (0x40000000UL)
#define TIM3_BASE_ADDR      (0x40000400UL)
#define TIM6_BASE_ADDR      (0x40001000UL)
#define TIM7_BASE_ADDR      (0x40001400UL)
#define ADC1_BASE_ADDR      (0x40012000UL)
#define USART3_BASE_ADDR    (0x40004800UL)



/* punteros maestros */
#define RCC                 ((J_RCC_TypeDef *) RCC_BASE_ADDR)
#define GPIOA               ((J_GPIO_TypeDef *) GPIOA_BASE_ADDR)
#define GPIOB               ((J_GPIO_TypeDef *) GPIOB_BASE_ADDR)
#define GPIOC               ((J_GPIO_TypeDef *) GPIOC_BASE_ADDR)
#define GPIOD               ((J_GPIO_TypeDef *) GPIOD_BASE_ADDR)
#define GPIOE               ((J_GPIO_TypeDef *) GPIOE_BASE_ADDR)
#define GPIOF               ((J_GPIO_TypeDef *) GPIOF_BASE_ADDR)
#define NVIC                ((J_NVIC_TypeDef *) NVIC_BASE_ADDR)
#define TIM2                ((J_TIM_General_TypeDef *) TIM2_BASE_ADDR)
#define TIM3                ((J_TIM_General_TypeDef *) TIM3_BASE_ADDR)
#define TIM6                ((J_TIM_Basic_TypeDef *) TIM6_BASE_ADDR)
#define TIM7                ((J_TIM_Basic_TypeDef *) TIM7_BASE_ADDR)
#define ADC1                ((J_ADC_TypeDef *) ADC1_BASE_ADDR)
#define USART3              ((J_USART_TypeDef *) USART3_BASE_ADDR)


#endif /* DIR_BASE_H_ */




