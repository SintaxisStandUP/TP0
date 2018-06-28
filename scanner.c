#include <stdio.h>
#include <ctype.h>
#include "scanner.h"
static const int TT[8][5] = {{3, 1, 5, 0, 7},
			{2, 1, 2, 2, 2},		
			{99, 99, 99, 99, 99},
			{3, 3, 4, 4, 4},
			{99, 99, 99, 99, 99},
			{6, 6, 5, 6, 6},
			{99, 99, 99, 99, 99},
			{99, 99, 99, 99, 99}};

int identificarCaracter (int carac);

int scanner (FILE **archivo) 
{
int estado = INICIAL;
int carac;
int caracter;

	while (estado != CTE_REC && estado != IDE_REC && estado != ERROR && estado != FDT)
	{
		carac = getc(*archivo); //Leer con getc
		caracter = identificarCaracter(carac);	
		estado = TT[estado][caracter];
	}

	switch(estado)
	{
		case CTE_REC:
			carac = ungetc(carac, *archivo);
			return TOKEN_CTE;
			break;	
		case IDE_REC:
			carac = ungetc(carac, *archivo);
			return TOKEN_IDE;
			break;
		case ERROR:
			carac = ungetc(carac, *archivo);
			return TOKEN_ERROR;
			break;
		case FDT:
			return TOKEN_FDT;
	}
}
int identificarCaracter (int carac)
{
	if (carac == EOF)
	{
		return END;
	}
	else if (isspace(carac))
	{	
		return ESPACIO;
	}
	else if (isdigit(carac))
	{
		return DIGITO;
	}
	else if (isalpha(carac))
	{
		return LETRA;
	}
	else 
	{
		return OTRO;
	}
}	
