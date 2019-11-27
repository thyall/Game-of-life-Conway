#include "gamelife.hpp"

/*!< Nesse metodo (construtor)
*	 estou alocando a matriz necessaria para receber os dados
*	 assim como armazeno as dimensões na estrutura (lin, col)
*/
cell::cell(int x, int y)
{
	linha = x;
	coluna = y;

	//alocando dinamicamente a dimensão x
	board = new char*[x+1];
	clone_board = new char*[x+1];

	//nesse for eu estou alocando a outra dimensão Y para cada ponteira ja alocado 
	for (int i = 0; i < y; ++i)
	{
		board[i] = new char[y+1];
		clone_board = new char[y+1];
	}

	//é incrementado +1 para não acorrer risco de segmentation fault
}