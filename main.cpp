#include "Character.h"
#include "Warrior.h"
#include "Wizard.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printTitle() {

cout << endl <<
"▄█ █░█ ▄█   █▀█ █░█ █ █▀▀ █▄▀   █▀▄▀█ ▄▀█ ▀█▀ █▀▀ █░█" << endl <<
"░█ ▀▄▀ ░█   ▀▀█ █▄█ █ █▄▄ █░█   █░▀░█ █▀█ ░█░ █▄▄ █▀█" << endl << endl;
cout << "             𝟏𝐯𝟏 𝐐𝐮𝐢𝐜𝐤 𝐌𝐚𝐭𝐜𝐡 - 2 Players" << endl << endl << endl;
}

void printMenu() {
  cout << "     .--.                 .--." << endl <<
"     (_ )-._.-=-._.-=-._.-(_ )" << endl <<
"     ( _)                 ( _)" << endl <<
"     (_ )   ~ New Game    (_ )" << endl <<
"     (_ )   ~ Load Game   (_ )" << endl <<
"     ( _)   ~ Quit Game   ( _)" << endl <<
"     ( _)                 ( _)" << endl <<
"     (_ )  New/Load/Quit  (_ )" << endl <<
"     ( _)                 ( _)" << endl <<
"     ( _)-._.-=-._.-=-._.-( _)" << endl <<
"     `--'                 `--'" << endl << endl;
}

void printWizard(){
  cout << endl << "                    ____ " << endl <<
"                  .'* *.'" << endl <<
"               __/_*_*(_" << endl <<
"              / _______ \\" << endl <<
"             _\\_)/___\(_/_ " << endl <<
"            / _((\\- -/))_ \\" << endl <<
"            \\ \\())(-)(()/ /" << endl <<
"             ' \\(((()))/ '" << endl <<
"            / ' \\)).))/ ' \\ " << endl <<
"           / _ \\ - | - /_  \\" << endl <<
"          (   ( .;''';. .'  )" << endl <<
"          _\\\"__ /    )\\ __\"/_" << endl <<
"            \\/  \\   ' /  \\/" << endl <<
"             .'  '...' ' )" << endl <<
"              / /  |  \\ \\" << endl <<
"             / .   .   . \\" << endl <<
"            /   .     .   \\" << endl <<
"           /   /   |   \\   \\" << endl <<
"         .'   /    b    '.  '." << endl <<
"     _.-'    /     Bb     '-. '-._" << endl <<
" _.-'       |      BBb       '-.  '-. " << endl <<
"(_______mrf(\\____.dBBBb._______/)____)" << endl << endl;
}
void printWarrior(){
  cout << endl << "  _,. " << endl << 
"    ,` -.)" << endl <<
"   ( _/-\\-._" << endl <<
"  /,|`--._,-^|            ," << endl <<
"  \\_| |`-._/||          ,'|" << endl <<
"    |  `-, / |         /  /" << endl <<
"    |     || |        /  /" << endl <<
"     `r-._||/   __   /  /" << endl <<
" __,-<_     )`-/  `./  /" << endl <<
"'  \\   `---'   \\   /  /" << endl <<
"    |           |./  /" << endl <<
"    /           //  /" << endl <<
"\\_/' \\         |/  /" << endl <<
" |    |   _,^-'/  /" << endl <<
" |    , ``  (\\/  /_" << endl <<
"  \\,.->._    \\X-=/^" << endl <<
"  (  /   `-._//^`" << endl <<
"   `Y-.____(__}" << endl <<
"    |     {__)" << endl <<
"          ()" << endl << endl;
}

void printActions(int i){
  cout << endl << "       _____________________" << endl <<
 "      / \\      Player " << i << "      \\." << endl <<
 "      \\_ |                    |." << endl <<
"        |      ~ Attack      |." << endl <<
"        |    ~ Print stats   |." << endl <<
"        | ~ Change weapon or |." << endl <<
"        |         spell      |." << endl <<
"        |     A/P/C/Quit     |." << endl <<
"        |    ________________|__" << endl <<
"         \\_/dc________________/." << endl << endl;

}

