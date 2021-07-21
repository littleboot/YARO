/*
 * display.c
 *
 *  Created on: 19 sep. 2020
 *      Author: Admin
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "display.h"


static float map(float x, float in_min, float in_max, float out_min, float out_max) {
	if( x == in_min ) return out_min;
	else if( x >= in_max ) return out_max;
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint8_t nextion_setText(const char* id, const char* val)
{
	uint8_t buffer[50] = { ' ' };

	sprintf( (char*)buffer, "%s.txt=\"%s\"\xFF\xFF\xFF",id, val);
	return nextion_uart_transmit( (uint8_t*)buffer );
}

char s_temp[10];
char* temp2string(float val)
{
	sprintf( s_temp, "%+6.2f C", val);
	return s_temp;
}

uint8_t nextion_add2wave(uint8_t id, uint8_t ch, float val)
{
	char buffer[20] = { ' ' };

	const unsigned int windowHeigth = 180; //waveform heigth

	const unsigned int X1 = 0; //X axis start
	const unsigned int X2 = 360; //X axis end

	const unsigned int Y1 = 22; //Y axis start
	const unsigned int Y2 = 36; //Y axis end

	unsigned int set = (uint32_t)map(val, Y1, Y2, 0, windowHeigth);

	sprintf( (char*)buffer, "add %u,%u,%u\xFF\xFF\xFF",id, ch, set);
	nextion_uart_transmit( (uint8_t*)buffer );

	sprintf( (char*)buffer, "n0.val=%u\xFF\xFF\xFF",X1);
	nextion_uart_transmit( (uint8_t*)buffer );

	sprintf( (char*)buffer, "n1.val=%u\xFF\xFF\xFF",X2);
	nextion_uart_transmit( (uint8_t*)buffer );

	sprintf( (char*)buffer, "n2.val=%u\xFF\xFF\xFF",Y1);
	nextion_uart_transmit( (uint8_t*)buffer );

	sprintf( (char*)buffer, "n3.val=%u\xFF\xFF\xFF",Y1+((Y2-Y1)/2) );
	nextion_uart_transmit( (uint8_t*)buffer );

	sprintf( (char*)buffer, "n4.val=%u\xFF\xFF\xFF",Y2);
	nextion_uart_transmit( (uint8_t*)buffer );

	return 0;
}


uint8_t nextionWakeup( )
{
	return nextion_uart_transmit((uint8_t *)"sleep=0\xFF\xFF\xFF");
}
