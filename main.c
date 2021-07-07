#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int escolha=0;
	
	setbuf(stdin,NULL);
		
	escolha = menuPrincipal();
	
	switch(escolha){
		case 1:
			calendario();
			break;
		case 2:
			calculadora();
			break;
		case 3:
			menuConversor();
			break;
		case 4:
			jogoForca();
			break;
		case 5:
			goto Fim;	
	}		
	
Fim:	
	return 0;
}
