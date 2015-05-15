class Solution {
public:
  bool isHappy(int n) {
    if(n == 0) return false;
    while(n != 1 && n != 4){
      int sum = 0;
      while(n){
	sum += (n % 10) * (n % 10);
	n = n / 10;
      }
      n = sum;
    }
    if(n == 4) return false;
    if(n == 1) return true;
  }
};
