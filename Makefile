FAMILY = f0

AS = arm-none-eabi-gcc
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy
SZ = arm-none-eabi-size
OD = arm-none-eabi-objdump
RM = rm
MD = mkdir
AR = ar rc
CP = cp

BUILD_DIR = build
TMP_DIR = tmp
MAIN_DIR = $(FAMILY)
ADDONS_DIR = $(FAMILY)/addons
CMSIS_DIR = $(FAMILY)/cmsis
CMSIS_GENERAL_DIR = $(CMSIS_DIR)/general
CMSIS_PLATFORM_DIR = $(CMSIS_DIR)/platform

DEFINES += STM32F030

#### END USER VARIABLES

OBJS += $(addprefix $(TMP_DIR)/, $(patsubst %.c, %.o, $(wildcard $(addsuffix /*.c, $(MAIN_DIR)))))

CFLAGS += $(addprefix -D, $(DEFINES))
CFLAGS += -I$(CMSIS_GENERAL_DIR)
CFLAGS += -I$(CMSIS_PLATFORM_DIR)

all: $(BUILD_DIR)/libjstm_$(FAMILY).a $(BUILD_DIR)/jstm

$(BUILD_DIR)/jstm:
	@echo $@
	@$(CP) -r $(MAIN_DIR) $(BUILD_DIR)/jstm

$(BUILD_DIR)/libjstm_$(FAMILY).a: $(OBJS)
	@$(MD) -p build tmp
	@echo "Create library"
	@$(AR) $(BUILD_DIR)/libjstm_$(FAMILY).a $(OBJS)
	@ranlib $(BUILD_DIR)/libjstm_$(FAMILY).a

$(TMP_DIR)/%.o: %.c
	@echo "CC" $<
	@$(MD) -p $(TMP_DIR)/$(dir $<)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf build
	@$(RM) -rf tmp