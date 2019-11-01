################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/AnalogToDigitalConverter.c \
../src/InputCapture.c \
../src/PidControl.c \
../src/PulseWidthModulation.c \
../src/hal_entry.c 

OBJS += \
./src/AnalogToDigitalConverter.o \
./src/InputCapture.o \
./src/PidControl.o \
./src/PulseWidthModulation.o \
./src/hal_entry.o 

C_DEPS += \
./src/AnalogToDigitalConverter.d \
./src/InputCapture.d \
./src/PidControl.d \
./src/PulseWidthModulation.d \
./src/hal_entry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\e2_studio_66\eclipse\/../\Utilities\\/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -D_RENESAS_SYNERGY_ -I"C:\Users\User\Desktop\ProyectoDiplomado\Integrator-Project\Code\Integrator_Project\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\User\Desktop\ProyectoDiplomado\Integrator-Project\Code\Integrator_Project\synergy_cfg\ssp_cfg\driver" -I"C:\Users\User\Desktop\ProyectoDiplomado\Integrator-Project\Code\Integrator_Project\synergy\ssp\inc" -I"C:\Users\User\Desktop\ProyectoDiplomado\Integrator-Project\Code\Integrator_Project\synergy\ssp\inc\bsp" -I"C:\Users\User\Desktop\ProyectoDiplomado\Integrator-Project\Code\Integrator_Project\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\User\Desktop\ProyectoDiplomado\Integrator-Project\Code\Integrator_Project\synergy\ssp\inc\driver\api" -I"C:\Users\User\Desktop\ProyectoDiplomado\Integrator-Project\Code\Integrator_Project\synergy\ssp\inc\driver\instances" -I"C:\Users\User\Desktop\ProyectoDiplomado\Integrator-Project\Code\Integrator_Project\src" -I"C:\Users\User\Desktop\ProyectoDiplomado\Integrator-Project\Code\Integrator_Project\src\synergy_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '

