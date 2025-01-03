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

# 配置文件和生成的头文件
CFG_FILE = config.cfg
MACROS_FILE = macros.h

# 默认目标
all: $(TARGET)

.PHONY: $(MACROS_FILE)

# 目标：生成 macros.h 文件
$(MACROS_FILE):
	@echo "Generating macros.h from $(CFG_FILE)"
	python generate_macros.py $(CFG_FILE) $(MACROS_FILE)|| (echo "Error generating macros.h" && exit 1)
	@echo "macros.h generated successfully"

# 链接目标文件
$(TARGET): $(OBJS) $(MACROS_FILE)
	$(CC) $(CFLAGS) -o $@ $^
	@$(MAKE) clean_objs

# 生成每个 .o 文件
%.o: %.c $(MACROS_FILE)  # 依赖于 macros.h
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET) $(MACROS_FILE)

# 只清理 .o 文件
clean_objs:
	rm -f $(OBJS)

.PHONY: all clean clean_objs
