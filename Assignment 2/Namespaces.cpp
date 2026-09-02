//============================================================================
// Name        : GameEngineNamespaceModule.cpp
// Author      :
// Version     :
// Copyright   : Game Studio Proprietary
// Description : Namespace Isolation for Physics and GameMath Utilities
//============================================================================

#include <iostream>

using namespace std;


namespace Physics {

    double clamp(double val, double min, double max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }


    double lerp(double a, double b, double t) {
        return a + t * (b - a);
    }
}


namespace GameMath {

    int clamp(int val, int min, int max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }


    double lerp(double a, double b, double t) {
        return a + t * (b - a);
    }
}

int main() {
    cout << "=== TESTING EXPLICIT NAMESPACE SCOPING ===\n" << endl;


    double rawVelocity = 145.8;
    double safeVelocity = Physics::clamp(rawVelocity, 0.0, 100.0);
    cout << "Physics Velocity Clamp (145.8 bound to 0-100) : " << safeVelocity << endl;

    int currentHealth = -15;
    int boundedHealth = GameMath::clamp(currentHealth, 0, 100);
    cout << "GameMath Health Pool Clamp (-15 bound to 0-100) : " << boundedHealth << endl;


    cout << "\n=== TESTING LIMITED BLOCK SCOPE NAMESPACE ===\n" << endl;


    {

        using namespace GameMath;


        double animatedUIPosition = lerp(10.0, 50.0, 0.5);
        cout << "[Inside Block Scope] GameMath lerp output (0.5 progress) : " << animatedUIPosition << endl;

        int itemLevel = clamp(12, 1, 10);
        cout << "[Inside Block Scope] GameMath level clamp (12 bound to 1-10): " << itemLevel << endl;
    }

    double physicsLerp = Physics::lerp(0.0, 100.0, 0.25);
    cout << "\n[Back in Main Scope] Explicit Physics lerp output           : " << physicsLerp << endl;

    return 0;
}
