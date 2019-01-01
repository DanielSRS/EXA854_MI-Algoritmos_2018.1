#include<stdio.h>
#include<math.h>
#include<string.h>
#define A 10

int main(void)
{
    int E=0, P=0, G=0, i,l, m, n, NL=0;
    char ch;
    float Matriz[10][25], o, p, q, r, s, t, u;
    struct a
    {
        int cod;
        char cat[20];
        char nam[17];
    } eq[A];
    FILE *fp;
//************************************************************************************************************************************************************
//																		Abre o arquivo de texto.
    fp = fopen("Arquivo de entrada.txt", "rb");
    if(fp==NULL)
	{
		printf("ERRO!! O arquivo nao pode ser aberto");
		getchar();
	}
//************************************************************************************************************************************************************
//														L� as informaões das equipes (codigo, categoria e nome)
    for(i=0;i<A;i++)
    {
        fscanf(fp, "%d", &eq[i].cod);
		if(i==6)
		{
			fseek(fp, 2*sizeof(char), SEEK_CUR);
			fread(eq[i].cat, 15*sizeof(char), 1, fp);
		}
		else
		{
			fscanf(fp, "%s", &eq[i].cat);
		}
		fscanf(fp, "%s", &eq[i].nam);
    }
//************************************************************************************************************************************************************
// 																		L� a matriz de notas
    rewind(fp);
    do 
	{
		fread(&ch, sizeof(char), 1, fp);
		if(ch == '\n')
			NL++;
	}while(NL<36);
	for(l=0;l<10;l++)
	{
		fseek(fp, 13*sizeof(char), SEEK_CUR);
		for(m=0;m<25;m++)
		{
			fscanf(fp, "%f", &Matriz[l][m]);
		}
	}
	fclose(fp);
//************************************************************************************************************************************************************
//                                               Imprime o Codigo, categoria e o nome da equipe
	for(i=0;i<A;i++)
    {
        printf("%d\n", eq[i].cod);
        printf("%s\n", eq[i].cat);
        printf("%s\n", eq[i].nam);
    }
//************************************************************************************************************************************************************
//												Imprime os jurados e as categorias acima da matriz [J1...C1...]
	printf("\n\n\n\n");
	
	printf("             ");
	for(i=1;i<6;i++)
	{
		for(l=0;l<5;l++)
		{
			printf("J%d  ", i);
		}
	}
	printf("\n");
	printf("             ");
	for(i=1;i<6;i++)
	{
		for(l=0;l<5;l++)
		{
			printf("C%d  ", i);
		}
	}
//************************************************************************************************************************************************************
//																	Imprime a matriz de notas
	printf("\n");
	for(l=0;l<10;l++)
	{
		if(l == 9)
			printf("%s  ", eq[l].nam);
		else
			printf("%s   ", eq[l].nam);
		printf("%c  ", eq[l].cat[0]);
		for(m=0;m<25;m++)
		{
			printf("%2.0f  ", Matriz[l][m]);
		}
		printf("\n");
	}
//************************************************************************************************************************************************************
//												//Soma as notas da mesma categoria
	for(l=0;l<10;l++)
	{
		for(m=0;m<5;m++)
		{
			Matriz[l][m] = Matriz[l][m] + Matriz[l][m+5] + Matriz[l][m+10] + Matriz[l][m+15] + Matriz[l][m+20];
		}
	}
//************************************************************************************************************************************************************
														// Calcula a media aritimetica
	for(l=0;l<10;l++)
	{
		for(m=5;m>-1;m--)
		{
			Matriz[l][m+1]= (Matriz[l][m] / 5);
		}
	}
//************************************************************************************************************************************************************
											//Coloca a media dasnotas de cada equipe na posi��o [x][6] da matriz
	for(l=0;l<10;l++)
	{
		Matriz[l][6] = 0;
		Matriz[l][6] = Matriz[l][6] + ( Matriz[l][1] * 1);
		Matriz[l][6] = Matriz[l][6] + ( Matriz[l][2] * 1);
		Matriz[l][6] = Matriz[l][6] + ( Matriz[l][3] * 2);
		Matriz[l][6] = Matriz[l][6] + ( Matriz[l][4] * 3);
		Matriz[l][6] = Matriz[l][6] + ( Matriz[l][5] * 3);
		Matriz[l][6] = (Matriz[l][6] / (1+1+2+3+3));
	}
//************************************************************************************************************************************************************
//											Coloca o ponteiro com o nome das equipes na primeira coluna da matriz
    for(i=0;i<10;i++)
    {
    	Matriz[i][0] = i;
    }
//************************************************************************************************************************************************************
//										Coloca o tipo de categoria das equipes na 7 coluna da matriz
    i = 0;
	while(i<10)
    {
    	ch = eq[i].cat[0];
    	printf("%c  ", ch);
    	
    	if(ch == 'E')
		{
			E++; 
			Matriz[i][7] = 1; 
			printf("%1.0f  ", Matriz[i][7]);
		}
    	if(ch == 'P')
    	{
			P++; 
			Matriz[i][7] = 2;
			printf("%1.0f  ", Matriz[i][7]);
		}
    	if(ch == 'G')
    	{
			G++; 
			Matriz[i][7] = 3;
			printf("%1.0f  ", Matriz[i][7]);
		}
	    i++;
    }
//************************************************************************************************************************************************************
//																	Ordena por categoria

	for(i=1;i<10; ++i)
	{
		for(l=9; l>=i; --l)
		{
			if(Matriz[l-1][7] > Matriz[l][7])
			{
				
				//printf("\n\n\n\n");
				
				o = Matriz[l-1][7];
				Matriz[l-1][7] = Matriz[l][7];
				Matriz[l][7] = o;
				//printf("%f   ", o);
				
				o = Matriz[l-1][6];
				Matriz[l-1][6] = Matriz[l][6];
				Matriz[l][6] = o;
				//printf("%f   ", o);
				
				o = Matriz[l-1][5];
				Matriz[l-1][5] = Matriz[l][5];
				Matriz[l][5] = o;
			//	printf("%f  ", o);
				
				o = Matriz[l-1][4];
				Matriz[l-1][4] = Matriz[l][4];
				Matriz[l][4] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][3];
				Matriz[l-1][3] = Matriz[l][3];
				Matriz[l][3] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][2];
				Matriz[l-1][2] = Matriz[l][2];
				Matriz[l][2] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][1];
				Matriz[l-1][1] = Matriz[l][1];
				Matriz[l][1] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][0];
				Matriz[l-1][0] = Matriz[l][0];
				Matriz[l][0] = o;
			//	printf("%f   ", o);
			}
		}
	}   
    
