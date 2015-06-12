/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/
class Solution {
public:
  int mySqrt(int x) {
    double epsilon = 0.00001;
    double lowerBound = 0;
    double upperBound = double(x);
    double guess = (lowerBound + upperBound)/2.0;
    double diff = guess * guess - double(x);
    while(abs(diff) > epsilon){
      if(diff < 0){
	lowerBound = guess + 1;
      }
      else{
	upperBound = guess - 1;
      }
      guess = (lowerBound + upperBound)/2.0;
      diff = guess * guess - double(x);
    }
    return guess;
  }
};
