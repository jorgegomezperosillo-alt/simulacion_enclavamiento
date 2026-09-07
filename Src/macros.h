/*
 * macros.h
 *
 *  Created on: 6 ago 2026
 *      Author: jorge
 */

#ifndef MACROS_H_
#define MACROS_H_

#include <stdint.h>
#include "plantillas.h"
#include "dir_base.h"

#define RCC_A             0
#define RCC_B             1
#define RCC_C             2
#define RCC_F             5
#define RCC_TIM2          0
#define RCC_TIM3          1
#define RCC_ADC1          8
#define BOTON_MARCHA_C0   (0UL)
#define BOTON_PARO_F5     (5UL)
#define LED_VERDE_C3      (3UL)
#define LED_ROJO_A3       (3UL) // TIM2 CANAL 4
#define LED_AMARILLO_C2   (2UL)
#define SERVO_A7          (7UL) // TIM3 CANAL2
#define SERVO_A0          (0UL) // TIM2 CANAL1
#define ADC1_B0           (0UL) // ADC1 CANAL 8
#define MASCARA           0x03UL
#define TEMP_MAX          60 // TEMPERATURA MAXIMA




#endif /* MACROS_H_ */
