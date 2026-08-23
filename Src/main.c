// VAMOS HA HACER LA PRUBA DE LOS PINBES DE ARDUINE DE MI PLACA

#include <stdint.h>
#include "plantillas.h"
#include "dir_base.h"
#include "macros.h"

void Iniciar_Gpio();
void Delay_Ms();
void juego_luces();
void Iniciar_Tim3();
void Iniciar_Tim2();




int main()
{
	// iniciamos el reloj a 16mhz por defecto
	RCC->CR |= (1UL << 0);

	// iniciamos la funcion
	Iniciar_Gpio();


	// --- TEST DE ARRANQUE ---
	// Encendemos el LED Verde inmediatamente usando tu BSRR
	GPIOC->BSRR = (1UL << LED_VERDE_C3);
	// ------------------------


	Iniciar_Tim3();
	Iniciar_Tim2();

	// activamos la palanca de donde va a mirar el procesador para saber que hacer
	NVIC->ISER[0] |= (1UL << 29); // ACTIVAAMOS LA PALANCA 29 DEL ELEMENTO 0 DEL ARRAY
	//NVIC->ISER[0] |= (1UL << 28); // ACTIVAAMOS LA PALANCA 28 DEL ELEMENTO 0 DEL ARRAY


	// 2. SOLUCIÓN OBLIGATORIA: Encendemos el interruptor global de la CPU ARM
	__asm volatile ("cpsie i" : : : "memory");

	while(1)
	{
		// iniciamos la funcion a ver si funciona
		//juego_luces();

	}

}


void Delay_Ms(uint32_t mili)
{
     uint32_t i;
     uint32_t iteraciones = mili * 1600;
     for (i = 0; i < iteraciones; i++)
     {
    	 	 __asm("nop");
     }
}

void juego_luces()
{
	// empezamos ha hacer pruebas con las funciones
	if ((GPIOC->IDR & (1UL << BOTON_MARCHA_C0)) != 0)
	{
		// APAGAMOS ROJO, ENCENDEMOS VERDE SI EL BOTON ESTA PRESIONADO
		GPIOC->BSRR = (1UL << LED_VERDE_C3);
		GPIOA->BSRR = (1UL << (LED_ROJO_A3 + 16));
	} else
	{
		// APAGAMOS VERDE Y ENENDEMOS ROJO  SI EL BOTON NO ESTA PRESIONADO
		GPIOA->BSRR = (1UL << LED_ROJO_A3);
		GPIOC->BSRR = (1UL << (LED_VERDE_C3 + 16));
	}
}
