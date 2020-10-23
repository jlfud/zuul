#include <iostream>
#include  <cstring>
#include <vector>
#include <map>
#include <iterator>
#include "room.h"
#include "item.h"

using namespace std;

int main(){
  vector<item*> inventory;
  char input[20];
  cout << "You are trapped in area 51. Find all 5 items within 40 rounds or the government finds you." << endl;
  cout << "your commands are a exit, pick, drop, or quit" << endl;
  cout << endl;
  room* current_room = new room();
  
  room* bedroom = new room();
  strcpy(bedroom->name, "bedroom");
  strcpy(bedroom->description, "what a putrid bedroom");  
  current_room = bedroom;
  
  room* pettingzoo = new room();
  strcpy(pettingzoo->name, "petting zoo");
  strcpy(pettingzoo->description, "when's the last time someone cleaned?");
  room* library = new room();
  strcpy(library->name, "library");
  strcpy(library->description, "nobody ever reads lets just move on");
  room* pokemonroom = new room();
  strcpy(pokemonroom->name, "pokemon room");
  strcpy(pokemonroom->description, "gotta catch em all");
  room* lounge = new room();
  strcpy(lounge->name, "lounge");
  strcpy(lounge->description, "just relax. no need to mind the government");
  room* daycare = new room();
  strcpy(daycare->name, "daycare");
  strcpy(daycare->description, "to keep your children");
  room* coffeehouse = new room();
  strcpy(coffeehouse->name, "coffee house");
  strcpy(coffeehouse->description, "what's a starbucks doing in area 51?");
  room* kitchen = new room();
  strcpy(kitchen->name, "kitchen");
  strcpy(kitchen->description, "hungry?");
  room* lab = new room();
  strcpy(lab->name, "computer lab");
  strcpy(lab->description, "can you program your way out?");
  room* bar = new room();
  strcpy(bar->name, "bar");
  strcpy(bar->description, "id please");
  room* storage = new room();
  strcpy(storage->name, "storage");
  strcpy(storage->description, "get your camera ready");
  room* missilesilo = new room();
  strcpy(missilesilo->name, "missile silo");
  strcpy(missilesilo->description, "press the red button");
  room* barracks = new room();
  strcpy(barracks->name, "barracks");
  strcpy(barracks->description, "you would think soldiers would be clean");
  room* weaponroom = new room();
  strcpy(weaponroom->name, "weapon room");
  strcpy(weaponroom->description, "probably isn't safe to be here");
  room* alienroom = new room();
  strcpy(alienroom->name, "alien room");
  strcpy(alienroom->description, "just like the memes");

  bedroom->exits.insert(pair<const char*, room*>("west", lab));
  for(int z = 0; z < 40; z++){
    cout << "you are in room " << current_room->name << endl; //describe room
    cout << current_room->description << endl; 
    cout << endl;
    cout << "the exits are: " << endl;
    //print exits
    cout << "the items are: " << endl;
    //print items
    cout << "input a command: " << endl;
    cin >> input;
    
    if(strcmp("quit", input)==0){
      cout << "bye!" << endl;
      return 0;
    } //then other commands
    else if(strcmp("exit", input)==0){
      cout << "which way would you like to go?" << endl;
      while(true){
	cin >> input;
	map<const char*, room*>::iterator it;
	for(it = current_room->exits.begin(); it != current_room->exits.end(); ++it){
	  if(strcmp(it->first, input) == 0){
	    current_room = it->second;
	    break;
	  }
	}
	break;
      }
    }
    else if(strcmp("drop", input)==0){
      //drop
    }
    else if(strcmp("pick", input)==0){
      //pick
    }
    else{
      cout << "invalid command! try again!" << endl;
    }
    
    //if inventory size is 5, player wins. 
    if(inventory.size() == 5){
      cout << "you have all five items! You win!" << endl;
      return 0; 
    }
    cout << endl;
  }
  cout << "the government finds you! you lose!" << endl;
  return 0;
}
