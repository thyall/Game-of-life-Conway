#include"gamelife.h"
#include<string>
#include<chrono>
#include <fstream>
#include <iostream>

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
    //auto s_arg = str_tolower( argv[1] );
   // auto s_arg2 = str_tolower( argv[3] );

    //Laço para ler os arugmentos passados por linha de comando
    //começo do 1 para pegar a primeira flag    
    //if ( s_arg == "-i" or s_arg == "-input" )
    max =  std::atoi(argv[4]) ; // passo o nome do arquivo para file_name e acresceto +1 para pular a variavel 

    //else if(s_arg == "maxgen" or s_arg == "max")   
        //max = std::atoi( argv[4] ); //passo a quantidade de grações

    //lse if ( s_arg2 == "-i" or s_arg2 == "-input" )
     // file_name = argv[4] ; // passo o nome do arquivo para file_name e acresceto +1 para pular a variavel       

    //else if(s_arg2 == "maxgen" or s_arg2 == "max")   
    file_name = argv[2] ; //passo a quantidade de grações

    //else
      //message("Invalid argumnent!!!");

    //------------------------- segunda flag ---------------------------//

    //variavel para receber o terceiro parametro
     //auto s_arg2 = str_tolower( argv[3] );

    //Laço para ler os arugmentos passados por linha de comando
    //começo do 1 para pegar a primeira flag    
    //if ( s_arg2 == "-i" or s_arg2 == "-input" )
      //file_name = argv[4] ; // passo o nome do arquivo para file_name e acresceto +1 para pular a variavel    

    //else if(s_arg == "maxgen" or s_arg == "max")   
        //max = std::atoi( argv[4] ); //passo a quantidade de grações

    //else
      //message("Invalid argumnent!!!");*/
    
    //------------------------- iniciando gerações ---------------------------//
    std::cout << max << " " << file_name << std::endl;  
    

    return 0;
}

