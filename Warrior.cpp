#include "Warrior.h"
#include "Character.h"

Warrior::Warrior():Character(){
  stamina = 100;
  weaponsList[0].wName = "Sword";
  weaponsList[0].damage = 15;
  weaponsList[0].cost = 20;

  weaponsList[1].wName = "Bow-and-Arrow";
  weaponsList[1].damage = 5;
  weaponsList[1].cost = 5;

  weaponsList[2].wName = "Halberd";
  weaponsList[2].damage = 25;
  weaponsList[2].cost = 40;

  activeWeapon = 0;
  round = 2;
}

void Warrior::attack(Character* victim) {
  //generate random number for random critical attack feature
  srand(time(0));
  int critical = rand()%6;
  bool able = true;

  //make sure player has enough stamina for currently selected weapon
  if (this->stamina < 5) {
    cout << "Too weak for any attack, rest this round.";
    able = false;
    this->stamina += 10;
  }
  else if (this->stamina < this->weaponsList[activeWeapon].cost) {
    while (this->stamina < this->weaponsList[activeWeapon].cost) {
      cout << endl << "Stamina too low, select another weapon:" << endl << endl;
      equipAttack();
    }
  }

  //adjust health according to weapon damage and whether its a critical hit
  if (able) {
    int h = victim->getHealth();
    if (critical == 2) {
      cout << endl << "Critical hit!" << endl;
      cout << "   +10 damage" << endl;
      cout << "   " << this->weaponsList[activeWeapon].damage + 10 << " total damage" << endl << endl;
      h -= ((this->weaponsList[activeWeapon].damage) + 10);
    }
    else {
      h -= this->weaponsList[activeWeapon].damage;
      cout << "   " << this->weaponsList[activeWeapon].damage << " total damage" << endl << endl;
    } 
    victim->setHealth(h);

    //adjust stamina according to weapon cost
    this->stamina -= this->weaponsList[activeWeapon].cost;

    //increase level
    this->level += 1;
    if (this->level % 4 == 0) {
      cout << "Leveled up!" << endl << "   +10 health" << endl << "   +5 damage all weapons" << endl;
      this->health += 10;
      for (int i = 0; i < 3; i++) {
        this->weaponsList[i].damage += 5;
      }
    }
    if (round == 0) round = 2;
    else {
      this->stamina += 10;
      round--;
    }
    this->printStats();
    victim->printStats();
  }
}

void Warrior::printStats() {
  cout << "~PLAYER NAME: " << name << endl;
  cout << "   HP: " << health << endl;
  cout << "   Stamina: " << stamina << endl;
  cout << "   Level: " << level << endl;
  cout << " Active Weapon: " << weaponsList[activeWeapon].wName << endl;
  cout << "   Damage: " << weaponsList[activeWeapon].damage << endl;
  cout << "   Cost: " << weaponsList[activeWeapon].cost << endl << endl;
}

void Warrior::equipAttack() {
  bool changed = false;
  string uInput;
  for(int i = 0; i < 3; i++) {
    cout << "~" << weaponsList[i].wName << endl << "   Damage: " << weaponsList[i].damage << endl << "   Cost: " << weaponsList[i].cost << endl;
  }
  while (!changed){
    cout << "Select weapon" << endl;
    cin.ignore();
    getline(cin, uInput);
    for(int i = 0; i<3; i++) {
      if (uInput == weaponsList[i].wName) {
        cout << endl << weaponsList[i].wName << " selected";
        activeWeapon = i;
        changed = true;
      }
    }
    if (!changed) cout << "Weapon not found." << endl;
  }
}

void Warrior::setEnergy(int energy) {
  stamina = energy;
}

int Warrior::getEnergy() {
  return stamina;
}

void Warrior::setLevel(int l) {
  level = l;

  if (level >= 4) {
    int lvlUps = level / 4;
    for (int i = 0; i < lvlUps; i++) {
      for (int j = 0; j < 3; j++) {
        this->weaponsList[j].damage += 5;
      }
    }
  }
}