//************************************************************************************************************************************************************
//																	Ordena pela media cat 1
    
	for(i=1;i<E; ++i)
	{
		for(l=E-1; l>=i; --l)
		{
			if(Matriz[l-1][6] < Matriz[l][6])
			{
				printf("OOHHHHHHHHH");
				//printf("\n\n\n\n");
				
				o = Matriz[l-1][7];
				Matriz[l-1][7] = Matriz[l][7];
				Matriz[l][7] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][6];
				Matriz[l-1][6] = Matriz[l][6];
				Matriz[l][6] = o;
			///	printf("%f   ", o);
				
				o = Matriz[l-1][5];
				Matriz[l-1][5] = Matriz[l][5];
				Matriz[l][5] = o;
			//	printf("%f  ", o);
				
				o = Matriz[l-1][4];
				Matriz[l-1][4] = Matriz[l][4];
				Matriz[l][4] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][3];
				Matriz[l-1][3] = Matriz[l][3];
				Matriz[l][3] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][2];
				Matriz[l-1][2] = Matriz[l][2];
				Matriz[l][2] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][1];
				Matriz[l-1][1] = Matriz[l][1];
				Matriz[l][1] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][0];
				Matriz[l-1][0] = Matriz[l][0];
				Matriz[l][0] = o;
			//	printf("%f   ", o);
			}
		}
	}   
