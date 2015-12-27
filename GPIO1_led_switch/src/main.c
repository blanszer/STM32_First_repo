//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f1-stdperiph/stm32f10x_rcc.h"//dodane zeby gpio mozna bylo uruchomic

// ----------------------------------------------------------------------------
//
// Standalone STM32F1 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

void delay(int time)
{
	volatile int i;
    for (i = 0; i < time * 4000; i++) {}
}


int
main(int argc, char* argv[])
{
	//gpio wspolne
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef gpio;  // obiekt gpio bêd¹cy konfiguracj¹ portów GPIO
	GPIO_StructInit(&gpio);  // domyœlna konfiguracja(wystarczy raz wpisac)
	//gpio wspolne

	//inicjalizacja pinu/portu diody led
	gpio.GPIO_Pin = GPIO_Pin_13;  // konfigurujemy pin 13
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;  // jako wyjœcie(push-pull)
	GPIO_Init(GPIOC, &gpio);  // inicjalizacja modu³u GPIOC
	//koniec inicjalizacji pinu/portu diody led

	//inicjalizacja pinu/portu switcha
	gpio.GPIO_Pin = GPIO_Pin_9; // konfigurujemy pin 9
	gpio.GPIO_Mode = GPIO_Mode_IPU; // jako wejœcie z rezystorem pull-up
	GPIO_Init(GPIOB, &gpio);
	//koniec inicjalizacji pinu/portu switcha

	while(1)
	{
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == 0)	//czy switch wcisniety
		{
			GPIO_SetBits(GPIOC, GPIO_Pin_13); // wy³¹czenie diody
			delay(1000);
			GPIO_ResetBits(GPIOC, GPIO_Pin_13); // za³aczenie diody
			delay(1000);
		}
	}

}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
