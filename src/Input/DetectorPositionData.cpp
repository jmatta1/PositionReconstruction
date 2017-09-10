#include"DetectorPositionData.h"

// includes for C system headers
// includes for C++ system headers
#include<iostream>
#include<iomanip>
// includes from other libraries
// includes from this code

bool DetectorPositionData::validate()
{
    bool notEmpty = ((detectorNumber.size() > 0) &&
                     (runNumber.size() > 0) &&
                     (xPosition.size() > 0) &&
                     (yPosition.size() > 0) &&
                     (zPosition.size() > 0));
    
    int tempSize = detectorNumber.size();
    bool equalSize = ((runNumber.size() == tempSize) &&
                      (xPosition.size() == tempSize) &&
                      (yPosition.size() == tempSize) &&
                      (zPosition.size() == tempSize));

    return (notEmpty && equalSize);
}

void DetectorPositionData::printValidation()
{
    bool notEmpty = ((detectorNumber.size() > 0) &&
                     (runNumber.size() > 0) &&
                     (xPosition.size() > 0) &&
                     (yPosition.size() > 0) &&
                     (zPosition.size() > 0));
    
    int tempSize = detectorNumber.size();
    bool equalSize = ((runNumber.size() == tempSize) &&
                      (xPosition.size() == tempSize) &&
                      (yPosition.size() == tempSize) &&
                      (zPosition.size() == tempSize));
    if(notEmpty)
    {
        std::cout << "There must be at least one entry in each column" << std::endl;
    }
    
    if(equalSize)
    {
        std::cout << "Each column must have the same number of entries" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const DetectorPositionData& dpd)
{
    os << "| Detector Number | Run Number | X Position | Y Position | Z Position |" << std::endl;
    os << "|-----------------|------------|------------|------------|------------|" << std::endl;
    
    int size = dpd.detectorNumber.size();
    
    for(int i=0; i<size; ++i)
    {
        os <<  "| " << std::setw(15) << dpd.detectorNumber[i];
        os << " | " << std::setw(10) << dpd.runNumber[i];
        os << " | " << std::setw(10) << std::setprecision(1) << dpd.xPosition[i];
        os << " | " << std::setw(10) << std::setprecision(1) << dpd.yPosition[i];
        os << " | " << std::setw(10) << std::setprecision(1) << dpd.zPosition[i];
        os << " |";
    }
    
    return os << "|-----------------|------------|------------|------------|------------|";
}
