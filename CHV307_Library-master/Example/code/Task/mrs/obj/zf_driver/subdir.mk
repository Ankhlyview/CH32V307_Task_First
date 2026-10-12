################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_adc.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_delay.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_dvp.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_encoder.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_exti.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_flash.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_gpio.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_iic.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_pit.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_pwm.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_soft_iic.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_soft_spi.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_spi.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_timer.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_uart.c \
d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_usb_cdc.c 

C_DEPS += \
./zf_driver/zf_driver_adc.d \
./zf_driver/zf_driver_delay.d \
./zf_driver/zf_driver_dvp.d \
./zf_driver/zf_driver_encoder.d \
./zf_driver/zf_driver_exti.d \
./zf_driver/zf_driver_flash.d \
./zf_driver/zf_driver_gpio.d \
./zf_driver/zf_driver_iic.d \
./zf_driver/zf_driver_pit.d \
./zf_driver/zf_driver_pwm.d \
./zf_driver/zf_driver_soft_iic.d \
./zf_driver/zf_driver_soft_spi.d \
./zf_driver/zf_driver_spi.d \
./zf_driver/zf_driver_timer.d \
./zf_driver/zf_driver_uart.d \
./zf_driver/zf_driver_usb_cdc.d 

OBJS += \
./zf_driver/zf_driver_adc.o \
./zf_driver/zf_driver_delay.o \
./zf_driver/zf_driver_dvp.o \
./zf_driver/zf_driver_encoder.o \
./zf_driver/zf_driver_exti.o \
./zf_driver/zf_driver_flash.o \
./zf_driver/zf_driver_gpio.o \
./zf_driver/zf_driver_iic.o \
./zf_driver/zf_driver_pit.o \
./zf_driver/zf_driver_pwm.o \
./zf_driver/zf_driver_soft_iic.o \
./zf_driver/zf_driver_soft_spi.o \
./zf_driver/zf_driver_spi.o \
./zf_driver/zf_driver_timer.o \
./zf_driver/zf_driver_uart.o \
./zf_driver/zf_driver_usb_cdc.o 

DIR_OBJS += \
./zf_driver/*.o \

DIR_DEPS += \
./zf_driver/*.d \

DIR_EXPANDS += \
./zf_driver/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
zf_driver/zf_driver_adc.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_adc.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_delay.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_delay.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_dvp.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_dvp.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_encoder.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_encoder.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_exti.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_exti.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_flash.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_flash.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_gpio.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_gpio.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_iic.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_iic.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_pit.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_pit.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_pwm.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_pwm.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_soft_iic.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_soft_iic.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_soft_spi.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_soft_spi.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_spi.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_spi.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_timer.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_timer.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_uart.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_uart.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_driver/zf_driver_usb_cdc.o: d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver/zf_driver_usb_cdc.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/CH32V307/CHV307_Library-master/Example/Libraries/doc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_components" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Core" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Ld" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Peripheral" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/sdk/Startup" -I"d:/CH32V307/CHV307_Library-master/Example/Task/user/inc" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_common" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_device" -I"d:/CH32V307/CHV307_Library-master/Example/Task/code" -I"d:/CH32V307/CHV307_Library-master/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

