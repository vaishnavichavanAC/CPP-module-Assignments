//============================================================================
// Name        : GameEngineEntityModule.cpp
// Author      : Vaishnavi Chavan
// Version     :
// Copyright   : Game Studio Proprietary
// Description : Game Object Entity Module with Method Chaining
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class Entity {
private:
    string name;
    int health;
    int level;
    string type;

public:

    Entity& setName(const string& name) {
        this->name = name;
        return *this;
    }

    Entity& setHealth(int health) {
        this->health = health;
        return *this;
    }

    Entity& setLevel(int level) {
        this->level = level;
        return *this;
    }

    Entity& setType(const string& type) {
        this->type = type;
        return *this;
    }



    string getName() const { return name; }
    int getHealth() const { return health; }
    int getLevel() const { return level; }
    string getType() const { return type; }



    void displayInfo() const {
        cout << "[Entity Profile] " << name << " (" << type << ")"
             << " | Level: " << level
             << " | Health: " << health << endl;
    }
};

int main() {
    cout << "=== INITIALIZING GAME ENTITIES (Method Chaining) ===\n" << endl;

    Entity player, enemy, item;


    player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
    enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
    item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");


    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();

    cout << "\n====================================================" << endl;
    return 0;
}
