#include<stdio.h>
#include<stdlib.h>

struct jogada{
	int linha;
	int coluna;
};

iniciaTabuleiro(char tabuleiro[8][8])
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			tabuleiro[i][j]='0';
		}	
	}	
	tabuleiro[3][3]='B';
	tabuleiro[3][4]='W';
	tabuleiro[4][3]='W';
	tabuleiro[4][4]='B';
}
DesenhaTabuleiro(char tabuleiro[8][8])
{
	for(int i=0;i<8;i++)
	{
		printf("%d ",i+1);
	}
	printf("\n");
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			printf("%c ",tabuleiro[i][j]);
		}	
		printf("%d\n",i+1);
	}
	printf("--------------------------\n");
}
jogada EscolhaJogada(jogada jog)
{
	printf("Escolha as coordenadas!\n");
	printf("Linha: ");
	scanf("%d",&jog.linha);
	printf("Coluna: ");
	scanf("%d",&jog.coluna);
	
	return jog;
}
int ExecutaJogada(char tab[8][8],int player,jogada mov)
{
	int aux=0;
	int o;
	switch(player)
	{
		case -1://PRETO
		{
			if(tab[mov.linha-1][mov.coluna-1]=='0')
			{
				if(tab[mov.linha-1][mov.coluna-1-1]=='W')//horizontal esquerda
				{
					for(int i=mov.coluna-1;i>=0;i--)
					{
						if(tab[mov.linha-1][i-1]=='B')
						{
							aux=1;	
							tab[mov.linha-1][mov.coluna-1]='B';	
							for(int j=mov.coluna-1;j>=0;j--)
							{
								if(tab[mov.linha-1][j-1]=='W')
								{
									tab[mov.linha-1][j-1]='B';
								}
								else
								{
									break;
								}
							}
							break;
						}	
						else
						{
							if(tab[mov.linha-1][i-1]=='0')
							{
								break;
							}
						}
						
					}		
				}
				if(tab[mov.linha-1][mov.coluna-1+1]=='W')//horizontal direita
				{
					for(int i=mov.coluna-1;i<8;i++)
					{
						if(tab[mov.linha-1][i+1]=='B')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='B';
							for(int j=mov.coluna-1;j<8;j++)
							{
								if(tab[mov.linha-1][j+1]=='W')
								{
									tab[mov.linha-1][j+1]='B';
								}
								else
								{
									break;
								}
							}	
							break;
						}
						else
						{
							if(tab[mov.linha-1][i+1]=='0')
							{
								break;
							}
						}
					}
				}			
				if(tab[mov.linha-1+1][mov.coluna-1]=='W')//vertical para baixo
				{
					for(int i=mov.linha-1;i<8;i++)
					{
						if(tab[i+1][mov.coluna-1]=='B')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='B';	
							for(int j=mov.linha-1;j<8;j++)
							{
								if(tab[j+1][mov.coluna-1]=='W')
								{
									tab[j+1][mov.coluna-1]='B';
								}
								else
								{
									break;
								}
							}
							break;
						}
						else
						{
							if(tab[i+1][mov.coluna-1]=='0')
							{
								break;
							}
						}
						
					}
				}
				if(tab[mov.linha-1-1][mov.coluna-1]=='W')//vertical cima
				{
					for(int i=mov.linha-1;i>=0;i--)
					{
						if(tab[i-1][mov.coluna-1]=='B')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='B';	
							for(int j=mov.linha-1;j>=0;j--)
							{
								if(tab[j-1][mov.coluna-1]=='W')
								{
									tab[j-1][mov.coluna-1]='B';
								}
								else
								{
									break;
								}
							}
							break;
						}
						else
						{
							if(tab[i-1][mov.coluna-1]=='0')
							{
								break;
							}
						}
						
					}
				}
				if(tab[mov.linha-1+1][mov.coluna-1-1]=='W')//diagonal secundaria baixo
				{
					o=mov.coluna-1;
					for(int i=mov.linha-1;i<8;i++)
					{
						if(tab[i+1][o-1]=='B')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='B';
							o=mov.coluna-1;
							for(int i=mov.linha-1;i<8;i++)
							{
								if(tab[i+1][o-1]=='W')
								{
									tab[i+1][o-1]='B';
								}
								else
								{
									break;
								}
								o--;
							}
							break;
						}
						else
						{
							if(tab[i+1][o-1]=='0')
							{
								break;
							}
						}
						o--;
					}
				}
				if(tab[mov.linha-1-1][mov.coluna-1+1]=='W')//diagonal secundaria cima
				{
					o=mov.coluna-1;
					for(int i=mov.linha-1;i>=0;i--)
					{
						if(tab[i-1][o+1]=='B')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='B';
							o=mov.coluna-1;
							for(int i=mov.linha-1;i>=0;i--)
							{
								if(tab[i-1][o+1]=='W')
								{
									tab[i-1][o+1]='B';
								}
								o++;
							}
							break;
						}
						else
						{
							if(tab[i-1][o+1]=='0')
							{
								break;
							}
						}
						o++;
					}
				}
				if(tab[mov.linha-1-1][mov.coluna-1-1]=='W')//diagonal superior cima
				{
					o=mov.coluna-1;
					for(int i=mov.linha-1;i>=0;i--)
					{
						if(tab[i-1][o-1]=='B')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='B';
							o=mov.coluna-1;
							for(int i=mov.linha-1;i>=0;i--)
							{
								if(tab[i-1][o-1]=='W')
								{
									tab[i-1][o-1]='B';
								}
								else
								{
									break;
								}
								o--;
							}	
							break;
						}
						else
						{
							if(tab[i-1][o-1]=='0')
							{
								break;
							}
						}
						
						o--;
					}
				}
				if(tab[mov.linha-1+1][mov.coluna-1+1]=='W')//diagonal superior baixo
				{
					o=mov.coluna-1;
					for(int i=mov.linha-1;i<8;i++)
					{
						if(tab[i+1][o+1]=='B')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='B';
							o=mov.coluna-1;
							for(int i=mov.linha-1;i<8;i++)
							{
								if(tab[i+1][o+1]=='W')
								{
									tab[i+1][o+1]='B';
								}
								else
								{
									break;
								}
								o++;
							}	
							break;
						}
						else
						{
							if(tab[i+1][o+1]=='0')
							{
								break;
							}
						}
						
						o++;
					}
				}
				else
				{
					if(aux!=1)
					{
						aux=0;
					}
				}
			}
			else
			{
				aux=0;
			}	
			
			
			break;
		}
		case 1://BRANCO 
		{
			if(tab[mov.linha-1][mov.coluna-1]=='0')
			{
				if(tab[mov.linha-1][mov.coluna-1-1]=='B')//horizontal esquerda
				{
					for(int i=mov.coluna-1;i>=0;i--)
					{
						if(tab[mov.linha-1][i-1]=='W')
						{
							aux=1;	
							tab[mov.linha-1][mov.coluna-1]='W';	
							for(int j=mov.coluna-1;j>=0;j--)
							{
								if(tab[mov.linha-1][j-1]=='B')
								{
									tab[mov.linha-1][j-1]='W';
								}
								else
								{
									break;
								}
							}
							break;
						}	
						else
						{
							if(tab[mov.linha-1][i-1]=='0')
							{
								break;
							}
						}	
					}		
				}
				if(tab[mov.linha-1][mov.coluna-1+1]=='B')//horizontal direita
				{
					for(int i=mov.coluna-1;i<8;i++)
					{
						if(tab[mov.linha-1][i+1]=='W')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='W';
							for(int j=mov.coluna-1;j<8;j++)
							{
								if(tab[mov.linha-1][j+1]=='B')
								{
									tab[mov.linha-1][j+1]='W';
								}
								else
								{
									break;
								}
							}	
							break;
						}
						else
						{
							if(tab[mov.linha-1][i+1]=='0')
							{
								break;
							}
						}
						
					}
				}
				if(tab[mov.linha-1+1][mov.coluna-1]=='B')//vertical para baixo
				{
					for(int i=mov.linha-1;i<8;i++)
					{
						if(tab[i+1][mov.coluna-1]=='W')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='W';	
							for(int j=mov.linha-1;j<8;j++)
							{
								if(tab[j+1][mov.coluna-1]=='B')
								{
									tab[j+1][mov.coluna-1]='W';
								}
								else
								{
									break;
								}
							}
							break;
						}
						else
						{
							if(tab[i+1][mov.coluna-1]=='0')
							{
								break;
							}
						}
						
					}
				}
				if(tab[mov.linha-1-1][mov.coluna-1]=='B')//vertical cima
				{
					for(int i=mov.linha-1;i>=0;i--)
					{
						if(tab[i-1][mov.coluna-1]=='W')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='W';	
							for(int j=mov.linha-1;j>=0;j--)
							{
								if(tab[j-1][mov.coluna-1]=='B')
								{
									tab[j-1][mov.coluna-1]='W';
								}
								else
								{
									break;
								}
							}
							break;
						}
						else
						{
							if(tab[i-1][mov.coluna-1]=='0')
							{
								break;
							}
						}
						
					}
				}
				if(tab[mov.linha-1+1][mov.coluna-1-1]=='B')//diagonal secundaria baixo
				{
					o=mov.coluna-1;
					for(int i=mov.linha-1;i<8;i++)
					{
						if(tab[i+1][o-1]=='W')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='W';
							o=mov.coluna-1;
							for(int j=mov.linha-1;j<8;j++)
							{
								if(tab[j+1][o-1]=='B')
								{
									tab[j+1][o-1]='W';
								}
								else
								{
									break;
								}
								o--;
							}
							break;
						}
						else
						{
							if(tab[i+1][o-1]=='0')
							{
								break;
							}
						}
						
						o--;
					}
				}
				if(tab[mov.linha-1-1][mov.coluna-1+1]=='B')//diagonal secundaria cima
				{
					o=mov.coluna-1;
					for(int i=mov.linha-1;i>=0;i--)
					{
						if(tab[i-1][o+1]=='W')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='W';
							o=mov.coluna-1;
							for(int i=mov.linha-1;i>=0;i--)
							{
								if(tab[i-1][o+1]=='B')
								{
									tab[i-1][o+1]='W';
								}
								else
								{
									break;
								}
								o++;
							}
							break;
						}
						else
						{
							if(tab[i-1][o+1]=='0')
							{
								break;
							}
						}
						
						o++;
					}
				}
				if(tab[mov.linha-1-1][mov.coluna-1-1]=='B')//diagonal superior cima
				{
					o=mov.coluna-1;
					for(int i=mov.linha-1;i>=0;i--)
					{
						if(tab[i-1][o-1]=='W')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='W';
							o=mov.coluna-1;
							for(int i=mov.linha-1;i>=0;i--)
							{
								if(tab[i-1][o-1]=='B')
								{
									tab[i-1][o-1]='W';
								}
								else
								{
									break;
								}
								o--;
							}	
							break;
						}
						else
						{
							if(tab[i-1][o-1]=='0')
							{
								break;
							}
						}
						
						o--;
					}
				}
				if(tab[mov.linha-1+1][mov.coluna-1+1]=='B')//diagonal superior baixo
				{
					o=mov.coluna-1;
					for(int i=mov.linha-1;i<8;i++)
					{
						if(tab[i+1][o+1]=='W')
						{
							aux=1;
							tab[mov.linha-1][mov.coluna-1]='W';
							o=mov.coluna-1;
							for(int i=mov.linha-1;i<8;i++)
							{
								if(tab[i+1][o+1]=='B')
								{
									tab[i+1][o+1]='W';
								}
								else
								{
									break;
								}
								o++;
							}	
							break;
						}
						else
						{
							if(tab[i+1][o+1]=='0')
							{
								break;
							}
						}
						o++;
					}
				}
			}
			else
			{
				aux=0;
			}	
			break;
		}	
	}
	
	
	return aux;
}


