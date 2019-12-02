#include "gamelife.h"

/*!< Nesse metodo (construtor)
*	 estou alocando a matriz necessaria para receber os dados
*	 assim como armazeno as dimensões na estrutura (lin, col)
*/
GameLife::GameLife(std::string file_name)
{
	int x, y;
	char charvivo, aux;
	// a stream de arquivo de entrada
    std::ifstream ifs { file_name };

    //int x, y;
    // z;
    //passando valores
    ifs >> x >> y;
    ifs >> charvivo;
 
	linha = x;
	coluna = y;
	live = charvivo;
	//char aux;	

	//std::cout<<"aqui3;";
	//alocando dinamicamente a dimensão x
	board = new char*[x];
	//std::cout<<"aqui3;";
	future_board = new char*[x];
	
	//nesse for eu estou alocando a outra dimensão Y para cada ponteira ja alocado 
	for (int i = 0; i < x; ++i)
	{
		board[i] = new char[y];
		future_board[i] = new char[y];
	}	

    for(int i=0; i <x; i++)
    {
		for(int j=0; j < y; j++)
		{
			ifs >> aux;
			board[i][j] = aux;
			future_board[i][j] = aux;

		}
	}
	
	int count = 0; 

	for(int i=0; i < x; i++)
	{
		for(int j=0; j < y; j++)
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

	std::cout << live <<" " << dead << " " << linha << " " << coluna << std::endl;
   
    ifs.close();  	
}
/*!< Nesse metodo 
*	 eu analiso todas as possibilidades de vizinhança estando na borda ou não
*	 conforme analisado eu incremento na variavel count e retorno ela
*/

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
/*!< Nesse metodo 
*	 eu passo toda configuração armazenada na matriz future e passo para a matriz atual board
*/

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
/*!< Nesse metodo 
*	 printo no terminal a configuração da matriz atual board
*/
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

/*!< Nesse metodo 
*	 aqui eu crio uma nova geração a partir da configuração da geração atual board
*	 seguindo as regras de vizinhança e armazeno tudo na geração future
*/

void GameLife::NextGeneration(GameLife &game)
{
	int aux = 0;

	live = game.live;
	dead = game.dead;

	//std::cout << live << " " << dead << std::endl;
	//std::cout << linha << " " << coluna << std::endl;

	
	for (int i = 0; i < game.linha; ++i)
	{
		for (int j = 0; j < game.coluna; ++j)
		{
			aux = NumNeighborsLive(i, j, game);			
			/*!<aqui estou aplicando as regras propostas
			 * e armazenando isso na matriz future_board
			 */			
			if(game.board[i][j] == live) // se a celula estiver viva
			{
				//std::cout << "vivo" << aux << std::endl;
				if(aux == 2 || aux == 3){
					//std::cout << aux << std::endl;
					future_board[i][j] = live;
					//std::cout << aux << std::endl;
				}

				else{
					//std::cout << "morra" << aux <<std::endl;
					//std::cout <<i<<j <<std::endl;
					future_board[i][j] = dead;
					//std::cout <<i << j << future_board[i][j] << std::endl;
				}
			}

			else
			{
				//std::cout << "morta" << aux <<std::endl;
				if(aux == 3)//se a celula estiver morta
					future_board[i][j] =  live;

				else
					future_board[i][j] =  dead;
			}		
		}	
	}
}

/*!< Nesse metodo 
*	 printo no terminal a configuração da matriz future
*/
void GameLife::PassGeneration(GameLife& game)
{
	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			std::cout<< game.future_board[i][j];
		}

		std::cout<< std::endl;
	}
}

/*!< Nesse metodo 
*	 eu reconhço se a configuração se tornou estável (n=0)
*	 falta melhorar esse metodo para reconhecer se está estavel com (n=1)
*/
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

/*!< Nesse metodo 
*	 eu reconhço se a configuração se tornou extinta
*	todos mortos
*/
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




