#include "Wizard.h"

Wizard::Wizard():Character(){
  mana = 100;
  spellsList[0].sName = "Fire-Ball";
  spellsList[0].damage = 15;
  spellsList[0].cost = 20;

  spellsList[1].sName = "Frost-Bolt";
  spellsList[1].damage = 5;
  spellsList[1].cost = 5;

  spellsList[2].sName = "Earthquake";
  spellsList[2].damage = 25;
  spellsList[2].cost = 40;

  numSpells = 0;
  round = 2;
}

void Wizard::attack(Character* victim) {
  //generate random number for random critical attack feature
  srand(time(0));
  int critical = rand()%6;
  bool able = true;

  //make sure player has enough mana for currently selected weapon
  if (this->mana < 5) {
    cout << "Too weak for any attack, rest this round.";
    able = false;
    this->mana += 10;
  }
  else if (this->mana < this->spellsList[numSpells].cost) {
    while (this->mana < this->spellsList[numSpells].cost) {
      cout << endl << "Mana too low, select another spell" << endl << endl;
      equipAttack();
    }
  }
  //adjust health according to spell damage and whether its a critical hit
  if (able) {
    int h = victim->getHealth();
    if (critical == 2) {
      cout << endl << "Critical hit!" << endl;
      cout << "   +10 damage" << endl;
      cout << "   " << (this->spellsList[numSpells].damage + 10) << " total damage" << endl << endl;
      h -= ((this->spellsList[numSpells].damage) + 10);
    }
    else {
      h -= this->spellsList[numSpells].damage;
      cout << "   " << this->spellsList[numSpells].damage << " total damage" <<endl << endl;
    } 
    victim->setHealth(h);
    //adjust mana according to weapon cost
    this->mana -= this->spellsList[numSpells].cost;

    this->level += 1;
    if (this->level % 4 == 0) {
      cout << "Leveled up!" << endl << "   +10 health" << endl << "   +5 damage all weapons" << endl;
      this->health += 10;
      for (int i = 0; i < 3; i++) {
        this->spellsList[i].damage += 5;
      }
    }
    if (round == 0) round = 2;
    else {
      this->mana += 10;
      round--;
    }
    this->printStats();
    victim->printStats();
  }
}

void Wizard::printStats() {
  cout << "~PLAYER NAME: " << name << endl;
  cout << "   HP: " << health << endl;
  cout << "   Mana: " << mana << endl;
  cout << "   Level: " << level << endl;
  cout << " Active Weapon: " << spellsList[numSpells].sName << endl;
  cout << "   Damage: " << spellsList[numSpells].damage << endl;
  cout << "   Cost: " << spellsList[numSpells].cost << endl << endl;
}

void Wizard::equipAttack() {
  bool changed = false;
  string uInput;
  for(int i = 0; i < 3; i++) {
    cout << spellsList[i].sName << endl << "   Damage: " << spellsList[i].damage << endl << "   Cost: " << spellsList[i].cost << endl;
  }
  while (!changed){
    cout << "Select spell" << endl;
    cin >> uInput;
    for(int i = 0; i<3; i++) {
      if (uInput == spellsList[i].sName) {
        cout << endl << spellsList[i].sName << " selected";
        numSpells = i;
        changed = true;
      }
    }
    if (!changed) cout << "Spell not found." << endl;
  }
}

void Wizard::setEnergy(int energy) {
  mana = energy;
}

int Wizard::getEnergy() {
  return mana;
}

void Wizard::setLevel(int l) {
  level = l;

  if (level >= 4) {
    int lvlUps = level / 4;
    for (int i = 0; i < lvlUps; i++) {
      for (int j = 0; j < 3; j++) {
        this->spellsList[j].damage += 5;
      }
    }
  }
}
