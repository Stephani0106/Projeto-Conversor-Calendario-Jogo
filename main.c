#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	int opcaoInicial;
	
	system("cls");
	INICIO:
	printf ("\n ----------MENU PRINCIPAL---------- \n");
	printf ("\n [1] Para converter temperaturas.");
	printf ("\n [2] Para ver o calendário.");
	printf ("\n [3] Para Jogar.");
	printf ("\n Digite a sua opção: ");	
	scanf ("%i", &opcaoInicial);
	printf ("\n \n");
	
	switch (opcaoInicial) 
	{
		case 1 :
		system("cls");
		menuConversor();
		break;
		
		case 2 :
		system("cls");
		menuCalendario();
		break;
		
		case 3 :
		system("cls");
		menuJogo();
		break;
		
		default :
		printf("Opção inválida!");
		goto INICIO;	
	}
}
