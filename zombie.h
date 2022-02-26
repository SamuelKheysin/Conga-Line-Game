#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>  

using namespace std;

class Zombie {
public:
    Zombie();
    Zombie(char);
    Zombie(const Zombie &);
    ~Zombie();

    void SetColor(char color);
    char GetColor();

    bool operator == (Zombie & zombie);
    friend ostream & operator << (ostream &, const Zombie &);

private:
    char color;
};

#endif // ZOMBIE_H
