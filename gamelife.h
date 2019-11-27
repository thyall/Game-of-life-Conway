/*	!Author:Thyall D'greville
 *
 * 	\ in this code I define the cell class
 *
 *  @date November, 27th.
 */

#ifndef GAMELIFE_H_
#define GAMELIFE_H_


class Cell
{
private:

	char **board;//!< para armazenar a grade
	char **clone_board; //!< uma grade copia que irá ser necessaria para os metodos
	int linha, coluna; //!< dimensões da grade
	char live, dead;//!< aqui eu recebo qual simbolo está sendo usada para cada tipo de celula


public:

	//construtor, aqui eu aloco o espaço necessario para a matriz
	Cell(int x, int y);

	//destrutor, mas não será necesasrio
	~Cell();

	//contador de vivos ou não vivos na vizinhaça
	int NumNeighbors(int x, int y);

	//printa a matriz a ser passada, talvez crie uma variavel para definir qual será passada
	void Print();

	//aqui eu analiso o estado atual da geração para poder gerar o proximo
	void NextGeneration();

	//função para determinar se a configuração se encontra estável
	void Stable();

	//função para determinar se a configuração se encontra extinct
	void Extinct();

	operator =();

	operator ==();
	
};

#endif