#include<iostream>
using std::cout; using std::endl; using std::cin; using std::ostream;
using std::boolalpha;
#include<iomanip>
using std::setprecision;
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<utility>
using std::pair; using std::make_pair;
#include<string>
using std::string; using std::getline;
#include<algorithm>
using std::copy; using std::sort; using std::transform;
#include<iterator>
using std::ostream_iterator;
#include<fstream>
using std::ifstream;
#include<sstream>
using std::istringstream; using std::ostringstream;
#include<stdexcept>
using std::out_of_range;
#include<cmath>

#include "functions.h"

int main(){
  cout << boolalpha;

  int test_no;
  cin >> test_no;

  switch(test_no){

  case 1:{
    Node n(10,10,"temp");
    cout << n.to_string() << endl;
    break;
  }

  case 2:{
    Node n1(10,10, "tens");
    Node n2(20, 20, "twentys");
    cout << n1.equal_nodes(n2) << endl;
    cout << n1.equal_nodes(n1) << endl;
    break;
  }

  case 3:{
    Node n1(10,10, "tens");
    Node n2(20, 20, "twentys");
    cout << n1.distance(n2) << endl;
    break;
  }

  case 4:{
    string fname;
    cin >> fname;
    ifstream fin(fname);
    Network net(fin);
    Node n = net.nodes["A"];
    cout << n.to_string() << endl;
    break;
  }

  case 5:{
    string fname;
    cin >> fname;
    ifstream fin(fname);
    Network net(fin);
    cout << net.to_string() << endl;
    break;
  }

  case 6:{
    string fname;
    cin >> fname;
    ifstream fin(fname);
    Network net(fin);
    Node n1, n2;
    try{
      n1 = net.get_node("A");
      n2 = net.get_node("X");
    }
    catch (out_of_range &e){
      cout << "Error:"<< e.what() << endl;
    }
    cout << n1.to_string() << endl;
    break;
  }

  case 7:{
    Network net;
    net.put_node( Node(10,10,"tens") );
    net.put_node( Node(20, 20, "twentys") );
    cout << net.to_string() << endl;
    net.put_node( Node(100, 100, "tens") );
    cout << net.to_string() << endl;    
    break;
  }

  case 8:{
    Network net;
    Node n1(10,10,"tens");
    Node n2(100, 100, "hundreds");
    net.route={"tens", "twentys"};
    cout << net.in_route(n1) << endl;
    cout << net.in_route(n2) << endl;
    break;
  }
    
  case 9:{
    string fname;
    cin >> fname;
    ifstream fin(fname);
    Network net(fin);
    auto n = net.get_node("A");
    auto close = net.closest(n);
    cout << close.to_string() << endl;
    cout << close.distance(n) << endl;
    break;
  }

  case 10:{
    string fname;
    cin >> fname;
    ifstream fin(fname);
    Network net(fin);
    Node n1 = net.get_node("A");
    Node n2 = net.get_node("D");
    cout << net.calculate_route(n1,n2) << endl;
    break;
  }

  }// of switch
} // of main
