#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

int main()
{
int token = 0;
int acum_ident = 0;
int acum_const = 0;
int acum_error = 0;

while (token == EOF) //Hasta fin de cadena.
{
	token=scanner();

	if(token == 2)
	{
		printf ("constante entera\n");
		acum_const+=1;
	}
	else if(token == 4)
	{
		printf ("identificador\n");
		acum_ident+=1;
	}
	else if (token == 10)
	{
		printf ("error\n");
		acum_error+=1;
	}
}			
	printf ("----\n");
	printf ("Totales: \n");
	printf ("Identificadores %d \n",acum_ident);
	printf ("Constantes enteras %d \n",acum_const);
	printf ("Errores %d \n",acum_error);

return 0;
}
