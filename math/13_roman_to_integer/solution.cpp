// 49 = XLIX
class Solution {
public:
  int romanToInt(string s) {
    int number = 0;
    unordered_map<char, int>roman2int;
    roman2int['I'] = 1;
    roman2int['V'] = 5;
    roman2int['X'] = 10;
    roman2int['L'] = 50;
    roman2int['C'] = 100;
    roman2int['D'] = 500;
    roman2int['M'] = 1000;
    for(int i = s.length()-1; i >= 0; i--){
      if(i == s.length() - 1){
	number += roman2int[s[i]];
      }
      else if(roman2int[s[i]] >= roman2int[s[i+1]]){
	number += roman2int[s[i]];
      }
      else{
	number -= roman2int[s[i]];
      }
    }
    return number;
  }
};
