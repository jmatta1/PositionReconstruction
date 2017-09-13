#include"DetectorSet.h"

namespace Reconstruction
{

static const float FourPi = 12.5663706f;

DetectorSet::DetectorSet(int numPos, int numEnBin):
    posCount(numPos), enBinCount(numEnBin)
{
    detCoords = new float[CoordSize*posCount];
    for(int i=0; i<posCount; ++i)
    {
        detCoords[CoordSize*i+0] = 0.0f;
        detCoords[CoordSize*i+1] = 0.0f;
        detCoords[CoordSize*i+2] = 0.0f;
        detCoords[CoordSize*i+3] = 0.0f;
    }
    posSpectra = new float*[enBinCount];
    centerEn = new float[enBinCount];
    for(int i=0; i<enBinCount; ++i)
    {
        centerEn[i] = 0.0f;
        posSpectra[i] = new float[posCount];
        float* temp = posSpectra[i];
        for(int j=0; j<numPos; ++j)
        {
            temp[j] = 0.0f;
        }
    }
}

DetectorSet::~DetectorSet()
{
    delete[] detCoords;
    for(int i=0; i<enBinCount; ++i)
    {
        delete[] posSpectra[i];
    }
    delete[] centerEn;
    delete[] posSpectra;
}


float DetectorSet::calculateDetectorWeight(int posNum, float* srcPt, float intensity) const
{//calculates the approximation of the intensity falling on each detector for a pt source at a given location
    int offset = CoordSize*posNum;
    
    //Handle the X-Coordinate
    float temp = (srcPt[0] - detCoords[offset + 0]);
    float area = 0.0f;
    if((temp > 1.125f) || (temp < -1.125f))
    { // positive or negative x side
        area += (4.25f*16.25f);
    }
    float sum = (temp*temp);
    
    //Handle the Y-Coordinate
    temp = (srcPt[1] - detCoords[offset + 1]);
    if((temp > 8.125f) || (temp < -8.125f))
    { // positive or negative y side
        area += (2.25f*4.25f);
    }
    sum += (temp*temp);
    
    //Handle the Z-Coordinate
    temp = (srcPt[2] - detCoords[offset + 2]);
    if((temp > 2.125f) || (temp < -2.125f))
    { // positive or negative z side
        area += (2.25f*16.25f);
    }
    sum += (temp*temp);
    return ((intensity*area)/(FourPi*sum));
}

}
