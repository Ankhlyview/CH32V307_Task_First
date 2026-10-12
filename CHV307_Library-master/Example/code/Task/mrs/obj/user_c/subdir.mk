################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
d:/CH32V307/CHV307_Library-master/Example/Task/user/src/isr.c \
d:/CH32V307/CHV307_Library-master/Example/Task/user/src/main.c 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

DIR_OBJS += \
./user_c/*.o \

DIR_DEPS += \
./user_c/*.d \

DIR_EXPANDS += \
./user_c/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: d:/CH32V307/CHV307_Library-master/Example/Task/user/src/isr.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
user_c/main.o: d:/CH32V307/CHV307_Library-master/Example/Task/user/src/main.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

