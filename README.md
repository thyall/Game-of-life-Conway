# Game-of-life-Conway

## Objetivo

  --> O objetivo deste trabalho é implementar um sistema que realize a simulação do jogo da vida de Conway uma representação do [cellular automato (CA)](http://mathworld.wolfram.com/CellularAutomaton.html).
  
## Sobre o jogo
  --> O jogo consiste em uma simulação que ocorre sobre uma grade (matriz) *Linha x Coluna*. Cada posição é chamada de célula e cada célula pode conter dois estados, vivo ou morto. A cada nova geração as células poderão mudar de estado, onde esse estado depende da sua vizinhaça, a seguir as regas que influenciam na mudança de estado por geração:

**1. Primeira Regra**
* Se uma céula está viva e a quantidade de vizinhos for menor ou igual a 1 ela morreŕa de solidação

**2. Segunda Regra**
* Se uma céula está viva e a quantidade de vizinhos for maior ou igual a 4 ela morreŕa por superpopulação

**3. Terceira Regra**
* Se uma céula está viva e a quantidade de vizinhos de 2 ou 3 permanece viva

**4. Quarta Regra**
* Se uma célula morta possui 3 vizinhos na próxima geração ela passará a ficar viva, se for um valro diferente permanece morta

--> O jogo é também possui estados, estável ou extinto, se em determinada geração todas as células estiverem mortas a simulação irá parar e será denominada de geração extinta. Para ser uma configuração estável a simulação pode ter duas caracteristicas a primeira é se duas gerações seguintes foram iguais, e a segunda forma é se um padrão de sequencias tender a se repetir até o infinito ou limite máximo de gerações passado por linha de comando. Sendo esta ultima forma de establidade não apresentada nesse código.

## Compilação
`g++ -std=c++11 -Wall -I include src/main.cpp src/func_gamelife.cpp`

## Executavél
`./a.out -i data/lab1.dat -max 40`
