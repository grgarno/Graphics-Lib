################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Windows/DecklinkOutputWindows.cpp \
../src/Windows/DesktopOutputWindows.cpp \
../src/Windows/ImageWindows.cpp \
../src/Windows/TextWindows.cpp \
../src/Windows/VideoWindows.cpp \
../src/Windows/WindowsGraphicObjectFactory.cpp \
../src/Windows/WindowsOutputFactory.cpp 

OBJS += \
./src/Windows/DecklinkOutputWindows.o \
./src/Windows/DesktopOutputWindows.o \
./src/Windows/ImageWindows.o \
./src/Windows/TextWindows.o \
./src/Windows/VideoWindows.o \
./src/Windows/WindowsGraphicObjectFactory.o \
./src/Windows/WindowsOutputFactory.o 

CPP_DEPS += \
./src/Windows/DecklinkOutputWindows.d \
./src/Windows/DesktopOutputWindows.d \
./src/Windows/ImageWindows.d \
./src/Windows/TextWindows.d \
./src/Windows/VideoWindows.d \
./src/Windows/WindowsGraphicObjectFactory.d \
./src/Windows/WindowsOutputFactory.d 


# Each subdirectory must supply rules for building sources it contributes
src/Windows/%.o: ../src/Windows/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	clang++ -std=c++11 -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/FreeType/include" -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/SDL/SDL2.framework/Headers" -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/CImg" -I/opt/X11/include -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/SDL/SDL2_image.framework/Headers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


