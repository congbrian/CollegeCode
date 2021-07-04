#ifndef NETWORK
#define NETWORK

#include<vector>
using std::vector;
#include<utility>
using std::pair;
#include<string>
using std::string;
#include<fstream>
using std::ifstream;
#include<map>
using std::map;


struct Node{
  int x;
  int y;
  string label;

  Node()=default;
  Node(int i, int j, string l) :  x(i), y(j), label(l) {} ;
  string to_string () const;
  bool equal_nodes(const Node&);
  double distance(const Node &)const;
  Node get_node()const;
};

struct Network{
  string label;
  map<string, Node> nodes;
  vector<string> route;

  Network()=default;
  Network(ifstream &);
  string to_string () const;
  Node get_node(string);
  void put_node(Node);
  bool in_route(const Node&);
  Node closest(Node &);
  string calculate_route(const Node&, const Node&);
};

#endif

  
