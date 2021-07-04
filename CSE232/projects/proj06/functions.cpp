/*
 * File: Functions.cpp
 * Author: Brian Cong
 * Assignment: CSE 232 Project06
 * 
 * Created March 10,2017
 */
#include <vector>
using std::vector;
#include <iostream>
using std::cout;using std::cin;using std::endl;

vector<vector<int>> readImage(int x_dim, int y_dim){
	size_t xsize = size_t(x_dim);
	size_t ysize = size_t(y_dim);
	vector< vector<int> > args (xsize);
	vector<int> inargs;
	for(size_t x = 0; x < xsize; ++x){
		for(size_t y = 0; y < ysize; ++y){
			int in;
			cin >> in;
			inargs.push_back(in);
		}	
		args.push_back(inargs);
		inargs.clear();
	}
}
void printImage(vector< vector<int> > args){
	for(size_t x = 0; x < args.size(); ++x){
		for(size_t y = 0; y < args[x].size(); ++y){
			cout << args[x][y];
		}
	}
}
