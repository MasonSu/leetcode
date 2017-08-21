/**
 *
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为
 * We%20Are%20Happy。
 *
 */

#include <iostream>

/* 最开始如果遍历修改了str, 记得一定要恢复, 否则str已经不再指向原来的位置了 */
class Solution {
public:
  void replaceSpace(char *str, int length) {
    int originLength = 0, count = 0;
    char *ptr = str;

    while (*ptr != '\0') {
      originLength++;
      if (*ptr == ' ')
        count++;
      ptr++;
    }

    int size = originLength + count * 2 - 1;
    str[size + 1] = '\0';
    for (int i = originLength - 1; i >= 0; --i) {
      if (str[i] == ' ') {
        str[size--] = '0';
        str[size--] = '2';
        str[size--] = '%';
      } else {
        str[size] = str[i];
        size--;
      }
    }
  }
};

