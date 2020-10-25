#include <iostream>
#include  <cstring>
#include <vector>
#include <map>
#include <iterator>
#include "room.h"
#include "item.h"
//imports (above)
using namespace std;

int main(){
  vector<item*> inventory; //user's items
  char input[20];
  cout << "You are trapped in area 51. Find all 5 items within 40 rounds or the government finds you." << endl;
  cout << "your commands are a go, pick, drop, or quit" << endl;
  cout << endl;
  //what room are we in?
  room* current_room = new room();
  //initialize all the rooms, exits, and items
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
  room* trump = new room();
  strcpy(trump->name, "trump's room");
  strcpy(trump->description, "zuul part 2 white house edition?");
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
  item* pillow = new item();
  strcpy(pillow->name, "pillow");
  bedroom->items.push_back(pillow);
  item* pokeball = new item();
  strcpy(pokeball->name, "pokeball");
  pokemonroom->items.push_back(pokeball);
  item* beer = new item();
  strcpy(beer->name, "beer");
  bar->items.push_back(beer);
  item* child = new item();
  strcpy(child->name, "child");
  daycare->items.push_back(child);
  item* watergun = new item();
  strcpy(watergun->name, "water gun");
  weaponroom->items.push_back(watergun);

  bedroom->exits.insert(pair<const char*, room*>("west", lab));
  bedroom->exits.insert(pair<const char*, room*>("north", barracks));
  bedroom->exits.insert(pair<const char*, room*>("south", lounge));
  bedroom->exits.insert(pair<const char*, room*>("east", pettingzoo));
  pettingzoo->exits.insert(pair<const char*, room*>("west", bedroom));
  pettingzoo->exits.insert(pair<const char*, room*>("east", library));
  pettingzoo->exits.insert(pair<const char*, room*>("north", weaponroom));
  library->exits.insert(pair<const char*, room*>("south", pokemonroom));
  library->exits.insert(pair<const char*, room*>("west", pettingzoo));
  pokemonroom->exits.insert(pair<const char*, room*>("north", library));
  weaponroom->exits.insert(pair<const char*, room*>("south", pettingzoo));
  weaponroom->exits.insert(pair<const char*, room*>("west", barracks));
  weaponroom->exits.insert(pair<const char*, room*>("north", alienroom));
  barracks->exits.insert(pair<const char*, room*>("south", bedroom));
  barracks->exits.insert(pair<const char*, room*>("east", weaponroom));
  alienroom->exits.insert(pair<const char*, room*>("south", weaponroom));
  lounge->exits.insert(pair<const char*, room*>("north", bedroom));
  lounge->exits.insert(pair<const char*, room*>("east", daycare));
  lounge->exits.insert(pair<const char*, room*>("south", coffeehouse));
  daycare->exits.insert(pair<const char*, room*>("west", lounge));
  coffeehouse->exits.insert(pair<const char*, room*>("north", lounge));
  lab->exits.insert(pair<const char*, room*>("north", bar));
  lab->exits.insert(pair<const char*, room*>("east", bedroom));
  lab->exits.insert(pair<const char*, room*>("south", kitchen));
  kitchen->exits.insert(pair<const char*, room*>("north", lab));
  trump->exits.insert(pair<const char*, room*>("east", kitchen));
  bar->exits.insert(pair<const char*, room*>("north", storage));
  bar->exits.insert(pair<const char*, room*>("west", missilesilo));
  bar->exits.insert(pair<const char*, room*>("south", lab));
  missilesilo->exits.insert(pair<const char*, room*>("east", bar));
  storage->exits.insert(pair<const char*, room*>("south", bar));

  for(int z = 0; z < 40; z++){ //game loop
    cout << "------round " << (z+1) << "---------" << endl;
    cout << "you are in room " << current_room->name << endl; //describe room, items, and exits
    cout << current_room->description << endl; 
    cout << endl;
    cout << "the exits are: " << endl;
    map<const char*, room*>::iterator it;
    for(it = current_room->exits.begin(); it != current_room->exits.end(); ++it){
      cout << it->first << ", ";
    }
    cout << endl;
    cout << "the items are: " << endl;
    for(vector<item*>::iterator it = current_room->items.begin(); it != current_room->items.end(); it++){
      cout << (*it)->name << ", ";
    }
    cout << endl;
    cout << "in your inventory: " << endl; //in inventory
    for(vector<item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
      cout << (*it)->name << ", ";
    }
    cout << endl;
    cout << "input a command: " << endl;
    cin >> input; //get input
    
    if(strcmp("quit", input)==0){ //a way to quit
      cout << "bye!" << endl;
      return 0;
    } //then other commands
    else if(strcmp("go", input)==0){
      cout << "which way would you like to go?" << endl;
      cin >> input;
      map<const char*, room*>::iterator it; //go in a direction to a room
      for(it = current_room->exits.begin(); it != current_room->exits.end(); ++it){
	if(strcmp(it->first, input) == 0){
	  current_room = it->second;
	  break;
	 }
      }
    }
    else if(strcmp("drop", input)==0){ //remove an item from inventory and add to room
       for(vector<item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
	 cout << "drop " << (*it)->name << "?";
	 cin >> input;
	 if(strcmp(input, "yes")==0){
	   item* i = (*it);
	   it = inventory.erase(it);
	   current_room->items.push_back(i);
	   break;
	 }
       }
    }
    else if(strcmp("pick", input)==0){//remove an item from room and add to inventory
      for(vector<item*>::iterator it = current_room->items.begin(); it != current_room->items.end(); it++){
        cout << "pick up " << (*it)->name << "?" << endl;
	cin >> input;
	if(strcmp(input, "yes")==0){
	  item* i = (*it);
	  it = current_room->items.erase(it);
	  inventory.push_back(i);
	  break;
	}
      }
    }
    else{
      cout << "invalid command! try again!" << endl;
    }
    
    //if inventory size is 5, player wins. 
    if(inventory.size() == 5){
      cout << "you have all five items! You win!" << endl;
      return 0; 
    }
    cout << "---------------------------------" << endl;
    cout << endl;
  }
  //if 40 rounds have passed, game ends
  cout << "the government finds you! you lose!" << endl;
  return 0;
}
