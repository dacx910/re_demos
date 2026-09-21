CC:=gcc
OUT_DIR:=./bin/
SRC_DIR:=./
SRCS:=$(wildcard $(SRC_DIR)*.c)
BINS:=$(patsubst $(SRC_DIR)%.c,$(OUT_DIR)%,$(SRCS))


.PHONY: clean all

all: $(BINS)

bin/x86: x86.c
	$(CC) -m32 $^ -o $@

$(OUT_DIR)%: $(SRC_DIR)%.c
	$(CC) $< -o $@

clean:
	@rm -f ./bin/*