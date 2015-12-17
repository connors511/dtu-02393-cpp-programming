#include "dict.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
#define NOT_FOUND "Entry Not Found"
 
// Testprogram:
int main(){
  map dan2eng("Danish to English");
  map eng2dan("English to Danish");
 
  eng2dan.insert("black","sort");
 
  dan2eng.insert("sort","black");
  dan2eng.insert("blaa","blue");
  dan2eng.insert("roed","red");
  dan2eng.insert("groen","green");
 
  cout << "English to Danish" << endl;
  cout << "black -> " << eng2dan.find("black") << "\n";
  cout << "contains 'blue'? " << eng2dan.find("blue") << "\n";
 
  cout  << endl << "Danish to English" << endl;
  cout << "groen -> " << dan2eng.find("groen") << "\n";
  cout << "contains 'gul'? " << dan2eng.find("gul") << "\n";
 
  map bilingual = dan2eng + eng2dan;
 
  cout  << endl<< "Printing all joint entries" << endl;
  print(bilingual);
  cout  << endl;
}