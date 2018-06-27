#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

int scanner (FILE **archivo) 
{
	int carac;

	int TT[7][5] = {{3, 1, 5, 0, 6},
			{5, 1, 5, 2, 6},		
			{99, 99, 99, 99, 6},
			{3, 3, 5, 4, 6},
			{99, 99, 99, 99, 6},
			{3, 1, 5, 0, 6},
			{99, 99, 99, 99, 6}};
	int estado = 0;

	while (!feof(*archivo))
	{
		carac = getc(*archivo); //Leer con getc
		if (carac == EOF) //Identificamos el caracter
		{
			carac = 4;
		}

		else if (isspace(carac)){
			carac = 3;
				}
		else if (isdigit(carac)){
			carac = 1;
				}
		else if (isalpha(carac)){
			carac = 0;
				}
		else {
			carac = 2;	
			}
		estado = TT[estado][carac];

		if(estado == 2) //estado aceptor
		{
			return 2; //retorna token cte	
		}
		else if(estado == 4) // estado aceptor
		{
			return 4; //retorna token identificador
		}
		else if (estado==5) // estado de error
		{
			carac = getc(*archivo);
			if (isspace(carac)){
				return 5; // retorna token error
				}
			else if (isdigit(carac) || isalpha(carac)){
				carac = ungetc(carac, *archivo); //retrocedo un caracter
				return 5;
				}
		}
		else if(estado == 6) // estado aceptor
		{
			return 6; //retorna token FIN DE TEXTO
		}
	}
}
