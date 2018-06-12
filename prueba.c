#include <stdio.h>
#include <ctype.h>
 
int main()
{
  /* char cadena[] = ";0ñfáR(4h&~?RÛ1/";
   int i;
   
   for(i = 0; cadena[i]; i++) 
      printf("%c, %d\n", cadena[i], isdigit(cadena[i]));
*/
	char cadena[] = "H0L	A ";
	for(int i = 0; i<7; i++) 
      printf("%c .. %d\n", cadena[i], isspace(cadena[i]));

   return 0;
}




/*
int automata (int estado, int carac){
switch (estado){
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

}
int estadoAnt = estado
}
}
*/

