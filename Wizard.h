#ifndef WIZARD_H
#define WIZARD_H
#include "Character.h"
using namespace std;

struct Spell {
  string sName;
  int damage;
  int cost;
};

class Wizard : public Character {
  public:
    Wizard();
    void equipAttack();
    void setEnergy(int);
    int getEnergy();
    void setLevel(int);

    void attack(Character*);
    void printStats();

  private:
    int mana;
    int numSpells;
    Spell spellsList[3];
    int round;

};

#endif