//************************************************************************************************************************************************************
//													Desempate se forem iguais	 cat 1
	
	for(i=1;i<E; ++i)
	{
		for(l=E-1; l>=i; --l)
		{
			p = Matriz[l-1][6];
			q = Matriz[l][6];
			
			if( p - q <= 0.05 && Matriz[l-1][4] < Matriz[l][4])
			{
				printf("AAAHHHHHHHHH\n\n");
				//printf("\n\n\n\n");
				printf("p = %f\n", p);
				printf("q = %f\n", p);
				printf("i = %d\n", i);
				printf("l = %d\n", l);
				printf("%s\n  ",  &eq[(int) Matriz[l-1][0]].nam );
				printf("%s\n  ",  &eq[(int) Matriz[l][0]].nam );
				
				o = Matriz[l-1][7];
				Matriz[l-1][7] = Matriz[l][7];
				Matriz[l][7] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][6];
				Matriz[l-1][6] = Matriz[l][6];
				Matriz[l][6] = o;
			///	printf("%f   ", o);
				
				o = Matriz[l-1][5];
				Matriz[l-1][5] = Matriz[l][5];
				Matriz[l][5] = o;
			//	printf("%f  ", o);
				
				o = Matriz[l-1][4];
				Matriz[l-1][4] = Matriz[l][4];
				Matriz[l][4] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][3];
				Matriz[l-1][3] = Matriz[l][3];
				Matriz[l][3] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][2];
				Matriz[l-1][2] = Matriz[l][2];
				Matriz[l][2] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][1];
				Matriz[l-1][1] = Matriz[l][1];
				Matriz[l][1] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][0];
				Matriz[l-1][0] = Matriz[l][0];
				Matriz[l][0] = o;
			//	printf("%f   ", o);
			}
		}
	}   
	
	

    
//************************************************************************************************************************************************************
//													        	Ordena pela media cstegoria 2
    
	for(i=1+E;i<P; ++i)
	{
		for(l=P-1; l>=i; --l)
		{
			if(Matriz[l-1][6] < Matriz[l][6])
			{
				printf("OOHHHHHHHHH");
				//printf("\n\n\n\n");
				
				o = Matriz[l-1][7];
				Matriz[l-1][7] = Matriz[l][7];
				Matriz[l][7] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][6];
				Matriz[l-1][6] = Matriz[l][6];
				Matriz[l][6] = o;
			///	printf("%f   ", o);
				
				o = Matriz[l-1][5];
				Matriz[l-1][5] = Matriz[l][5];
				Matriz[l][5] = o;
			//	printf("%f  ", o);
				
				o = Matriz[l-1][4];
				Matriz[l-1][4] = Matriz[l][4];
				Matriz[l][4] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][3];
				Matriz[l-1][3] = Matriz[l][3];
				Matriz[l][3] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][2];
				Matriz[l-1][2] = Matriz[l][2];
				Matriz[l][2] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][1];
				Matriz[l-1][1] = Matriz[l][1];
				Matriz[l][1] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][0];
				Matriz[l-1][0] = Matriz[l][0];
				Matriz[l][0] = o;
			//	printf("%f   ", o);
			}
		}
	}   
