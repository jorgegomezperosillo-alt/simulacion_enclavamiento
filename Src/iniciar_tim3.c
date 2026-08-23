/*
 * iniciar_tim3.c
 *
 *  Created on: 10 ago 2026
 *      Author: jorge
 */

#include <stdint.h>
#include "plantillas.h"
#include "dir_base.h"
#include "macros.h"

void Iniciar_Tim3()
{
	// lo primero es habilitar el reloj
	RCC->APB1ENR |= (1UL << RCC_TIM3);

	// HACEMOS EL PRESCALER 1
	TIM3->PSC = 16 - 1;

	// CUENTA HASTA 20MS PERFECTO PAREL SERVOMOTOR
	TIM3->ARR = 20000 - 1;

	// PONEMOS  EL TIM EN SALIDA COMO PWM
	TIM3->CCMR1 &= ~(3UL << 8);
	TIM3->CCMR1 &= ~(7UL << 12);
	TIM3->CCMR1 |= (6UL << 12);

	// ACTIVAR LA PRECARGA (Preload) DEL CANAL 2 (Crucial para que acepte los cambios del Handler)
	TIM3->CCMR1 |= (1UL << 15);   // OC1PE = 2

	// HABILITAR EL CANAL 2
	TIM3->CCER &= ~(1UL << 4);
	TIM3->CCER |= (1UL << 4);

	// PARTIMOS DE UN VALOR
	TIM3->CCR2 = 1500;

	// HACEMOS QUE EL PROCEADOR VEA LA INTERRUPCION
	TIM3->DIER |= (1UL << 0);

	// HACEMOS QUE EL TEMPORIZADOR ARRANQUE LIMPIO
	TIM3->EGR |= (1UL << 0); // COMO REINICIA A 0 NO ES NECESARIO LIMPIARLO


	TIM3->SR &= ~(1UL << 0);

	//HABILITAMOS EL TIM
	TIM3->CR1 |= (1UL << 0);


}

void TIM3_IRQHandler()
{

	static uint32_t enclavamiento = 0;
	uint32_t giro_servo = 0;
	// miramos la bandera lo primero
	if ((TIM3->SR & (1UL << 0)) != 0)
	{

		uint32_t marcha = ((GPIOC->IDR & (1UL << BOTON_MARCHA_C0)) != 0);
		uint32_t paro = ((GPIOF->IDR & (1UL << BOTON_PARO_F5)) != 0);

		// EMPEZAMOS LA LOGICA DE LA INTERRUPCION
		if ((marcha || enclavamiento) && (paro == 1))
		{
			enclavamiento = 1;
		} else
		{
			enclavamiento = 0;
		}

		if (enclavamiento == 1)
		{
			// APAGAMOS ROJO, ENCENDEMOS VERDE SI EL BOTON ESTA PRESIONADO
			GPIOC->BSRR = (1UL << LED_VERDE_C3);
			GPIOA->BSRR = (1UL << (LED_ROJO_A3 + 16));

			giro_servo = 1950;

		} else
		{
			// APAGAMOS VERDE Y ENENDEMOS ROJO  SI EL BOTON NO ESTA PRESIONADO
			GPIOA->BSRR = (1UL << LED_ROJO_A3);
			GPIOC->BSRR = (1UL << (LED_VERDE_C3 + 16));

			giro_servo = 1500;

		}

		TIM3->CCR2 = giro_servo;
		TIM2->CCR1 = giro_servo;

		// limpiamos la bandera para el siguiente ciclo
		TIM3->SR &= ~(1UL << 0);
	}
}


