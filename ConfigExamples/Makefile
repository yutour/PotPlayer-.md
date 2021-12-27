# 编译器
CC=clang
# 中间编译产物
OBJS=main.o
# 固定编译参数
CFLAGS+= -c -Wall -g

# 获取当前项目引入的所有头文件列表
SHELL_GET_HEADERS:=$(shell find . -name "*.[ch]" | xargs head -30 | grep -h '\#include ' | sort | uniq)

# 如果有引入 math.h 头文件，增加链接参数
ifeq ($(findstring <math.h>, $(SHELL_GET_HEADERS)),<math.h>)
	LIBS+= -lm
endif

# 最终生成目标产物
all:bina

# 生成最终目标产物
bina:$(OBJS)
	$(CC) $^ -o $@ $(LIBS)

# 编译所有 .c 文件为 .o 文件
%.o:%.c
	@echo -e "🧬🧬🧬 \033[36;1mMaking ······\033[0m"
	$(CC) $^ $(CFLAGS) -o $@

# 清理中间编译产物命令
.PHONY:clean
# .SILENT:clean
clean:
	@echo -e "🧹🧹🧹 \033[36;1mCleaning ······\033[0m"
	-$(RM) *.o bina -r

# 运行最终目标产物命令
.PHONY:run
# .SILENT:run
run:
	@echo -e "🚀🚀🚀 \033[36;1mRunning ······\033[0m"
	./bina
