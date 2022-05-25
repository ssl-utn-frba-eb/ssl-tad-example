TARGET:=adt#program name

BIN:=./bin
SOURCES:=./src
INCLUDES:=./inc
TESTS:=./tests

ifeq ($(MAKECMDGOALS),build)
	BUILD:=./build
else ifeq ($(MAKECMDGOALS),dbg)
	BUILD:=./build/dbg
else ifeq ($(MAKECMDGOALS),test)
	BUILD:=./build/test
else ifeq ($(MAKECMDGOALS),testdbg)
	BUILD:=./build/testdbg
else
	BUILD:=./build
endif

CC:=gcc
CFLAGS:=-std=c11 -g -I$(INCLUDES)

CFILES:=$(shell find $(SOURCES) -printf '%P ' -name '*.c')
OFILES:=$(patsubst %.c,$(BUILD)/%.o,$(CFILES))
TCFILES:=$(shell find $(TESTS) -printf '%P ' -name '*.c')
TOFILES:=$(patsubst %.c,$(BUILD)/%.o,$(TCFILES))

.PHONY: build test clean mkdir
.DEFAULT_GOAL:=build

build: CFLAGS+=-O2
build: mkdir $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(BIN)/$(TARGET)

test: CFLAGS+=-lcspecs
test: build $(TOFILES)
	$(CC) $(CFLAGS) $(TOFILES) $(filter-out $(BUILD)/main.o,$(OFILES)) -o $(BIN)/$(TARGET).test

mkdir:
	mkdir -p $(BIN)
	mkdir -p $(BUILD)

clean:
	rm -rf $(BIN)
	rm -rf $(BUILD)
	rm -f $(TARGET)
	rm -f $(TARGET).test
	rm -f $(TARGET).dbg
	rm -f $(TARGET).dbg.test

$(OFILES): $(BUILD)/%.o: $(SOURCES)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TOFILES): $(BUILD)/%.o: $(TESTS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@