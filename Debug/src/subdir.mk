################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DecklinkOutput.cpp \
../src/DesktopOutput.cpp \
../src/GraphicObject.cpp \
../src/GraphicObjectFactory.cpp \
../src/GraphicObjectNode.cpp \
../src/Image.cpp \
../src/Output.cpp \
../src/OutputFactory.cpp \
../src/Solid.cpp \
../src/TestFile.cpp \
../src/Text.cpp \
../src/Video.cpp 

OBJS += \
./src/DecklinkOutput.o \
./src/DesktopOutput.o \
./src/GraphicObject.o \
./src/GraphicObjectFactory.o \
./src/GraphicObjectNode.o \
./src/Image.o \
./src/Output.o \
./src/OutputFactory.o \
./src/Solid.o \
./src/TestFile.o \
./src/Text.o \
./src/Video.o 

CPP_DEPS += \
./src/DecklinkOutput.d \
./src/DesktopOutput.d \
./src/GraphicObject.d \
./src/GraphicObjectFactory.d \
./src/GraphicObjectNode.d \
./src/Image.d \
./src/Output.d \
./src/OutputFactory.d \
./src/Solid.d \
./src/TestFile.d \
./src/Text.d \
./src/Video.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	clang++ -std=c++11 -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/FreeType/include" -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/SDL/SDL2.framework/Headers" -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/CImg" -I/opt/X11/include -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/SDL/SDL2_image.framework/Headers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


