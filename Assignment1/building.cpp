#include <iostream>
#include <iomanip> // This gives us 'setprecision' to clean up decimals

using namespace std;

int main() {
    // 1. Create a 3x3 grid (2D Array) for 3 floors and 3 rooms per floor
    double building[3][3];

    cout << "Enter temperatures for all 9 rooms (Floor by Floor, Room 1 to 3):" << endl;

    // Read user inputs using nested loops (a loop inside a loop)
    for (int f = 0; f < 3; f++) {
        for (int r = 0; r < 3; r++) {
            cin >> building[f][r];
        }
    }

    // --- REQUIREMENT 2: Display the formatted table ---
    cout << "\n\tRoom1\tRoom2\tRoom3" << endl;
    cout << fixed << setprecision(1); // Force numbers to show 1 decimal point

    for (int f = 0; f < 3; f++) {
        cout << "Floor " << (f + 1) << "  : ";
        for (int r = 0; r < 3; r++) {
            cout << building[f][r] << "\t"; // '\t' jumps like a Tab key
        }
        cout << endl; // Drops down to a clean new line for the next floor
    }

    // --- Create Tracking Variables for Requirements 3, 4, and 5 ---
    double max_temp = -999.0; // Start super low so any room resets it
    int hot_floor_idx = 0;
    int hot_room_idx = 0;

    double highest_floor_avg = -999.0; // Start low to track the warmest floor average
    int hottest_floor_num = 1;

    int warning_count = 0; // Simple clicker to count problem rooms

    // --- LOOP THROUGH THE GRID TO COMPUTE THE ANALYSIS ---
    for (int f = 0; f < 3; f++) {
        double floor_sum = 0.0; // Clears to zero EVERY time we move to a new floor

        for (int r = 0; r < 3; r++) {
            double current_temp = building[f][r];

            // Requirement 3: Is this specific room the hottest one so far?
            if (current_temp > max_temp) {
                max_temp = current_temp; // Save the value
                hot_floor_idx = f;       // Save the floor index coordinate
                hot_room_idx = r;        // Save the room index coordinate
            }

            // Requirement 5: Is this room at or above the warning limit (30°C)?
            if (current_temp >= 30.0) {
                warning_count = warning_count + 1; // Click! Add 1 to the count
            }

            // Accumulate the room temp to calculate this floor's total sum
            floor_sum = floor_sum + current_temp;
        }

        // Requirement 4: Calculate the average for the current floor
        double current_floor_avg = floor_sum / 3.0;

        // Is this floor's average higher than any previous floor average?
        if (current_floor_avg > highest_floor_avg) {
            highest_floor_avg = current_floor_avg; // Save the record average
            hottest_floor_num = f + 1;             // Convert 0-index to actual Floor (1, 2, or 3)
        }
    }

    // --- FINAL REPORT OUTPUT FOR THE MANAGER ---
    cout << fixed << setprecision(1); // Set 1 decimal point for room temperature
    cout << "Hottest Room  : Floor " << (hot_floor_idx + 1)
         << ", Room " << (hot_room_idx + 1) << "  →  " << max_temp << "°C" << endl;

    cout << "Hottest Floor : Floor " << hottest_floor_num
         << "  (avg " << setprecision(2) << highest_floor_avg << "°C)" << endl; // 2 decimals for average

    cout << "Rooms at WARNING or above : " << warning_count << endl;

    return 0;
}
