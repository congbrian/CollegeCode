/* 
 * File:   main.cpp
 * Author: 
 * Assignment: CSE 232 Project 06
 * 
 * Created on February 23, 2017
 */
 
#include <iostream>
#include <vector>
using std::cout;using std::cin;using std::endl;
using std::vector;

#include "functions.h"

int main() {
	
	int x_dim, y_dim, test_case;
	
	cin >> test_case;
	
	// read in number of columns as x_dim
	cin >> x_dim;
	
	// read in number of rows as y_dim
	cin >> y_dim;
	
	vector<vector<int>> image = readImage(x_dim, y_dim);
	
	switch (test_case){

	  case 1 : {
		printImage(image);
		break;
	  } // of case 1

	  case 2 : {
		printImage(image);
		break;
	  } // of case 2

	  case 3 : {
		printImage(image);
		cout << "Hole count: " << countHoles(image) << endl;
		break;
	  } // of case 3   

	  case 4 : {
		cout << "Hole count: " << countHoles(image) << endl;
		break;
	  } // of case 4

	  case 5 : {
		cout << "Hole count: " << countHoles(image) << endl;
		break;
	  } // of case 5
	  
	  case 6 : {
		cout << "Hole count: " << countHoles(image) << endl;
		break;
	  } // of case 6
		
	  } // of switch

} // of main
