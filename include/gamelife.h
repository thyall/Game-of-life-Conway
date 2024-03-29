/*	!Author:Thyall D'greville
 *
 * 	\ in this code I define the GameLife class
 *
 *  @date November, 27th.
 */

#ifndef GAMELIFE_H_
#define GAMELIFE_H_

/// possiveis saidas para ReadArguemnts()
#define ERR_FAILED_OPENING_INPUT_FILE 0

#include<string>
#include<chrono>
#include <fstream>
#include <iostream>

class GameLife
{
private:

	//alocação inspirada no batleship
	char **board;//!< para armazenar a grade
	char **future_board; //!< uma grade copia que irá ser necessaria para os metodos
	int linha, coluna; //!< dimensões da grade
	char live, dead;//!< aqui eu recebo qual simbolo está sendo usada para cada tipo de celula


public:

	//construtor, aqui eu aloco o espaço necessario para a matriz
	GameLife(std::string file_name );

	//destrutor, mas não será necesasrio
	//~GameLife();

	//contador de vivos ou não vivos na vizinhaça
	int NumNeighborsLive(int x, int y, GameLife &game);

	//printa a matriz a ser passada, talvez crie uma variavel para definir qual será passada
	void Print(void) const;

	//aqui eu analiso o estado atual da geração para poder gerar o proximo
	//e armazeno tudo na matriz future
	void NextGeneration(GameLife &game);
	
	//passo a configuração de future_board para board
	void SetFillFBoard(GameLife &game);

	//essa função passa toda configuração de future_board para o board
	void PassGeneration(GameLife &game);

	//função para determinar se a configuração se encontra estável
	bool Stable();

	//função para determinar se a configuração se encontra extinct
	bool Extinct();
	
};

#endif
