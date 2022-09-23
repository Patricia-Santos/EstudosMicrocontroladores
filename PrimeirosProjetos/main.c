/*
 * Projeto: Hello World!!
 * Placa: STM32F4VEx
 * Descri��o: Ligando led da placa dando pulsos diferentes cada vez menores
 * Autor: Patricia Santos e Richard Ferreira
*/

#include "stm32f4xx.h"

void atraso(int delay)
{
	while(delay > 0) --delay;
}

int main(void)
{
	RCC->AHB1ENR |= 1; // Liga o clock do GPIO A
	GPIOA->MODER |= (0b01 << 12); // Configura o pino PA6 como saida

	while(1){ //void loop

		GPIOA->ODR |= (1 << 6); // N�vel l�gico alto no pino 6
		atraso(1000000); // Aguarda um tempo

		GPIOA->ODR &= ~(1 << 6); // N�vel l�gico baixo no pino 6
		atraso(1000000); // Aguarda um tempo
	}
}
