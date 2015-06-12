/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
  bool isPalindrome(int x) {
    if(x < 0) return false;
    int counterX = 1;
    while(x / counterX >= 10){
      counterX *= 10;
    }
    while(x){
      int lessSig = x % 10;
      int mostSig = x / counterX;
      if(lessSig != mostSig) return false;
      x = (x % counterX) / 10;
      counterX /= 100;
    }
    return true;
  }
};
