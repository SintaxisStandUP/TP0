#include <stdio.h>
#include <ctype.h>

int automata (int estado, int carac) //Esto iria en el "scanner.h"

int main (void) {

int estado = 0;
int estadoAnt = 0;
int carac;
int acum_ident = 0;
int acum_const = 0;
int acum_error = 0;
int resultados[20];
int i = 0;

FILE *archivo;
archivo = fopen ("lexemas.txt","r");

while (!feof(archivo))
{
	carac = getc(archivo); //Lee un caracter
	estado = automata (estado, carac)//Invoco al scanner que me devuelve la categoria lexica(estado)
	if (estado == 4 || estado == 2)
	{
	resultados[i] = estado;
	i++;
	estado = 0;
	}
}
	
	//ACA empezaria el tema de calcular a partir de la lista
	//la cantidad de ident y despues mostrar por pantalla y demas.
	//Ahora paso al scanner.




return 0;
}
