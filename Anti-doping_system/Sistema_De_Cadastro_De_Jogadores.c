#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

//''''''''''''''''''''''''''''''''''''''''''''''
//		Estrutura de cadastro de jogadores

typedef struct Cadastro_de_Jogadores{
	char Nome_do_Jogador[100];
	int Ano_de_Nascimento;
	char Pais_da_Selecao[100];
	int Numero_da_Camisa;
	char Posicao_no_Time[100];
	struct Cadastro_de_Jogadores *Proximo_no_da_Lista;
}Cadastro;

//''''''''''''''''''''''''''''''''''''''''''''''

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//            Estrutura sorteio de jogadores

typedef struct Sorteio_de_Jogadores{
	int numero_sorteado;
	Cadastro *Jogador_sorteado;
	struct Sorteio_de_Jogadores *Proximo_no_da_Lista;
}anti_doping;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int Menu_principal(void);
int Inserir_na_Lista(Cadastro **Inicio_da_Lista,FILE *fp, int u);
int imprimir_tudo(Cadastro *Inicio_da_Lista);
Cadastro *Buscar(Cadastro *Inicio, char *Nome_para_comparacao);
int Excluir_da_lista(Cadastro **retorno_da_busca);
int Alterar_Cadastro();
int Menu_de_Inicio(void);
int remover(Cadastro **q, Cadastro  *p, char *n);
int Contar_nos_d_Lista(Cadastro *Inicio_da_Lista);
void ler(FILE *fp, char *v);
void manager(Cadastro **Inicio_da_Lista,anti_doping **Sorteio, FILE *fp);
void sortear_Jogador(Cadastro *Inicio_da_Lista, anti_doping **Sorteio, int quantidade);
int Inserir_na_Lista_Sorteio(anti_doping  **Inicio_da_Lista, int u);

//_____________| funcao principal |_____________

int main(void){
	
	Cadastro *Inicio_da_Lista = NULL;
	anti_doping *Sorteio = NULL;
	char n[100], v[100];
	int a;
	FILE *fp;
	fp = fopen("entrada5.txt", "r");
	
	printf("Sistema Antidoping - COPA DO MUNDO 2018\n\n");
	manager(&Inicio_da_Lista, &Sorteio, fp); // Leitura por arquivo
	
	while(1){
		switch(Menu_principal())
		{
			case 1:
					Inserir_na_Lista(&Inicio_da_Lista, fp, 0);
					break;
			case 2: 
					break;
			case 3:
					printf("Digite o nome: ");
					scanf(" %[^\n]s", n);
					remover(&Inicio_da_Lista, Buscar(Inicio_da_Lista, n), n);
					break;
			case 4:
					break;
			case 5:
					break;
			case 6:
					imprimir_tudo(Inicio_da_Lista);
					break;
			case 7:
					break;
			case 8:
					exit(0);
					break;
			case 9:
					
					break;
			default: 
					printf("Algo errado aconteceu, tente novamente");
		}
		printf("\n\n\nPressione ""ENTER"" para continuar...");
		scanf("c\n");
	}
	
} 
//______________________________________________


//----------------| funcao menu |---------------

int Menu_principal(void){
	
	int Erro_de_escolha = 0, Escolha_de_opcao;
	
	do{	
		if(Erro_de_escolha > 0){
			system("cls || clear");
			printf("***Opcao invalida, por favor digite novamente***\n\n");
		}
	    printf("\n\t\t-------| MENU PRINCIPAL |-------\n\n\n");
		printf("[1] - CADASTRAR JOGADOR\n");
		printf("[2] - ALTERAR NUMERO DA CAMISA\n");
		printf("[3] - REMOVER\n");
		printf("[4] - SORTEAR\n");
		printf("[5] - FILTRAR PELA POSICAO\n");
		printf("[6] - EXIBIR TODOS OS JOGADORES\n");
		printf("[7] - EXIBIR JOGADORES SORTEADOS\n");
		printf("[8] - SAIR DO PROGRAMA\n");
		printf("\n\nDigite a sua escolha: ");
		scanf("%d", &Escolha_de_opcao);
	Erro_de_escolha++;
	}while(Escolha_de_opcao <1 || Escolha_de_opcao>9);
	return Escolha_de_opcao;
}

