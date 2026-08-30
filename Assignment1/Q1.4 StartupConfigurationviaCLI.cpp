//============================================================================
// Name        : 4.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]){

    if (argc != 4)
    {
        cout << "Usage : ./sensor_monitor "
             << "<warn_threshold> "
             << "<critical_threshold> "
             << "<num_readings>" << endl;

        cout << "Error : Missing arguments." << endl;

        return 1;
    }

    double warnThreshold = atof(argv[1]);
    double criticalThreshold = atof(argv[2]);
    int numReadings = atoi(argv[3]);

    if (warnThreshold >= criticalThreshold)
    {
        cout << "Error : Warn threshold must be less than "
             << "critical threshold." << endl;

        return 1;
    }


    if (numReadings < 1 || numReadings > 500)
    {
        cout << "Error : Number of readings must be "
             << "between 1 and 500." << endl;

        return 1;
    }

    cout << "Config : Warn=" << warnThreshold
         << "Â°C Critical=" << criticalThreshold
         << "Â°C Readings=" << numReadings << endl;

    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;


    for (int i = 0; i < numReadings; i++)
    {
        int temperature = rand() % 70;

        if (temperature < warnThreshold)
        {
            normal++;
        }
        else if (temperature < criticalThreshold)
        {
            warning++;
        }
        else if (temperature < 60)
        {
            critical++;
        }
        else
        {
            shutdown++;
        }
    }

    cout << "Results : Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << critical
         << " Shutdown:" << shutdown << endl;

    return 0;
}
