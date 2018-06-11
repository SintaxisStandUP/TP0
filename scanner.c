#include <stdio.h>
#include <ctype.h>

//Puede recibir un estado y el caracter leido y hacer determinada accion
int estadoAnt;
int automata (int estado, int carac){
while (estado =! 99){
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
	
	break;
	case 1:
	if (isdigit(carac)){
		estado=1;
		}
	else if (isspace(carac)){
		estado = 2;
		}
	break;
	
	case 2:
	return 2;
	break;
	}
estadoAnt = estado;
}
}
