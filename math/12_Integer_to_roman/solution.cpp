/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

// thanks to http://blog.csdn.net/kenden23/article/details/16991627
// https://stupidcodergoodluck.wordpress.com/2014/03/31/leetcode-integer-to-roman/

class Solution {
public:
  string intToRoman(int num) {
    string romanChar[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int assoInt[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string cvtdRoman = "";
    for(int i = 0; i < 13 && num > 0; i++){
      while(num >= assoInt[i]){
	num -= assoInt[i];
	cvtdRoman += romanChar[i];
      }
    }
    return cvtdRoman;
  }
};
