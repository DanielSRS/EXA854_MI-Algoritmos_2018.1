/**********************************************************************************************************************************************
Autor: Daniel Santa Rosa Santos
Componente Curricular: Algoritmos I
Concluido em: 02/05/2018
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
*********************************************************************************************************************************************/

#include<stdio.h>

int main()
{
/********* VARIAVEIS PARA ARMAZENAR OS VOTOS NOS CANDIDATOS************************************************************************************************************************************************************************************************************************************************************/
    float MaeliGenteBoa = 0, AntonioDoBrasil = 0, LissandroProgresso = 0, MaiaDaAna = 0, Gentil = 0, DonaSelmaSilva = 0, GutembergSilva = 0, FernandoFernandes = 0, AnaVitoria = 0, PauloGuilherme = 0, AnaRitaPacheco = 0, AnaGuilherme = 0, AdalbertoCampos = 0;
/**********************************************************************************************************************************************************************************************************************************************************************

********** VARIAVEIS PARA ARMAZENAR OS PERCENTUAIS RELATIVOS À VOTAÇÂO ************************************************************************************************************************************************************************************************************************************************************/
	float VotosPresidentePercentual, VotosGovernadorPercentua, VotosSenadorPercentual, DeputadoEstadualPercentual, DeputadoFederalPercentual, MaeliGenteBoaPercentual, AntonioDoBrasilPercentual, LissandroProgressoPercentual, MaiaDaAnaPercentual, GentilPercentual;
    float DonaSelmaSilvaPercentual, GutembergSilvaPercentual, FernandoFernandesPercentual, AnaVitoriaPercentual, PauloGuilhermePercentual, AnaRitaPachecoPercentual, AnaGuilhermePercentual, AdalbertoCamposPercentual;
    float SexoMasculinoPercentual, PercentualVotoBranco, PercentualVotoNulo, SexoFemininoPercentual;
/*********************************************************************************************************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************************************************************************************************/
	float TotalDeVotosPresidente, TotalDeVotosGovernador, TotalDeVotosSenador, TotalDeVotosDeputadoEstadual, TotalDeVotosDeputadoFederal, TotalVotoNulo = 0, TotalVotoBranco = 0 , TotalSexoMasculino, TotalSexoFeminino, NumeroDoTitulo = 0, NumeroDeSaida;
	int Escolha, Menu = 0, InicioVotacao = 0, Votacao1, Votacao2, Votacao3, Votacao4, Votacao5, TotalDeVotosValidos, TotalAbsolutoDeVotos;
/*********************************************************************************************************************************************************************************************************************************************************************/

/*********************************************************************************************************************************************************************************************************************************************************************/
	do //Laço de repetição que mantem o rograma em loop até que seja encerrado manualmente. Seu ojetivo é permitir uma sequencia ciclica de valor nao ppredefinido
	{
/********* MENU INICIAL EM QUE SE APRESENTAM AS OPÇÕES DO PROGRAMA ************************************************************************************************************************************************************************************************************************************************************/
		do //Laço de repetição com o intuito de evitar erro ao escolher uma opção invalida
		{
			system("cls");
			Escolha = -41149511;
			printf("\n\tEscolha uma op%c%co: \n\n[1] - Para votar\n[2] - Para ver resultado\n[3] - Para encerrar\n\nDigite sua escolha: ", 135, 198);
			fflush(stdin); //Usado para evitar que o programa falhe ao ser digitado uma letra.
			scanf("%i", &Escolha);
		}while (Escolha != 1 && Escolha!= 2 && Escolha !=3); 
/*********************************************************************************************************************************************************************************************************************************************************************/

/********* Switch case implementado para a realizaão das votações ************************************************************************************************************************************************************************************************************************************************************/
		switch(Escolha)
		{
			case 1:
				do
				{
					system("cls");
					NumeroDoTitulo = -41149511;
					printf("\n\tDigite o n%cmero do seu t%ctulo de eleitor: ", 163, 161);
					fflush(stdin); //Usado para evitar que o programa falhe ao ser digitado uma letra.
                    scanf("%f", &NumeroDoTitulo);
				}while (NumeroDoTitulo<100000000000 || NumeroDoTitulo>=1000000000000);
				InicioVotacao++; // variael para indicar se ouve ou não alguma votação
				do
				{
					system("cls");
					Votacao1 = -41149511;
					printf("\n\tVota%c%co para presidente\n\n[17] - Sra. Maeli Gente Boa\n[22] - Sr. Antonio do Brasil\n[31] - Dr. Lissandro Progresso\n[01] - Branco\n\nPara votar, digite o n%cmero correspondente e confirme (enter): ", 135, 198, 163);
					fflush(stdin); //Usado para evitar que o programa falhe ao ser digitado uma letra.
					scanf("%i", &Votacao1);
				}while(Votacao1 <= -41149511);
				do
				{
					system("cls");
					Votacao2 = -41149511;
					printf("\n\tVota%c%co para governador\n\n[38] - Sr. Maia da Ana\n[40] - Sr. Gentil\n[18] - Sra. Dona Selma Silva\n[01] - Branco\n\nPara votar, digite o n%cmero correspondente e confirme (enter): ", 135, 198, 163);
					fflush(stdin); //Usado para evitar que o programa falhe ao ser digitado uma letra.
					scanf("%i", &Votacao2);
				}while(Votacao2 <= -41149511);
				do
				{
					system("cls");
					Votacao3 = -41149511;
					printf("\n\tVota%c%co para senador\n\n[04] - Sr. Gutemberg Silva\n[67] - Sr. Fernando Fernandes\n[01] - Branco\n\n\nPara votar, digite o n%cmero correspondente e confirme (enter): ", 135, 198, 163);
					fflush(stdin); //Usado para evitar que o programa falhe ao ser digitado uma letra.
					scanf("%i", &Votacao3);
				}while(Votacao3 <= -41149511);
				do
				{
					system("cls");
					Votacao4 = -41149511;
					printf("\n\tVota%c%co para deputado federal\n\n[56] - Sra. Ana Vitoria\n[33] - Sr. Paulo Guilherme\n[01] - Branco\n\n\nPara votar, digite o n%cmero correspondente e confirme (enter): ", 135, 198, 163);
					fflush(stdin); //Usado para evitar que o programa falhe ao ser digitado uma letra.
					scanf("%i", &Votacao4);
				}while(Votacao4 <= -41149511);
				do
				{
					system("cls");
					Votacao5 = -41149511;
					printf("\n\tVota%c%co para deputado estadual\n\n[51] - Dra. Ana Rita Pacheco\n[34] - Sra. Ana Guilherme\n[11] - Sr. Adalberto Campos\n[01] - Branco\n\nPara votar, digite o n%cmero correspondente e confirme (enter): ", 135, 198, 163);
					fflush(stdin); //Usado para evitar que o programa falhe ao ser digitado uma letra.
					scanf("%i", &Votacao5);
				}while(Votacao5 <= -41149511);
				system("cls");
/*********************************************************************************************************************************************************************************************************************************************************************/

/********** Espelho de votação ***********************************************************************************************************************************************************************************************************************************************************/
				switch (Votacao1)
				{
					case 01:
						TotalVotoBranco = TotalVotoBranco + 1;
						printf("\n\n\tPara Presidente, voc%c votou Branco.\n", 136);
						break;
					case 17:
						MaeliGenteBoa = MaeliGenteBoa + 1;
						printf("\n\n\tVoc%c votou na Sra. Maeli Gente Boa para presidente.\n", 136);
						break;
					case 22:
						AntonioDoBrasil = AntonioDoBrasil + 1;
						printf("\n\n\tVoc%c votou no Sr. Antonio do Brasil para presidente.\n", 136);
						break;
					case 31:
						LissandroProgresso = LissandroProgresso + 1;
						printf("\n\n\tVoc%c votou no Dr. Lissandro Progresso para presidente.\n", 136);
						break;
					default:
						TotalVotoNulo = TotalVotoNulo + 1;
						printf("\n\n\tPara Presidente, voc%c votou nulo.\n", 136);
						break;
				}
				switch (Votacao2)
				{
					case 01:
						TotalVotoBranco = TotalVotoBranco + 1;
						printf("\n\n\tPara governador, voc%c votou Branco.\n", 136);
						break;
					case 18:
						DonaSelmaSilva = DonaSelmaSilva + 1;
						printf("\n\n\tvoc%c votou na Sra. Dona Selma Silva para governador.\n", 136);
						break;
					case 38:
						MaiaDaAna = MaiaDaAna + 1;
						printf("\n\n\tvoc%c votou no Sr. Maia da Ana para governador.\n", 136);
						break;
					case 40:
						Gentil = Gentil + 1;
						printf("\n\n\tvoc%c votou no Sr. Gentil para governador.\n", 136);
						break;
					default:
						TotalVotoNulo = TotalVotoNulo + 1;
						printf("\n\n\tPara governador, voc%c votou nulo.\n", 136);
						break;
				}
				switch (Votacao3)
				{
					case 01:
						TotalVotoBranco = TotalVotoBranco + 1;
						printf("\n\n\tPara senador, voc%c votou Branco.\n", 136);
						break;
					case 04:
						GutembergSilva = GutembergSilva + 1;
						printf("\n\n\tvoc%c votou na Sr. Gutemberg Silva para senador.\n", 136);
						break;
					case 67:
						FernandoFernandes = FernandoFernandes + 1;
						printf("\n\n\tvoc%c votou no Sr. Fernando Fernandes para senador.\n", 136);
						break;
					default:
						TotalVotoNulo = TotalVotoNulo + 1;
						printf("\n\n\tPara senador, voc%c votou nulo.\n", 136);
						break;
				}
				switch (Votacao4)
				{
					case 01:
						TotalVotoBranco = TotalVotoBranco + 1;
						printf("\n\n\tPara deputado federal, voc%c votou Branco.\n", 136);
						break;
					case 33:
						PauloGuilherme = PauloGuilherme + 1;
						printf("\n\n\tvoc%c votou no Sr. Paulo Gulerme para deputado federal.\n", 136);
						break;
					case 56:
						AnaVitoria = AnaVitoria + 1;
						printf("\n\n\tvoc%c votou na Sra. Ana Vitoria para deputado federal.\n", 136);
						break;
					default:
						TotalVotoNulo = TotalVotoNulo + 1;
						printf("\n\n\tPara deputado federal, voc%c votou nulo.\n", 136);
						break;
				}
				switch (Votacao5)
				{
					case 01:
						TotalVotoBranco = TotalVotoBranco + 1;
						printf("\n\n\tPara deputado estadual, voc%c votou Branco.\n", 136);
						break;
					case 11:
						AdalbertoCampos = AdalbertoCampos + 1;
						printf("\n\n\tvoc%c votou no Sr. Adalberto Campos para deputado estadual.\n", 136);
						break;
					case 34:
						AnaGuilherme = AnaGuilherme + 1;
						printf("\n\n\tvoc%c votou na Sra. Ana Guilherme para deputado estadual.\n", 136);
						break;
					case 51:
						AnaRitaPacheco = AnaRitaPacheco + 1;
						printf("\n\n\tvoc%c votou na Dra. Ana Rita Pacheco para deputado estadual.\n", 136);
						break;
					default:
						TotalVotoNulo = TotalVotoNulo + 1;
						printf("\n\n\tPara deputado estadual, voc%c votou nulo.\n", 136);
						break;
				}
				printf("\n\nPressione qualquer tecla para continuar... ");
				getch();
				break;
/*********************************************************************************************************************************************************************************************************************************************************************/

/*********  ************************************************************************************************************************************************************************************************************************************************************/
			case 2:
				if(InicioVotacao == 0) //Condição para caso não tenha sido realizada nunhuma votação anteriormente. 
				{
					system("cls");
					printf("\n\n\n\n\tNenhuma vota%c%co foi feita. Vote antes de ver o resultado.\n\n\nPressione qualquer tecla para continuar... ", 135, 198);
					getch();
					break;
				}
/*********************************************************************************************************************************************************************************************************************************************************************/				
				
/********* SEÇÃO DE CALCULO DAS ENTRADAS DE VALORES ************************************************************************************************************************************************************************************************************************************************************/
				TotalDeVotosPresidente = MaeliGenteBoa + AntonioDoBrasil + LissandroProgresso;
				TotalDeVotosGovernador = MaiaDaAna + Gentil + DonaSelmaSilva;
				TotalDeVotosSenador = GutembergSilva + FernandoFernandes;
				TotalDeVotosDeputadoFederal = AnaVitoria + PauloGuilherme;
				TotalDeVotosDeputadoEstadual = AnaRitaPacheco + AnaGuilherme + AdalbertoCampos;
				TotalSexoFeminino = MaeliGenteBoa + DonaSelmaSilva + AnaVitoria + AnaRitaPacheco + AnaGuilherme;
				TotalSexoMasculino = AntonioDoBrasil + LissandroProgresso + MaiaDaAna + Gentil + GutembergSilva + FernandoFernandes + PauloGuilherme + AdalbertoCampos;
				TotalDeVotosValidos = TotalSexoFeminino + TotalSexoMasculino;
				TotalAbsolutoDeVotos = TotalDeVotosValidos + TotalVotoBranco + TotalVotoNulo;
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------********************************************************************************************************************************************************************************************************************************************************************/

/********* Condições para caso certos valores sejam 0 (zero), evitando assim erros ao realiar determinado masi é exatamnte ************************************************************************************************************************************************************************************************************************************************************/				
				if(TotalDeVotosPresidente == 0)
					TotalDeVotosPresidente = 1;
				if(TotalDeVotosGovernador == 0)
					TotalDeVotosGovernador = 1;
				if(TotalDeVotosSenador == 0)
					TotalDeVotosSenador = 1;
				if(TotalDeVotosDeputadoFederal == 0)
					TotalDeVotosDeputadoFederal = 1;
				if(TotalDeVotosDeputadoEstadual == 0)
					TotalDeVotosDeputadoEstadual = 1;
				if(TotalDeVotosValidos == 0)
				{
					TotalDeVotosValidos = 1;
					SexoFemininoPercentual = (TotalSexoFeminino * 100) / TotalDeVotosValidos;
					SexoMasculinoPercentual = (TotalSexoMasculino * 100) / TotalDeVotosValidos;
				}
				else
				{
					SexoFemininoPercentual = (TotalSexoFeminino * 100) / TotalDeVotosValidos;
					SexoMasculinoPercentual = (TotalSexoMasculino * 100) / TotalDeVotosValidos;
				}
				MaeliGenteBoaPercentual = (MaeliGenteBoa * 100) / TotalDeVotosPresidente;
				AntonioDoBrasilPercentual = (AntonioDoBrasil * 100) / TotalDeVotosPresidente;
				LissandroProgressoPercentual = (LissandroProgresso * 100) / TotalDeVotosPresidente;
				MaiaDaAnaPercentual = (MaiaDaAna * 100) / TotalDeVotosGovernador;
				GentilPercentual = (Gentil * 100) / TotalDeVotosGovernador;
				DonaSelmaSilvaPercentual = (DonaSelmaSilva * 100) / TotalDeVotosGovernador;
				GutembergSilvaPercentual = (GutembergSilva * 100) / TotalDeVotosSenador;
				FernandoFernandesPercentual = (FernandoFernandes * 100) / TotalDeVotosSenador;
				AnaVitoriaPercentual = (AnaVitoria * 100) / TotalDeVotosDeputadoFederal;
				PauloGuilhermePercentual = (PauloGuilherme * 100) / TotalDeVotosDeputadoFederal;
				AnaRitaPachecoPercentual = (AnaRitaPacheco * 100) / TotalDeVotosDeputadoEstadual;
				AnaGuilhermePercentual = (AnaGuilherme * 100) / TotalDeVotosDeputadoEstadual;
				AdalbertoCamposPercentual = (AdalbertoCampos * 100) / TotalDeVotosDeputadoEstadual;
				PercentualVotoBranco = (TotalVotoBranco * 100) / TotalAbsolutoDeVotos;
				PercentualVotoNulo = (TotalVotoNulo * 100) / TotalAbsolutoDeVotos;
/*********************************************************************************************************************************************************************************************************************************************************************/

/********* Secção de apresentação de resultados ************************************************************************************************************************************************************************************************************************************************************/
				system("cls");
				printf("\n\t\tVotos para presidente\n\nSra. Maeli Gente Boa:\n\t%.0f votos validos\n\t%.2f%%%% dos votos validos", MaeliGenteBoa, MaeliGenteBoaPercentual);
				printf("\n\nSr. Antonio do Brasil:\n\t%.0f votos validos\n\t%.2f%% dos votos validos", AntonioDoBrasil, AntonioDoBrasilPercentual);
				printf("\n\nDr. Lissandro Progresso:\n\t%.0f votos validos\n\t%.2f%% dos votos validos", LissandroProgresso, LissandroProgressoPercentual);
				if (LissandroProgressoPercentual <= 50 && AntonioDoBrasilPercentual <= 50 && MaeliGenteBoaPercentual <= 50)
					printf("\n\n\tHavera segundo turno.\n");
				printf("\n\n\t\tVotos para governador\n\nSr. Maia da Ana:\n\t%.0f votos validos\n\t%.2f%% dos votos", MaiaDaAna, MaiaDaAnaPercentual);
				printf("\n\nSr. Gentil:\n\t%.0f votos validos\n\t%.2f%% dos votos", Gentil, GentilPercentual);
				printf("\n\nSra. Dona Selma Silva:\n\t%.0f votos validos\n\t%.2f dos votos", DonaSelmaSilva, DonaSelmaSilvaPercentual);
				printf("\n\n\t\tVotos para senador\n\nSr. Gutemberg Silva:\n\t%.0f votos validos\n\t%.2f%% dos votos validos", GutembergSilva, GutembergSilvaPercentual);
				printf("\n\nSr. Fernando Fernandes:\n\t%.0f votos validos\n\t%.2f%% dos votos validos", FernandoFernandes, FernandoFernandesPercentual);
				printf("\n\n\t\tVotos para deputado federal\n\nSra. Ana Vitoria:\n\t%.0f votos validos\n\t%.2f%% dos votos validos", AnaVitoria, AnaVitoriaPercentual);
				printf("\n\nSr. Paulo Guilherme:\n\t%.0f votos validos\n\t%.2f%% dos votos validos", PauloGuilherme, PauloGuilhermePercentual);
				printf("\n\n\t\tVotos para deutado estadual\n\nDra. Ana Rita Pacheco:\n\t%.0f votos validos\n\t%.2f%% dos votos validos", AnaRitaPacheco, AnaRitaPachecoPercentual);
				printf("\n\nSra. Ana Guilerme:\n\t%.0f votos validos\n\t%.2f%% dos votos validos", AnaGuilherme, AnaGuilhermePercentual);
				printf("\n\nSr. Adalberto Campos:\n\t%.0f votos validos\n\t%.2f%% dos votos validos", AdalbertoCampos, AdalbertoCamposPercentual); 
				printf("\n\n\t\tVotos em candidatos por sexo\n\nCandidatos do sexo feminino:\n\t%.0f votos validos\n\t%.2f%% dos votos validos", TotalSexoFeminino, SexoFemininoPercentual);
				printf("\n\nCandidatos do sexo masculino:\n\t%.0f votos validos\n\t%.2f%% dos votos validos", TotalSexoMasculino, SexoMasculinoPercentual);
				printf("\n\n\t\tVotos brancos e nulos\n\nVotos brancos:\n\t%.0f votos\n\t%.2f%% dos votos totais", TotalVotoBranco, PercentualVotoBranco);
				printf("\n\nVotos nulos:\n\t%.0f votos\n\t%.2f%% dos votos totais\n\nPressione qualquer tecla para continuar: ", TotalVotoNulo, PercentualVotoNulo);
				getch();
				break;
/*********************************************************************************************************************************************************************************************************************************************************************/

/********* OPÇÃO PARA TERMINAR A EXECUÇÃO DO CÓDIGO ************************************************************************************************************************************************************************************************************************************************************/
			case 3:
				do //do while a fim de evitar erro de digitação do codigo.
				{
					system("cls");
					NumeroDeSaida = -41149511;
					printf("\n\n\tDigite o codigo para sair, ou 0 para cancelar\n\n---->");
					fflush(stdin); //Usado para evitar que o programa falhe ao ser digitado uma letra.
					scanf("%f", &NumeroDeSaida);
				}while (NumeroDeSaida != 41149511 && NumeroDeSaida != 0);
				if(NumeroDeSaida == 41149511)
				{
					printf("\n\nvoc%c escolheu sair", 136);
					Menu = 1; // Torna falso a condiao de reexecução do codigo, encerrado o programa
				}
				else
				{
					printf("\n\nCancelar");
					break;
				}
/*********************************************************************************************************************************************************************************************************************************************************************/

		}
	}while(Menu != 1); //Condição de parada do programa. Se diferente disso a execução continua.
}
