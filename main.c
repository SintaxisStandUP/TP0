#include <stdio.h>
#include <ctype.h>

int automata(int estado, int carac); //Esto iria en el "scanner.h"

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

	//ACA empezaria el tema de calcular a partir de la lista
	//la cantidad de ident y despues mostrar por pantalla y demas.
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

//	for (int h=0;h<i;h++)
	//printf ("estado resultante nro %d : %d\n",h, resultados[h]);
return 0;
}
