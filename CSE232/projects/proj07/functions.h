#ifndef DOCUMENT_SIM
#define DOCUMENT_SIM

#include<string>
using std::string;
#include<map>
using std::map;
#include<utility>
using std::pair;
#include<vector>
using std::vector;

string map_to_string(map<string,long>  &m);
string vector_to_string(vector<pair<string,long>> &v);
string clean_string(string w);
vector<string> generate_ngrams(string w, size_t n);
void process_line(map<string, long>& m, string line, size_t n);
bool pair_string_lessthan(const pair<string, long> &p1, const pair<string, long> &p2);
bool pair_frequency_greaterthan(const pair<string, long> &p1, const pair<string, long> &p2);
vector<pair<string, long>> top_n(map<string, long> &m, int num);
double ochiai(map<string, long> &m1, map<string, long> &m2);

// optional, see @461 in piazza
double ochiai2(map<string, long> &m1, map<string, long> &m2, int num);  

#endif
