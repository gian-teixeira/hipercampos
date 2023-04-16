PROJ_NAME=TP1

SRC_DIR=src
BUILD_DIR=build
INCLUDE_DIR=include
BIN_DIR=bin

C_SOURCE=$(wildcard $(SRC_DIR)/*.c)
H_SOURCE=$(wildcard $(INCLUDE_DIR)/*.h)
OBJ=$(subst .c,.o,$(subst $(SRC_DIR),$(BUILD_DIR),$(C_SOURCE)))

CC=gcc
CC_FLAGS=-c -g -I include/
 
all: $(PROJ_NAME)
 
$(PROJ_NAME): $(OBJ)
	@echo 'Finally, building $@'
	$(CC) $^ -o $@
	@echo 'Finished building binary: $@'

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c 
	@echo 'Building $<'
	$(CC) -c $< $(CC_FLAGS) -o $@ 

clean:
	rm -r build/*
