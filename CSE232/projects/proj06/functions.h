/* 
 * File:   functions.h
 * Author: 
 * Assignment: CSE 232 Project 06
 * 
 * Created on February 23, 2017
 */
#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include<vector>
using std::vector;

vector<vector<int>> readImage(int, int);

void printImage(vector<vector<int>>);

int countHoles(vector<vector<int>>);

#endif	/* FUNCTIONS_H */
