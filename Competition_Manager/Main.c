#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define A 10

//******************************************************************************************************************************************************
// 														Declaracao gloal de uma estrutura
struct a{
    int cod;
    char cat[20];
    char nam[17];
};

int Le_Arquivo_TXT(FILE *fg, struct a *eq, float Matriz[][25]);
int ordenacao(int E,int P,int G, float Matriz[][25]);
int medias(float Matriz[][25]);
int Entrada_de_equipes(float m[][25], struct a *eq);
int troca(float Matriz[][25], int l);

//******************************************************************************************************************************************************
// 															funcao principal

int main(void){
    int E=0, P=0, G=0, i,l, m, n, NL=0, Escolha;
    char ch;
    float Matriz[10][25], o, p, q, r, s, t, u;
    struct a eq[A];
    FILE *fp;
    
    do{
    	system("cls");
    	printf("\t\t--- Insercao de equipes e madias ---\n\n");
		printf ("[1] - Entrada manual\n[2] - Entrada a partir de um arquivo de texto\n[3] - Sair\n\nDigite sua escolha: ");
		Escolha = -1;
		fflush(stdin);
		scanf("%d", &Escolha);
	}while(Escolha != 1 && Escolha != 2 && Escolha != 3);
	
	if(Escolha == 1)
		Entrada_de_equipes(Matriz, eq);
	if(Escolha == 3)
		exit(0);
	if(Escolha == 2)
	//**************************************************************************************************************************************************
	//									Le as informacoes das equipes (codigo, categoria e nome) e a matri de notas
    	Le_Arquivo_TXT(fp, eq, Matriz);
	//**************************************************************************************************************************************************
	//																calcula as medias
	medias(Matriz);
	//**************************************************************************************************************************************************
	//											Coloca o ponteiro com o nome das equipes na primeira coluna da matriz
    for(i=0;i<10;i++) Matriz[i][0] = i;
	//**************************************************************************************************************************************************
	//												Coloca o tipo de categoria das equipes na 7 coluna da matriz
    i = 0;
	while(i<10){
    	ch = eq[i].cat[0];
    	
    	if(ch == 'E'){
			E++; 
			Matriz[i][7] = 1;
		}
    	if(ch == 'P'){
			P++; 
			Matriz[i][7] = 2;
		}
    	if(ch == 'G'){
			G++; 
			Matriz[i][7] = 3;
		}
	    i++;
    }
	//**************************************************************************************************************************************************
	//																	Ordena por categoria

	ordenacao(E, P, G, Matriz);
	//**************************************************************************************************************************************************
	//														 Printa a matriz de ranking cat educacao
	system("cls");
	printf("\n\n\t\t----------| Resultado |----------\n\n\n");
	printf("RANKING\n");
	printf("Educacao  \t\t\t\tC1   C2   C3   C4   C5   M\n");
	for(l=0;l<E;l++){
		for(m=0;m<7;m++){
			if(m != 0){
				if(Matriz[l][m] < 10)
					printf("%1.1f  ", Matriz[l][m]);
				else
					printf("%2f  ", Matriz[l][m]);
			}
			else{
				n = (int) Matriz[l][m];
				printf("%s \t\t\t\t", &eq[n].nam);
    		}
		}
		printf("\n");
	}
	//**************************************************************************************************************************************************
	//																ranking projeto social
	
	printf("\n\nProjeto Social\n");
	for(l=E;l<E+P;l++){
		for(m=0;m<7;m++){
			if(m != 0){
				if(Matriz[l][m] < 10)
					printf("%1.1f  ", Matriz[l][m]);
				else
					printf("%2f  ", Matriz[l][m]);
			}
			else{
				n = (int) Matriz[l][m];
				printf("%s \t\t\t\t", &eq[n].nam);
    		}
		}
		printf("\n");
	}
	//**************************************************************************************************************************************************
	//                                                                  ranking gestï¿½o	
	
	printf("\n\n\nGestao\n");
	for(l=E+P;l<E+P+G;l++){
		for(m=0;m<7;m++){
			if(m != 0){
				if(Matriz[l][m] < 10)
					printf("%1.1f  ", Matriz[l][m]);
				else
					printf("%2f  ", Matriz[l][m]);
			}
			else{
				n = (int) Matriz[l][m];
				printf("%s \t\t\t\t", &eq[n].nam);
    		}
		}
		printf("\n");
	}
	//**************************************************************************************************************************************************
	//																Resultado final

	printf("\n\n\n\nRESULTADO FINAL\nEducacao: %s\nProjeto Social: %s\nGestao: %s\n\n\n", 
	eq[(int) Matriz[0][0]].nam, eq[(int) Matriz[E][0]].nam, eq[(int) Matriz[E+P][0]].nam);
	printf("Equipes desclassificadas: ");
	l=0;
	for(i=0;i<10;i++){
		if(Matriz[i][6] < 7){
			l++;
			if(l > 1)
				printf("                          ");
			printf("%s", eq[(int) Matriz[i][0]].nam);
		}
	}
	printf("\n\n\n\t\t");
	system("pause");
	//**********************************************************************************8***************************************************************
	//														Cria Arquivo txt para gravacao	
	char cna[34], extensao[4]={".txt"};
	do{
		system("cls");
		printf("\n\n\t\t----------| Criacao do arquivo com o resultado |----------\n");
		printf("\n\nDigite o nome do arquivo [Maximo 30 caracteres], caso ja exista um com mesmo nome, sera sobrescrito: ");
		fflush(stdin);
		gets(cna);
	}while(strlen(cna) > 30 || strlen(cna) == 0);
	strcat(cna,extensao);
	fp = fopen(("%s", cna), "w");
    if(fp==NULL){
		printf("\n\nERRO!! O arquivo nao pode ser criado\n\n");
		system("pause");
	}
	//**************************************************************************************************************************************************
	//														Escreve a matriz de ranking cat educacao
	fprintf(fp, "RANKING\n");
	fprintf(fp, "Educacao  \t\t\t\tC1   C2   C3   C4   C5   M\n");
	for(l=0;l<E;l++){
		for(m=0;m<7;m++){
			if(m != 0){
				if(Matriz[l][m] < 10)
					fprintf(fp, "%1.1f  ", Matriz[l][m]);
				else
					fprintf(fp, "%2f  ", Matriz[l][m]);
			}
			else{
				n = (int) Matriz[l][m];
				fprintf(fp, "%s \t\t\t\t", &eq[n].nam);
    		}
		}
		fprintf(fp, "\n");
	}
	//**************************************************************************************************************************************************
	//															Escreve o ranking projeto social
	
	fprintf(fp, "\n\nProjeto Social\n");
	for(l=E;l<E+P;l++){
		for(m=0;m<7;m++){
			if(m != 0){
				if(Matriz[l][m] < 10)
					fprintf(fp, "%1.1f  ", Matriz[l][m]);
				else
					fprintf(fp, "%2f  ", Matriz[l][m]);
			}
			else{
				n = (int) Matriz[l][m];
				fprintf(fp, "%s \t\t\t\t", &eq[n].nam);
    		}
		}
		fprintf(fp, "\n");
	}
	//**************************************************************************************************************************************************
	//                                                        Escreve o ranking gestao	
	
	fprintf(fp, "\n\n\nGestao\n");
	for(l=E+P;l<E+P+G;l++){
		for(m=0;m<7;m++){
			if(m != 0){
				if(Matriz[l][m] < 10)
					fprintf(fp, "%1.1f  ", Matriz[l][m]);
				else
					fprintf(fp, "%2f  ", Matriz[l][m]);
			}
			else{
				n = (int) Matriz[l][m];
				fprintf(fp, "%s \t\t\t\t", &eq[n].nam);
    		}
		}
		fprintf(fp, "\n");
	}
	//**************************************************************************************************************************************************
	//														Escreve o Resultado final

	fprintf(fp, "\n\n\n\nRESULTADO FINAL\nEducacao: %s\nProjeto Social: %s\nGestao: %s\n\n\n", 
	eq[(int) Matriz[0][0]].nam, eq[(int) Matriz[E][0]].nam, eq[(int) Matriz[E+P][0]].nam);
	fprintf(fp, "Equipes desclassificadas: ");
	l=0;
	for(i=0;i<10;i++){
		if(Matriz[i][6] < 7)	{
			l++;
			if(l > 1)
				fprintf(fp, "                          ");
			fprintf(fp, "%s", eq[(int) Matriz[i][0]].nam);
		}
	}
	system("cls");
	printf("\n\n\n\t\t---- Arqquivo gerado no diretorio do programa ----\n\n");
	fclose(fp);
	system("pause");
}


