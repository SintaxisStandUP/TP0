#include <stdio.h>
#include <ctype.h>
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
	printf ("Error \n");
	break;	
	}

}
printf("\nfin \n");
int fclose (FILE *archivo);
return 0;
}

/*
estado  :=  INICIAL;

while  not  debo_parar(estado)

Leer  caracter

estado  :=  T[estado][caracter];
/*  otras  acciones  como  contar  líneas
Armar  lexema,  etc  
end  while;
if  aceptor(estado)  then
if  centinela(estado)  then
unput(caracter);
accept(state);  /*  retornar  token  
else
error;/*  devolver  token  de  error  
o  invocar  rutina  de  manejor  de  error  
end  if  ;
*/

/*	LO QUE HICE CUANDO NO SABIA QUE EXISTIA ISALPHA
if (carac < 91 && carac > 64)
		estado = 1;		
	else if (carac < 123 && carac > 96)
		estado = 1;
	else if(carac < 58 && carac > 47)
		estado = 1;
	printf("%c", carac);
	break;
*/