//************************************************************************************************************************************************************
//														Desempate se forem iguais	cetgoria 2
	
	for(i=1+E;i<P+E; ++i)
	{
		for(l=P+E-1; l>=i; --l)
		{
			p = Matriz[l-1][6];
			q = Matriz[l][6];
			
			if( p - q <= 0.05 && Matriz[l-1][4] < Matriz[l][4])
			{
				printf("AAAHHHHHHHHH\n\n");
				//printf("\n\n\n\n");
				printf("p = %f\n", p);
				printf("q = %f\n", p);
				printf("i = %d\n", i);
				printf("l = %d\n", l);
				printf("%s\n  ",  &eq[(int) Matriz[l-1][0]].nam );
				printf("%s\n  ",  &eq[(int) Matriz[l][0]].nam );
				
				o = Matriz[l-1][7];
				Matriz[l-1][7] = Matriz[l][7];
				Matriz[l][7] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][6];
				Matriz[l-1][6] = Matriz[l][6];
				Matriz[l][6] = o;
			///	printf("%f   ", o);
				
				o = Matriz[l-1][5];
				Matriz[l-1][5] = Matriz[l][5];
				Matriz[l][5] = o;
			//	printf("%f  ", o);
				
				o = Matriz[l-1][4];
				Matriz[l-1][4] = Matriz[l][4];
				Matriz[l][4] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][3];
				Matriz[l-1][3] = Matriz[l][3];
				Matriz[l][3] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][2];
				Matriz[l-1][2] = Matriz[l][2];
				Matriz[l][2] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][1];
				Matriz[l-1][1] = Matriz[l][1];
				Matriz[l][1] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][0];
				Matriz[l-1][0] = Matriz[l][0];
				Matriz[l][0] = o;
			//	printf("%f   ", o);
			}
		}
	}   
	
	

    
//************************************************************************************************************************************************************
//															Ordena pela media  cat 3
    
	for(i=1+E+P;i<G+P+E; ++i)
	{
		for(l=G+P+E-1; l>=i; --l)
		{
			if(Matriz[l-1][6] < Matriz[l][6])
			{
				printf("OOHHHHHHHHH");
				//printf("\n\n\n\n");
				
				o = Matriz[l-1][7];
				Matriz[l-1][7] = Matriz[l][7];
				Matriz[l][7] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][6];
				Matriz[l-1][6] = Matriz[l][6];
				Matriz[l][6] = o;
			///	printf("%f   ", o);
				
				o = Matriz[l-1][5];
				Matriz[l-1][5] = Matriz[l][5];
				Matriz[l][5] = o;
			//	printf("%f  ", o);
				
				o = Matriz[l-1][4];
				Matriz[l-1][4] = Matriz[l][4];
				Matriz[l][4] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][3];
				Matriz[l-1][3] = Matriz[l][3];
				Matriz[l][3] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][2];
				Matriz[l-1][2] = Matriz[l][2];
				Matriz[l][2] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][1];
				Matriz[l-1][1] = Matriz[l][1];
				Matriz[l][1] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][0];
				Matriz[l-1][0] = Matriz[l][0];
				Matriz[l][0] = o;
			//	printf("%f   ", o);
			}
		}
	}   
//************************************************************************************************************************************************************
//															Desempate se forem iguais	cat3
	
	for(i=1+E+P;i<G+P+E; ++i)
	{
		for(l=G+P+E-1; l>=i; --l)
		{
			p = Matriz[l-1][6];
			q = Matriz[l][6];
			
			if( p - q <= 0.05 && Matriz[l-1][4] < Matriz[l][4])
			{
				printf("AAAHHHHHHHHH\n\n");
				//printf("\n\n\n\n");
				printf("p = %f\n", p);
				printf("q = %f\n", p);
				printf("i = %d\n", i);
				printf("l = %d\n", l);
				printf("%s\n  ",  &eq[(int) Matriz[l-1][0]].nam );
				printf("%s\n  ",  &eq[(int) Matriz[l][0]].nam );
				
				o = Matriz[l-1][7];
				Matriz[l-1][7] = Matriz[l][7];
				Matriz[l][7] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][6];
				Matriz[l-1][6] = Matriz[l][6];
				Matriz[l][6] = o;
			///	printf("%f   ", o);
				
				o = Matriz[l-1][5];
				Matriz[l-1][5] = Matriz[l][5];
				Matriz[l][5] = o;
			//	printf("%f  ", o);
				
				o = Matriz[l-1][4];
				Matriz[l-1][4] = Matriz[l][4];
				Matriz[l][4] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][3];
				Matriz[l-1][3] = Matriz[l][3];
				Matriz[l][3] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][2];
				Matriz[l-1][2] = Matriz[l][2];
				Matriz[l][2] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][1];
				Matriz[l-1][1] = Matriz[l][1];
				Matriz[l][1] = o;
			//	printf("%f   ", o);
				
				o = Matriz[l-1][0];
				Matriz[l-1][0] = Matriz[l][0];
				Matriz[l][0] = o;
			//	printf("%f   ", o);
			}
		}
	}   
	
	

    
         
