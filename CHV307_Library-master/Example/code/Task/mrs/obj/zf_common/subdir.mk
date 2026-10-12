################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_clock.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_debug.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_fifo.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_font.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_function.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_interrupt.c 

C_DEPS += \
./zf_common/zf_common_clock.d \
./zf_common/zf_common_debug.d \
./zf_common/zf_common_fifo.d \
./zf_common/zf_common_font.d \
./zf_common/zf_common_function.d \
./zf_common/zf_common_interrupt.d 

OBJS += \
./zf_common/zf_common_clock.o \
./zf_common/zf_common_debug.o \
./zf_common/zf_common_fifo.o \
./zf_common/zf_common_font.o \
./zf_common/zf_common_function.o \
./zf_common/zf_common_interrupt.o 

DIR_OBJS += \
./zf_common/*.o \

DIR_DEPS += \
./zf_common/*.d \

DIR_EXPANDS += \
./zf_common/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
zf_common/zf_common_clock.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_clock.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_debug.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_debug.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_fifo.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_fifo.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_font.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_font.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_function.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_function.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_interrupt.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common/zf_common_interrupt.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