//----------------------------------------------------------------------------------------------------------------------------------------------------
//																		Funções
//----------------------------------------------------------------------------------------------------------------------------------------------------

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\\
//												Funcao de leitura de dados da equipe e da matrx de notas

Le_Arquivo_TXT(FILE *fg, struct a *z, float Matriz[][25]){
	int i;
	
	char ch;
	int NL=0, l, m;
	
	fg = fopen("Arquivo de entrada.txt", "rb");
	    if(fg==NULL){
			printf("ERRO!! O arquivo nao pode ser aberto");
			getchar();
		}
		
	for(i=0;i<A;i++){
        fscanf(fg, "%d", &z[i].cod);
		if(i==6){
			fseek(fg, 2*sizeof(char), SEEK_CUR);
			fread(z[i].cat, 15*sizeof(char), 1, fg);
		}
		else
			fscanf(fg, "%s", &z[i].cat);
		fscanf(fg, "%s", &z[i].nam);
    }
	
	rewind(fg);
	do{
		fread(&ch, sizeof(char), 1, fg);
		if(ch == '\n')
			NL++;
	}while(NL<36);
	for(l=0;l<10;l++){
		fseek(fg, 13*sizeof(char), SEEK_CUR);
		for(m=0;m<25;m++){
			fscanf(fg, "%f", &Matriz[l][m]);
		}
	}
	fclose(fg);
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\\
//													Funcao para registrar as equipes manualmente

Entrada_de_equipes(float m[][25], struct a *eq){
   
    int i,j, k, verificar;

    for(i=0;i<A;i++){
        do{
			do{
				system("cls");
				printf("\n\n\t\t\t----------| Cadastro das equipes |----------");
				printf("\n\n\n\tDigite o codigo do projeto [Numero maior que 0]\n\n%d%c equipe: ", i+1, 248);
		        eq[i].cod = -1;
				fflush(stdin);
		        scanf("%d", &eq[i].cod);
			}while(eq[i].cod <= 0);
			for(k=0, verificar=0;k<i;k++){
				if(eq[i].cod == eq[k].cod)
					verificar++;
			}
			if(verificar > 0)
				printf("\n\t\tCodigo ja em uso, digite outro\n\n");
			else
				verificar = -3434;
		}while(verificar != -3434);
		system("cls");
		printf("\n\n\t\t\t----------| Cadastro das equipes |----------");
        printf("\n\n\n\tDigite a categoria: \n\n%d%c equipe: ", 1+i, 248);
        fflush(stdin);
		scanf("%s", &eq[i].cat);
		system("cls");
		printf("\n\n\t\t\t----------| Cadastro das equipes |----------");
		printf("\n\n\n\tDigite o nome da equipe: \n\n%d%c equipe: ", 1+i, 248);
        fflush(stdin);
		scanf("%s", &eq[i].nam);
    }
    //____________________________________________________________________gravar notas_____________________________________________________________

	for(i=0;i<A;i++){
		for(j=0;j<25;j++){
			do{
				system("cls");
				printf("\n\n\nDigite a nota [de 0 a 10] %d da equipe %d: ", j+1,i+1);
				fflush(stdin);
				scanf("%d", &m[i][j]);
			}while(m[i][j] < 0 && m[i][j] > 10);
		}
	}
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// 															função de calculo das medias
 
medias(float Matriz[][25]){
	
	int l, m;
	//**************************************************************************************************************************************************
	//														Soma as notas da mesma categoria de cada euipe
	for(l=0;l<10;l++)
		for(m=0;m<5;m++) Matriz[l][m] = Matriz[l][m] + Matriz[l][m+5] + Matriz[l][m+10] + Matriz[l][m+15] + Matriz[l][m+20];
	//**************************************************************************************************************************************************
	//													 Calcula a media aritimetica
	for(l=0;l<10;l++)
		for(m=5;m>-1;m--) Matriz[l][m+1]= (Matriz[l][m] / 5);
	//**************************************************************************************************************************************************
	//										Coloca a media dasnotas de cada equipe na posiï¿½ï¿½o [x][6] da matriz
	for(l=0;l<10;l++){
		Matriz[l][6] = 0;
		Matriz[l][6] = Matriz[l][6] + ( Matriz[l][1] * 1);
		Matriz[l][6] = Matriz[l][6] + ( Matriz[l][2] * 1);
		Matriz[l][6] = Matriz[l][6] + ( Matriz[l][3] * 2);
		Matriz[l][6] = Matriz[l][6] + ( Matriz[l][4] * 3);
		Matriz[l][6] = Matriz[l][6] + ( Matriz[l][5] * 3);
		Matriz[l][6] = (Matriz[l][6] / (1+1+2+3+3));
	}
}
 
troca(float Matriz[][25], int l){
	
	float o;
	o = Matriz[l-1][7];
	Matriz[l-1][7] = Matriz[l][7];
	Matriz[l][7] = o;
	
	o = Matriz[l-1][6];
	Matriz[l-1][6] = Matriz[l][6];
	Matriz[l][6] = o;
	
	o = Matriz[l-1][5];
	Matriz[l-1][5] = Matriz[l][5];
	Matriz[l][5] = o;
	
	o = Matriz[l-1][4];
	Matriz[l-1][4] = Matriz[l][4];
	Matriz[l][4] = o;
	
	o = Matriz[l-1][3];
	Matriz[l-1][3] = Matriz[l][3];
	Matriz[l][3] = o;
	
	o = Matriz[l-1][2];
	Matriz[l-1][2] = Matriz[l][2];
	Matriz[l][2] = o;
	
	o = Matriz[l-1][1];
	Matriz[l-1][1] = Matriz[l][1];
	Matriz[l][1] = o;
	
	o = Matriz[l-1][0];
	Matriz[l-1][0] = Matriz[l][0];
	Matriz[l][0] = o;
}
 					
					
//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\\

//																Funcao de ordenação 
 
int ordenacao(int E,int P,int G, float Matriz[][25]){
	int i, l, x=0;
	float o, p, q;
	
	//**************************************************************************************************************************************************
	//													Separa as equipes em grupos de mesma categoria	
	
	for(i=1;i<10; ++i)
		for(l=9; l>=i; --l)
			if(Matriz[l-1][7] > Matriz[l][7])
				troca(Matriz, l);
	//**************************************************************************************************************************************************
	//												Ordena pela media cat 1 e desempata se forem iguais
    
	for(i=1;i<E; ++i)
		for(l=E-1; l>=i; --l)
			if(Matriz[l-1][6] < Matriz[l][6])
				troca(Matriz, l);
			if( Matriz[l-1][6] - Matriz[l][6] <= 0.05 && Matriz[l-1][4] < Matriz[l][4])
				troca(Matriz, l);
	//**************************************************************************************************************************************************
	//													       	Ordena pela media cstegoria 2
    
	for(i=1+E;i<P; ++i)
		for(l=P-1; l>=i; --l)
			if(Matriz[l-1][6] < Matriz[l][6])
				troca(Matriz, l);  
	//**************************************************************************************************************************************************
	//													Desempate se forem iguais	cetgoria 2
	
	for(i=1+E;i<P+E; ++i)
		for(l=P+E-1; l>=i; --l)
			if( Matriz[l-1][6] - Matriz[l][6] <= 0.05 && Matriz[l-1][4] < Matriz[l][4])
				troca(Matriz, l);   
	//**************************************************************************************************************************************************
	//											Ordena pela media  cat 3 e desempata se forem iguais
    
	for(i=1+E+P;i<G+P+E; ++i)
		for(l=G+P+E-1; l>=i; --l)
			if(Matriz[l-1][6] < Matriz[l][6])
				troca(Matriz, l);
			if( Matriz[l-1][6] - Matriz[l][6] <= 0.05 && Matriz[l-1][4] < Matriz[l][4])
				troca(Matriz, l);   
}
