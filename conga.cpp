#include <math.h>
#include "conga.h"

Conga::Conga() {
    // Run a Rainbow Brains!
    Zombie zombie;
    actionRainbowBrains(zombie);     
    // Run a random number (2~5) of Brains
    int count = rand() % 4 + 2;
    for (int i = 0; i < count; i++) {
        Zombie zombie;
        actionBrains(zombie);
    }
}

Conga::~Conga() {
    zombies.Empty();
}

void Conga::Play(int rounds) {
    // play round by round
    for (int i = 0; i < rounds; i++) {
        // print round
        cout << endl << endl << "Round: " << i << endl;
        cout << "The Zombie Party keeps on groaning!" << endl;
        // generate a random action
        int action = rand() % 7;
        // generate a random zombie
        Zombie zombie;
        // print list before action
        zombies.PrintList();
        // perform action
        switch (action) {
        case 0:
            cout << zombie.GetColor() << " zombie jumps in the front of the line! (ENGINE!)" << endl;
            actionEngine(zombie);
            break;
        case 1:
            cout << zombie.GetColor() << " zombie pulls up the rear! (CABOOSE!)" << endl;
            actionCaboose(zombie);
            break;
        case 2:
            cout << zombie.GetColor() << " zombie sneaks into the line! (JUMP IN THE LINE!)" << endl;
            actionJump(zombie);
            break;
        case 3:
            cout << zombie.GetColor() << " zombie has gone with its friends! (EVERYONE OUT!)" << endl;
            actionOut(zombie);
            break;
        case 4:
            cout << zombie.GetColor() << " zombie takes out the first match in the line! (YOU'RE DONE!)" << endl;
            actionDone(zombie);
            break;
        case 5:
            cout << zombie.GetColor() << " zombie brings its friends to the party! (BRAINS!)" << endl;
            actionBrains(zombie);
            break;
        case 6:
            cout << zombie.GetColor() << " zombie brought a whole party itself! (RAINBOW BRAINS!)" << endl;
            actionRainbowBrains(zombie);
            break;
        }
        // print list after action
        cout << "The conga line is now:" << endl;
        zombies.PrintList();
        // every 5 rounds, remove the head and tail
        if (i % 5 == 4) {
            cout << endl << "Removing head and tail zombies." << endl;
            zombies.RemoveFromFront();
            zombies.RemoveFromEnd();
            zombies.PrintList();
        }
        // check if the list is empty
        if (zombies.Length() == 0) {
            cout << "The party is over." << endl;
            return;
        }

    }
}

void Conga::actionEngine(Zombie & zombie) {
    // add to the front
    zombies.AddToFront(zombie);
}

void Conga::actionCaboose(Zombie & zombie) {
    // add to the end
    zombies.AddToEnd(zombie);
}

void Conga::actionJump(Zombie & zombie) {
    // insert at a random position X
    int X = rand() % zombies.Length();
    zombies.AddAtIndex(zombie, X);
}

void Conga::actionOut(Zombie & zombie) {
    // remove all matching zombies
    zombies.RemoveAllOf(zombie);
}

void Conga::actionDone(Zombie & zombie) {
    // remove the first matching zombie
    zombies.RemoveTheFirst(zombie);
}

void Conga::actionBrains(Zombie & zombie1) {
    // create 2 matching zombies
    Zombie zombie2(zombie1);
    Zombie zombie3(zombie1);
    // add one to the front
    zombies.AddToFront(zombie1);
    // add one to the end
    zombies.AddToEnd(zombie2);
    // add one to the middle
    zombies.AddAtIndex(zombie3, zombies.Length() / 2);
}

void Conga::actionRainbowBrains(Zombie & zombie) {
    // create 6 different zombies
    Zombie zombieR('R');
    Zombie zombieY('Y');
    Zombie zombieG('G');
    Zombie zombieB('B');
    Zombie zombieM('M');
    Zombie zombieC('C');
    // add this zombie to the front
    zombies.AddToFront(zombie);
    // add 6 zomies to the end
    zombies.AddToEnd(zombieR);
    zombies.AddToEnd(zombieY);
    zombies.AddToEnd(zombieG);
    zombies.AddToEnd(zombieB);
    zombies.AddToEnd(zombieM);
    zombies.AddToEnd(zombieC);
}
