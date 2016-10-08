################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Mac/CNSWindow/CMacsTypes.c 

OBJS += \
./src/Mac/CNSWindow/CMacsTypes.o 

C_DEPS += \
./src/Mac/CNSWindow/CMacsTypes.d 


# Each subdirectory must supply rules for building sources it contributes
src/Mac/CNSWindow/%.o: ../src/Mac/CNSWindow/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


