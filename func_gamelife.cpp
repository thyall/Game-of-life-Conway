#include "gamelife.hpp"

/*!< Nesse metodo (construtor)
*	 estou alocando a matriz necessaria para receber os dados
*	 assim como armazeno as dimensões na estrutura (lin, col)
*/
GameLife::GameLife(int x, int y)
{
	linha = x;
	coluna = y;

	//alocando dinamicamente a dimensão x
	board = new char*[x+1];
	future_board = new char*[x+1];

	//nesse for eu estou alocando a outra dimensão Y para cada ponteira ja alocado 
	for (int i = 0; i < y; ++i)
	{
		board[i] = new char[y+1];
		future_board = new char[y+1];
	}

	//é incrementado +1 para não acorrer risco de segmentation fault
}

int GameLife::NumNeighborsLive(int x, int y)
{
	int count = 0;

	if(	board[x][y-1] == live )//esquerda
		count++;

	if( board[x][y+1] == live )//direita
		count++;

	if( board[x-1][y] == live)//cima
		count++;

	if( board[x+1][y] == live )//baixo
		count++;

	if( board[x-1][y-1] == live )//canto superior esquerdo
		count++;

	if( board[x+1][y-1] == live )//canto inferior esquerdo
		count++;

	if( board[x-1][y+1] == live)//canto superior direito
		count++;

	if( board[x+1][y+1] == live)//canto inferior direito
		count++;

	return count;

}

void GameLife::print()
{
	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			std::cout << board[i][j];
		}

		std::endl;
	}
}

void GameLife::NextGeneration()
{
	int aux = 0;

	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			aux = NumNeighborsLive(i, j);

			/*!<aqui estou aplicando as regras propostas
			 * e armazenando isso na matriz future_board
			 */
			if(board[i][j] == live) // se a celula estiver viva
			{
				if(aux == 2 or aux == 3)
					future_board[i][j] = live;

				else
					future_board[i][j] = dead;
			}

			else
			{
				if(aux == 3)//se a celula estiver morta
					future_board[i][j] = live;

				else
					future_board[i][j] = dead;
			}		
		}
		std::endl;
	}
}

void GameLife::PassGeneration()
{
	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			board[i][j] = future_board[i][j];
		}
	}
}

bool GameLife::Stable()
{
	int aux = 0;//variavel para podermos pausar

	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			if(board[i][j] != future_board[i][j])
				aux++;
		}
	}

	if(aux == 0)
		return true;

	else 
		return false;
}

bool GameLife::Stable()
{
	int aux = 0;//variavel para podermos pausar

	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			if(board[i][j] != dead)
				aux++;
		}
	}

	if(aux == 0)
		return true;

	else 
		return false;
}





