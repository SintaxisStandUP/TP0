#include <stdio.h>
#include <ctype.h>

int main(){
FILE *archivo;
archivo = fopen ("lexemas.txt","r");
int c = 24;
int i = 0;
int carac = 0;
int caract = 0;
/*while (i<5)
{
	carac = getc(archivo);
	printf("el caracter es: %c \n",carac); 
	i++;
}
i = 0;
carac = ungetc (carac, archivo);
printf("caract es: %c \n", carac);

carac = getc(archivo);
printf("el caracter despues de ungetc: %c \n",carac);
while (i<5)
{
	carac = getc(archivo);
	printf("el caracter es: %c \n",carac); 
	i++;
}
*/
while (carac != EOF)
{
	carac = getc(archivo);
	printf("el caracter es: %c \n",carac);
	if (carac == EOF){
	printf("FINAL DE ARCHIVO");}
}
return 0;
}
