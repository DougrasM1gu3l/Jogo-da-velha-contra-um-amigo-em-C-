#include<stdio.h>
#include<locale.h>
#include<iostream>
#define TAMANHO 3		//Substituindo o valor "3" por 'tamanho' para que a constru��o do programa se torne facilitada

//------------------------------------------------------------------------------ Prot�tipos
void iniciarTabuleiro();
void trocarPlayer();		//void - fun��es com resultados variados
void displayTabuleiro();
bool fazerMovimento(int row, int col);
bool checarEmpate();		//bool - fun��es que seram confirmadas com verdadeiro ou falso
bool checarVitoria();

//------------------------------------------------------------------------------ Vari�veis globais
char tabuleiro[TAMANHO][TAMANHO];
char player = 'x';

//------------------------------------------------------------------------------ Execu��o
int main(){		
	setlocale(LC_ALL, "");
	iniciarTabuleiro();

	while(true){
		displayTabuleiro();													//Mostra o tabuleiro na tela
		int row, col;		//Definindo 'row' e 'col' que seram usados em todo o algoritmo
		std::cout <<"Jogador "<< player <<", escolha a linha e a coluna.";	//Usando a sintaxe Iostream -> std::cout <<(print)  // std::cin >>(scan)	
		std::cin >>row>>col;
		
		if(fazerMovimento(row -1, col -1)){									//Reajusta o ind�ce para o usu�rio digitar n�meros a partir do �ndicce um
			if(checarVitoria()){											//Dando mensagem de vit�ria em caso de ela ter sido verificada (de acordo com a condi��o construida na linha 79)
				displayTabuleiro();
				std::cout <<"O jogador "<< player<<" venceu!"<< std::endl;
				break;
			}
			if(checarEmpate()){												//Dando mensagem de empate em caso de ter sido verificado (de acordo com a condi��o construida na linha 95)
				displayTabuleiro();
				std::cout<<"� empate!"<<std::endl;
				break;
			}
			trocarPlayer(); 		//A��a trocar player que est� elaborada na linha 106 do c�digo
		}else{
			std::cout<<"Movimento inv�lido. Tente novamente"<< std::endl;
		}	
	}
	return 0;
}
//------------------------------------------------------------------------------  Configura��o para "iniciarTabuleiro" (formato)

	void iniciarTabuleiro(){
		for(int i=0;i<TAMANHO;i++){												//Para linha < 3, linha add 1: linha[0][1][2]
			for(int j=0;j<TAMANHO;j++){											//Para coluna <3, coluna add 1: coluna[0][1][2]
				tabuleiro[i][j] = ' ';
			}
		}
	}

//------------------------------------------------------------------------------ Configura��o para dar "displayTabuleiro" (mostrar)
	void displayTabuleiro(){
		for(int i=0;i<TAMANHO;i++){
			for(int j=0;j<TAMANHO;j++){
				std::cout<< tabuleiro[i][j];
				if(j<TAMANHO - 1) std::cout<< " | ";
			}
				std::cout<< std::endl;
				if (i<TAMANHO - 1) std::cout<< "---------" << std::endl;
			}
		}
	
//------------------------------------------------------------------------------ Configurando o "checar movimento" para identificar movimentos inv�lidos
 	bool fazerMovimento(int row, int col){
 		if(row >= 0 && row < TAMANHO && col >= 0 && col < TAMANHO &&tabuleiro[row][col] == ' ' ){
 			tabuleiro[row][col] = player;
			 return true;
		}else{		
			return false;
		 }
 	}

//------------------------------------------------------------------------------ Configurando o "checarVitoria"
 	bool checarVitoria(){
 		for(int i=0;i<TAMANHO;i++){
 			if (tabuleiro[i][0] == player && tabuleiro[i][1] == player && tabuleiro[i][2] == player){		//Linha 83 - 86 (Vit�rias horizontais ou verticais)
 				return true;
			 }else if(tabuleiro[0][i] == player && tabuleiro[1][i] == player && tabuleiro[2][i] == player){
			 	return true;
			 }else if(tabuleiro[2][0] == player && tabuleiro[1][1] == player && tabuleiro[0][2] == player){	//Linha 87 - 89 (Vit�rias diagonais)
			 	return true;
			 }else if(tabuleiro[0][0] == player && tabuleiro[1][1] == player && tabuleiro[2][2] == player){
			 	return true;
			 }else{
		 	return false;
		 }
	 }
}
//------------------------------------------------------------------------------ Configurando o "checarEmpate" (s� h� duas alternativas de conclus�o nesse jogo: vit�ria ou empate -> ambos direcionados a um player)

	bool checarEmpate(){
		for(int i=0;i<TAMANHO;i++){
			for(int j=0; j<TAMANHO; j++){
				if (tabuleiro[i][j]==' ') return false;	//Enquanto houverem espa�os em branco, ainda n�o h� empate
				}
			}
			return true;
		}
	
//------------------------------------------------------------------------------ Configurando a fun��o "trocarJogador"

	void trocarPlayer(){
		player = (player =='x') ? 'o':'x';		//Player recebe o valor de x. Se player for 'o', substituir por 'x' e vice versa
	}
