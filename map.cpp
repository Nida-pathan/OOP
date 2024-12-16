/*
THIS CODE HAS BEEN TESTED AND IS FULLY OPERATIONAL.

Problem Statement: Write a program in C++ to use map associative container. The keys will be the names of states, and the values will be the populations of the states. When the program runs, the user is prompted to type the name of a state. The program then looks in the map, using the state name as an index, and returns the population of the state.

Code from Object Oriented Programming (SPPU - Second Year - Computer Engineering - Content) repository on KSKA Git: https://git.kska.io/sppu-se-comp-content/ObjectOrientedProgramming
*/

// BEGINNING OF CODE
#include <iostream>
#include <map>
#include <iterator> // THIS IS NOT NEEDED FOR NEWER C++ COMPILER, BUT SINCE COLLEGES USE OLD STUFF, HAD TO INCLUDE
using namespace std;

map<string, int> m1; // Creating an associative container (map) with string as key (state name) and int as value (state population)
int total; // Store total number of states

void addState() {
  string key;
  int value;

  cout<<endl<<"--- ENTER STATE INFORMATION ---\n";
  for (int i=0; i<total; i++) {
    cout<<endl<<"--- STATE "<<i+1<<" ---";
    cout<<endl<<"State name:\t";
    cin>>key;
    cout<<"State population:\t";
    cin>>value;
    m1.insert({key, value});
    cout<<"--- STATE SAVED ---"<<endl;
  }
  cout<<endl<<"--- ALL STATES SAVED ---"<<endl;
}

void delState() {
  string key;
  cout<<endl<<"Specify the state name to delete:\t";
  cin>>key;

  auto p = m1.find(key); // auto automatically determines the datatype (i.e. int, float, etc.)
  if (p == m1.end()) {
    cout<<endl<<"State ["<<key<<"] not found.\n";
  }
  else {
    cout<<endl<<"State ["<<p->first<<"] with population of ["<<p->second<<"] deleted.\n";
    m1.erase(p);
  }
}

void displayState() {
  string key;
  cout<<endl<<"Specify state name to search:\t";
  cin>>key;

  auto p = m1.find(key);
  cout<<endl<<"--- SEARCH RESULT ---";
  if (p == m1.end()) {
    cout<<endl<<"State ["<<key<<"] not found.\n";
  }
  else {

    cout<<endl<<"State ["<<p->first<<"] has a population of:\t ["<<p->second<<"]"<<endl;
  }
  cout<<"--- END OF SEARCH ---"<<endl;
}

void displayAll() {
  map<string, int>::iterator p;

  p = m1.begin();
  while (p != m1.end()) {
    cout<<endl<<"--- STATE INFORMATION BEGINS ---";
    cout<<endl<<"State name:\t"<<p->first; // first = first value, i.e. key (state name)
    cout<<endl<<"State population:\t"<<p->second; // second = second value, i.e. value (state population)
    cout<<endl<<"--- STATE INFORMATION ENDS ---"<<endl;
    p++;
  }
}

int main() {

  int optn;

  while (1) {
    cout<<endl<<"--- MAIN MENU ---";
    cout<<endl<<"1 -> Add states";
    cout<<endl<<"2 -> Delete state";
    cout<<endl<<"3 -> Search for a state";
    cout<<endl<<"4 -> Display all states";
    cout<<endl<<"5 -> Exit";
    cout<<endl<<"Choose an option (1-5):\t";
    cin>>optn;

    switch (optn) {
      case 1:
        cout<<endl<<"Total states to add:\t";
        cin>>total;
        addState();
        break;
      case 2:
        delState();
        break;
      case 3:
        displayState();
        break;
      case 4:
        displayAll();
        break;
      case 5:
        cout<<endl<<"## DESIGNED AND ENGINEERED BY KSHITIJ\n## END OF CODE\n\n";
        exit(1);
        break;
      default:
        cout<<endl<<"Please choose a valid option (1-5)\n\n";
        break;
    }
  }
  return 0;
}
// END OF CODE
