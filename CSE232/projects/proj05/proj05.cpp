#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::stoi; using std::to_string;
#include<sstream>
using std::ostringstream; using std::istringstream;
#include<iterator>
using std::distance; using std::back_inserter;
#include<algorithm>
using std::transform;
#include<cctype>
#include<functional>
// whatever headers you need
//Lowering and stripping string s
//Erase all non-alphanumeric/whitespace characters
//Use custom predicate-- predicate(char c)
//Lower string after stripping.
//Return updated string.
string lower_and_strip(string& s){
	s.erase(std::remove_if(s.begin(), s.end(), std::not1(std::ptr_fun( (int(*)(int))std::isalnum ))), s.end());
	for(auto letter:s){
		tolower(letter);
	}
	return s;
}


//Return encoded character -- start at start, take char c, and a key
//if key is found, and it is at a location less than start, return location + length
//if the char is not found, return key size+1
//update start to new location
int return_encoded_char(string key, string::size_type &start, char c){
	int dist = 0;
	if(key.find(c)){
		if(key.find(c)< start){
			
			return key.find(c)+key.length();
		}else{
			return key.find(c);
		}
		start = key.find(c);
	}else{
		start = 0;
		return (key.size()+1);
	}
}

//Encode message using key
string encode(string message, string key){
//lower and strip message
	lower_and_strip(message);
//set location start to 0
	size_t start = 0;
//Declare return string
	string ret = "";
//For every letter in message, return the encoded character, using the key and start location, and append whitespace
	for(char letter:message){
		ret += to_string(return_encoded_char(key, start, letter));
		ret += " ";
	}
	return ret;
}

//Decode char with start function and number
char return_decoded_char(string key, string::size_type &start, int num){
	char ret = '_';
//if the number is less than the key size, then set the wraparound holder to be start + num
	if(num < key.size()+1){
		size_t loc = size_t(num) + start;
//if the holder is greater than key size, then subtract size from holder
		if(loc > key.size()){ loc = loc-key.size();}
//set start to location after processing and return char to location
		start = loc;
		ret = key[loc];
		
	}else{
		start = 0;
	}
	return ret;
}
//decode encoded text
//set start to 0
//for each character, decode using function and find value
string decode (string encoded_text, string key){
	size_t start = 0;
	for(auto c:encoded_text){
		return_decoded_char(key, start, key.find(c));
	}
}

// your functions here


int main (){
  cout << boolalpha;

  int test_case;
  cin >> test_case;

  switch (test_case){

  case 1 : {
    string line;
    cin.ignore(20, '\n');
    getline(cin, line);
    cout << lower_and_strip(line) << endl;
    break;
  } // of case 1

  case 2 : {
    string key;
    char C;
    int num;
    string::size_type start;
    cin.ignore(20, '\n');
    getline(cin, key);
    cin >> C;
    cin >> start;
    num = return_encoded_char (key, start, C); 
    cout << num << " " << start << endl;
    break;
  } // of case 2

  case 3 : {
    string key, line;
    string::size_type start=0;
    cin.ignore(20, '\n');
    getline(cin, key);
    getline(cin, line);
    cout << encode(line, key) << endl;
    break;
  } // of case 3   

  case 4 : {
    int num;    
    string key;
    char C;
    string::size_type start;
    cin.ignore(20, '\n');
    getline(cin, key);
    cin >> num;
    cin >> start;
    C = return_decoded_char (key, start, num);
    cout << C << " "<<start << endl;
    break;
  } // of case 4

  case 5 : {
    string key, line;
    string::size_type start=0;    
    cin.ignore(20, '\n');
    getline(cin, key);
    getline(cin, line);
    cout << decode(line, key) << endl;
    break;
  } // of case 5
    
  } // of switch

} // of main
  
  
