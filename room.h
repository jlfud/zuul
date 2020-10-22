#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

class room{
public:
  room();
  char name[80];
  char description[80];
  vector<item*> items;
  //map of exits
  map<char*, room*> exits; //direction and room
};

#endif