//_______________________________________________


//___________| Funcao printar tudo |____________

int imprimir_tudo(Cadastro *Inicio_da_Lista){
	
	int i;
	Cadastro *Auxiliar;
	Auxiliar = Inicio_da_Lista;
	
	if(Auxiliar == NULL){
//		for(i=0;i<10000;i++) printf("\b");
		printf("\n\nNAO EXISTEM JOGADORES REGISTRADOS!\n\n");
		return 0;
	}
	else{
		printf("\n\nEXIBICAO DE TODOS OS JOGADORES\n");
		while(Auxiliar != NULL){
			printf("%s\t", Auxiliar->Nome_do_Jogador);
			printf("%d\t", Auxiliar->Ano_de_Nascimento);
			printf("%s\t", Auxiliar->Pais_da_Selecao);
			printf("%d\t", Auxiliar->Numero_da_Camisa);
			printf("%s\n", Auxiliar->Posicao_no_Time);
			Auxiliar = Auxiliar->Proximo_no_da_Lista;
		}
	}
	return 0;
}

//-----------------------------------------------


//________| Funcao inserir na Lista |__________

int Inserir_na_Lista(Cadastro **Inicio_da_Lista,FILE *fp, int u){
	char w[100];
	char y[100];
	
	Cadastro *Novo_Jogador, *Ponteiro_Auxiliar, *anterior;
	Novo_Jogador = (Cadastro*) malloc(sizeof(Cadastro));
	
	if(u == 1){
//		printf("entou no arquivo\n");
		ler(fp, Novo_Jogador->Nome_do_Jogador);
		ler(fp, w);
		ler(fp, Novo_Jogador->Pais_da_Selecao);
		ler(fp, y);
		ler(fp, Novo_Jogador->Posicao_no_Time);
		Novo_Jogador->Ano_de_Nascimento = atoi(w);
		Novo_Jogador->Numero_da_Camisa = atoi(y);
//		printf("saiu\n");
	}
	if(u == 0){
		
		printf("\n\nDigite o nome do jogador: ");
		//gets(Novo_Jogador->Nome_do_Jogador);
		scanf(" %[^\n]s", Novo_Jogador->Nome_do_Jogador);
		printf("Digite o ano de nascimento: ");
		scanf("%d", &Novo_Jogador->Ano_de_Nascimento);
		printf("Digite o pais da selecao: ");
		scanf("%s", Novo_Jogador->Pais_da_Selecao);
		printf("Digite o numero da camisa: ");
		scanf("%d", &Novo_Jogador->Numero_da_Camisa);
		printf("Digite a posicao no time: ");
		scanf("%s", Novo_Jogador->Posicao_no_Time);
	}
	if(*Inicio_da_Lista == NULL)
	{
//		printf("sera");
		*Inicio_da_Lista = Novo_Jogador;
		Novo_Jogador->Proximo_no_da_Lista = NULL;
//		printf("nao,nao eh");
	}
	
	
	else{
//		printf("aaaaaaaaaaaa\n");
		Ponteiro_Auxiliar = *Inicio_da_Lista;
//		printf("bbbbbbbb\n");
		Ponteiro_Auxiliar = Ponteiro_Auxiliar->Proximo_no_da_Lista;
//		printf("cccccccc\n");
		anterior = *Inicio_da_Lista;
//		printf("ddddddddd\n");
		while(Ponteiro_Auxiliar != NULL){
//			printf("eeeeeee\n");
	      	Ponteiro_Auxiliar = Ponteiro_Auxiliar->Proximo_no_da_Lista;
//			printf("fffffff\n");
	      	anterior = anterior->Proximo_no_da_Lista;
//			printf("gggggggg\n");
	    }
//	    printf("hhhhhhhhhhh\n");
	    Novo_Jogador->Proximo_no_da_Lista = NULL;
//	    printf("iiiiiiiiiii\n");
	    anterior->Proximo_no_da_Lista = Novo_Jogador;
//	    printf("jjjjjjjjjjjj\n");
	}
	
	/*
	
	else{
		
		Ponteiro_Auxiliar = *Inicio_da_Lista;
		*Inicio_da_Lista = Novo_Jogador;
		Novo_Jogador->Proximo_no_da_Lista = Ponteiro_Auxiliar;
	}
	
	*/
	
	return 0;
}

