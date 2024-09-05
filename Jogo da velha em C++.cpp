#include<stdio.h>
#include<locale.h>
#include<iostream>
#define TAMANHO 3		//Substituindo o valor "3" por 'tamanho' para que a construção do programa se torne facilitada

//------------------------------------------------------------------------------ Protótipos
void iniciarTabuleiro();
void trocarPlayer();		//void - funções com resultados variados
void displayTabuleiro();
bool fazerMovimento(int row, int col);
bool checarEmpate();		//bool - funções que seram confirmadas com verdadeiro ou falso
bool checarVitoria();

//------------------------------------------------------------------------------ Variáveis globais
char tabuleiro[TAMANHO][TAMANHO];
char player = 'x';

//------------------------------------------------------------------------------ Execução
int main(){		
	setlocale(LC_ALL, "");
	iniciarTabuleiro();

	while(true){
		displayTabuleiro();													//Mostra o tabuleiro na tela
		int row, col;		//Definindo 'row' e 'col' que seram usados em todo o algoritmo
		std::cout <<"Jogador "<< player <<", escolha a linha e a coluna.";	//Usando a sintaxe Iostream -> std::cout <<(print)  // std::cin >>(scan)	
		std::cin >>row>>col;
		
		if(fazerMovimento(row -1, col -1)){									//Reajusta o indíce para o usuário digitar números a partir do índicce um
			if(checarVitoria()){											//Dando mensagem de vitória em caso de ela ter sido verificada (de acordo com a condição construida na linha 79)
				displayTabuleiro();
				std::cout <<"O jogador "<< player<<" venceu!"<< std::endl;
				break;
			}
			if(checarEmpate()){												//Dando mensagem de empate em caso de ter sido verificado (de acordo com a condição construida na linha 95)
				displayTabuleiro();
				std::cout<<"É empate!"<<std::endl;
				break;
			}
			trocarPlayer(); 		//Açõa trocar player que está elaborada na linha 106 do código
		}else{
			std::cout<<"Movimento inválido. Tente novamente"<< std::endl;
		}	
	}
	return 0;
}
//------------------------------------------------------------------------------  Configuração para "iniciarTabuleiro" (formato)

	void iniciarTabuleiro(){
		for(int i=0;i<TAMANHO;i++){												//Para linha < 3, linha add 1: linha[0][1][2]
			for(int j=0;j<TAMANHO;j++){											//Para coluna <3, coluna add 1: coluna[0][1][2]
				tabuleiro[i][j] = ' ';
			}
		}
	}

//------------------------------------------------------------------------------ Configuração para dar "displayTabuleiro" (mostrar)
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
	
//------------------------------------------------------------------------------ Configurando o "checar movimento" para identificar movimentos inválidos
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
 			if (tabuleiro[i][0] == player && tabuleiro[i][1] == player && tabuleiro[i][2] == player){		//Linha 83 - 86 (Vitórias horizontais ou verticais)
 				return true;
			 }else if(tabuleiro[0][i] == player && tabuleiro[1][i] == player && tabuleiro[2][i] == player){
			 	return true;
			 }else if(tabuleiro[2][0] == player && tabuleiro[1][1] == player && tabuleiro[0][2] == player){	//Linha 87 - 89 (Vitórias diagonais)
			 	return true;
			 }else if(tabuleiro[0][0] == player && tabuleiro[1][1] == player && tabuleiro[2][2] == player){
			 	return true;
			 }else{
		 	return false;
		 }
	 }
}
//------------------------------------------------------------------------------ Configurando o "checarEmpate" (só há duas alternativas de conclusão nesse jogo: vitória ou empate -> ambos direcionados a um player)

	bool checarEmpate(){
		for(int i=0;i<TAMANHO;i++){
			for(int j=0; j<TAMANHO; j++){
				if (tabuleiro[i][j]==' ') return false;	//Enquanto houverem espaços em branco, ainda não há empate
				}
			}
			return true;
		}
	
//------------------------------------------------------------------------------ Configurando a função "trocarJogador"

	void trocarPlayer(){
		player = (player =='x') ? 'o':'x';		//Player recebe o valor de x. Se player for 'o', substituir por 'x' e vice versa
	}
