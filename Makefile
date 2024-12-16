# 编译器
CC = gcc
# 编译选项
CFLAGS = -g -Wall
# 项目源文件
SRCS = main.c crc_func.c check_sum_func.c
# 目标文件
OBJS = $(SRCS:.c=.o)
# 输出的可执行文件
TARGET = main.exe

# 默认目标
all: $(TARGET)

# 链接目标文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	@$(MAKE) clean_objs

# 生成每个 .o 文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 只清理 .o 文件
clean_objs:
	rm -f $(OBJS)

.PHONY: all clean clean_objs
