#include<iostream>

int main(int argc, char* argv[])
{
    if( argc != 2 )
    {
        std::cout << "Usage:\n\t" << argv[0] << " <primary configuration file>"<<std::endl;
        return 0;
    }
    std::cout << "Reading primary configuration from: " << argv[1] << std::endl;
    
    
    return 0;
}
