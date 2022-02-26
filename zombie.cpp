#include <math.h>
#include "zombie.h"

Zombie::Zombie() {
    // Create a random colored zombie
    int number = rand() % 6;
    switch (number) {   
    case 0:
        color = 'R';
        break;
    case 1:
        color = 'Y';
        break;
    case 2:
        color = 'G';
        break;
    case 3:
        color = 'B';
        break;
    case 4:
        color = 'M';
        break;
    case 5:
        color = 'C';
        break;
    }
}

Zombie::Zombie(char color) {
    this->color = color;
}

Zombie::Zombie(const Zombie & zombie) {
    this->color = zombie.color;
}

Zombie::~Zombie() {
    // do nothing
}

void Zombie::SetColor(char color) {
    this->color = color;
}

char Zombie::GetColor() {
    return this->color;
}

bool Zombie::operator == (Zombie & zombie) {
    return this->color == zombie.color;
}

ostream & operator << (ostream & out, const Zombie & zombie) {
    out << " [" << zombie.color << "]";
    return out;
}
