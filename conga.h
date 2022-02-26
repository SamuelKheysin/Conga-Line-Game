#ifndef CONGA_H
#define CONGA_H

#include <iostream>
#include "zombie.h"
#include "node.h"
#include "linkedlist.h"    

using namespace std;

class Conga
{
public:
    Conga();
    ~Conga();

    void Play(int);

private:
    LinkedList<Zombie> zombies;

    void actionEngine(Zombie &);
    void actionCaboose(Zombie &);
    void actionJump(Zombie &);
    void actionOut(Zombie &);
    void actionDone(Zombie &);
    void actionBrains(Zombie &);
    void actionRainbowBrains(Zombie &);
};

#endif // CONGA_H