void printWinner(int i){
 cout << "     .-\"-._,-'_`-._,-'_`-._,-'_`-,_,-'_`-,_,-'_`-,_,-'_`-,." << endl <<
"   (  ,-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-<.>-'_,-~-} ;." << endl <<
"    \\ \\.'_>-._`-<_>-._`-<_>-._`-<_>-._`-<_>-._`-._~--. \\ ." << endl <<
"    /\\ \\/ ,-' `-._,-' `-._,-' `-._,-' `-._,-' `-._`./ \\ \\ ." << endl <<
"   ( (`/ /                                        `/ /.) ) . " << endl <<
"    \\ \\ / \\                                       / / \\ / ." << endl << 
"     \\ \\') )             Player " << i << "                ( (,\\ \\ ." << endl <<
"    / \\ / /                  wins!                \\ / \\ \\ ." << endl <<
"   (`dc / /                                        / /.) ) ." << endl <<
"    \\ \\ / \\       _       _       _       _       / / \\ /." << endl <<
"     \\ `.\\ `-._,-'_`-._,-'_`-._,-'_`-._,-'_`-._,-'_/,\\ \\ ." << endl <<
"    ( `. `,~-._`-<,>-._`-<,>-._`-<,>-._`-<,>-._`-=,' ,\\ \\ ." << endl <<
"     `. `'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,-<_>-'_,\"-' ; ." << endl <<
"       `-' `-._,-' `-._,-' `-._,-' `-._,-' `-._,-' `-.-' ." << endl << endl;

}

