#include<iostream>
using std::cout; using std::cin; using std::endl;
using std::ostream; using std::boolalpha;
#include<fstream>
using std::ifstream;
#include<map>
using std::map;
#include<deque>
using std::deque;
#include<string>
using std::string;
#include<sstream>
using std::istringstream;
#include<stdexcept>
using std::domain_error; using std::out_of_range;
#include<iterator>
using std::ostream_iterator;
#include<algorithm>
using std::copy; using std::find;

#include "functions.h"

int main () {
  int test_no;
  cin >> test_no;
  cout << boolalpha;

  switch (test_no){

  case 1:{
    FSA fsa;
    string state;
    cin >> state;
    try{
      fsa.add_state(state);
      cout << "added state:"<<state<<endl;
      // should throw
      fsa.add_state(state);
    }
    catch(domain_error &e){
      cout << e.what() <<endl;
    }
    cout << fsa.exists_state(state) << endl;
    cout << fsa.exists_state("X") << endl;
    break;
  }

  case 2:{
    FSA fsa;
    string from_s, input, to_s;
    cin >> from_s >> input >> to_s;
    try{
      fsa.add_state(from_s);
      fsa.add_transition(from_s, input, to_s);
      cout << "from "<<from_s << " to "<<input<<" on "
	   <<input<<endl;

      // should throw
      fsa.add_transition("X", input, to_s);
    }
    catch(domain_error &e){
      cout << e.what() <<endl;
    }
    break;
  }

  case 3:{
    FSA fsa;
    string from_s, input, to_s;
    cin >> from_s >> input >> to_s;
    try{
      fsa.add_state(from_s);
      fsa.add_transition(from_s, input, to_s);
      cin >> from_s >> input >> to_s;
      fsa.add_transition(from_s, input, to_s);      
      cout << fsa.transitions_to_string (from_s) << endl;

      // throw
      cout << fsa.transitions_to_string("X") << endl;

    }
    catch(domain_error &e){
      cout << e.what() <<endl;
    }
    break;
  }    
    
  case 4:{
    string from_s, input, to_s;
    cin >> from_s >> input >> to_s;
    FSA fsa(from_s, to_s);    
    fsa.add_state(from_s);
    fsa.add_transition(from_s, input, to_s);
    cin >> from_s >> input >> to_s;
    fsa.add_transition(from_s, input, to_s);      

    cout << fsa << endl;
    break;
  }

  case 5:{
    string fname;
    cin >> fname;
    ifstream fin(fname);
    FSA fsa(fin);
    cout << fsa << endl;
    break;
  }

  case 6:{
    string fname;
    cin >> fname;
    ifstream fin(fname);
    FSA fsa(fin);
    string state;
    cin >> state;
    
    try{
      cout << fsa.next(state, "0") << endl;

      // should throw
      cout << fsa.next("X", "1") << endl;
    }
    catch(domain_error &e){
      cout << e.what() << endl;
    }
    break;
  }

  case 7:{
    string fname;
    cin >> fname;
    ifstream fin(fname);
    FSA fsa(fin);
    string state;
    cin >> state;
    
    try{
      cout << fsa.next(state, "0") << endl;

      // should throw
      cout << fsa.next(state, "X") << endl;
    }
    catch(domain_error &e){
      cout << e.what() << endl;
    }
    break;
  }

  case 8:{
    string fname;
    cin >> fname;
    ifstream fin(fname);
    FSA fsa(fin);
    string input;
    cin >> input;

    bool accept;
    accept = fsa.run(input);
    cout << endl<< "accepted?: "<<accept << endl;
    break;
  }

  case 9:{
    string fname;
    cin >> fname;
    ifstream fin(fname);
    FSA fsa(fin);
    string input;
    cin >> input;
    
    cout << fsa << endl;
    bool accept;
    accept = fsa.run(input);
    cout << endl<< "accepted?: "<<accept << endl;
    cout << fsa << endl;
    break;
  }
    
  } // of switch
} // of main;

