#include <iostream>
#include <string>
using namespace std;


//PART A
//This part uses the this pointer and method chaining.


class Entity
{
private:
    string name;
    int health;
    int level;
    string type;

public:

    Entity& setName(const string& n)
    {
        this->name = n;
        return *this;
    }

    Entity& setHealth(int h)
    {
        this->health = h;
        return *this;
    }

    Entity& setLevel(int l)
    {
        this->level = l;
        return *this;
    }

    Entity& setType(const string& t)
    {
        this->type = t;
        return *this;
    }

    string getName() const
    {
        return name;
    }

    int getHealth() const
    {
        return health;
    }

    int getLevel() const
    {
        return level;
    }

    string getType() const
    {
        return type;
    }

    void displayInfo() const
    {
        cout << "\nName   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Level  : " << level << endl;
        cout << "Type   : " << type << endl;
    }
};


//PART B =================
//This part uses namespaces.
//Physics and GameMath both have clamp() and lerp().
//Clamp means keeping a value inside a fixed range.
//Lerp means Linear Interpolation.


namespace Physics
{
    double clamp(double value, double minimum, double maximum)
    {
        if (value < minimum)
            return minimum;

        if (value > maximum)
            return maximum;

        return value;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


namespace GameMath
{
    int clamp(int value, int minimum, int maximum)
    {
        if (value < minimum)
            return minimum;

        if (value > maximum)
            return maximum;

        return value;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


//PART C =================
// This part creates a dynamic 2D array using int**.


int main()
{
    // PART B

    Entity player, enemy, item;

    player.setName("Archer")
          .setHealth(100)
          .setLevel(10)
          .setType("Player");

    enemy.setName("Orc")
         .setHealth(60)
         .setLevel(5)
         .setType("Enemy");

    item.setName("HealthPotion")
        .setHealth(0)
        .setLevel(1)
        .setType("Item");

    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();


    // PART B

    cout << "\nPhysics Clamp: "
         << Physics::clamp(120.5, 0.0, 100.0) << endl;

    cout << "GameMath Clamp: "
         << GameMath::clamp(120, 0, 100) << endl;

    cout << "Physics Lerp: "
         << Physics::lerp(10, 20, 0.5) << endl;

    cout << "GameMath Lerp: "
         << GameMath::lerp(20, 40, 0.5) << endl;


    // PART B

    int rows, columns;

    cout << "\nEnter rows: ";
    cin >> rows;

    cout << "Enter columns: ";
    cin >> columns;

    int** map = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        map[i] = new int[columns];
    }

    cout << "\nEnter tile values (0-4):" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> map[i][j];
        }
    }

    cout << "\n===== GAME MAP =====" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << map[i][j] << " ";
        }

        cout << endl;
    }

    int count[5] = {0};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (map[i][j] >= 0 && map[i][j] <= 4)
            {
                count[map[i][j]]++;
            }
        }
    }

    cout << "\nLegend: 0=Grass 1=Water 2=Mountain 3=Forest 4=Dungeon"
         << endl;

    cout << "\nTile Count:" << endl;
    cout << "Grass    : " << count[0] << endl;
    cout << "Water    : " << count[1] << endl;
    cout << "Mountain : " << count[2] << endl;
    cout << "Forest   : " << count[3] << endl;
    cout << "Dungeon  : " << count[4] << endl;


    for (int i = 0; i < rows; i++)
    {
        delete[] map[i];
    }

    delete[] map;

    return 0;
}