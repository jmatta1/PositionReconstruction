#include<iostream>

#include"Input/Data/ConfigData.h"
#include"Input/Data/DetectorPositionData.h"
#include"Input/Data/PanelPositionData.h"
#include"Input/ParseFunctions.h"


int main(int argc, char* argv[])
{
    //check for the appropriate number of command line arguments
    if( argc != 2 )
    {
        std::cout << "Usage:\n\t" << argv[0] << " <primary configuration file>"<<std::endl;
        return 1;
    }
    std::cout<<"\n";
    Input::Data::ConfigData config;
    std::string configFileName(argv[1]);
    //read and output the primary input file
    if(!Input::parseValAndPrintConfigFile(&config, configFileName, std::cout))
    {
        std::cout << "Primary Configuration File Input Error, Quitting" << std::endl;
        return 1;
    }
    else
    {
        std::cout << config << std::endl;
    }
    
    std::cout<<"\n\n";
    //read and output the detector position file
    Input::Data::DetectorPositionData detPos;
    if(!Input::parseValAndPrintDetectorPositionFile(&detPos, config.detPosInputFile, std::cout))
    {
        std::cout << "Detector Position File Input Error, Quitting" << std::endl;
        return 1;
    }
    else
    {
        std::cout << detPos << std::endl;
    }
    std::cout<<"\n\n";
    //read and output the panel position file
    Input::Data::PanelPositionData panPos;
    if(!Input::parseValAndPrintPanelPositionFile(&panPos, config.panelPosInputFile, std::cout))
    {
        std::cout << "Panel Position File Input Error, Quitting" << std::endl;
        return 1;
    }
    else
    {
        std::cout << panPos << std::endl;
    }
    
    return 0;
}
