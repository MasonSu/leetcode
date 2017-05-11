/**
 *
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为
 * We%20Are%20Happy。
 *
 */

#include <iostream>

class Solution {
public:
  void replaceSpace(char *str, int length) {
    int countSpace = 0, orginLength = 0;
    char *ptr1 = str;
    while (*ptr1 != '\0') {
      if (*ptr1 == ' ')
        countSpace++;
      ptr1++;
      orginLength++;
    }
    if (orginLength + countSpace * 2 > length)
      return;
    char *ptr2 = ptr1 + countSpace * 2;
    while (ptr1 != ptr2) {
      if (*ptr1 != ' ') {
        *ptr2-- = *ptr1--;
      } else {
        *ptr2-- = '0';
        *ptr2-- = '2';
        *ptr2-- = '%';
        ptr1--;
      }
    }
  }
};
