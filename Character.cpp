#include "Character.h"
using namespace std;

//default constructor
Character::Character(){
  name = "";
  race = "";
  health = 100;
  level = 0;
}

void Character::setName(string _name) {
  name = _name;
}

void Character::setRace(string _race) {
  race = _race;
}

void Character::setHealth(int h) {
  health = h;
}

string Character::getName() {
  return name;
}

string Character::getRace() {
  return race;
}

int Character::getLevel() {
  return level;
}

int Character::getHealth() {
  return health;
}
