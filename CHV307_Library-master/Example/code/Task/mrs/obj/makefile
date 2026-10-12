################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################
-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include zf_driver/subdir.mk
-include zf_device/subdir.mk
-include zf_components/subdir.mk
-include zf_common/subdir.mk
-include user_c/subdir.mk
-include sdk/Startup/subdir.mk
-include sdk/Peripheral/subdir.mk
-include sdk/Core/subdir.mk
-include code/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
E01_gpio_demo.hex \

SECONDARY_LIST += \
E01_gpio_demo.lst \

SECONDARY_SIZE += \
E01_gpio_demo.siz \


# All Target
all: 
	$(MAKE) --no-print-directory main-build 

main-build: E01_gpio_demo.elf secondary-outputs

# Tool invocations
E01_gpio_demo.elf: $(OBJS) $(USER_OBJS_ESCAPE)
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -T "d:\CH32V307\CHV307_Library-master\Example\libraries\sdk\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -L"d:\CH32V307\CHV307_Library-master\Example\Task\mrs" -L"d:\CH32V307\CHV307_Library-master\Example\libraries\zf_device" -Wl,-Map,"E01_gpio_demo.map" --specs=nano.specs -u _printf_float --specs=nosys.specs -Wl,--print-memory-usage -o "E01_gpio_demo.elf" $(OBJS) $(LIBS)
E01_gpio_demo.hex: E01_gpio_demo.elf
	@	riscv-none-embed-objcopy -O ihex "E01_gpio_demo.elf" "E01_gpio_demo.hex"
E01_gpio_demo.lst: E01_gpio_demo.elf
	@	riscv-none-embed-objdump --source --all-headers --demangle --line-numbers --wide "E01_gpio_demo.elf" > "E01_gpio_demo.lst"
E01_gpio_demo.siz: E01_gpio_demo.elf
	riscv-none-embed-size --format=berkeley "E01_gpio_demo.elf"

# Other Targets
clean:
	-$(RM) $(DIR_OBJS) $(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE) E01_gpio_demo.elf
	-$(RM) $(DIR_EXPANDS) $(CALLGRAPH_DOT)
	-$(RM) $(DIR_DEPS)
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets