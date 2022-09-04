#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>

using namespace std;

class Character {
  public:
    Character();
    void setName(string);
    void setRace(string);
    void setHealth(int);
    string getName();
    string getRace();
    int getLevel();
    int getHealth();

    virtual void printStats(){}
    //FIX ME: throws vtable error when uncommented ???
    virtual void setEnergy(int){}
    virtual int getEnergy() {return 0;}
    virtual void setLevel(int){}
    virtual void equipAttack(){}
    virtual void attack(Character*){}

  protected:
    string name;
    string race;
    int health;
    int level;
};

#endif
