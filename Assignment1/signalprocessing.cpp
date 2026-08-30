/*
 * signalprocessing.cpp
 *
 *  Created on: 28-Aug-2026
 *      Author: Vaishnavi
 */


#include <iostream>
#include <cmath>
using namespace std;

double computeRMS(double* signal, int n){
// Returns sqrt( sum of (each element squared) / n
double sum=0;
double* ptr = signal;

for(int i=0; i<n; i++)
{
sum = sum + (*ptr)*(*ptr);
ptr++;
}

return sqrt(sum/n);
}

void normalise(double* signal, int n){
// Divides every element by the max absolute value in the array (in-place)

double maxabs=0;
double* ptr=signal;

for(int i=0;i<n; i++){
	if(fabs(*ptr)>maxabs){

	maxabs = fabs(*ptr);
	}
 ptr++;
}

ptr= signal;

for(int i=0; i<n; i++){

	*ptr =*ptr/maxabs;
	ptr++;
}
}

int countZeroCrossings(double* signal, int n){
// Returns count of positions where adjacent elements have opposite signs
int count= 0;
double* ptr= signal;


for(int i=0;i<n;i++){
  if((count>0 && (count+1)<0) ||
		  (*ptr < 0 && *(ptr + 1) > 0)){

count++;

		  }
  ptr++;

}

return count;
}

void applyGain(double* signal, int n, double gainFactor)
// Multiplies every element by gainFactor (in-place)


{
    double* ptr = signal;

    for (int i = 0; i < n; i++)
    {
        *ptr = *ptr * gainFactor;
        ptr++;
    }
}

int main(){

double signal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};
	int n= 7;
	cout<<"Original signal: ";
	for(int i=0;i<n; i++){
		cout<<signal[i]<<" ";

	}
	double rms = computeRMS(signal, n);

	cout<<rms<<endl;





	 normalise( signal , n);

	 cout<<"After normalise: ";

	 for(int i=0;i<n; i++){
		 cout<<signal[i]<<" ";

	 }
cout<<endl;



	 countZeroCrossings(signal, n);
	 cout<<"After zerocrosssings: " <<" ";

	 for(int i=0; i<n; i++){

		 cout<<signal[i]<<" ";
	 }

	 cout<<endl;

	 applyGain(signal, n, 2.0);

	     cout << "After Gain: ";

	     for (int i = 0; i < n; i++)
	     {
	         cout << signal[i] << " ";
	     }

	     cout << endl;

	return 0;
}