int main() {
  // declare variable to hold user responses
  string input = "";
  Character *player1;
  Character *player2;
  printTitle();
  ofstream save;
  ifstream load;
  // ask whether or not to play and continue the program
  printMenu();
  getline(cin, input);
  //if user inputs something other than given options (capitalized or not), loop unil a valid response is given
  while (input != "New" && input != "Load" && input != "Quit" && input != "new" && input != "load" && input != "quit") {
    cout << endl << "Invalid choice" << endl << endl;
    printMenu();
    cin >> input;
  }
  //if quit, exit program
  if (input=="Quit" || input=="quit") {
    return -1;
  }
  string filename;
  if(input=="Load" || input=="load") {
    cout << "file name?" << endl;
    cin >> filename;
    while (input != "Yes" && input != "yes") {
      cout << "file name: " << filename << endl;
      cout << "are you sure?" << endl;
      cin >> input;
      if (input == "no" || input == "No") {
        cout << "file name?" << endl;
        cin >> filename;
      }
    }
    load.open(filename);
    //Quit program if file does not exist
    if(!load.is_open()){
      cout << "File not found." << endl;
      return -1;
    }
    for (int i = 1; i<=2; i++) {
      //First input from file is character type
      //Initialize variables according to player number and type given
      load >> input;
      if ((input == "warrior" || input == "Warrior") && i == 1)
        player1 = new Warrior;
      else if ((input == "warrior" || input == "Warrior") && i == 2)
        player2 = new Warrior;
      else if ((input == "wizard" || input == "Wizard") && i == 1)
        player1 = new Wizard;
      else if ((input == "wizard" || input == "Wizard") && i == 2)
        player2 = new Wizard;

      //recieve and set name
      load.ignore();
      getline(load, input);
      if (i == 1) player1->setName(input);
      else if (i == 2) player2->setName(input);

      //recieve and set race
      load >> input;
      if (i == 1) player1->setRace(input);
      else if (i == 2) player2->setRace(input);
    }
    int values;
    int hp;
    int energy;
    while (!load.eof()) {
      load >> values;
      if (values == 1) {
        //recieve and set health
        load >> hp;
        player1->setHealth(hp);
        //recieve and set Energy (Stamina / Mana)
        load >> energy;
        player1->setEnergy(energy);
        //recieve and set Level
        load >> values;
        player1->setLevel(values);
      } else if (values == 2) {
        load >> values;
        player2->setHealth(values);
        //recieve and set Energy (Stamina / Mana)
        load >> values;
        player2->setEnergy(values);
        //recieve and set Level
        load >> values;
        player2->setLevel(values);
      }
    }
    save.open(input);
  }

  else if (input=="New" || input=="new") {
    //open new file with user input name;
    remove(filename.c_str());
    cout << "Save name: " << endl;
    cin >> input;
    cout << endl << "New save will be called " << input << endl;
    save.open(input);

    //declare variable to hold given character traits
    string traits = "";
    //loop twice to gather info for each player
    for (int i = 1; i <= 2; i++){
      //loop until valid response for character type is given
      while (input != "Warrior" && input != "Wizard" && input != "warrior" && input != "wizard") {
        cout << endl << "Player " << i << ", Choose your character: " << endl << "~ Warrior" << endl << "~ Wizard" << endl;
        cin >> input;
        // create character of specified type
        if(input == "Warrior" || input == "warrior") {
          printWarrior();
          if(i == 1) player1 = new Warrior;
          else player2 = new Warrior;
          //output into file character type
          save << input << endl;
        }
        else if (input == "Wizard" || input == "wizard") {
          printWizard();
          if (i==1) player1 = new Wizard;
          else player2 = new Wizard;
          //output into file character type
          save << input << endl;
        }
        else 
          cout << "invalid choice" << endl;
      }
      //get name
      cout << "Name your character: ";
      cin.ignore();
      getline(cin, traits);
      // confirm name, loop until valid response given
      while (input != "Yes" && input != "yes" && input != "confirm" && input != "Confirm") {
        if (input == "no" || input == "No") {
          cout << "Name your character: ";
          cin.ignore();
          getline(cin, traits);
          input = "";
        }
        else {
          cout << "Your character's name will be " << traits << "." << endl << "Are you sure? (Yes/No)" << endl;
          cin >> input;
        }
      }
      ////output into file character name
      save << traits << endl;

      //Sets chosen name
      if(i == 1) {
        player1->setName(traits);
        } else {
        player2->setName(traits);
      }

      //Get race
      cout << endl << "Choose your race: " << endl << "~ Human" << endl << "~ Elf" << endl << "~ Orc" << endl;
      cin >> input;

      //loop until valid response given
      while(input != "Human" && input != "human" && input != "Elf" && input != "elf" && input != "Orc" && input != "orc"){
        cout << endl << "Invalid response" << endl << endl << "Choose your race: " << endl << "~ Human" << endl << "~ Elf" << endl << "~ Orc" << endl;
        cin >> input;
      }
      //output into file character race
      save << input << endl;

      //Sets chosen race
      if(i==1) {
        player1->setRace(input);
        cout << endl << endl << "Base Stats" << endl;
        player1->printStats();
      } else {
        player2->setRace(input);
        player2->printStats();
      }
    }
  }

  cout << endl << "     ~~~ Fight! ~~~" << endl;

  //fight sequence, loops until either character's health falls
  while(player1->getHealth() > 0 && player2->getHealth() > 0 && input != "quit" && input != "Quit") {
    while (player1->getHealth() > 0 && player2->getHealth() > 0 && input != "quit" && input != "Quit") {
      printActions(1);
      cin >> input;
      if (input == "attack" || input == "Attack" || input == "a" || input == "A") {
      player1->attack(player2);
        break;
      }
      else if (input == "print" || input == "Print" || input == "p" || input == "P") {
        player1->printStats();
      }
      else if (input == "change" || input == "Change" || input == "c" || input =="C"){
        player1->equipAttack();
      } 
      else if (input == "Quit" || input == "quit" || input == "q" || input == "Q") {
        cout << "Are you sure you want to quit?"<<endl;
        cin >> input;
        if (input == "yes" || input == "yes"){
          save.close();
          return -1;
        } else if (input != "no" && input != "No") {
          cout << "Invalid response";
        }
      }
      else cout << "invalid response";
    }
    while (input != "quit" && input != "Quit" && player1->getHealth() > 0 && player2->getHealth() > 0) {
      printActions(2);
      cin >> input;
      if (input == "attack" || input == "Attack" || input == "a" || input == "A") {
        //FIX ME: wont call function
        player2->attack(player1);
        save << "1 " << player1->getHealth() << " " << player1->getEnergy() << " " << player1->getLevel() <<endl;
        save << "2 " << player2->getHealth() << " " << player2->getEnergy() << " " << player2->getLevel() << endl;
        break;
      }
      else if (input == "print" || input == "Print" || input == "p" || input == "P") {
        player2->printStats();
      }
      else if (input == "change" || input == "Change" || input == "c" || input =="C"){
        //FIX ME: virtual function in base class throws errors
        player2->equipAttack();
      }
      else if (input == "Quit" || input == "quit" || input == "q" || input == "Q") {
        cout << "are you sure you want to quit?"<<endl;
        cin >> input;
        if (input == "yes" || input == "yes"){
          save.close();
          if (load.is_open()) load.close();
          return -1;
        } 
        else if (input != "no" && input != "No") {
          cout << "Invalid response";
        }
      }
      else cout << "Invalid response";
    }
    if (player1->getHealth() <= 0 || player2->getHealth() <= 0) {
      if(player1->getHealth() <= 0) {
      printWinner(2);
    } else printWinner(1);
      while (input != "yes" && input != "Yes" && input != "No" && input != "no"){
        cout << "Play again?" << endl << "  ~Play with same chracters and continue with current level and replenished health and energy" << endl;
        cin >> input;
        if (input == "yes" || input == "Yes") {
          player1->setHealth(100);
          player2->setHealth(100);
          player1->setEnergy(100);
          player2->setEnergy(100);
        } else if (input == "no" || input == "No") {
          return -1;
        }
        else {
          cout << "Invalid response";
          cin >> input;
        }
      }
    }
    
  }

  save.close();
  if (load.is_open()) load.close();

  return 0;
}
