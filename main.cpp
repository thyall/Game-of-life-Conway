#include"gamelife.h"
#include<string>
#include<chrono>
#include <fstream>
#include <iostream>

/*int read_file( std::string file_name, vector<vector<int>> &matrix, int *x, int *y )
{
    // The input file strem.
    std::ifstream ifs { file_name }; // Creating and Opening the stream.
    // Flags that indicates whether the maze has entry and exit.
    bool has_entry{false}, has_apple{false};

    // Check whether we sucessfully open the input file.
    if ( ifs.fail() ) return ERR_FAILED_OPENING_INPUT_FILE;
    
    ifs >> *x >> *y;

    // While there is lines to read from the input file...
    while( not ifs.eof() )
    {
        std::string line; // Stores a line from the input file.
        std::getline( ifs, line );
        std::vector<int> temp; // Array to hold the integer representation of one line of a maze.
        // Traverse the string we just read in from the input file.
        for ( const char &elem : line )
        {
            // Teste which type of cell we've got.
            if ( elem == '.' or elem == ' ' or elem == '0') // espaço vazio no labirinto.
                temp.push_back(Snakegame::FREE );

            else if ( elem == '1') // parede
                temp.push_back( Snakegame::WALL );

            else if ( elem == 'm' or elem == 'M' or elem == '*' ) // The start.
            {
                temp.push_back( Snakegame::ENTRY );
                has_entry = true; // Turn on flag to indicate we've found the entry cell.
            }

            //isso aqui vai ser retirado
            else if ( elem == 'e' or elem == 'E' ) // The exit.
            {
                temp.push_back( Snakegame::APPLE );
                has_apple = true; // Turn on flag to indicate we've found the exit cell.
            }

            //else // Found an invalid value in the file.
                //std::cerr << "Invalid value!!\n";

        }
        // Store the new line in the maze.
        matrix.push_back( temp );
    }

    // All mazes to be valid must have entry/exit cells.
    if ( not has_entry or not has_apple )
        return ERR_MISSING_ENTRY_EXIT;

    // Closes input file stream.
    ifs.close();

    return READ_OK;
}*/

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
    //Gamelife The_game(int x, int y);
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
    

    return 0;
}

