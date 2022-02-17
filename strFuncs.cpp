#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "strFuncs.h"
using namespace std;


/* Precondition: Two valid strings s1 and s2, each containing a mix of alphabets, spaces and punctuations
 * Post condition: Return true if one string is an anagram of the other string. White spaces, punctuations and
 * the case for the letters (upper or lower) should not
 * affect your result. 
 */
string simplifyString(string s){
  for (int i = 0; i < s.size(); i++) {
    if (ispunct(s[i]) || s[i] == ' ') {
      s.erase(i--, 1);
    } else {
      s[i] = tolower(s[i]);
    }
  }
  return s;
}

bool isAnagram(string s1, string s2){
  string simplifiedS1 = simplifyString(s1);
  string simplifiedS2 = simplifyString(s2);
  if (simplifiedS1.size() != simplifiedS2.size()) {
    return false;
  } else if (simplifiedS1.size() == 0 && simplifiedS2.size() == 0) {
    return true;
  } else if (simplifiedS1.size() == 1 && simplifiedS2.size() == 1) {
    if (simplifiedS1 == simplifiedS2) {
      return true;
    } else {
      return false;
    }
  } else {
    string firstLetter = simplifiedS1.substr(0,1);
    string restLetter = simplifiedS1.substr(1);
    string newS2 = simplifiedS2.erase(simplifiedS2.find(firstLetter));
    isAnagram(restLetter, newS2);
  }
  return true;
}

/* Precondition: s1 is a valid string that may contain upper or lower case alphabets, no spaces or special characters
 * Postcondition: Returns true if s1 is a palindrome, false otherwise
 * You should provide a recursive solution
 */
bool isPalindrome(const string s1){
  string simplifiedS1 = simplifyString(s1);
  string first = simplifiedS1.substr(0,1);
  string last = simplifiedS1.substr(simplifiedS1.size()-1,1);

  if (first == last) {
    string rest = simplifiedS1.substr(1,simplifiedS1.size()-2);
    if (simplifiedS1.size() <= 1) {
      return true;
    }
    return isPalindrome(rest);
  } else {
    return false;
  }
  return false;
}


