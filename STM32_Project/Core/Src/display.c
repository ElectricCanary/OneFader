/*
 * display.c
 *
 *  Created on: Oct 22, 2021
 *      Author: Electric Canary
 */

#include <stdio.h>
#include "display.h"
#include "../Inc/Display/ssd1306.h"
#include "protocol.h"
#include <math.h>
#include "main.h"
#include "behavior.h"

void Display_VU(void)
{
	uint8_t i;

	for(i = 0; i<4; ++i)
	{
		ssd1306_Line(0, i, 130, i, Black);
	}

	for(i = 0; i<4; ++i)
	{
		ssd1306_Line(0, i, 11*VULevel[0], i, White);
	}

	for(i = 5; i<9; ++i)
	{
		ssd1306_Line(0, i, 130, i, Black);
	}

	for(i = 5; i<9; ++i)
	{
		ssd1306_Line(0, i, 11*VULevel[8], i, White);
	}
}

void Display_Mute(void)
{
	uint8_t i;

	if (MuteBank[0] == 1)
	{
		for(i = 64; i>47; --i)
		{
			ssd1306_Line(0, i, 18, i, White);
		}
		ssd1306_SetCursor(7, 52);
		ssd1306_WriteChar('M', Font_7x10, Black);
	}

	if(MuteBank[0] == 0)
	{
		for(i = 64; i>47; --i)
		{
			ssd1306_Line(0, i, 18, i, Black);
		}
	}
}

void Display_Solo(void)
{
	uint8_t i;

	if (SoloBank[0] == 1)
	{
		for(i = 64; i>47; --i)
		{
			ssd1306_Line(113, i, 130, i, White);
		}
		ssd1306_SetCursor(118, 52);
		ssd1306_WriteChar('S', Font_7x10, Black);
	}

	if(SoloBank[0] == 0)
	{
		for(i = 64; i>47; --i)
		{
			ssd1306_Line(113, i, 130, i, Black);
		}
	}
}

void Display_Big(void)
{
	uint8_t i;
	uint8_t length = 6;
	uint8_t offset = 0;

	for(i=6; i!=0; i--)
	{
		if(DisplayBank[0][i-1]<=0x7F && DisplayBank[0][i-1]!=0x20)
		{
			break;
		}
		length--;
	}

	if((length%2) != 0)
	{
		offset = 8;
	}

	ssd1306_SetCursor(18, 16);
	ssd1306_WriteString("       ", Font_16x26, White);

	ssd1306_SetCursor(18 + offset, 16);
	for(i = 0; i < (6-length)/2; i++)
	{
		ssd1306_WriteChar(0x20, Font_16x26, White);
	}
	for(i = 0; i<length; i++)
	{
		ssd1306_WriteChar(DisplayBank[0][i], Font_16x26, White);
	}
}

void Display_Small(void)
{
	float pos = FaderPositions[0];
	float dB = 82.704*log10f(pos/11730);
	char buf[10];
	uint8_t length = 10;
	uint8_t i;
	uint8_t offset = 0;

	//snprintf(buf,10,"%0.2fdB", dB);
	snprintf(buf,10,"%d", FaderPositions[0]);
	//snprintf(buf,10,"%d", ADC_Buf[0]);
	//snprintf(buf,10,"%d", faderpos);
	//snprintf(buf,10,"%d", ADC_half);

	for(i=10; i!=0; i--)
	{
		if(buf[i-1]<=0x7F && buf[i-1]!=0x20)
		{
			break;
		}
		length--;
	}

	if((length%2) != 0)
	{
		offset = 3;
	}

	ssd1306_SetCursor(35, 52);
	ssd1306_WriteString("          ", Font_7x10, White);
	ssd1306_SetCursor(35 + offset, 52);
	for(i = 0; i < (10-length)/2; ++i)
	{
		ssd1306_WriteChar(0x20, Font_7x10, White);
	}
	for(i = 0; i<length; ++i)
	{
		ssd1306_WriteChar(buf[i], Font_7x10, White);
	}
}

void Display_Frame(void)
{
	Display_VU();
	Display_Big();
	Display_Small();
	Display_Mute();
	Display_Solo();
	ssd1306_UpdateScreen();
}
