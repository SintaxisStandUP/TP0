#include <stdio.h>
#include <ctype.h>
 
int main()
{
   char cadena[] = ";0ñfáR(4h&~?RÛ1/";
   int i;
   
   for(i = 0; cadena[i]; i++) 
      printf("%c, %d\n", cadena[i], isdigit(cadena[i]));

   return 0;
}