//************************************************************************************************************************************************************
//																	Printa espao vazio
	printf("\n\n\n\n\n\n");

//************************************************************************************************************************************************************
//																 Printa a matriz de ranking cat educacao
	printf("RANKING\n");
	printf("Educacao  \t\t\t\tC1   C2   C3   C4   C5   M\n");
	for(l=0;l<E;l++)
	{
		getch();
		for(m=0;m<7;m++)
		{
			if(m != 0)
			{
				if(Matriz[l][m] < 10)
					printf("%1.1f  ", Matriz[l][m]);
				else
					printf("%2f  ", Matriz[l][m]);
			}
			else
    		{
				n = (int) Matriz[l][m];
				printf("%s \t\t\t\t", &eq[n].nam);
    		}
		}
		printf("\n");
	}
//************************************************************************************************************************************************************
//																ranking projeto social
	
	printf("\n\nProjeto Social\n");
	for(l=E;l<E+P;l++)
	{
		getch();
		for(m=0;m<7;m++)
		{
			if(m != 0)
			{
				if(Matriz[l][m] < 10)
					printf("%1.1f  ", Matriz[l][m]);
				else
					printf("%2f  ", Matriz[l][m]);
			}
			else
    		{
				n = (int) Matriz[l][m];
				printf("%s \t\t\t\t", &eq[n].nam);
    		}
		}
		printf("\n");
	}
//************************************************************************************************************************************************************
//                                                                  ranking gest�o	
	
	printf("\n\n\nGestao\n");
	for(l=E+P;l<E+P+G;l++)
	{
		getch();
		for(m=0;m<7;m++)
		{
			if(m != 0)
			{
				if(Matriz[l][m] < 10)
					printf("%1.1f  ", Matriz[l][m]);
				else
					printf("%2f  ", Matriz[l][m]);
			}
			else
    		{
				n = (int) Matriz[l][m];
				printf("%s \t\t\t\t", &eq[n].nam);
    		}
		}
		printf("\n");
	}
//************************************************************************************************************************************************************
//																Resultado final

	printf("\n\n\n\nRESULTADO FINAL\nEducacao: %s\nProjeto Social: %s\nGestao: %s\n\n\n", eq[(int) Matriz[0][0]].nam, eq[(int) Matriz[E][0]].nam, eq[(int) Matriz[E+P][0]].nam);
	printf("Equipes desclassificadas: ");
	l=0;
	for(i=0;i<10;i++)
	{
		if(Matriz[i][6] < 7)
		{
			l++;
			if(l > 1)
				printf("                          ");
			printf("%s", eq[(int) Matriz[i][0]].nam);
		}
	}
//************************************************************************************************************************************************************
//																Cria Arquivo txt para gravacao	
	char cna[34], extensao[4]={".txt"};
	do
	{
		printf("digite o nome do arquivo (MAX 30 caracteres): ");
		gets(cna);
	}while(strlen(cna) > 30);
	strcat(cna,extensao);
	fp = fopen(("%s", cna), "w");
    if(fp==NULL)
	{
		printf("\n\nERRO!! O arquivo nao pode ser criado");
		getchar();
	}
//************************************************************************************************************************************************************
//														 Escreve a matriz de ranking cat educacao
	fprintf(fp, "RANKING\n");
	fprintf(fp, "Educacao  \t\t\t\tC1   C2   C3   C4   C5   M\n");
	for(l=0;l<E;l++)
	{
		for(m=0;m<7;m++)
		{
			if(m != 0)
			{
				if(Matriz[l][m] < 10)
					fprintf(fp, "%1.1f  ", Matriz[l][m]);
				else
					fprintf(fp, "%2f  ", Matriz[l][m]);
			}
			else
    		{
				n = (int) Matriz[l][m];
				fprintf(fp, "%s \t\t\t\t", &eq[n].nam);
    		}
		}
		fprintf(fp, "\n");
	}
