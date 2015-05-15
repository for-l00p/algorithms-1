/*
write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

  Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
// http://www.cnblogs.com/grandyang/p/4447233.html
class Solution {
public:
  bool isHappy(int n) {
    map <int, int> subValue;
    while(n != 1){
      int sum = 0;
      while(n){
	sum += (n % 10) * (n % 10);
	n = n / 10;
      }
      n = sum;
      if(subValue.find(sum) == subValue.end()){
	subValue[sum] = 1;
      }
      else{
	return false;
      }
    }
    return true;
  }
};
