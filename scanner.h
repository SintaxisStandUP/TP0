#ifndef HEADER_SCANNER
#define HEADER_SCANNER
enum token {
	TOKEN_CTE = 2,	
	TOKEN_IDE = 4,
	TOKEN_ERROR = 5,
	TOKEN_FDT = 7,
	
};
enum columnas {
	LETRA = 0,	
	DIGITO = 1,
	OTRO = 2,
	ESPACIO = 3,
	END = 4,
	
};
enum estados {INICIAL, RECDIGITO, CTE_REC, RECLETRA, IDE_REC, REC_ERROR, ERROR, FDT};
int scanner(FILE **archivo);

#endif