//************************************************************************************************************************************************************
//														Escreve o ranking projeto social
	
	fprintf(fp, "\n\nProjeto Social\n");
	for(l=E;l<E+P;l++)
	{
		for(m=0;m<7;m++)
		{
			if(m != 0)
			{
				if(Matriz[l][m] < 10)
					fprintf(fp, "%1.1f  ", Matriz[l][m]);
				else
					fprintf(fp, "%2f  ", Matriz[l][m]);
			}
			else
    		{
				n = (int) Matriz[l][m];
				fprintf(fp, "%s \t\t\t\t", &eq[n].nam);
    		}
		}
		fprintf(fp, "\n");
	}
//************************************************************************************************************************************************************
//                                                                  Escreve o ranking gest�o	
	
	fprintf(fp, "\n\n\nGestao\n");
	for(l=E+P;l<E+P+G;l++)
	{
		for(m=0;m<7;m++)
		{
			if(m != 0)
			{
				if(Matriz[l][m] < 10)
					fprintf(fp, "%1.1f  ", Matriz[l][m]);
				else
					fprintf(fp, "%2f  ", Matriz[l][m]);
			}
			else
    		{
				n = (int) Matriz[l][m];
				fprintf(fp, "%s \t\t\t\t", &eq[n].nam);
    		}
		}
		fprintf(fp, "\n");
	}
//************************************************************************************************************************************************************
//																	Escreve o Resultado final

	fprintf(fp, "\n\n\n\nRESULTADO FINAL\nEducacao: %s\nProjeto Social: %s\nGestao: %s\n\n\n", eq[(int) Matriz[0][0]].nam, eq[(int) Matriz[E][0]].nam, eq[(int) Matriz[E+P][0]].nam);
	fprintf(fp, "Equipes desclassificadas: ");
	l=0;
	for(i=0;i<10;i++)
	{
		if(Matriz[i][6] < 7)
		{
			l++;
			if(l > 1)
				fprintf(fp, "                          ");
			fprintf(fp, "%s", eq[(int) Matriz[i][0]].nam);
		}
	}
/************************************************************************************************************************************************************
//                                               escreve o Codigo, categoria e o nome da equipe
	for(i=0;i<A;i++)
    {
        fprintf(fp, "%d\n", eq[i].cod);
        fprintf(fp, "%s\n", eq[i].cat);
        fprintf(fp, "%s\n", eq[i].nam);
    }
//************************************************************************************************************************************************************
//												escreve os jurados e as categorias acima da matriz [J1...C1...]
	fprintf(fp, "%s", "\n\n\n\n");
	
	fprintf(fp, "%s", "             ");
	for(i=1;i<6;i++)
	{
		for(l=0;l<5;l++)
		{
			fprintf(fp, "%c%d  ", 'J', i);
		}
	}
	fprintf(fp, "%c", '\n');
	fprintf(fp, "%s", "             ");
	for(i=1;i<6;i++)
	{
		for(l=0;l<5;l++)
		{
			fprintf(fp, "C%d  ", i);
		}
	}
//************************************************************************************************************************************************************
//																	escreve a matriz de notas
	fprintf(fp, "%c", '\n');
	for(l=0;l<10;l++)
	{
		if(l == 9)
			fprintf(fp, "%s  ", eq[l].nam);
		else
			fprintf(fp, "%s   ", eq[l].nam);
		fprintf(fp, "%c  ", eq[l].cat[0]);
		for(m=0;m<25;m++)
		{
			fprintf(fp, "%2.0f  ", Matriz[l][m]);
		}
		fprintf(fp, "%c", '\n');
	}
*/
	fclose(fp);
	getch();
}
