#include <stdio.h>
#include <ctype.h>
//SCANNER.C
int main (void) {
FILE *archivo;
archivo = fopen ("lexemas.txt","r");
int estado = 0;
char carac = 'q';
int i = 60;
while (!feof(archivo))
{
i = i -1;
carac = getc(archivo);
printf("%c", carac);
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
