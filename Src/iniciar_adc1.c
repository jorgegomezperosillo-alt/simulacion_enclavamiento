/*
 * iniciar_adc1.c
 *
 *  Created on: 1 sept 2026
 *      Author: jorge
 */

#include <stdint.h>
#include "plantillas.h"
#include "dir_base.h"
#include "macros.h"


void Iniciar_Adc1()
{
	// LO PRIMERO INICIAR EL RELOJ PARA HABILITAR EL PERIFERICO
	RCC->APB2ENR |= (1UL << RCC_ADC1);

	// PONER UN CILCO DE 15 PARA EL CANAL 8 DEL ADC1
	ADC1->SMPR2 &= ~(7UL << 24);
	ADC1->SMPR2 |= (1UL << 24);

	// PONEMOS PARA UNA CONVERSION AL SER SOLO UN POTECIOMETRO
	ADC1->SQR1 &= ~(15UL << 20);

	// PONEMOS EL CANAL 8 COMO ENTRADA EN LA PRIMERA POSICION
	ADC1->SQR3 &= ~(31UL << 0);
	ADC1->SQR3 |= (8UL << 0);

	// RESOLUCION DE 12 BITS
	ADC1->CR1 &= ~(3UL << 24);

	// DESHABILITAR LA INTERRUPCION DE FIN DE CONVERSION
	ADC1->CR1 &= ~(1UL << 5);
	//ADC1->CR1 |= (1UL << 5);

	// DESHABILTAR CONVERSION CONTINUA
	ADC1->CR2 &= ~(1UL << 1);


	// HABILITAR ADC
	ADC1->CR2 &= ~(1UL << 0);
	ADC1->CR2 |= (1UL << 0);

	//Delay obligatorio de estabilización de silicio (unas cuantas instrucciones)
	for (volatile uint32_t i = 0; i < 2000; i++) { __asm("nop"); }


}


