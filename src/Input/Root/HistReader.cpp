#include"HistReader.h"
// includes for C system headers
// includes for C++ system headers
#include<sstream>
// includes from other libraries
#include<TFile.h>
#include<TH1.h>
// includes from this code
#include"Input/Data/DetectorPositionData.h"
#include"Reconstruction/DetectorSet.h"

namespace Input
{

Reconstruction::DetectorSet* HistReader::readPositionSpectra()
{
    TFile* inFile = new TFile(fileName.c_str());
    
    //first read the first histogram just to get the number of energy bins so
    //that we can construct the detector set
    buildSpecName(detPosData->detectorNumber[0], detPosData->runNumber[0]);
    TH1D* hist = (TH1D*)inFile->Get(specName.c_str());
    int loBin = hist->FindBin(minEn);
    int hiBin = hist->FindBin(maxEn);
    int numEnBins = (hiBin-loBin+1);
    //now construct the detector set
    int numRuns = detPosData->runNumber.size();
    Reconstruction::DetectorSet* output = new Reconstruction::DetectorSet(numRuns, numEnBins);
    //load the energy centers
    for(int j=loBin; j<=hiBin; ++j)
    {
        output->setEnergy(j-loBin, hist->GetBinCenter(j));
    }
    delete hist;
    //now load each histogram, set the position, and set the position spectra counts
    for(int i=0; i<numRuns; ++i)
    {
        buildSpecName(detPosData->detectorNumber[i], detPosData->runNumber[i]);
        hist = (TH1D*)inFile->Get(specName.c_str());
        //set the position for this particular position bin
        output->setPosition(i, detPosData->xPosition[i],
                            detPosData->yPosition[i], detPosData->zPosition[i]);
        for(int j=0; j < numEnBins; ++j)
        {
            output->setPosBin(i, j, hist->GetBinContent(j+loBin));
        }
        delete hist;
    }
    delete inFile;
    return output;
}

void HistReader::buildSpecName(int detNum, int runNum)
{
    std::ostringstream namer;
    namer << "Decomp_" << detNum << "_" << runNum;
    specName = namer.str();
}

}
