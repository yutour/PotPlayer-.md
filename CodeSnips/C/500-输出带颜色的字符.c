/*
 * @Description: 只在 Linux 下测试了，未在 Windows 下测试。
 *               颜色代号和功能详表见维基百科 :
 *               https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
 *               方法一在不同的终端有时候会多一个换行，暂时还不知为什么。
 *               推荐方法二、三、四。
 * @Author: yyangdid
 * @Date: 2021-12-20 14:19:16
 * @LastEditors: yyangdid
 * @LastEditTime: 2021-12-20 14:22:05
 */
#include <stdio.h>

// ///////////////////////////////////////////////////////////////////////////
// 方法一：使用宏设置独立颜色输出，在输出语句前使用
// 设置输出前景色
#define PRINT_FONT_BLA printf("\033[30m"); // 黑色
#define PRINT_FONT_RED printf("\033[31m"); // 红色
#define PRINT_FONT_GRE printf("\033[32m"); // 绿色
#define PRINT_FONT_YEL printf("\033[33m"); // 黄色
#define PRINT_FONT_BLU printf("\033[34m"); // 蓝色
#define PRINT_FONT_PUR printf("\033[35m"); // 紫色
#define PRINT_FONT_CYA printf("\033[36m"); // 青色
#define PRINT_FONT_WHI printf("\033[37m"); // 白色
// 设置输出背景色
#define PRINT_BACK_BLA printf("\033[40m"); // 黑色
#define PRINT_BACK_RED printf("\033[41m"); // 红色
#define PRINT_BACK_GRE printf("\033[42m"); // 绿色
#define PRINT_BACK_YEL printf("\033[43m"); // 黄色
#define PRINT_BACK_BLU printf("\033[44m"); // 蓝色
#define PRINT_BACK_PUR printf("\033[45m"); // 紫色
#define PRINT_BACK_CYA printf("\033[46m"); // 青色
#define PRINT_BACK_WHI printf("\033[47m"); // 白色
// 输出属性设置
#define PRINT_ATTR_REC printf("\033[0m"); // 重新设置属性到缺省设置
#define PRINT_ATTR_BOL printf("\033[1m"); // 设置粗体
#define PRINT_ATTR_LIG printf("\033[2m"); // 设置一半亮度(模拟彩色显示器的颜色)
#define PRINT_ATTR_LIN printf("\033[4m"); // 设置下划线(模拟彩色显示器的颜色)
#define PRINT_ATTR_GLI printf("\033[5m");   // 设置闪烁
#define PRINT_ATTR_REV printf("\033[7m");   // 设置反向图象
#define PRINT_ATTR_THI printf("\033[22m");  // 设置一般密度
#define PRINT_ATTR_ULIN printf("\033[24m"); // 关闭下划线
#define PRINT_ATTR_UGLI printf("\033[25m"); // 关闭闪烁
#define PRINT_ATTR_UREV printf("\033[27m"); // 关闭反向图象

// 示例函数
void before_printf(void) {
  PRINT_FONT_BLA
  printf("hello world!\n");
  PRINT_FONT_BLU
  printf("hello world!\n");
  PRINT_FONT_RED
  printf("hello world!\n");
  PRINT_FONT_YEL
  printf("hello world!\n");
  PRINT_FONT_GRE
  printf("hello world!\n");
  PRINT_FONT_WHI
  printf("hello world!\n");
  PRINT_FONT_PUR
  printf("hello world!\n");
  PRINT_ATTR_REV
  printf("hello world!\n");
  PRINT_ATTR_REC
}

// ///////////////////////////////////////////////////////////////////////////
// 方法二：使用宏设置独立颜色，在输出语句中使用
#define NONE "\033[m"
#define RED "\033[0;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BLUE "\033[0;34m"
#define LIGHT_BLUE "\033[1;34m"
#define DARY_GRAY "\033[1;30m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define LIGHT_GRAY "\033[0;37m"
#define WHITE "\033[1;37m"

// 示例函数
void in_printf(void) {
  printf(NONE "Hello World!\n");
  printf(RED "Hello World!\n");
  printf(LIGHT_RED "Hello World!\n");
  printf(GREEN "Hello World!\n");
  printf(LIGHT_GREEN "Hello World!\n");
  printf(BLUE "Hello World!\n");
  printf(LIGHT_BLUE "Hello World!\n");
  printf(DARY_GRAY "Hello World!\n");
  printf(CYAN "Hello World!\n");
  printf(LIGHT_CYAN "Hello World!\n");
  printf(PURPLE "Hello World!\n");
  printf(LIGHT_PURPLE "Hello World!\n");
  printf(BROWN "Hello World!\n");
  printf(YELLOW "Hello World!\n");
  printf(LIGHT_GRAY "Hello World!\n");
  printf(WHITE "Hello World!\n");
  printf("END\n");
}

// ///////////////////////////////////////////////////////////////////////////
// 方法三：这里的两个输出 256 色的函数为独立函数，可单独使用
// 输出 256 前景色
void printf_foreground(void) {
  for (int i = 0; i < 256; i++) {
    if (i % 16 == 0 && i != 0)
      putchar('\n');
    printf("\033[38;5;%dm%5d\033[0m", i, i);
  }
  putchar('\n');
}

// 输出 256 背景色
void printf_background(void) {
  for (int i = 0; i < 256; i++) {
    if (i % 16 == 0 && i != 0)
      putchar('\n');
    printf("\033[48;5;%dm%5d\033[0m", i, i);
  }
  putchar('\n');
}

// ///////////////////////////////////////////////////////////////////////////
// 方法四：输出 24 位真色（RGB）
void printf_24(void) {
  printf("\033[48;2;33;136;255m24 True Color foreground\033[0m\n");
  printf("\033[38;2;33;136;255m24 True Color foreground\033[0m\n");
  printf("\033[48;2;33;136;255m\033[38;2;246;99;44m\033[1m24 True Color "
         "foreground\033[0m\n");
}

// ///////////////////////////////////////////////////////////////////////////
int main(void) {
  printf("方法一：\n");
  before_printf();
  putchar('\n');

  printf("方法二：\n");
  in_printf();
  putchar('\n');

  printf("方法三：\n - 输出 256 前景色：\n");
  printf_foreground();
  putchar('\n');
  printf(" - 输出 256 背景色：\n");
  printf_background();
  putchar('\n');
  printf("方法四：输出 24 位真色（RGB）：\n");
  printf_24();

  return 0;
}
