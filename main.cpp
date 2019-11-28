#include"gamelife.h"
#include<string>
#include<chrono>

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
                      <<"--imgdir <path>      ->    Specify directory where output images are written to. Make sure that the folder exists.\n"
                      <<"--maxgen <num>       ->    Maximum number of generations to simulate. \n"
                      <<"--fps <num>          ->    Number of generations to be presented per second. Default: 1 \n"
                      <<"--outfile <filename> ->    Output filename for storing the text representations of the simulation. \n \n"
                      <<"Note: Our program will not work if the arguments are not entered correctly. \n"
                      << std::endl;
    exit( 0 );
}

int main(int argc, char const *argv[])
{
    // Default values.
    //std::string inputcfg; // Usado para receber arquivo de Entrada contendo as confiruações da primeira geração de céculas 
    //std::string outputFolder(""); // Diretório onde serão salvas as imagens de saída
    //int maxGen = 0; // Define um limite de gerações para o programa (para que não fique rodando inifinitamente, caso seja possível)
    //std::chrono::seconds fps(1); // Define um temporizador para calcular as gerações (nesse caso ele itera uma geração por segundo)
    
    //std::string outfile(""); // Arquivo txt que vai salvar as informações em texto das gerações, caso o usuário não queira gerar as imagens
    
    if ( argc == 1 )
    {
        message();
    }   

    if ( argc > 4 )
    {
        message("Too many argumnents!");        
    } 
    
    

    return 0;
}