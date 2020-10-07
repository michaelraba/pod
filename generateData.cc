#include<iostream>
#include<cstring>
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


  for(int t=0; t<timeStep; ++t) // t time lool
    {

   // begin digit counter 
    int num, temp;
    num = t;
    int count = 0;
    // Store to temporary variable.
    temp = num;
    while(temp != 0) {

        // Increment counter
        count++;
        // Remove last digit of 'temp'
        temp /= 10;
    }
    //cout << endl << "Total digits in " << num << " : "  << count;
   // end digit counter 

int numZeros = 4 - count;
std::string zeroString  ;
for(int i =0 ; i<4- count  ; ++i  )
{
zeroString = zeroString + '0';
}
//cout<<"theZeroString sei "<<zeroString<<endl;

// declare fileNameFortran
string fileNameFortran="";
string fileNameMatlab="";

if (t ==0)
{
//    cout<<"zeroCase......"<<endl;
    fileNameFortran = "fft_c0001_t_0000.dat";
    fileNameMatlab = "cpod_c_001_f_0000.dat";
//    cout<<"dat fileNameFortran is "<< fileNameFortran<<endl;
}
else
{
    fileNameFortran = "fft_c0001_t_"+ zeroString  + std::to_string(t) +".dat";

// cpod_c001_f_0000.dat";
    fileNameMatlab = "cpod_c_001_f_"+ zeroString  + std::to_string(t) +".dat";


//    cout<<"dat fileNameFortran is "<< fileNameFortran<<endl;
}

// open filestream for fortran
  ofstream podDataFortran;

// open filestream for matlab
  ofstream podDataMatlab;

  podDataFortran.open(fileNameFortran);
  podDataMatlab.open(fileNameMatlab);
  for(int i=1; i<nPoints; ++i) // i is spatialVariation
    {
      podDataFortran  <<
	    i <<" " << sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)+ 2*sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi) <<endl;
	     // sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)+ 2*sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi) <<endl;
	      
	   //   <<""<<endl;

      // without index
// podDataFortran <<  sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)+ 2*sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)<<" 0 0 0"<<endl;
// podDataFortran <<  sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)+ 2*sin((i-1)/nPoints*4*pi)* cos((t-1)/(timeStep)*2*pi)<<" 0 0"<<endl;

    } // i loop endFortranWrite

//begin Matlabwrite

  for(int i=1; i<nPoints; ++i) // i is spatialVariation
    {
      podDataMatlab  <<
	    i <<" " << sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)+ 2*sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi) <<endl;
	     // sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)+ 2*sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi) <<endl;
	      
	   //   <<""<<endl;

      // without index
// podDataMatlab <<  sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)+ 2*sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)<<" 0 0 0"<<endl;
// podDataMatlab <<  sin((i-1)/nPoints*2*pi)* cos((t-1)/(timeStep)*2*pi)+ 2*sin((i-1)/nPoints*4*pi)* cos((t-1)/(timeStep)*2*pi)<<" 0 0"<<endl;

    } // i loop



  podDataFortran.close();
  podDataMatlab.close();
    } // t loop
  return 0; 
}
