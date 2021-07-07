#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "header.h"
#define nome "\t\t Jogo da Forca \n\n" 

// ---------- Menu Principal ---------- //
int menuPrincipal(){
	
	int escolha = 0;
	
	setlocale(LC_ALL, "Portuguese");	
	
Menu:
	
	setbuf(stdin,NULL);

	system("cls");	
	
	printf("\n----------MENU PRINCIPAL----------\n");
	
	printf("\n[1] Calendário");	
	printf("\n[2] Calculadora");
	printf("\n[3] Conversor de Temperaturas");
	printf("\n[4] Jogo da Forca");
	printf("\n[5] Sair\n\n");
	printf("Escolha uma opção: ");
	scanf("%d",&escolha);
	
	system("cls");
	
	if(escolha < 1 || escolha > 5){
		printf("\nEscolha uma das opções do Menu!\n\n\n");
		system("pause");
		goto Menu;
	}
	
	return(escolha);
}

// ---------- Calendário ----------//
void calendario(){
	
	int parametro, diaInicial, ano;
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    parametro = tm.tm_mon;
    char tecla;
    ano = tm.tm_year + 1900; 
    
    //Define em qual dia da semana será o primeiro dia do mês
   	diaInicial = primeiro_dia_da_semana(ano);
    
    system("cls");
	executaCalendario(parametro,diaInicial);	
	
INICIO:		
	
	setbuf(stdin,NULL);
	tecla = getch();
	
	if (tecla == -32) {
	    tecla = getch();
	    switch(tecla) {
	        case 75: //Seta para esquerda
	        	parametro-=1;
	        	executaCalendario(parametro,diaInicial);
	        	goto INICIO;
	            break;
	            
	        case 77: //Seta para direita
	        	parametro+=1;
	            executaCalendario(parametro,diaInicial);
				goto INICIO;
				break;
				
			case 72: //Seta para cima
				main();
				break;	
	    }
	}
}

//Calendário => Função para encontrar o primeiro dia da semana
int primeiro_dia_da_semana(int ano){
    int dia;
    dia = (((ano - 1) * 365) + ((ano - 1) / 4) - ((ano - 1) / 100) + ((ano) / 400) + 1) % 7;
	return dia;
}

int diaIniMes(int par, int ini){
	
	int i,j,k,diaIniM;
	int diasM[] = {31,28,31,30,31,30,31,31,30,31,30,31};
			
	k = ini;
	
	for(i = 0; i < par; i++)
    {
        j = diasM[i];
        
        k += j;        
    }
    
    k = k%7;
    
    diaIniM = k;
    
	return diaIniM;
}

