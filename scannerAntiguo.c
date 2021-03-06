#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

int scanner (FILE **archivo) {
//FILE *archivo;
int carac;

//archivo = fopen("lexemas.txt","r");
int TT[6][4] = {{3, 1, 10, 0},
		{10, 1, 10, 2},		
		{99, 99, 99, 99},
		{3, 3, 10, 4},
		{99, 99, 99, 99},
		{3, 1, 10, 0}};
int estado = 0;
while (!feof(*archivo))
{
	carac = getc(*archivo); //Leer con getc
	if (carac == EOF)
	{
		return EOF;
	}
	switch (estado)
	{
	case 0:
		if (isspace(carac)){
			estado = TT[0][3];
			}
		else if (isdigit(carac)){
			estado = TT[0][1];
			}
		else if (isalpha(carac)){
			estado = TT[0][0];
			}
		else {
			estado = TT[0][2];
			}
		break;
		
	case 1:
		if (isdigit(carac)){
			estado=TT[1][1];
			}
		else if (isspace(carac)){
			estado = TT[1][3];
			}
		else 
			estado = TT[1][0];
			
		break;

	case 3:
		if (isspace(carac)){
			estado=TT[3][3];
			}
		else if (isdigit(carac) || isalpha(carac)){
			estado = TT[3][1];
			}
		else 
			estado = TT[3][2];
		break;
	}

//Aqui estaba el while(1).
	
	if(estado == 2) //estado aceptor
	{
		return 2; //retorna token cte	
	}
	else if(estado == 4) // estado aceptor
	{
		return 4; //retorna token identificador
	}
	else if (estado==10) // estado de error
	{
		if (isspace(carac)){
			estado = TT[5][3];
			return 10; // retorna token error
			}
		else if (isdigit(carac) || isalpha(carac)){
			estado = TT[5][1]; //Finaliza el error (cte/ide)
			carac = ungetc(carac, *archivo); //retrocedo un caracter
			return 10;
			}
		else { //Sigue el error
			estado = TT[5][2];	
			}
	}
}//END WHILE
}
/*
Tabla del automata:
	Letra	Digito	Otros	Espacio	EOF
0-	3	1	10	0	15
1	10	1	10	2	15
2+	99	99	99	99	15
3	3	3	10	4	15
4+	99	99	99	99	15
10	3	1	10	0	15
15	99	99	99	99	99
*/
