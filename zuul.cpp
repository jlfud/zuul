#include <iostream>
#include  <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

int main(){
  vector<room*> rooms;
  vector<item> inventory; 
  char input[20];
  cout << "You are trapped in area 51. Find all 5 items within 40 rounds or the government finds you." << endl;
  cout << "your commands are a direction, pick, drop, or quit" << endl;
  for(int z = 0; z < 40; z++){
    cout << "you are in room " << endl; //describe room 
    cout << "the exits are: " << endl;
    //print exits
    cout << "the items are: " << endl;
    //print items
    cout << "input a command: " << endl;
    cin >> input;
    if(strcmp("quit", input)==0){
      cout << "bye!" << endl;
      return 0;
    }
    //other commands

    //if inventory size is 5, player wins. 
    

  }
  cout << "the government finds you! you lose!" << endl;
  return 0;
}
