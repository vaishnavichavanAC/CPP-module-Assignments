//============================================================================
// Name        : 5DroneNavigationUtilities.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <utility>

using namespace std;
inline double distanceBetween(double x1, double y1, double x2, double y2)
{
  return sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) );

}




inline double toRadians(double degrees){

return degrees * (M_PI / 180.0);

}


inline double clamp(double value, double minVal, double maxVal){

if (value < minVal)
    {
        return minVal;
    }
    else if (value > maxVal)
    {
        return maxVal;
    }
    else
    {
        return value;
    }
}
// Restrict value to [minVal, maxVal]





inline bool isInSafeZone(double x, double y,
                         double cx, double cy, double radius)
{
    double distanceSquared = pow(x - cx, 2) + pow(y - cy, 2);

    if (distanceSquared <= pow(radius, 2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() {

	double x1= 10;
	double y1 =20;
	double x2= 30;
	double y2 =40;
    double degrees=60;




	double res=distanceBetween(x1,y1,x2,y2);
	cout<<res<<endl;

	double result = toRadians(degrees);
	cout<<result<<endl;

	double result1 = clamp(15, 0, 10);
	cout << result1 << endl;


	bool val=isInSafeZone(3, 4, 0, 0, 5);
	cout<<val;

	return 0;
}
