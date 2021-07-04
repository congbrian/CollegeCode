/*

 * File: Functions.cpp

 * Author: Brian Cong

 * Assignment: CSE 232 Project08

 * 

 * Created March 23,2017

 */
#include <vector>

using std::vector;

#include <iostream>

using std::cout;using std::cin;using std::endl;
#include<sstream>
using std::ostringstream;
using std::stringstream;
#include<string>
using std::string;
#include<map>
using std::map;
#include<cmath>
#include<array>
#include<stdexcept>
#include<functional>
#include<utility>
#include<iterator>
#include<algorithm>
#include "functions.h"
//Simple node-to-string function
string Node::to_string () const{
//OSS for good output
	ostringstream oss;
	oss<< label << ":(" <<  x << "," << y << ")";
	return oss.str();
}
//comparison function
bool Node::equal_nodes(const Node &n){
//single-line of code
	if(label == n.label){ return true;} else {return false;}
	return false;
}
//Eudlidian Distance
double Node::distance(const Node &n)const{
	double ret;
//used cmath here
	ret = std::sqrt(pow((double)x - (double)n.x,2)+pow((double)y- (double)n.y,2));
	return ret;
}
//get_node for const purposes
Node Node::get_node()const{
//Arrows rather than .
	Node ret(this->x, this->y, this->label);
	return ret;
}
//Declaration
Network::Network(ifstream &ifs){
	//Network nodes;
	stringstream ss;
	//If I'm understanding the code correctly, getline
	//will store the characters in the line(deliminated by '\n') to the array a
	//getline(char_type*s, std::streamsize count, char_type delim) imply that
	//getline will store characters of streamsize count amount, deliminated by char_type characters, into s
	//This is, of course, assuming that getline is inherited by ifstream from istream.
	//According to cppreference, the following loop will terminate when the ifs.getline returns a false std::ios_base::operator bool().
//cout << "running";
	for(std::array<char, 6> a; ifs.getline(&a[0], 6, '\n'); ){
		//ss << a[4];
		string label (1, a[4]);
		//ss >> label;
		int x1 = a[0] - '0';
		int y1 = a[2] - '0';
		Node n(x1, y1, label);
//cout << n.to_string();
		nodes[n.label] = n;
	}
}
//Sets network to string
string Network::to_string () const{
	ostringstream oss;
//DEBUG
	//cout << "running";
//Ranged-based for
	for(auto a:nodes){
		oss << a.second.to_string() << ", ";
		//cout << a.second.to_string();
	}
	string s = oss.str();
	s.pop_back();
	return s;
}
//Get node based on label
Node Network::get_node(string l){
//ranged based for
	for(auto a: nodes){
		if(a.second.label == l){
			return a.second;
		}else{
			throw std::out_of_range ("Out of range.");
		}
	}
	Node ret(0, 0, "failed");
	return ret;
}
//Put node in network
void Network::put_node(Node n){
//Put node in map based on label
	nodes[n.label] = n;
	//cout << n.label;
	//cout << n.to_string()<<endl;
}
//check to see if node is in network
bool Network::in_route(const Node&n){
	if(std::find(std::begin(route), std::end(route), label) != route.end()){
	//route contains label
		return true;
	}else{
	//route does not contain label
		return false;
	}
	return false;
}
//check for closest node
Node Network::closest(Node &n){
	Node ret;
//set to some unreasonable distance
	double mindist = 9999999;
	for(auto a:nodes){
		double cur = sqrt(pow(double(a.second.x - n.x),2) + pow(double(a.second.y - n.y),2));
		if(cur < mindist && !(a.second.equal_nodes(n))){
			mindist = cur;
			ret = a.second;
		}
	}
	return ret;
}
//calculate a greedy route
string Network::calculate_route(const Node&start, const Node&end){
	string ret = "";
	route.push_back(start.label);
	ret += start.label + " ";
	Node cur = start.get_node();
	double totaldist = 0;
//had trouble with this-- const get_node fixes it.
	while(!end.get_node().equal_nodes(cur)){
		totaldist += cur.distance(closest(cur));
		cur = closest(cur);
		route.push_back(cur.label);
		ret += cur.label + " ";
	}
	ret = std::to_string(totaldist) + ": " + ret;
	return ret;
}
