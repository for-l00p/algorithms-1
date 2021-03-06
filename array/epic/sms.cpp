/*
5.       SMS
You are given a telephone keyboard
0-0, 1-1, 2-ABC2, 3-DEF3, 4-GHI4, 5-JKL5, 6-MNO6,7-PQRS7, 8-TUV8, 9-WXYZ9, *-space, #-char separater if you type "2", you will get 'A', that is "2"-'A', "22"-'B' ,"222"-'C', "2222"-'D' However, the digits can repeated many times "22222"-you get 'A' again You can use "#" to separate characters, for example "2#22", you get "AB". Waral éæéåææææç , However, you may also have consecutive different digits without separator:"23"-'AD' If you type "*", it means space. You a given a sequence of digits, translate it into a text message

*/
#include <unordered_map>

using namespace std;

string smsTranslate(string input);

int main(){
  vector<string> test;
  test.push_back("2");
  test.push_back("22");
  test.push_back("222");
  test.push_back("2222");
  test.push_back("22222");
  test.push_back("2#22");
  test.push_back("23");
  test.push_back("*");
  for(int i = 0; i < test.size(); i++){
    cout << test[i] << " translate into \"" << smsTranslate(test[i]) << "\"\n";
  }
  return 0;
}

string smsTranslate(string input){
  string text = "", onekey;
  if(input.size() == 0) return text;
  unordered_map<char, string> keyboard;
  keyboard['0'] = "0";
  keyboard['1'] = "1";
  keyboard['2'] = "ABC2";
  keyboard['3'] = "DEF3";
  keyboard['4'] = "GHI4";
  keyboard['5'] = "JKL5";
  keyboard['6'] = "MNO6";
  keyboard['7'] = "PQRS";
  keyboard['8'] = "TUV8";
  keyboard['9'] = "WXYZ9";
  keyboard['*'] = " ";
  keyboard['#'] = "";
  
  // count for the first char in the input string
  int count = 1;
  for(int i = 1; i <= input.length(); i++){
    if(i == input.length() || input[i] != input[i-1]){
      onekey = keyboard[input[i-1]];
      if(onekey.size()){
	text += onekey[(count - 1)% onekey.size()];
      }
      count = 1;
    }
    else{
      count++;
    }
  }
  return text;
}
