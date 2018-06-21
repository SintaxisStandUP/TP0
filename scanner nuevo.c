#include <stdio.h>
#include <ctype.h>

void automata (void) {
FILE *archivo;
int carac;

archivo = fopen("lexemas.txt", r);
int TT[6][4] = {{3, 1, 10, 0},
		{10, 1, 10, 2},		
		{99, 99, 99, 99},
		{3, 3, 10, 4},
		{99, 99, 99, 99},
		{3, 1, 99, 0}};
int estado = 0;
while (estado != 2 && estado != 4 && estado != 10)
{
	carac = getc(archivo); //Leer con getc
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
	break;

	case 3:
	if (isspace(carac)){
		estado=TT[3][3];
		}
	else if (isdigit(carac) || isalpha(carac)){
		estado = TT[3][1];
		}
	break;
	}
}
	
	if(estado == 2)
	{
		return 2; //retorna token cte	
	}
	else if(estado == 4)
	{
		return 4; //retorna token identificador
	}
}
/*
Tabla del automata:
	Letra	Digito	Otros	Espacio
0-	3	1	10	0
1	10	1	10	2
2+	99	99	99	99
3	3	3	10	4
4+	99	99	99	99
10	3	1	99	0
*/