//_____________________________________________


//_______________| Fucao busca |_______________

Cadastro *Buscar(Cadastro *Inicio, char *Nome_para_comparacao){

	Cadastro *Auxiliar, *auxcomp;
	auxcomp = Inicio;
	if(auxcomp == NULL) // se vazia
		return NULL;
	if(!strcmp(Nome_para_comparacao, auxcomp->Nome_do_Jogador)) // se so tem 1 elemento
		return auxcomp;
	do{
		Auxiliar = auxcomp;
		if(auxcomp->Proximo_no_da_Lista){
			if(!strcmp(Nome_para_comparacao, auxcomp->Proximo_no_da_Lista->Nome_do_Jogador))
				return Auxiliar;
		}
		if(auxcomp != NULL)
			auxcomp = auxcomp->Proximo_no_da_Lista;
	}while(auxcomp != NULL);
	return NULL;		
}


//_____________________________________________


//_________| Funcao Excluir da lista |_________

int remover(Cadastro **q, Cadastro  *p, char *n){
	
   Cadastro *lixo;
   if(p == NULL){
   		printf("\n\nNAO FOI POSSIVEL A REMOCAO DE %s.\nCADASTRO INEXISTENTE.", n);
   		return -2;
   	}
   if(!strcmp(p->Nome_do_Jogador, n)){
 //  		printf("%s \n", p->Nome_do_Jogador);
//   		printf("erro");
   //		return -1;
   		lixo = p;
  		*q = p->Proximo_no_da_Lista;
   		free(lixo);
   		return 0;
   }
   	lixo = p->Proximo_no_da_Lista;
	p->Proximo_no_da_Lista = lixo->Proximo_no_da_Lista;
	free (lixo);
   return 0;
}

//_____________________________________________


//__________| Funcao alterar cadastro|__________

int Alterar_Cadastro(){
	
	
	return 0;
}
	
//_____________________________________________
	
	
//__________| Funcao Menu de Inicio |___________

int Menu_de_Inicio(void)
{
	
	printf("[1] - Entrada pelo teclado\n");
	printf("[2] - Entrada por arquivo\n\n");
	printf("Digite a opcao desejada: ");

	return 0;	
}
		
//______________________________________________

		
//______| Funcao Gerenciador de Chamadas |______

void manager(Cadastro **Inicio_da_Lista,anti_doping **Sorteio, FILE *fp){	

	char n[100], v[100], w[100], x[100], y[100], z[100], a;	
	int m;
	
	
//	ler(fp, v);
	
	while(!feof(fp)){
		
		ler(fp, v);
	//	printf("%s\n", v);
	//	printf("%d\n", atoi(v));
//		fscanf(fp, " %d ", &m);
//		fgets(v, sizeof(char ), fp);
		m = atoi(v);
//		printf("%d", m);
		switch(m)
		{
			case 1:
					Inserir_na_Lista(Inicio_da_Lista, fp, 1);
					break;
			case 2: 
					ler(fp, v);
					ler(fp, v);
					break;
			case 3:
					ler(fp, v);
			//		printf("Digite o nome para remover: ");
			//		scanf("%s", n);
					remover(Inicio_da_Lista, Buscar(*Inicio_da_Lista, v), v);
					break;
			case 4:
					ler(fp, v);
					printf("%s\n", v);
					sortear_Jogador(*Inicio_da_Lista, Sorteio, atoi(v));
					break;
					break;
			case 5:
					ler(fp, v);
					break;
			case 6:
					imprimir_tudo(*Inicio_da_Lista);
					break;
			case 7:
					break;
			case 8:
					printf("\n\nAplicação encerrada. Obrigado por usar nosso sistema!");
//					exit(0);
					break;
			case 9:
					
					break;
			default: 
//					printf("Algo errado aconteceu, tente novamente");
					break;
		}
//		printf("\n\n\nPressione ""ENTER"" para continuar...");
//		scanf("c\n");
	}		
}
//______________________________________________

