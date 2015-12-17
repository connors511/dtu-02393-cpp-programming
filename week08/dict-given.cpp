#include "dict.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

map::map(string n){
  name=n;
};

map::~map(){
  cout << "Deleting ... "<< name << endl;
};


int map::contains(string key) const{
  // Compares the key to all keys in the map. Returns the position if found,
  // otherwise returns length of the keys vector.
  for(vector<string>::size_type i=0 ; i<keys.size() ; i++){
    if ( keys[i] == key ){
      return i;
    }
  }
  return -1;
}

string map::find(string key) const{
  int i=contains(key);
  if (i==-1) return NOT_FOUND;
  return entries[i];
}

void map::insert(string key, string entry){
  // Assumes that contains() will return size if key not found.
  int n = contains(key);

  if ( n == -1){
    keys.push_back(key);
    entries.push_back(entry);
  }
  else{
    entries[n] = entry;
  }
}

map map::operator+(const map & m) const{
  map result(name+"+"+m.name);
  for(int i=0; i<keys.size(); i++)
    result.insert(keys[i],entries[i]);
  for(int i=0; i<m.keys.size(); i++)
    result.insert(m.keys[i],m.entries[i]);
  return result;    
};

void map::print() const{
  for(int i=0; i<keys.size(); i++)
    cout << keys[i] << "->" << entries[i] << endl;
};

