//============================================================================
// Name        : DynamicGameMapModule.cpp
// Author      : 
// Version     :
// Copyright   : Game Studio Proprietary
// Description : Dynamic 2D Matrix Game Map Allocation and Analytics
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(0)));

    int R, C;
    cout << "Enter number of rows (R): ";
    cin >> R;
    cout << "Enter number of columns (C): ";
    cin >> C;


    int** gameMap = new int*[R];
    for (int i = 0; i < R; i++) {
        gameMap[i] = new int[C];
    }


    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            gameMap[i][j] = rand() % 5;
        }
    }


    cout << "\n===== GAME MAP (" << R << " x " << C << ") =====" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << " " << gameMap[i][j];
        }
        cout << endl;
    }


    cout << "Legend: 0=Grass 1=Water 2=Mountain 3=Forest 4=Dungeon" << endl;

    //  Find and print the count of each tile type
    int grassCount = 0;
    int waterCount = 0;
    int mountainCount = 0;
    int forestCount = 0;
    int dungeonCount = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            switch (gameMap[i][j]) {
                case 0: grassCount++; break;
                case 1: waterCount++; break;
                case 2: mountainCount++; break;
                case 3: forestCount++; break;
                case 4: dungeonCount++; break;
            }
        }
    }

    cout << "Tile Count:" << endl;
    cout << " Grass : " << grassCount << endl;
    cout << " Water : " << waterCount << endl;
    cout << " Mountain : " << mountainCount << endl;
    cout << " Forest : " << forestCount << endl;
    cout << " Dungeon : " << dungeonCount << endl;


    for (int i = 0; i < R; i++) {
        delete[] gameMap[i];
    }
    delete[] gameMap;

    return 0;
}
