#include <stdio.h>
#include <ctype.h>

//Puede recibir un estado y el caracter leido y realiza una determinada acción.
int automata (int estado, int carac) {
switch (estado)
	{
	case 0:
	if (isspace(carac)){
		estado=0;
		}
	else if (isdigit(carac)){
		estado = 1;
		}
	else if (isalpha(carac)){
		estado = 3;
		}
	else {
		estado = 5;
		}
	
	break;
	case 1:
	if (isdigit(carac)){
		estado=1;
		}
	else if (isspace(carac)){
		estado = 2;
		}
	break;

	case 3:
	if (isspace(carac)){
		estado=4;
		}
	else if (isdigit(carac) || isalpha(carac)){
		estado = 3;
		}
	break;

	case 5:
	if (isspace(carac)){
		estado=10;
		}
	else if (isdigit(carac)){
		estado = 1;
		}
	else if (isalpha(carac)){
		estado = 3;
		}

	else {
		estado = 5;
		}
	break;
	}
return estado;
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
















