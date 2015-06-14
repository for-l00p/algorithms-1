/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
class Solution {
public:
  int strStr(string haystack, string needle) {
    // a must in C++, elsewise overflow in the for condition
    int haystackLength = haystack.size();
    int needleLength = needle.size();
    if(haystack == needle) {
      return 0;
    }
    for(int i = 0; i <= haystackLength - needleLength; i++){
      int j = 0;
      for(; j < needleLength && i + j < haystackLength; j++){
	if(needle[j] != haystack[i + j]) break;
      }
      if(j == needleLength) {
	return i;
      }
    }
    return -1;
  }
};
