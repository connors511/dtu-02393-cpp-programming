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
    if (keys.empty()) {
      keys.push_back(key);
      entries.push_back(entry);
    } else {
      keys.resize(keys.size()+1);
      entries.resize(entries.size()+1);

      int i;
      for (i = keys.size() - 1; keys[i-1] > key && (i-1) >= 0; --i)
      {
          keys[i] = keys[i - 1];
          entries[i] = entries[i - 1];
      }
      keys[i] = key;
      entries[i] = entry;

      // vector<string>::reverse_iterator pos = keys.rbegin();
      // vector<string>::reverse_iterator pos2 = entries.rbegin();

      // for ( ; *(pos+1) > key && (pos+1) != keys.rend(); ++pos, ++pos2) {
      //     *pos = *(pos+1);
      //     *pos2 = *(pos2+1);
      // }
      // *pos = key;
      // *pos2 = entry;
    }
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

map::iterator map::begin() {
  return keys.begin();
}

map::iterator map::end() {
  return keys.end();
}

// void map::print() const{
//   cout << name << endl;
//   for(int i=0; i<keys.size(); i++)
//     cout << keys[i] << "->" << entries[i] << endl;
// };

void print(map & m) {
  for (map::iterator it = m.begin(); it != m.end(); ++it)
  {
    cout << *it << "->" << m.find(*it) << endl;
  }
}