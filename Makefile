# in device.mk MCU, PROGRAMMER, PORT, F_CPU, BAUD variables are defined
-include device.mk

PROG := main.elf

AVR_GCC := avr-gcc
AVRDUDE := avrdude

SRC_DIR := src
SRCS := $(wildcard $(SRC_DIR)/*.c)

BUILD_DIR := build
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

LIB_DIR := lib
LIB_SRCS := $(wildcard $(LIB_DIR)/*.c)
LIB_INCS := $(wildcard $(LIB_DIR)/*.h)
LIB_OBJS := $(LIB_SRCS:$(LIB_DIR)/%.c=$(BUILD_DIR)/%.o)

COMPILE_COMMANDS := compile_commands.json

CFLAGS := -Wall -Wpedantic -Wconversion -Os -ffunction-sections -fdata-sections -std=c17 -I$(LIB_DIR)
LDFLAGS := -mmcu=$(MCU) -Wl,--gc-sections -Wl,--as-needed

# Obligatory flags
CFLAGS += -mmcu=$(MCU) -DF_CPU=$(CPU_FREQ) -DBAUD=$(BAUD_RATE)

ifndef MCU
$(error MCU is not defined. Please define it to compile program)
endif

ifndef PROGRAMMER
$(error PROGRAMMER is not defined. Please define it to flash program to the device)
endif

ifndef PORT
$(error PORT is not defined. Please define it to flash program to the device)
endif

ifndef CPU_FREQ
$(error CPU_FREQ is not defined. Please define it to compile program)
endif

ifndef BAUD_RATE
$(error BAUD_RATE is not defined. Please define it to compile program)
endif

all: flash $(COMPILE_COMMANDS)

flash: $(BUILD_DIR)/$(PROG)
	$(AVRDUDE) -v -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -U flash:w:$(BUILD_DIR)/$(PROG)

$(COMPILE_COMMANDS): $(BUILD_DIR)/$(PROG)
	compiledb -n make

clean:
	rm -rf $(BUILD_DIR) $(COMPILE_COMMANDS)

$(BUILD_DIR)/$(PROG): $(OBJS) $(LIB_OBJS)
	$(AVR_GCC) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c | $(BUILD_DIR)
	$(AVR_GCC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(AVR_GCC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: all flash clean
