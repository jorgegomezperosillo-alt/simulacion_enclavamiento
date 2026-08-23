/*
 * iniciar_tim2.c
 *
 *  Created on: 19 ago 2026
 *      Author: jorge
 */

#include <stdint.h>
#include "plantillas.h"
#include "dir_base.h"
#include "macros.h"

void Iniciar_Tim2()
{
	// lo primero es habilitar el reloj
	RCC->APB1ENR |= (1UL << RCC_TIM2);

	// HACEMOS EL PRESCALER 1
	TIM2->PSC = 16 - 1;

	// CUENTA HASTA 20MS PERFECTO PAREL SERVOMOTOR
	TIM2->ARR = 20000 - 1;

	// PONEMOS  EL TIM EN SALIDA COMO PWM
	TIM2->CCMR1 &= ~(3UL << 0);
	TIM2->CCMR1 &= ~(7UL << 4);
	TIM2->CCMR1 |= (6UL << 4);

	// ACTIVAR LA PRECARGA (Preload) DEL CANAL 1 (Crucial para que acepte los cambios del Handler)
	TIM2->CCMR1 |= (1UL << 3);   // OC1PE = 1

	// HABILITAR EL CANAL 1
	TIM2->CCER &= ~(1UL << 0);
	TIM2->CCER |= (1UL << 0);

	// PARTIMOS DE UN VALOR
	TIM2->CCR1 = 1500;

	// HACEMOS QUE EL PROCEADOR VEA LA INTERRUPCION
	//TIM2->DIER |= (1UL << 0);

	// HACEMOS QUE EL TEMPORIZADOR ARRANQUE LIMPIO
	TIM2->EGR |= (1UL << 0); // COMO REINICIA A 0 NO ES NECESARIO LIMPIARLO


	TIM2->SR &= ~(1UL << 0);

	//HABILITAMOS EL TIM
	TIM2->CR1 |= (1UL << 0);


}