//________| Funcao contar nos da lista |________

int Contar_nos_d_Lista(Cadastro *Inicio_da_Lista){
	int i=0;
	Cadastro *g;
	if(Inicio_da_Lista == NULL)
		return -1;
	g = Inicio_da_Lista;
	do{
		g = g->Proximo_no_da_Lista;
		i++;
	}while(g != NULL);
	return i;
}

//________________| funcao leitura de linha |_________________


void ler(FILE *fp, char *v){
	
	int i;
	char c = 'z';
	
	for(i=0;i<100 || c == '\n';i++){
		
		c = fgetc(fp);
		if(c != '\n')
			v[i] = c;
		else{
			v[i] = '\0';
			break;
		}
	}
}

//____________________________________________________________


//##########################################################
//                    sortear numero

int sortear_numero(int x)
{
    int i;
    srand( (unsigned)time(NULL) );
    return (1 + (rand() % x));
}

//##########################################################


//__________________________________________________________
//                   sortear jogador

void sortear_Jogador(Cadastro *Inicio_da_Lista, anti_doping **Sorteio, int quantidade){
	
	int i, t, k;
	anti_doping *auxSort;
	
	auxSort = *Sorteio;
	i = 0;
	do
	{
		t = sortear_numero(Contar_nos_d_Lista(Inicio_da_Lista));
		printf("%d", t);
//		if(Sorteio == NULL)
//			printf(" ");
		k = 0;
		while(auxSort != NULL){
			if(auxSort->numero_sorteado == t)
				k++;
			auxSort = auxSort->Proximo_no_da_Lista;
		}
		if(k == 0){
			
			Inserir_na_Lista_Sorteio(Sorteio, t);
			i++;
		}
	}while(i < quantidade);
}


//________| Funcao inserir na Lista |__________

int Inserir_na_Lista_Sorteio(anti_doping  **Inicio_da_Lista, int u){
	char w[100];
	char y[100];
	
	anti_doping *Novo_Jogador_Sorteado, *Ponteiro_Auxiliar, *anterior;
	Novo_Jogador_Sorteado = (anti_doping *) malloc(sizeof(anti_doping));
	
	Novo_Jogador_Sorteado->numero_sorteado = u;
	
	if(*Inicio_da_Lista == NULL)
	{
//		printf("sera");
		*Inicio_da_Lista = Novo_Jogador_Sorteado;
		Novo_Jogador_Sorteado->Proximo_no_da_Lista = NULL;
//		printf("nao,nao eh");
	}
	
	
	else{
//		printf("aaaaaaaaaaaa\n");
		Ponteiro_Auxiliar = *Inicio_da_Lista;
//		printf("bbbbbbbb\n");
		Ponteiro_Auxiliar = Ponteiro_Auxiliar->Proximo_no_da_Lista;
//		printf("cccccccc\n");
		anterior = *Inicio_da_Lista;
//		printf("ddddddddd\n");
		while(Ponteiro_Auxiliar != NULL){
//			printf("eeeeeee\n");
	      	Ponteiro_Auxiliar = Ponteiro_Auxiliar->Proximo_no_da_Lista;
//			printf("fffffff\n");
	      	anterior = anterior->Proximo_no_da_Lista;
//			printf("gggggggg\n");
	    }
//	    printf("hhhhhhhhhhh\n");
	    Novo_Jogador_Sorteado->Proximo_no_da_Lista = NULL;
//	    printf("iiiiiiiiiii\n");
	    anterior->Proximo_no_da_Lista = Novo_Jogador_Sorteado;
//	    printf("jjjjjjjjjjjj\n");
	}
	
	/*
	
	else{
		
		Ponteiro_Auxiliar = *Inicio_da_Lista;
		*Inicio_da_Lista = Novo_Jogador;
		Novo_Jogador->Proximo_no_da_Lista = Ponteiro_Auxiliar;
	}
	
	*/
	
	return 0;
}