/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
  string addBinary(string a, string b) {
    string sum = "";
    int indexA = a.length()-1, indexB = b.length()-1;
    int x, y;
    char carry = '0';
    while(indexA >= 0 || indexB >= 0){
      if(indexA >= 0) x = a[indexA] - '0'; else x = 0;
      if(indexB >= 0) y = b[indexB] - '0'; else y = 0;
      char val = '0' + (x + y + carry - '0') % 2;
      carry = '0' + (x + y + carry- '0') / 2;
      sum = val + sum;
      indexA--; indexB--;
    }
    if(carry != '0'){
      sum = carry + sum;
    }
    return sum;
  }
};
