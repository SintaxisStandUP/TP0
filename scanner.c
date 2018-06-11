#include <stdio.h>
#include <ctype.h>
<<<<<<< HEAD
=======
//SCANNER.C
int main (void) {
FILE *archivo;
archivo = fopen ("lexemas.txt","r");
int estado = 0;
int carac;
int acum_ident = 0;
int acum_const = 0;
int acum_error = 0;
char lexemaIdentificador [200];


while (!feof(archivo))
{
carac = getc(archivo);
switch (estado){
	case 0:
	if (isspace(carac)){
		estado=0;
		break;
		}
	else if (isdigit(carac)){
		estado = 1;
		break;}
	else if (isalpha(carac)){
		estado = 3;
		break;}
	else
		estado = 10;
	
	case 1:
	if (isspace(carac)){
		estado=2;
		break;
		}
	else if (isdigit(carac)){
		estado = 1;
		break;}
	else if (isalpha(carac)){
		estado = 10;
		break;}
	else
		estado = 10;
	break;	
	
	case 2:
	estado = 99;
	acum_const += 1;
	printf ("constante entera \n");
	break;
	
	case 3:
	if (isspace(carac)){
		estado=4;
		break;
		}
	else if (isdigit(carac)||isalpha(carac)){
		estado = 3;
		break;}
	else
		estado = 10;
	break;
	
	case 4:
	estado = 99;
	acum_ident += 1;
	printf ("identificador \n");
	break;
	
	case 10:
	if (isspace(carac)){
		estado=0;
		break;
		}
	else if (isdigit(carac)){
		estado = 1;
		break;}
	else if (isalpha(carac)){
		estado = 3;
		break;}
	else
		estado = 99;
	printf ("Error \n");
	break;	
	}
>>>>>>> 9062f4231daa52ef3b644270b3ecd60e03f07b6b

//Aca tiene que venir lo de switch, como va leyendo y demas.
//Puede recibir un estado y el caracter leido y hacer determinada accion
void automata (){
return;
}
