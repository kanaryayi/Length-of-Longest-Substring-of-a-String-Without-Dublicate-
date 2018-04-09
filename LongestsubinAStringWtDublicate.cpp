#include <iostream>
#include <string>
#include <ctype.h>
#include <map>
using namespace std;
// make string lower case
string convertLowerCase(string s){
  int i = s.size()-1;
  while(i>-1){
    if(!islower(s[i])){
      s[i] = tolower(s[i]);
    }
    i--;
  }
  return s;
}
int substringWhDublicate(string s){
  int size = s.length();
  int maxSubs = 0;
  int currentSubs = 0;
  //head holds start indes of substring
  int head = -1;
  // char and index of char
  // map holds last visited index of characters
  map<char,int> chars;
  for(int i = 0 ;i<size ;i++){
      // in map means visited
      if(chars.count(s[i])>0){
          // substring reaches a dublicate char
          if(currentSubs>maxSubs){
            maxSubs = currentSubs;
          }
          // curtail length from index of dublicate character
          // use head variable to make it dynamically
          currentSubs = currentSubs - chars[s[i]] + head + 1;
          head = chars[s[i]];
          chars[s[i]] = i;
      }
      // not in map means not visited
      else{
        chars[s[i]] = i;
        currentSubs ++;
      }
  }
  //check if curren greater than max for last round
  if(maxSubs<currentSubs){
    return currentSubs;
  }
  return maxSubs;

}
int main(int argc, char const *argv[]) {
  string input = "asdasde";
  input = convertLowerCase(input);
  cout << input<<endl;
  int res = substringWhDublicate(input);
  cout << res << endl;
  return 0;
}
