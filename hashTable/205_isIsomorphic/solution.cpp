/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if(isIsomorphicUni(s, t) && isIsomorphicUni(t, s)){
      return true;
    }
    else{
      return false;
    }
  }
  bool isIsomorphicUni(string s, string t){
    unordered_map<char, char> char2char;
    for(int i = 0; i < s.length(); i++){
      if(char2char.find(s[i]) == char2char.end()){
	char2char[s[i]] = t[i];
      }
      else if(char2char.find(s[i])->second != t[i]){
	return false;
      }
    }
    return true;
  }
};
