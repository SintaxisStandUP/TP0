#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

int scanner (FILE **archivo) 
{
	int carac;
	int caracter; //es un auxiliar para no modificar carac y poder hacer "ungetc(); con lo que esta guardado en carac"

	int TT[8][5] = {{3, 1, 5, 0, 7},
			{2, 1, 2, 2, 2},		
			{99, 99, 99, 99, 99},
			{3, 3, 4, 4, 4},
			{99, 99, 99, 99, 99},
			{6, 6, 5, 6, 6}, //nueva columna recono error
			{99, 99, 99, 99, 99},
			{99, 99, 99, 99, 99}};
	int estado = INICIAL;

	while (estado != CTE_REC && estado != IDE_REC && estado != ERROR && estado != FDT)
	{
		carac = getc(*archivo); //Leer con getc
		if (carac == EOF) //Identificamos el caracter
		{
			caracter = END;
		}

		else if (isspace(carac)){
			caracter = ESPACIO;
				}
		else if (isdigit(carac)){
			caracter = DIGITO;
				}
		else if (isalpha(carac)){
			caracter = LETRA;
				}
		else {
			caracter = OTRO;	
			}
		estado = TT[estado][caracter];
	}
//tenemos en "carac" guardado un simbolo que es centinela, por lo tanto hacemos ungetc();
		if(estado == CTE_REC) //estado aceptor
		{
			carac = ungetc(carac, *archivo);
			return TOKEN_CTE;	
		}
		else if(estado == IDE_REC) // estado aceptor
		{
			carac = ungetc(carac, *archivo);
			return TOKEN_IDE;
		}
		else if (estado == ERROR) // estado de error
		{
			carac = ungetc(carac, *archivo);
			return TOKEN_ERROR;
		}
		else if(estado == FDT) // estado aceptor
		{
			return TOKEN_FDT;
		}
}
