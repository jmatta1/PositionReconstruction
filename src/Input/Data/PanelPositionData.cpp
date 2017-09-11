#include"PanelPositionData.h"

// includes for C system headers
// includes for C++ system headers
#include<iostream>
#include<iomanip>
// includes from other libraries
// includes from this code

namespace Input
{
namespace Data
{

bool PanelPositionData::validate()
{
    bool notEmpty = ((panelNumber.size() > 0) &&
                     (xPosition.size() > 0) &&
                     (xHalfSize.size() > 0) &&
                     (yPosition.size() > 0) &&
                     (yHalfSize.size() > 0) &&
                     (zPosition.size() > 0) &&
                     (zPosition.size() > 0));
    int tempSize = panelNumber.size();
    bool equalSize = ((panelNumber.size() == tempSize) &&
                      (xPosition.size() == tempSize) &&
                      (xHalfSize.size() == tempSize) &&
                      (yPosition.size() == tempSize) &&
                      (yHalfSize.size() == tempSize) &&
                      (zPosition.size() == tempSize) &&
                      (zHalfSize.size() == tempSize));
    return (notEmpty && equalSize);
}

void PanelPositionData::printValidation()
{
    bool notEmpty = ((panelNumber.size() > 0) &&
                     (xPosition.size() > 0) &&
                     (xHalfSize.size() > 0) &&
                     (yPosition.size() > 0) &&
                     (yHalfSize.size() > 0) &&
                     (zPosition.size() > 0) &&
                     (zPosition.size() > 0));
    int tempSize = panelNumber.size();
    bool equalSize = ((panelNumber.size() == tempSize) &&
                      (xPosition.size() == tempSize) &&
                      (xHalfSize.size() == tempSize) &&
                      (yPosition.size() == tempSize) &&
                      (yHalfSize.size() == tempSize) &&
                      (zPosition.size() == tempSize) &&
                      (zHalfSize.size() == tempSize));
    if(notEmpty)
    {
        std::cout << "There must be at least one entry in each column" << std::endl;
    }
    
    if(equalSize)
    {
        std::cout << "Each column must have the same number of entries" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const PanelPositionData& ppd)
{
    os << "| Panel Number | X Pos. | X Size | Y Pos. | Y Size | Z Pos. | Z Size |" << std::endl;
    os << "|--------------|--------|--------|--------|--------|--------|--------|" << std::endl;
    
    int size = ppd.panelNumber.size();
    
    for(int i=0; i<size; ++i)
    {
        os <<  "| " << std::setw(12) << ppd.panelNumber[i];
        os << " | " << std::setw(6) << std::setprecision(1) << ppd.xPosition[i];
        os << " | " << std::setw(6) << std::setprecision(1) << ppd.xHalfSize[i];
        os << " | " << std::setw(6) << std::setprecision(1) << ppd.yPosition[i];
        os << " | " << std::setw(6) << std::setprecision(1) << ppd.yHalfSize[i];
        os << " | " << std::setw(6) << std::setprecision(1) << ppd.zPosition[i];
        os << " | " << std::setw(6) << std::setprecision(1) << ppd.zHalfSize[i];
        os << " |";
    }
    
    return os << "|--------------|--------|--------|--------|--------|--------|--------|";
}

}
}
