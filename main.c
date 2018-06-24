/*
TP 0 – 2018 - Un escáner elemental
Grupo 02 - 2da Entrega

Cortez Francisco Andres	1638130
Kuric Mariela		1627740
Storozuk Irina Belén	1634355
Vazquez Candela		1646916
Tabla del automata:
	Letra	Digito	Otros	Espacio
0-	3	1	10	0
1	10	1	10	2
2+	99	99	99	99
3	3	3	10	4
4+	99	99	99	99
10	3	1	10	0

Referencias:
0-  ->	Estado inicial
1   ->	Reconociendo constante entera
2+  ->	Constante entera reconocida
3   ->	Reconociendo identificador
4+  ->	Identificador reconocido
10  ->	Error
*/

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
archivo = fopen("lexemas.txt","r");
int i = 0;
while (token != EOF) //Hasta fin de cadena.
{
	token=scanner(&archivo);

	if(token == 2)
	{
		printf ("constante entera\n");
		acum_const++;
	}
	else if(token == 4)
	{
		printf ("identificador\n");
		acum_ident++;
	}
	else if (token == 10)
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
