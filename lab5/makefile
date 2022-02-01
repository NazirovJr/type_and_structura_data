
CC := gcc
CFLAGS := -std=c99 -Wall -Wpedantic  -ggdb

SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out
UTESTS_DIR := ./unit_tests

OBJECTS_ALL := $(OUT_DIR)/arr_que_operation.o $(OUT_DIR)/list_que_operation.o $(OUT_DIR)/menu.o $(OUT_DIR)/print.o $(OUT_DIR)/proccess.o $(OUT_DIR)/timer.o $(OUT_DIR)/utils.o
OBJECTS_MAIN := $(OUT_DIR)/main.o
OBJECTS_UNIT := $(OUT_DIR)/check_main.o $(OUT_DIR)/check_errors.o $(OUT_DIR)/check_init.o $(OUT_DIR)/check_memory.o $(OUT_DIR)/check_math_matrix_operation.o $(OUT_DIR)/check_read.o


%.exe: $(OBJECTS_MAIN) $(OBJECTS_ALL)
	$(CC) -o $@ $^

unit_tests.exe: $(OBJECTS_UNIT) $(OBJECTS_ALL)
	$(CC) -o $@ $^

$(OUT_DIR)/check_%.o: ${UTESTS_DIR}/check_%.c ${INC_DIR}/*.h object_dir
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.o: ${SRC_DIR}/%.c ${INC_DIR}/check_*.h object_dir
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: object_dir
object_dir:
	@mkdir -p $(OUT_DIR)

.PHONY: clean
clean:
	$(RM) $(OUT_DIR)/*.o
	$(RM) *.exe
	$(RM) *.o
	rm -rf $(OUT_DIR)

