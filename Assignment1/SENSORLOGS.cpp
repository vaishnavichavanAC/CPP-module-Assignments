#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cout << "Readings entered : ";
    cin >> N;

    if (N < 1 || N > 100) {
        return 1;
    }

    double readings[100];

    for (int i = 0; i < N; i++) {
        cin >> readings[i];
    }

    int skipped = 0;
    cout << "Valid readings   : ";
    for (int i = 0; i < N; i++) {
        if (readings[i] < 0) {
            skipped = skipped + 1;
            continue;
        }

        cout << fixed << setprecision(1) << readings[i] << "  "; // To Print the valid reading with 1 decimal place
    }
    cout << "\nSkipped (errors) : " << skipped << endl;




    for (int i = 0; i < N; i++) {
        if (readings[i] < 0) {
            continue;
        }

        if (readings[i] >= 45.0) {
            cout << "First CRITICAL   : Index " << i << "  →  " << readings[i] << "°C" << endl;
            break;
        }
    }


    double min_val = 999.0;
    double max_val = -999.0;
    double sum = 0.0;
    int valid_count = 0;

    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    for (int i = 0; i < N; i++) {
        if (readings[i] < 0) {
            continue;
        }


        valid_count = valid_count + 1;
        sum = sum + readings[i];


        if (readings[i] < min_val) {
            min_val = readings[i];
        }


        if (readings[i] > max_val) {
            max_val = readings[i];
        }


        if (readings[i] >= 55.0) {
            shutdown = shutdown + 1;
        }
        else if (readings[i] >= 40.0) {
            critical = critical + 1;
        }
        else if (readings[i] >= 25.0) {
            warning = warning + 1;
        }
        else {
            normal = normal + 1;
        }
    }


    double average = sum / valid_count;


    cout << fixed << setprecision(1);
    cout << "Min : " << min_val << "°C    Max : " << max_val << "°C    ";

    cout << setprecision(2);
    cout << "Avg : " << average << "°C" << endl;

    cout << "Normal:" << normal << "   Warning:" << warning
         << "   Critical:" << critical << "   Shutdown:" << shutdown << endl;

    return 0;
}
