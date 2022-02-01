cmake_minimum_required(VERSION 3.20)
project(lab5 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab5 src/main.c inc/que_struct.h src/list_que_operation.c inc/list_que_operation.h src/arr_que_operation.c inc/arr_que_operation.h inc/errors.h inc/utils.h src/timer.c inc/timer.h src/menu.c inc/menu.h src/utils.c inc/utils.h src/process.c inc/process.h src/print.c inc/print.h)
