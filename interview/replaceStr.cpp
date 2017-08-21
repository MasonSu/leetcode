#include <iostream>
#include <string>
#include <cstring>

#include "catch.hpp"

using std::string;

class Solution {
public:
  char* transform(char* str, int size) {
    int index = 0;

    for (int i = 0; i < size;) {
      if (str[i] == 'A' && str[i + 1] == 'B') {
        str[index++] = 'B';
        i += 2;
      } else {
        str[index++] = str[i];
        i++;
      }
    }

    int count = 0;
    for (int i = 0; i < index; ++i) {
      if (str[i] == 'C')
        count++;
    }

    size = index + count;
    str[size] = '\0';
    size -= 1;

    for (int i = index - 1; i >= 0; --i) {
      if (str[i] == 'C') {
        str[size--] = 'D';
        str[size--] = 'C';
      } else {
        str[size--] = str[i];
      }
    }

    return str;
  }
};

TEST_CASE("str replace", "[transform]") {
  Solution test;

  char str1[20] = "CC";
  REQUIRE(string(test.transform(str1, strlen(str1))) == "CDCD");

  char str2[20] = "ABAB";
  REQUIRE(string(test.transform(str2, strlen(str2))) == "BB");

  char str3[20] = "ABC";
  REQUIRE(string(test.transform(str3, strlen(str3))) == "BCD");

  char str4[20] = "ABCCABD";
  REQUIRE(string(test.transform(str4, strlen(str4))) == "BCDCDBD");

  char str5[20] = "ABDCACABCCAB";
  REQUIRE(string(test.transform(str5, strlen(str5))) == "BDCDACDBCDCDB");
}