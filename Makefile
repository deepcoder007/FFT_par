CC=g++

MKFILE_PATH= $(abspath $(lastword  $(MAKEFILE_LIST)))
CUR_DIR= $(notdir $(patsubst %/,%,$(dir $(MKFILE_PATH))))
ROOT= $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))


INCLUDE_PATH=$(ROOT)/include
SRC_PATH=$(ROOT)/src
OBJ_PATH=$(ROOT)/obj
BIN_PATH=$(ROOT)/bin


SRC=$(SRC_PATH)/Complex.cpp \
	$(SRC_PATH)/main.cpp \
	$(SRC_PATH)/poly_mult_naive.cpp \
	$(SRC_PATH)/polynomial.cpp \
	$(SRC_PATH)/fft.cpp  \
	$(SRC_PATH)/fft_par.cpp  \
	$(SRC_PATH)/test2.cpp


OBJ=$(OBJ_PATH)/Complex.o \
	$(OBJ_PATH)/main.o \
	$(OBJ_PATH)/poly_mult_naive.o \
	$(OBJ_PATH)/polynomial.o  \
	$(OBJ_PATH)/fft_par.o   \
	$(OBJ_PATH)/fft.o  \


OBJ2=$(OBJ_PATH)/Complex.o \
	$(OBJ_PATH)/poly_mult_naive.o \
	$(OBJ_PATH)/polynomial.o  \
	$(OBJ_PATH)/fft_par.o   \
	$(OBJ_PATH)/fft.o  \
	$(OBJ_PATH)/test2.o

INCLUDES= -I $(INCLUDE_PATH)

prog: $(OBJ)
	$(CC) -std=c++11 -pthread $^  -o $(BIN_PATH)/$@

test: $(OBJ2)
	$(CC) -std=c++11 -pthread $^  -o $(BIN_PATH)/$@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CC) -std=c++11 -pthread $(INCLUDES) -c $< -o $@

clean:
	rm ./obj/*
	rm ./bin/prog
	rm ./bin/test
