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
	board = new char*[x+2];
	future_board = new char*[x+2];

	//nesse for eu estou alocando a outra dimensão Y para cada ponteira ja alocado 
	for (int i = 0; i < y; ++i)
	{
		board[i] = new char[y+2];
		future_board = new char[y+2];
	}

	//é incrementado +2 para não acorrer risco de segmentation fault
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

void GameLife::ReadArguments(std::sting file_name)
{
	//Variaveis para linha e coluna 
	int x, y;
	//variaveis para o char vivo e morto
	char live2, morto2;

	// The input file strem.
    std::ifstream ifs { file_name }; // Creating and Opening the stream

    // Check whether we sucessfully open the input file.
    if ( ifs.fail() ) return ERR_FAILED_OPENING_INPUT_FILE;
    
    //passando valores
    ifs >> x >> y;
    ifs >> live2;

    //armazendo os valores recebidos na estrutura 
    linha = x;
    coluna = y;
    live = live2;

   
    ifs.close();  
}

void GameLife::print() const
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

void GameLife::NextGeneration(GameLife &game)
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
			if(game.board[i][j] == live) // se a celula estiver viva
			{
				if(aux == 2 or aux == 3)
					 game.future_board[i][j] = game.live;

				else
					 game.future_board[i][j] = game.dead;
			}

			else
			{
				if(aux == 3)//se a celula estiver morta
					 game.future_board[i][j] =  game.future_board.live;

				else
					 game.future_board[i][j] =  game.future_board.dead;
			}		
		}
		std::endl;
	}
}

void GameLife::PassGeneration(GameLife &game)
{
	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			game.board[i][j] = game.future_board[i][j];
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





