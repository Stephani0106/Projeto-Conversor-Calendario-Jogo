#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "header.h"

void menuPrincipal() {
	setlocale(LC_ALL, "Portuguese");
	
	
}

void menuConversor() {
	setlocale(LC_ALL, "Portuguese");
	
	char voltar;
	int opcaoDe, opcaoPara;
	float temperaturaDeCelsius, temperaturaParaCelsius;
	float temperaturaDeFahrenheit, temperaturaParaFahrenheit;
	float temperaturaDeKelvin, temperaturaParaKelvin;
	float temperaturaKelvinAuxiliar;
		
	DE:
	system("cls");
	printf ("\n ----------CONVERSOR DE TEMPERATURAS---------- \n");
	printf ("\n Informe a unidade da temperatura (DE)");
	printf ("\n [1] Para converter de Celsius.");
	printf ("\n [2] Para converter de Fahrenheit.");
	printf ("\n [3] Para converter de Kelvin.");
	printf ("\n Digite a sua opcao: ");	
	scanf ("%i", &opcaoDe);
	printf ("\n \n");
	
	if (opcaoDe > 3 || opcaoDe <= 0) {
		system("cls");
		printf("Opção inválida!");
		system("PAUSE");
		goto DE;
	}
	
	else {
		PARA:
		system("cls");
		printf ("\n ----------CONVERSOR DE TEMPERATURAS---------- \n");
		printf ("\n Informe a unidade da temperatura (PARA)");
		printf ("\n [1] Para converter para Celsius.");
		printf ("\n [2] Para converter para Fahrenheit.");
		printf ("\n [3] Para converter para Kelvin.");
		printf ("\n Digite a sua opcao: ");	
		scanf ("%i", &opcaoPara);
		printf ("\n \n");
		
		
		if (opcaoDe == opcaoPara) 
		{
			system("cls");
			printf("Não é possível converter para unidades iguais!\n\n");
			system("PAUSE");
			goto PARA;
		}
		
		else if (opcaoPara > 3 || opcaoPara <= 0) 
		{
			system("cls");
			printf("Opção inválida!\n\n");
			system("PAUSE");
			goto PARA;
		}
		
		//Convertendo de Celsius para Fahrenheit
		else if (opcaoDe == 1 && opcaoPara == 2) 
		{
			system("cls");	
			printf (" Convertendo DE: Celsius (°C) PARA: Fahrenheit (°F)\n");
			printf ("\n Informe a temperatura em graus Celsius (°C): ");
			scanf ("%f", &temperaturaDeCelsius);	
			temperaturaParaFahrenheit = (temperaturaDeCelsius * 1.8) + 32;
			printf ("\n A temperatura em Fahrenheit é igual a: %0.2f °F", temperaturaParaFahrenheit);	
			
			printf("\n\n Voltar ao menu principal? (S/N) ->");
			scanf("%s", &voltar);
			
			if (voltar == 's' || voltar == 'S') {
				goto DE;
			}
			else if (voltar == 'n' || voltar == 'N'){
				printf("Obrigada por usar nosso sistema de conversão!");
			}
		}
	
		//Convertendo de Celsius para Kelvin
		else if (opcaoDe == 1 && opcaoPara == 3) 
		{
			system("cls");
			printf (" Convertendo DE: Celsius (°C) PARA: Kelvin (K)\n");
			printf ("\n Informe a temperatura em graus Celsius (°C): ");
			scanf ("%f", &temperaturaDeCelsius);
			temperaturaParaKelvin = temperaturaDeCelsius + 273.15;
			printf ("\n A temperatura em Kelvin é igual a: %0.2f K", temperaturaParaKelvin);
		
			printf("\n\n Voltar ao menu principal? (S/N) ->");
			scanf("%s", &voltar);
			
			if (voltar == 's' || voltar == 'S') {
				goto DE;
			}
			else if (voltar == 'n' || voltar == 'N'){
				printf("Obrigada por usar nosso sistema de conversão!");
			}
		}
		
		//Convertendo de Fahrenheit para Celsius
		else if (opcaoDe == 2 && opcaoPara == 1) 
		{
			system("cls");
			printf (" Convertendo DE: Fahrenheit (°F) PARA: Celsius (°C)\n");
			printf ("\n Informe a temperatura em graus Fahrenheit (°F): ");
			scanf ("%f", &temperaturaDeFahrenheit);
			temperaturaParaCelsius = (temperaturaDeFahrenheit - 32) / 1.8;
			printf ("\n A temperatura em Celsius e igual a: %0.2f C", temperaturaParaCelsius);
			
			printf("\n\n Voltar ao menu principal? (S/N) -> ");
			scanf("%s", &voltar);
			
			if (voltar == 's' || voltar == 'S') {
				goto DE;
			}
			else if (voltar == 'n' || voltar == 'N'){
				printf("Obrigada por usar nosso sistema de conversão!");
			}
		}
		
		//Convertendo de Fahrenheit para Kelvin
		else if (opcaoDe == 2 && opcaoPara == 3) 
		{
			system("cls");
			printf (" Convertendo DE: Fahrenheit (°F) PARA: Kelvin (K)\n");
			printf ("\n Informe a temperatura em graus Fahrenheit (°F): ");
			scanf ("%f", &temperaturaDeFahrenheit);
			temperaturaKelvinAuxiliar = (temperaturaDeFahrenheit - 32) / 1.8;
			temperaturaParaKelvin = temperaturaKelvinAuxiliar + 273.15;
			printf ("\n A temperatura em Kelvin e igual a: %0.2f K", temperaturaParaKelvin);			
			
			printf("\n\n Voltar ao menu principal? (S/N) -> ");
			scanf("%s", &voltar);
			
			if (voltar == 's' || voltar == 'S') {
				goto DE;
			}
			else if (voltar == 'n' || voltar == 'N'){
				printf("Obrigada por usar nosso sistema de conversão!");
			}
		}
		
		//Convertendo de Kelvin para Celsius
		else if (opcaoDe == 3 && opcaoPara == 1) 
		{
			system("cls");
			printf (" Convertendo DE: Kelvin (K) PARA: Celsius (°C)\n");
			printf ("\n Informe a temperatura em Kelvin (K): ");
			scanf ("%f", &temperaturaDeKelvin);
			temperaturaParaCelsius = temperaturaDeKelvin - 273.15;
			printf ("\n A temperatura em Celsius e igual a: %0.2f °C", temperaturaParaCelsius);
			
			printf("\n\n Voltar ao menu principal? (S/N) ->");
			scanf("%s", &voltar);
			
			if (voltar == 's' || voltar == 'S') {
				goto DE;
			}
			else if (voltar == 'n' || voltar == 'N'){
				printf("Obrigada por usar nosso sistema de conversão!");
			}
		}
		
		//Convertendo de Kelvin para Fahrenheit
		else if (opcaoDe == 3 && opcaoPara == 2) 
		{
			system("cls");
			printf (" Convertendo DE: Kelvin (K) PARA: Fahrenheit (F°)\n");
			printf ("\n Informe a temperatura em Kelvin (K): ");
			scanf ("%f", &temperaturaDeKelvin);
			temperaturaKelvinAuxiliar = temperaturaDeKelvin-273.15;
			temperaturaParaFahrenheit = (temperaturaKelvinAuxiliar*1.8)+32;
			printf ("\n A temperatura em Fahrenheit e igual a: %0.2f F", temperaturaParaFahrenheit);
			
			printf("\n\n Voltar ao menu principal? (S/N) -> ");
			scanf("%s", &voltar);
			
			if (voltar == 's' || voltar == 'S') {
				goto DE;
			}
			else if (voltar == 'n' || voltar == 'N'){
				printf("Obrigada por usar nosso sistema de conversão!");
			}
		}
	}
}

void menuCalendario() {
	setlocale(LC_ALL, "Portuguese");
	
	printf ("\n ----------CALENDÁRIO---------- \n");
}

void menuJogo() {
	setlocale(LC_ALL, "Portuguese");
	
	printf ("\n ----------JOGO---------- \n");
}



