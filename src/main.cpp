#include"gamelife.h"
#include<string>
#include<chrono>
#include <fstream>
#include <iostream>
#include <thread>

/// Converte uma string para minusculas
std::string str_tolower( std::string str )
{
    for ( char & c : str )
        c = std::tolower( c );

    return str;
}

void message( std::string msg="")
{
    if ( msg != "" )
        std::cout << "   bpg ERROR: \"" << msg << "\"\n\n";
        
    std::cout <<"Usage: [<options>] -input <filename> \n"
                  <<"--help               ->    Print this help text.\n"
                  <<"-input <filename>    ->    Name of the file used for input. \n"
                  <<"--maxgen <num>       ->    Maximum number of generations to simulate. \n"                                      
                  <<"Note: My program will not work if the arguments are not entered correctly. \n"
                  << std::endl;
    exit( 0 );
}

int main(int argc, char const *argv[])
{  
    //criando objeto do tipo gamelife
    //Gamelife The_game;
    // preciso ler o arquivo de entrada

    std::string file_name;
    int max;

    max = 0;

    if ( argc == 1 )
    {
        message();
    }   

    if ( argc > 5 )
    {
        message("Too many argumnents!");        
    }

    //------------------------- primeira flag ---------------------------// 

    //variavel para receber o primeiro parametro
    auto s_arg = str_tolower( argv[1] );
    auto s_arg2 = str_tolower( argv[3] );

    //começo do 1 para pegar a primeira flag    
    if ( s_arg == "-i" or s_arg == "-input" )
      file_name = argv[2] ; //passo a quantidade de gerações
    else
      message("Invalid Flag try: -i or -input");

    //------------------------- primeira flag ---------------------------// 

    if (s_arg2 == "-maxgen" or s_arg2 == "-max")
      max =  std::atoi(argv[4]);

    else
      message("Invalid Flag try: -maxgen or -max"); 

    
    std::cout << max << " " << file_name << std::endl; 


    //The_game.ReadArguments(file_name);
    GameLife The_game(file_name);

    The_game.Print(); // pegar forma de print do snake depois

    std::cout << std::endl;
    int i = 0;
    int gerax = 1;
    bool st;
    bool ex;

    while(i < max)
    {
      //The_game.SetFillFBoard(The_game);
      The_game.NextGeneration(The_game);

      std::this_thread::sleep_for (std::chrono::microseconds(105000)); //melhor periodo

      //GameLife teste(file_name, 8, 8);
      std::cout << "Geração: " << gerax << std::endl;

      st = The_game.Stable();
      ex = The_game.Extinct();

      The_game.PassGeneration(The_game);

       if(ex)
      {
        std::cerr << "Configuração Morta!!!" << std::endl;
        break;
      }

      if(st)
      {
        std::cerr << "Configuração Estavel!!!" << std::endl;
        break;
      }

      The_game.SetFillFBoard(The_game);

      std::cout << std::endl;     

      i++;
      gerax++;
    }   

    return 0;
}