int main()
{
	char t[8][8];
	int pecaPreta=-1,pecaBranca=1,rodadas=1,x=0,vez,cont=0,pontosBranco=0,pontosPreto=0,ajuda=0;
	jogada movimento;
	
	iniciaTabuleiro(t);
	
	
	do
	{
		DesenhaTabuleiro(t);
		if(rodadas%2==0)
		{
			printf("Vez do jogador Branco(1)\nFaca sua jogada!\n");
			movimento= EscolhaJogada(movimento);
			vez=ExecutaJogada(t,pecaBranca,movimento);
			switch(vez)
			{
				case 1:
				{
					rodadas++;
					ajuda=0;
					break;
				}
				case 0:
				{
					printf("Jogada invalida!Tente outra coordenada\n");
					if(ajuda==4)
					{
						printf("Voce fez jogadas invalidas demais, talvez nao haja uma coordenada dentro das regras\nComo deve haver 1 disponivel sempre,sua proxima jogada sera considerada,mas ela nao convertera outras pecas para a mesma cor que a sua.\n");
					}
					if(ajuda>=5)
					{
						
						
						if(t[movimento.linha-1][movimento.coluna-1]=='0')
						{
							t[movimento.linha-1][movimento.coluna-1]='W';
							rodadas++;
							ajuda=0;
						}
						else
						{
							printf("A coordenada nao pode ja esta preenchida\n");
						}
					}
					break;			
				}
		
			}
		}
		else
		{
			printf("Vez do jogador Preto(-1)\nFaca sua jogada!\n");
			movimento= EscolhaJogada(movimento);
			vez=ExecutaJogada(t,pecaPreta,movimento);
			switch(vez)
			{
				case 1:
				{
					rodadas++;
					ajuda=0;
					break;
				}
				case 0:
				{
					printf("Jogada invalida!Tente outra coordenada\n");
					ajuda++;
					if(ajuda==4)
					{
						printf("Voce fez jogadas invalidas demais, talvez nao haja uma coordenada dentro das regras\nComo deve haver 1 disponivel sempre,sua proxima jogada sera considerada,mas ela nao convertera outras pecas para a mesma cor que a sua.\n");
					}
					if(ajuda>=5)
					{
						
						
						if(t[movimento.linha-1][movimento.coluna-1]=='0')
						{
							t[movimento.linha-1][movimento.coluna-1]='B';
							rodadas++;
							ajuda=0;
						}
						else
						{
							printf("A coordenada nao pode ja esta preenchida\n");
						}
					}
					break;			
				}
			}
		}
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(t[i][j]!='0')
				{
					cont++;
				}
			}
		}
		if(cont==64)
		{
			x=100;
		}
		else
		{
			cont=0;
		}
	}while(x==0);
	
	
	printf("Fim de jogo!\n");
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;i++)
		{
			if(t[i][j]=='B')
			{
				pontosPreto++;
			}
			if(t[i][j]=='W')
			{
				pontosBranco++;
			}
		}
	}
	if(pontosBranco>pontosPreto)
	{
		printf("Parabens jogador Branco!Voce eh o vencedor!\n");
	}
	if(pontosPreto>pontosBranco)
	{
		printf("Parabens Jogador Preto!Voce eh o vencedor\n");
	}
	if(pontosPreto==pontosBranco)
	{
		printf("Empate!\n");
	}
	
	return 0;
}
