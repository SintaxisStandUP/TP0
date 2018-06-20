/*
TP 0 – 2018 - Un escáner elemental
Grupo 02

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
10	3	1	99	0

Referencias:
0-  ->	Estado inicial
1   ->	Reconociendo constante entera
2+  ->	Constante entera reconocida
3   ->	Reconociendo identificador
4+  ->	Identificador reconocido
10  ->	Error
Nota: En la implementación del código, con fines practicos se agrego un estado "5".
*/

#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

int main()
{
int estado = 0;
int estadoAnt = 0;
int carac;
int acum_ident = 0;
int acum_const = 0;
int acum_error = 0;
int resultados[20];
int i = 0;
int boolAux = 0;

FILE *archivo;
archivo = fopen ("lexemas.txt","r");

while (!feof(archivo))
{
	carac = getc(archivo); //Lee un caracter
	estado = automata (estado, carac);//Invoco al scanner que me devuelve la categoria lexica(estado)
	if (estado == 4 || estado == 2 || estado == 10)
	{
	if (estado == 10 && boolAux)
		boolAux = 0;
	if (estado != 10 && boolAux)
	{
		resultados[i] = 10; //Marca el error que hubo antes.
		i++;			//Para el caso #&/$823
		boolAux = 0;
	}

	resultados[i] = estado;
	i++;
	estado = 0;
	}
	if(estado == 5  && !boolAux)
	{
	boolAux = 1;
	}
}

	for (int h=0; h<i ;h++)
    {
		if (resultados[h]==2){
			printf ("constante entera\n");
			acum_const+=1;}
		else{
			if (resultados[h]==4)
			{	printf ("identificador\n");
				acum_ident+=1;}
					else
					{	printf ("error\n");
						acum_error+=1; }
			}
}	
	printf ("----\n");
	printf ("Totales: \n");
	printf ("Identificadores %d \n",acum_ident);
	printf ("Constantes enteras %d \n",acum_const);
	printf ("Errores %d \n",acum_error);

return 0;
}
