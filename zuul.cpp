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
  room* current_room;
  
  room* bedroom;
  strcpy(bedroom->name, "bedroom");
  strcpy(bedroom->description, "what a putrid bedroom");  
  current_room = bedroom;

  //initialize other rooms 
  
  for(int z = 0; z < 40; z++){
    cout << "you are in room " << current_room->name << endl; //describe room
    cout << current_room->description << endl; 
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
      //exit
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
