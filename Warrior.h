#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"
using namespace std;

struct Weapon {
  string wName;
  int damage;
  int cost;
};

class Warrior : public Character {
  public:
    Warrior();
    int getEnergy();
    void setEnergy(int);
    void setLevel(int);
    void equipAttack();
    void attack(Character*);
    void printStats();

  private:
    int stamina;
    int activeWeapon;
    Weapon weaponsList[3];
    int round;
};

#endif
