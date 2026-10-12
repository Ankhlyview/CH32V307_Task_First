################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core/core_riscv.c 

C_DEPS += \
./sdk/Core/core_riscv.d 

OBJS += \
./sdk/Core/core_riscv.o 

DIR_OBJS += \
./sdk/Core/*.o \

DIR_DEPS += \
./sdk/Core/*.d \

DIR_EXPANDS += \
./sdk/Core/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
sdk/Core/core_riscv.o: d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core/core_riscv.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Project/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Project/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

