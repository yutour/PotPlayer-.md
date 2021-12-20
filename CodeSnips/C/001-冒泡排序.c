/*
 * @Description: 冒泡排序示例
 * @Author: yyangdid
 * @Date: 2021-12-20 12:40:39
 * @LastEditors: yyangdid
 * @LastEditTime: 2021-12-20 14:17:42
 */
#include <stdio.h>

#define NUMBER 5

void bsort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }
}

int main(void) {
  int a[NUMBER] = {3, 5, 2, 4, 7};

  bsort(a, NUMBER);

  putchar('{');
  for (int i = 0; i < NUMBER; i++) {
    printf("%d", a[i]);
    if (i < NUMBER - 1)
      printf(", ");
  }
  printf("}\n");

  return 0;
}
