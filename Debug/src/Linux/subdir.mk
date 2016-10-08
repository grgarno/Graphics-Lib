################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Linux/DecklinkOutputLinux.cpp \
../src/Linux/DesktopOutputLinux.cpp \
../src/Linux/ImageLinux.cpp \
../src/Linux/LinuxGraphicObjectFactory.cpp \
../src/Linux/LinuxOutputFactory.cpp \
../src/Linux/TextLinux.cpp \
../src/Linux/VideoLinux.cpp 

OBJS += \
./src/Linux/DecklinkOutputLinux.o \
./src/Linux/DesktopOutputLinux.o \
./src/Linux/ImageLinux.o \
./src/Linux/LinuxGraphicObjectFactory.o \
./src/Linux/LinuxOutputFactory.o \
./src/Linux/TextLinux.o \
./src/Linux/VideoLinux.o 

CPP_DEPS += \
./src/Linux/DecklinkOutputLinux.d \
./src/Linux/DesktopOutputLinux.d \
./src/Linux/ImageLinux.d \
./src/Linux/LinuxGraphicObjectFactory.d \
./src/Linux/LinuxOutputFactory.d \
./src/Linux/TextLinux.d \
./src/Linux/VideoLinux.d 


# Each subdirectory must supply rules for building sources it contributes
src/Linux/%.o: ../src/Linux/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	clang++ -std=c++11 -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/FreeType/include" -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/SDL/SDL2.framework/Headers" -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/CImg" -I/opt/X11/include -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/SDL/SDL2_image.framework/Headers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


