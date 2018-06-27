#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

int main()
{
int token = 0;
int acum_ident = 0;
int acum_const = 0;
int acum_error = 0;
FILE *archivo;
//archivo = fopen("P.txt","r");
archivo = fopen("lexemas.txt","r");
int i = 0;
while (token != TOKEN_FDT) //Hasta fin de cadena.
{
	token=scanner(&archivo);

	if(token == TOKEN_CTE)
	{
		printf ("constante entera\n");
		acum_const++;
	}
	else if(token == TOKEN_IDE)
	{
		printf ("identificador\n");
		acum_ident++;
	}
	else if (token == TOKEN_ERROR)
	{
		printf ("error\n");
		acum_error++;
	}
}			
	printf ("----\n");
	printf ("Totales: \n");
	printf ("Identificadores %d \n",acum_ident);
	printf ("Constantes enteras %d \n",acum_const);
	printf ("Errores %d \n",acum_error);

return 0;
}
