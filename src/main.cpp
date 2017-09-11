#include<iostream>

#include"Input/Data/ConfigData.h"
#include"Input/ParseFunctions.h"


int main(int argc, char* argv[])
{
    if( argc != 2 )
    {
        std::cout << "Usage:\n\t" << argv[0] << " <primary configuration file>"<<std::endl;
        return 0;
    }
    Input::Data::ConfigData config;
    std::string configFileName(argv[1]);
    if(!Input::parseValAndPrintConfigFile(&config, configFileName, std::cout))
    {
        std::cout << "Could not read input, exitting: " << std::endl;
    }
    
    
    return 0;
}
