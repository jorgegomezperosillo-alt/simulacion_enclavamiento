/*
 * iniciar_gpio.c
 *
 *  Created on: 6 ago 2026
 *      Author: jorge
 */

#include <stdint.h>
#include "plantillas.h"
#include "dir_base.h"
#include "macros.h"

void Iniciar_Gpio()
{
	// encendemos el reloj
	RCC->AHB1ENR |= (1UL << RCC_A);
	RCC->AHB1ENR |= (1UL << RCC_B);
	RCC->AHB1ENR |= (1UL << RCC_C);
	RCC->AHB1ENR |= (1UL << RCC_F);

	// LIMPIAR PINES Y PONER EN MODO SALIDA EL QUE CORRESPONDA
	GPIOA->MODER &= ~(MASCARA << (2 * LED_ROJO_A3));
	GPIOC->MODER &= ~(MASCARA << (2 * BOTON_MARCHA_C0));
	GPIOF->MODER &= ~(MASCARA << (2 * BOTON_PARO_F5));
	GPIOA->MODER &= ~(MASCARA << (2 * SERVO_A7));
	GPIOA->MODER &= ~(MASCARA << (2 * SERVO_A0));
	GPIOC->MODER &= ~(MASCARA << (2 * LED_VERDE_C3));


	GPIOA->MODER |= (1UL << (2 * LED_ROJO_A3));
	GPIOA->MODER |= (2UL << (2 * SERVO_A7));
	GPIOA->MODER |= (2UL << (2 * SERVO_A0));
	GPIOC->MODER |= (1UL << (2 * LED_VERDE_C3));

	// ACTIVAR RESITENCIA PULL DOWN EN BOTON C0 PARA HACER PULSADOR NA
	GPIOC->PUPDR &= ~(3UL << (2 * BOTON_MARCHA_C0));
	GPIOC->PUPDR |= (2UL << (2 * BOTON_MARCHA_C0));

	// ACTIVAR RESISTENCIA PULL UP PARA HACER PULSADOR NC
	GPIOF->PUPDR &= ~(3UL << (2 * BOTON_PARO_F5));
	GPIOF->PUPDR |= (1UL << (2 * BOTON_PARO_F5));

	// CONFIGURAMOS LA FUNCION ALTERNA DE LOS PINES A7  C3
	//GPIOA->AFR[0] &= ~(15UL << (4 * LED_ROJO_A3));
	GPIOA->AFR[0] &= ~(15UL << (4 * SERVO_A7));
	GPIOA->AFR[0] &= ~(15UL << (4 * (SERVO_A0)));
	//GPIOA->AFR[0] |= (1UL << (4 * LED_ROJO_A3));
	GPIOA->AFR[0] |= (2UL << (4 * SERVO_A7));
	GPIOA->AFR[0] |= (1UL << (4 * (SERVO_A0)));



}


