/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
  string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") return "0";
    // open a slot to hold each weight
    vector<int> productLtEnd(num1.length() + num2.length(), 0);
    for(int i = 0; i < num1.length(); i++){
      for(int j = 0; j < num2.length(); j++){
	int index = (num1.length() - 1 - i) + (num2.length() -1 - j);
	productLtEnd[index] += (num1[i] - '0') * (num2[j] - '0');
      }
    }
    string productStr = "";
    for(int i = 0; i < productLtEnd.size() - 1; i++){
      char prefixChar = productLtEnd[i] % 10 + '0';
      productStr = prefixChar + productStr;
      productLtEnd[i+1] += productLtEnd[i] / 10;
    }
    char mostSignificant = productLtEnd[productLtEnd.size()-1] + '0';
    if(mostSignificant != '0'){
      productStr = mostSignificant + productStr;
    }
    return productStr;
  }
};
