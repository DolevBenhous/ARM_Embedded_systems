################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DB/Src/DB_ADC.c \
../DB/Src/DB_I2C.c \
../DB/Src/DB_MAIN.c \
../DB/Src/DB_SERVER.c \
../DB/Src/DB_SPI.c \
../DB/Src/DB_TIMER.c \
../DB/Src/DB_UART.c \
../DB/Src/TEST.c \
../DB/Src/Tools.c 

OBJS += \
./DB/Src/DB_ADC.o \
./DB/Src/DB_I2C.o \
./DB/Src/DB_MAIN.o \
./DB/Src/DB_SERVER.o \
./DB/Src/DB_SPI.o \
./DB/Src/DB_TIMER.o \
./DB/Src/DB_UART.o \
./DB/Src/TEST.o \
./DB/Src/Tools.o 

C_DEPS += \
./DB/Src/DB_ADC.d \
./DB/Src/DB_I2C.d \
./DB/Src/DB_MAIN.d \
./DB/Src/DB_SERVER.d \
./DB/Src/DB_SPI.d \
./DB/Src/DB_TIMER.d \
./DB/Src/DB_UART.d \
./DB/Src/TEST.d \
./DB/Src/Tools.d 


# Each subdirectory must supply rules for building sources it contributes
DB/Src/%.o DB/Src/%.su: ../DB/Src/%.c DB/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Drivers/BSP/Components/lan8742 -I../DB/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DB-2f-Src

clean-DB-2f-Src:
	-$(RM) ./DB/Src/DB_ADC.d ./DB/Src/DB_ADC.o ./DB/Src/DB_ADC.su ./DB/Src/DB_I2C.d ./DB/Src/DB_I2C.o ./DB/Src/DB_I2C.su ./DB/Src/DB_MAIN.d ./DB/Src/DB_MAIN.o ./DB/Src/DB_MAIN.su ./DB/Src/DB_SERVER.d ./DB/Src/DB_SERVER.o ./DB/Src/DB_SERVER.su ./DB/Src/DB_SPI.d ./DB/Src/DB_SPI.o ./DB/Src/DB_SPI.su ./DB/Src/DB_TIMER.d ./DB/Src/DB_TIMER.o ./DB/Src/DB_TIMER.su ./DB/Src/DB_UART.d ./DB/Src/DB_UART.o ./DB/Src/DB_UART.su ./DB/Src/TEST.d ./DB/Src/TEST.o ./DB/Src/TEST.su ./DB/Src/Tools.d ./DB/Src/Tools.o ./DB/Src/Tools.su

.PHONY: clean-DB-2f-Src