//Calendário => Função para montar o calendário
void executaCalendario(int par, int dIni){
	system("cls");
	
	setlocale(LC_ALL, "Portuguese");
	printf ("\n ----------CALENDÁRIO---------- \n");
	
	if(par < 0){
		par = 0;
	}
	if(par > 11){
		par = 11;
	}	
	
	//Define a data atual
	time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    printf("\nData atual: %d/0%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);  
    
    //Variáveis
    int ano, dia=0, diaNoMes, diaDaSemana=0;//, diaInicial;
    ano = tm.tm_year + 1900;
    char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    int diasMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        
    //Define quantos dias terá o mês
    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
    {
        diasMes[1] = 29;
    }    
    
    //Monta a estrutura do calendário
        diaNoMes = diasMes[par];
        
        
    //Verifica o dia da semana em que o mês começa 
    dIni = diaIniMes(par,dIni);    
        
        printf("\n\n--------------%s--------------", meses[par--]);
        printf("\n  Dom  Seg  Ter  Qua  Qui  Sex  Sab\n");
        
        for(diaDaSemana = 0; diaDaSemana < dIni; diaDaSemana++)
        {
           printf("     ");
        }
        
        for(dia = 1; dia <= diaNoMes; dia++)
        {
            printf("%5d", dia);
            
            if(++diaDaSemana > 6)
            {
                printf("\n");
                diaDaSemana = 0;
            }
            dIni = diaDaSemana;
        }
    
    printf("\n\nPara voltar ao menu pressione Seta para Cima");
}
	
// ---------- CALCULADORA ----------//
int qtdCaractres(int k){
	
	int q = 0;
	
	do{
		q += 1;
		k = k / 10;
		
	}while(k > 0);
	
	return q;
}

float calculo(int y, float x, float z){
	
	float res=0;
	
	switch(y){
		case 1:
			res = x + z;
			break;
		case 2:
			res = x - z;
			break;
		case 3:
			res = x * z;
			break;
		case 4:
			res = x / z;
			break;	 			
	}
	
	return res;
}

void imprime(float x, int y, float z, float resultado){
	
	int l, m, n, i,tot1, tot2;
	char o[0];
	
	if(x >= 0){
		l = qtdCaractres(x);
	}
	
	if(z >= 0){
		m = qtdCaractres(z); 
	}
		
	if(resultado >= 0){
		n = qtdCaractres(resultado);
	}
	
	switch(y){
		case 1:
			o[0] = '+';
			break;
		case 2:
			o[0] = '-';
			break;
		case 3:
			o[0] = 'x';
			break;
		case 4:
			o[0] = '/';
			break;
		default:
			o[0] = ' ';						
	}	
	
	printf("      _______________________________     \n");
	printf("     |                               |    \n");
//---------------------------------------------------------------//	
	printf("     |");	
	
	tot1 = 30-l-3-m-6;
	for(i=tot1;i>0;i--){
		printf(" ");
	}
	printf("%.2f %c %.2f",x,o[0],z);
	printf(" |    \n");
//---------------------------------------------------------------//	
	printf("     |");
	
	tot1 = 30-l-3-m-6;
	tot2 = l+3+m+6;
	for(i=tot1;i>0;i--){
		printf(" ");
	}	
	for(i=tot2;i>0;i--){
		printf("_");
	}
	printf(" |    \n");
//---------------------------------------------------------------//	
	printf("     |");
	tot1 = 30-n-5;
	for(i=tot1;i>0;i--){
		printf(" ");
	}	
	printf("= %.2f",resultado);
	printf(" |    \n");
//---------------------------------------------------------------//	
	
	printf("     |_______________________________|    \n");
	printf("     |       |       |       |       |    \n");
	printf("     |   7   |   8   |   9   |   :   |    \n");
	printf("     |_______|_______|_______|_______|    \n");
	printf("     |       |       |       |       |    \n");
	printf("     |   4   |   5   |   6   |   X   |    \n");
	printf("     |_______|_______|_______|_______|    \n");
	printf("     |       |       |       |       |    \n");
	printf("     |   1   |   2   |   3   |   -   |    \n");
	printf("     |_______|_______|_______|_______|    \n");
	printf("     |       |               |       |    \n");
	printf("     |   0   |       =       |   +   |    \n");
	printf("     |_______|_______________|_______|    \n");		
}

void calculadora(){
	
	float x, z, resultado, i;
	int y, voltar;
	
Inicio:

	system("cls");	

	x = 0;
	y = 0; 
	z = 0; 
	i = 0;
	resultado = 0; 
	
	imprime(x,y,z,resultado);
	
	printf("\nDigite um valor: \n");
	scanf("%f", &x);
	
	system("cls");
	imprime(x,y,z,resultado);
	
	printf("\nDigite a operacao:\n");
	printf("\nSoma[1] Subtracao[2] Multiplicacao[3] Divisao[4]\n");
	scanf("%d",&y);
	
	if(y > 0 && y < 5){
		system("cls");
		imprime(x,y,z,resultado);
	}else{
			
		do{
			system("cls");
			printf("\nOperacao Invalida: \n\n\n\n\n");
			system("pause");
			system("cls");			
			
			imprime(x,y,z,resultado);
			printf("\nDigite a operacao:\n");
			printf("\nSoma[1] Subtracao[2] Multiplicacao[3] Divisao[4]\n");
			scanf("%d",&y);
			
		}while(y < 0 || y > 5);	
		
		system("cls");
		imprime(x,y,z,resultado);	
	}	
	
	printf("\nDigite outro valor: \n");
	scanf("%f", &z);
	
	system("cls");	
	resultado = calculo(y,x,z);	
	imprime(x,y,z,resultado);
	
	printf("\n[1] Novo Calculo");
	printf("\n[2] Menu Principal\n\n");
	scanf("%d",&voltar);
	
	switch(voltar){
		case 1:
			goto Inicio;
			break;
		case 2:
			main();;
			break;
		default:
			main();;
			break;	
	}
}

// ---------- TERMOMETROS ----------//
void deCpara(float c){
	
	float f,k;
	
	f = (c*(9.0/5.0))+32.0;
	
	k = (c+273.15);
	
	imprimeTermometro(c,f,k);	
}

void deFpara(float f){
	
	float c,k;
	
	c = ((f-32.0)*(5.0/9.0));
	
	k = (c+273.15);
	
	imprimeTermometro(c,f,k);
}

void deKpara(float k){
	
	float c,f;
	
	c = (k - 273.15);
	
	f = (c*(9.0/5.0))+32.0;
	
	imprimeTermometro(c,f,k);
}

void imprimeTermometro(double c,double f,double k){
	
	setlocale(LC_ALL, "Portuguese");
	
	system("cls");
	
	printf(" _____________________________  \n");
	printf("|   °F        °C         K    | \n");
	
	if(f>=0){
		if(f<10){
			printf("|   %.2f",f);
		}else{
			printf("|  %.2f",f);
		}		
	}else{
		if(f>-10){
			printf("|  %.2f",f);	
		}else{
			printf("| %.2f",f);
		}		
	}
	
	if(c>=0){
		if(c<10){
			printf("      %.2f    %.2f  | \n",c,k);
		}else{
			if(c>99){
				printf("   %.2f    %.2f  | \n",c,k);
			}else{
				printf("     %.2f    %.2f  | \n",c,k);
			}			
		}		
	}else{
		if(c>-10){
			printf("     %.2f    %.2f  | \n",c,k);
		}else{
			printf("    %.2f    %.2f  | \n",c,k);
		}		
	}	
	
	printf("|             ___             | \n");
	printf("|   212  --  ");	
	if(c > 95.0){
		printf("|100|  --  373   | \n");
	}else{
		printf("|   |  --  373   | \n");
	}		
	
	printf("|   194  --  ");	
	if(c > 85.0){
		printf("|+90|  --  363   | \n");
	}else{
		printf("|   |  --  363   | \n");
	}		
	
	printf("|   176  --  ");	
	if(c > 75.0){
		printf("|+80|  --  353   | \n");
	}else{
		printf("|   |  --  353   | \n");
	}		
	
	printf("|   158  --  ");	
	if(c > 65.0){
		printf("|+70|  --  243   | \n");
	}else{
		printf("|   |  --  243   | \n");
	}		
	
	printf("|   140  --  ");	
	if(c > 55.0){
		printf("|+60|  --  333   | \n");
	}else{
		printf("|   |  --  333   | \n");
	}		
	
	printf("|   122  --  ");	
	if(c > 45.0){
		printf("|+50|  --  323   | \n");
	}else{
		printf("|   |  --  323   | \n");
	}		
	
	printf("|   104  --  ");	
	if(c > 35.0){
		printf("|+40|  --  313   | \n");
	}else{
		printf("|   |  --  313   | \n");
	}		
	
	printf("|    86  --  ");	
	if(c > 25.0){
		printf("|+30|  --  303   | \n");
	}else{
		printf("|   |  --  303   | \n");
	}		
	
	printf("|    68  --  ");	
	if(c > 15.0){
		printf("|+20|  --  293   | \n");
	}else{
		printf("|   |  --  293   | \n");
	}		
	
	printf("|    50  --  ");	
	if(c > 5.0){
		printf("|+10|  --  283   | \n");
	}else{
		printf("|   |  --  283   | \n");
	}		
	
	printf("|    32  --  ");	
	if(c > -05.0){
		printf("|0.0|  --  273   | \n");
	}else{
		printf("|   |  --  273   | \n");
	}		
	printf("");
	
	printf("|    14  --  ");	
	if(c > -15.0){
		printf("|-10|  --  263   | \n");	
	}else{
		printf("|   |  --  263   | \n");
	}		
	
	printf("|   -04  --  ");	
	if(c > -25.0){
		printf("|-20|  --  253   | \n");	
	}else{
		printf("|   |  --  253   | \n");
	}		
	
	printf("|   -22  --  ");	
	if(c > -35.0){
		printf("|-30|  --  243   | \n");	
	}else{
		printf("|   |  --  243   | \n");
	}		
	
	printf("|           /#####\\           | \n");
	printf("|          (#######)          | \n");
	printf("|           \\#####/           | \n");
	printf("|_____________________________| \n");
}

void menuConversor(){
	setlocale(LC_ALL,"Portuguese");
	float c,f,k;
	int opc, voltar;
	
Inicio:

	system("cls");
	c=0.0;
	f=0.0;
	k=0.0;	
	
	printf("\nEscolha a conversão que deseja fazer:\n");
	
	printf("\n[1] De: Celsius    ->  Para: Fahrenheit e Kelvin   ");
	printf("\n[2] De: Fahrenheit ->  Para: Celsius e Kelvin   ");
	printf("\n[3] De: Kelvin     ->  Para: Celsius e Fahrenheit \n");
	
	scanf("%d",&opc);
	
	system("cls");
	
	switch(opc){
		case 1:
			printf("\nDigite a temperatura em graus Celcius: ");
			scanf("%f",&c);
			deCpara(c);
			break;
		case 2:
			printf("\nDigite a temperatura em graus Fahrenheit: ");
			scanf("%f",&f);
			deFpara(f);
			break;
		case 3:
			printf("\nDigite a temperatura em Kelvins: ");
			scanf("%f",&k);
			deKpara(k);
			break;
		default:
			printf("\nEscolha uma opcao valida\n\n\n\n\n");
			system("pause");
			goto Inicio;
	}
	
	printf("\n[1] Nova Conversão");
	printf("\n[2] Menu Principal\n\n");
	scanf("%d",&voltar);
	
	switch(voltar){
		case 1:
			goto Inicio;
			break;
		case 2:
			main();
			break;
		default:
			main();
			break;	
	}
}

// ---------- JOGO DA FORCA ----------//
void imprimeForca(int chances){
	
	printf(nome);
	
	switch(chances){
		case 6:
			printf("\t   ____   \n");
			printf("\t  |    |  \n");
			printf("\t  |       \n");
			printf("\t  |       \n");
			printf("\t  |       \n");
			printf("\t__|__     \n\n");
			printf("Chances Restantes: %d \n",chances);
			break;
		case 5:
			printf("\t   ____    \n");
			printf("\t  |    |   \n");
			printf("\t  |    0   \n");
			printf("\t  |        \n");
			printf("\t  |        \n");
			printf("\t__|__      \n\n");
			printf("Chances Restantes: %d \n",chances);
			break;
		case 4:
			printf("\t   ____    \n");
			printf("\t  |    |   \n");
			printf("\t  |    0   \n");
			printf("\t  |    |   \n");
			printf("\t  |        \n");
			printf("\t__|__      \n\n");
			printf("Chances Restantes: %d \n",chances);
			break;
		case 3:
			printf("\t   ____    \n");
			printf("\t  |    |   \n");
			printf("\t  |   \\0  \n");
			printf("\t  |    |   \n");
			printf("\t  |        \n");
			printf("\t__|__      \n\n");
			printf("Chances Restantes: %d \n",chances);
			break;
		case 2:
			printf("\t   ____    \n");
			printf("\t  |    |   \n");
			printf("\t  |   \\0/ \n");
			printf("\t  |    |   \n");
			printf("\t  |        \n");
			printf("\t__|__      \n\n");
			printf("Chances Restantes: %d \n",chances);
			break;
		case 1:
			printf("\t   ____    \n");
			printf("\t  |    |   \n");
			printf("\t  |   \\0/ \n");
			printf("\t  |    |   \n");
			printf("\t  |   /    \n");
			printf("\t__|__      \n\n");
			printf("Chances Restantes: %d \n",chances);
			break;
		case 0:
			printf("\t   ____    \n");
			printf("\t  |    |   \n");
			printf("\t  |   \\0/ \n");
			printf("\t  |    |   \n");
			printf("\t  |   / \\ \n");
			printf("\t__|__      \n\n");
			printf("Você Perdeu! \n\n",chances);
			break;
	}	
}

void jogoForca(){
	
	setlocale(LC_ALL,"Portuguese");
	
	char palavra[30], letra[1], secreta[30], escolha[1], caract[1];
	int tamanho, i, chances, acertos, voltar, l, j;
	bool acerto;
	
Inicio:	
	
	chances = 6;
	tamanho = 0;
	acertos = 0;
	i       = 0;
	l       = 0;
	j       = 0;
	acerto  = false;
	caract[0] = '-';
	
	system("cls");
	
	printf(nome);
	
	printf("Fale para seu amigo fechar os olhos e digite a palavra secreta: ");
	setbuf(stdin,NULL);
	gets(secreta);
		
	system("cls");
	
	while(secreta[i] != '\0'){
		i++;
		tamanho++;
	}
	
	for(i=0;i<tamanho;i++){
		palavra[i] = '-';
	}	
	
	while((chances>0) && (acertos<tamanho)){
	
		imprimeForca(chances);
		
		printf("\nPalavra Secreta: ");

		for(i=0;i<tamanho;i++){
			if(i==0){
				printf("%c",caract[0]);
			}else{
				printf("%c",palavra[i]);
			}							
		}
		
		printf("\n\nDigite uma letra: ");
		setbuf(stdin,NULL);
		gets(letra);		
					
		for(i=0;i<tamanho;i++){
			if(secreta[i] == letra[0]){				
				acerto = true;
				palavra[i] = letra[0];
				if(palavra[0]!='\0'){
					caract[0]=palavra[0];
				}
				acertos++;
			}
		}
		
		if(!acerto){
			chances--;
		}
		
		acerto = false;
		system("cls");
	}
	
	if(acertos == tamanho){
		printf("\n\t\t Você Venceu! \n\n");
	}else{
		imprimeForca(chances);
	}
	
	printf("\n[1] Jogar Novamente");
	printf("\n[2] Menu Principal\n\n");
	scanf("%d",&voltar);
	
	switch(voltar){
		case 1:
			goto Inicio;
			break;
		case 2:
			main();
			break;
		default:
			main();
			break;		
	}
}
