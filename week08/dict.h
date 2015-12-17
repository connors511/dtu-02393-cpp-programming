#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define NOT_FOUND "Entry Not Found"

// Data-structure for dictionaries
class map{
private:
  vector<string> keys;
  vector<string> entries;
  string name;
  int contains(string key) const;

public:
  map(string name);
  ~map();
  
  void insert(string key, string entry);
  string find(string key) const;
  // void print() const;
  map operator+(const map & m) const;

  // new
  typedef vector<string>::iterator iterator;
  iterator begin();
  iterator end();
};

void print(map & m);
