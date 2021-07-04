#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<iomanip>
using std::setprecision;
#include<map>
using std::map;
#include<vector>
using std::vector;
#include<utility>
using std::pair;
#include<string>
using std::string; using std::getline;
#include<fstream>
using std::ifstream;
#include<iterator>
using std::ostream_iterator;


#include "functions.h"

int main (){
  
  int case_no;
  ostream_iterator<string> oss(cout, ", ");
  cout << boolalpha;
  cout << setprecision(3);
  cin >> case_no;

  switch(case_no){

  case 1 : {
    cin.ignore(100, '\n');
    string s;
    getline(cin, s);
    cout << clean_string(s) << endl;
    break;
  }

  case 2:{
    string s;
    int n;
    cin >> n;
    cin.ignore(100, '\n');    
    getline(cin, s);
    auto v = generate_ngrams(s, n);
    copy (v.begin(), v.end(), oss);
    cout << endl;
    break;
  }

  case 3:{
    map<string,long> m{ {"a",3}, {"b",2}, {"c",1} };
    cout << map_to_string(m) << endl;
    break;
  }
    
  case 4:{
    string s;
    int n;
    map<string,long> m;
    cin >> n;
    cin.ignore(100, '\n');    
    getline(cin, s);
    process_line(m, s, n);
    cout << map_to_string(m) << endl;
    break;
  }

  case 5:{
    string s;
    long l;
    cin >> s >> l;
    pair<string, long> p1(s,l);
    cin >> s >> l;    
    pair<string, long> p2(s,l);
    cout << pair_frequency_greaterthan(p1,p2) << endl;
    break;
  }

  case 6:{
    vector<pair<string,long>> v{ {"a",1}, {"b",2}, {"c",3} };
    cout << vector_to_string(v) << endl;
    break;
  }

  case 7:{
    string s;
    int ngram, topn;
    map<string,long> m;
    cin >> ngram >> topn;
    cin.ignore(100, '\n');    
    getline(cin, s);
    process_line(m, s, ngram);
    auto v = top_n(m, topn);
    cout << vector_to_string(v) << endl;
    break;
  }
    
  case 8:{
    string fname1, fname2, line;
    int ngram;
    map<string,long> m1, m2;
    cin >> ngram >> fname1 >> fname2;
    ifstream if1(fname1);
    ifstream if2(fname2);
    while (getline(if1, line) )
      process_line(m1, line, ngram);
    while (getline(if2, line) )
      process_line(m2, line, ngram);
    cout << ochiai(m1, m2) << endl;
    break;
  }
    
  }
}
