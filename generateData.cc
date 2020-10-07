#include<iostream>
#include<cmath>
#include<fstream>
double pi =  M_PI;
using namespace std;
int main()
{
//  double nPoints=100;
  // double timeStep=10;
  double nPoints=100;
  double timeStep=101;
  string fileName_Number = "";
  int t=2;


  for(int t=0; t<timeStep; ++t) // t time lool
    {
  auto fileName = "fft_c0001_t_000" + std::to_string(t) +".dat";
  ofstream podData;
  podData.open(fileName);
  for(int i=1; i<nPoints; ++i) // i is spatialVariation
    {
podData <<  sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)+ 2*sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)<<" 0 0 0"<<endl;
// podData <<  sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)+ 2*sin((i-1)/nPoints*4*pi)* cos((t-1)/(timeStep)*2*pi)<<" 0 0"<<endl;

    } // i loop
  podData.close();
    } // t loop
  return 0; 
}
