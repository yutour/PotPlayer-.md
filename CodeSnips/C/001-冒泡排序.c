/**
 * @brief 冒泡排序示例
 * @file 001-冒泡排序.c
 * @version 0.0.1
 * @date ⏲️ 2021-12-20 12:40:39
 * @par Last modified time
 * ⏲️ 2021-12-27 19:50:14
 * @author yyangdid (yyangdid@gmail.com)
 */

#include <stdio.h>

#define NUMBER 5

/**
 * @brief 一：普通算法，一定会进行 n-1 轮比较
 * @param[in] a 要进行排序的数组
 * @param[in] n 数组元素的个数
 */
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

/**
 * @brief 二：优化算法，最多进行 n-1 轮比较
 * @param[in] a 要进行排序的数组
 * @param[in] n 数组元素的个数
 */
void bsort_good(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    // 状态机，假设剩余的元素已经排序完成
    int is_sorted = 1;
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
        // 改变状态，有元素进行了交换，说明剩余元素还没排序完成
        is_sorted = 0;
      }
    }
    // 如果没有元素进行交换，说明剩余元素已经排序完成，直接跳出循环
    if (is_sorted)
      break;
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
