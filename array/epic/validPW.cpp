#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

bool diversity(string input);
bool validPW(string input);

int main(){
  vector<string> test;
  test.push_back("123123qs");
  test.push_back("123qs123");
  test.push_back("123qs123123");
  test.push_back("1acabcdghabc");
  test.push_back("124123123qs");
  test.push_back("12");
  for(int i = 0; i < test.size(); i++){
    if(validPW(test[i])){
      cout << test[i] << " is a valid password" << endl;
    }
    else{
      cout << test[i] << " is not a valid password.\n";
    }
  }
  return 0;
}

bool diversity(string input){
  for(int i = 0; i < input.size(); i++){
    char c = input[i];
    if(c >= '0' && c <= '9') return true;
    else if(c >= 'a' && c <= 'z') return true;
  }
  return false;
}

bool validPW(string input){
  // hashmap from substring to final index of substr;
  map<string, int> m;
  int length = input.length();
  if(length > 13 || length < 5) return false;
  if(!diversity(input)) return false;
  for(int subLength = 2; subLength < length; subLength++){
    for(int i = 0; i + subLength <= length; i++){
      string sub = input.substr(i, subLength);
      // this substr is once recorded in the hashmap
      map<string, int>::iterator iter;
      iter = m.find(sub);
      if(iter != m.end()){
	// assuming exists, check if they are close neightbour
	if(iter->second + 1 == i){
	  return false;
	}
	// if not close neighbour, update the ending index;
	else{
	  iter->second = i + subLength - 1;
	}
      }
      else{
	// insert the pair of substr and ending index;
	m[sub] = i + subLength - 1;
      }
    }
  }
  return true;
}
