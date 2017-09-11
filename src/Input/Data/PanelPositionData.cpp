#include"PanelPositionData.h"

// includes for C system headers
// includes for C++ system headers
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

void PanelPositionData::printValidationErrors(std::ostream& os)
{
    bool notEmpty = ((panelNumber.size() > 0) &&
                     (xPosition.size() > 0) &&
                     (xHalfSize.size() > 0) &&
                     (xNorm.size() > 0) &&
                     (yPosition.size() > 0) &&
                     (yHalfSize.size() > 0) &&
                     (yNorm.size() > 0) &&
                     (zPosition.size() > 0) &&
                     (zPosition.size() > 0) &&
                     (zNorm.size() > 0));
    int tempSize = panelNumber.size();
    bool equalSize = ((panelNumber.size() == tempSize) &&
                      (xPosition.size() == tempSize) &&
                      (xHalfSize.size() == tempSize) &&
                      (xNorm.size() == tempSize) &&
                      (yPosition.size() == tempSize) &&
                      (yHalfSize.size() == tempSize) &&
                      (yNorm.size() == tempSize) &&
                      (zPosition.size() == tempSize) &&
                      (zHalfSize.size() == tempSize) &&
                      (zNorm.size() == tempSize));
    if(notEmpty)
    {
        os << "There must be at least one entry in each column" << std::endl;
    }
    
    if(equalSize)
    {
        os << "Each column must have the same number of entries" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const PanelPositionData& ppd)
{
    os << "| Number | X Pos. | Y Pos. | Z Pos. | X Size | Y Size | Z Size | X Norm | Y Norm | Z Norm |" << std::endl;
    os << "|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|" << std::endl;
    
    int size = ppd.panelNumber.size();
    
    for(int i=0; i<size; ++i)
    {
        os <<  "| " << std::setw(6) << ppd.panelNumber[i];
        os << " | " << std::setw(6) << std::setprecision(6) << ppd.xPosition[i];
        os << " | " << std::setw(6) << std::setprecision(6) << ppd.yPosition[i];
        os << " | " << std::setw(6) << std::setprecision(6) << ppd.zPosition[i];
        os << " | " << std::setw(6) << std::setprecision(6) << ppd.xHalfSize[i];
        os << " | " << std::setw(6) << std::setprecision(6) << ppd.yHalfSize[i];
        os << " | " << std::setw(6) << std::setprecision(6) << ppd.zHalfSize[i];
        os << " | " << std::setw(6) << std::setprecision(6) << ppd.xNorm[i];
        os << " | " << std::setw(6) << std::setprecision(6) << ppd.yNorm[i];
        os << " | " << std::setw(6) << std::setprecision(6) << ppd.zNorm[i];
        os << " |\n";
    }
    
    return os << "|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|";
}

}
}
