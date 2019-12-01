#include "gamelife.h"

/*!< Nesse metodo (construtor)
*	 estou alocando a matriz necessaria para receber os dados
*	 assim como armazeno as dimensões na estrutura (lin, col)
*/
GameLife::GameLife(std::string file_name , int a, int b, char live2)
{
	// a stream de arquivo de entrada
    std::ifstream ifs { file_name }; 
	linha = a;
	coluna = b;
	char aux;	

	//alocando dinamicamente a dimensão x
	board = new char*[a];
	future_board = new char*[a];

	//nesse for eu estou alocando a outra dimensão Y para cada ponteira ja alocado 
	for (int i = 0; i < b; ++i)
	{
		board[i] = new char[b];
		future_board[i] = new char[b];
	}

	//Variaveis para linha e coluna 
	//int x, y;
	//variaveis para o char vivo e morto
	//char aux;

	// a stream de arquivo de entrada
    //std::ifstream ifs { file_name }; 

    // vejo se tive sucesso em abrir o arquivo
    //if ( ifs.fail() ) return ERR_FAILED_OPENING_INPUT_FILE;
    int x, y;
    // z;
    //passando valores
    ifs >> x >> y;
    ifs >> aux;

    //armazendo os valores recebidos na estrutura 
    linha = x;
    coluna = y;
    live = aux;

    for(int i=0; i <a; i++)
    {
		for(int j=0; j < b; j++)
		{
			ifs >> aux;
			board[i][j] = aux;
			future_board[i][j] = aux;

		}
	}
	
	int count = 0; 

	for(int i=0; i < a; i++)
	{
		for(int j=0; j < b; j++)
		{
			if(board[i][j] != live)
			{
				dead = board[i][j];
				count++;
				break;
			}
		}
		if(count == 1) break;
	}
   
    ifs.close();  

	//é incrementado +2 para não acorrer risco de segmentation fault
}

int GameLife::NumNeighborsLive(int x, int y, GameLife &game)
{
	int count = 0;

	//-----------------------vertices----------------------//
	//canto superior esquerdo
	if(x == 0 and y == 0)
	{
		if( game.board[x][y+1] == live )//direita
			count++;

		if( game.board[x+1][y+1] == live)//canto inferior direito
			count++;

		if( game.board[x+1][y] == live )//baixo
			count++;
	}

	//canto inferior esquerdo
	if(x == linha -1 and y == 0)
	{
		if( game.board[x][y+1] == live )//direita
			count++;

		if( game.board[x-1][y-1] == live)//canto superior direito
			count++;

		if( game.board[x-1][y] == live )//cima
			count++;
	}

	//canto superior direito
	if(x == 0 and y == coluna - 1)
	{
		if( game.board[x][y-1] == live )//esquerda
			count++;

		if( game.board[x+1][y-1] == live)//canto inferior esquerdo
			count++;

		if( game.board[x+1][y] == live )//baixo
			count++;
	}

	//canto inferior direito
	if(x == linha - 1 and y == coluna - 1)
	{
		if( game.board[x][y-1] == live )//esquerda
			count++;

		if( game.board[x-1][y-1] == live)//canto superior esquerdo
			count++;

		if( game.board[x-1][y] == live )//cima
			count++;
	}
	//------------------colunas--------------------------//

	//-----------------coluna esquerda------------------//
	if(y == 0 and x > 0 and x < linha - 1)
	{
		if( game.board[x][y+1] == live )//direita
			count++;

		if( game.board[x+1][y+1] == live)//canto inferior direito
			count++;

		if( game.board[x+1][y] == live )//baixo
			count++;

		if( game.board[x-1][y+1] == live)//canto superior direito
			count++;

		if( game.board[x-1][y] == live)//cima
			count++;
	}

	//----------------coluna direita--------------------//
	if(y == coluna-1 and x > 0 and x < linha - 1)
	{
		if( game.board[x][y-1] == live )//esquerda
			count++;

		if( game.board[x+1][y-1] == live)//canto inferior esquerdo
			count++;

		if( game.board[x+1][y] == live )//baixo
			count++;

		if( game.board[x-1][y-1] == live)//canto superior esquerdo
			count++;

		if( game.board[x-1][y] == live)//cima
			count++;
	}

	//-------------------linha superior------------------//
	if(x == 0 and y < coluna - 1 and y > 0)
	{
		if( game.board[x][y+1] == live )//direita
			count++;

		if( game.board[x][y-1] == live)//esquerda
			count++;

		if( game.board[x+1][y] == live )//baixo
			count++;

		if( game.board[x+1][y+1] == live)//canto inferior direito
			count++;

		if( game.board[x+1][y-1] == live)//canto inferior esquerdo
			count++;

	}

	//----------------linhas inferior------------------//
	if(x == linha-1 and y < coluna - 1 and y > 0)
	{
		if( game.board[x][y+1] == live )//direita
			count++;

		if( game.board[x][y-1] == live)//esquerda
			count++;

		if( game.board[x-1][y] == live )//cima
			count++;

		if( game.board[x-1][y+1] == live)//canto superior direito
			count++;

		if( game.board[x-1][y-1] == live)//canto superior esquerdo
			count++;
	}

	//-------------------coordenadas sem tocar nas bordas-------------------//
	if(x < linha-1 and x > 0 and y < coluna - 1 and y > 0)
	{		
		if(	game.board[x][y-1] == game.live )//esquerda
			count++;

		if( game.board[x][y+1] == game.live )//direita
			count++;

		if( game.board[x-1][y] == game.live)//cima
			count++;

		if( game.board[x+1][y] == game.live )//baixo
			count++;

		if( game.board[x-1][y-1] == game.live )//canto superior esquerdo
			count++;

		if( game.board[x+1][y-1] == game.live )//canto inferior esquerdo
			count++;

		if( game.board[x-1][y+1] == game.live)//canto superior direito
			count++;

		if( game.board[x+1][y+1] == game.live)//canto inferior direito
			count++;
	}

	return count;
}

void GameLife::SetFillFBoard(GameLife &game)
{
	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			game.board[i][j] = game.future_board[i][j];
		}	
	}
}
void GameLife::Print(void) const
{
	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			std::cout << board[i][j];
		}

		std::cout<< std::endl;
	}
}

void GameLife::NextGeneration(GameLife &game)
{
	int aux = 0;

	live = game.live;
	dead = game.dead;

	
	for (int i = 0; i < game.linha; ++i)
	{
		for (int j = 0; j < game.coluna; ++j)
		{
			aux = NumNeighborsLive(i, j, game);
			//std::cout << "aux" << std::endl;			
			/*!<aqui estou aplicando as regras propostas
			 * e armazenando isso na matriz future_board
			 */
			if(game.board[i][j] == game.live) // se a celula estiver viva
			{
				if(aux == 2 or aux == 3)
					future_board[i][j] = live;

				else
					future_board[i][j] = dead;
			}

			else
			{
				if(aux == 3)//se a celula estiver morta
					future_board[i][j] =  live;

				else
					future_board[i][j] =  dead;
			}		
		}	
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

bool GameLife::Extinct()
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





