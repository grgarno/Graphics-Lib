################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Mac/DecklinkOutputMac.cpp \
../src/Mac/DesktopOutputMac.cpp \
../src/Mac/ImageMac.cpp \
../src/Mac/MacGraphicObjectFactory.cpp \
../src/Mac/MacOutputFactory.cpp \
../src/Mac/TextMac.cpp \
../src/Mac/VideoMac.cpp 

OBJS += \
./src/Mac/DecklinkOutputMac.o \
./src/Mac/DesktopOutputMac.o \
./src/Mac/ImageMac.o \
./src/Mac/MacGraphicObjectFactory.o \
./src/Mac/MacOutputFactory.o \
./src/Mac/TextMac.o \
./src/Mac/VideoMac.o 

CPP_DEPS += \
./src/Mac/DecklinkOutputMac.d \
./src/Mac/DesktopOutputMac.d \
./src/Mac/ImageMac.d \
./src/Mac/MacGraphicObjectFactory.d \
./src/Mac/MacOutputFactory.d \
./src/Mac/TextMac.d \
./src/Mac/VideoMac.d 


# Each subdirectory must supply rules for building sources it contributes
src/Mac/%.o: ../src/Mac/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	clang++ -std=c++11 -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/FreeType/include" -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/SDL/SDL2.framework/Headers" -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/CImg" -I/opt/X11/include -I"/Users/grgarno/Desktop/Dropbox/CSCI 426/Assignment1 Code/lib/SDL/SDL2_image.framework/Headers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Mac/TextMac.o: ../src/Mac/TextMac.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	clang++ -std=c++11 -I.././lib/FreeType/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/Mac/TextMac.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


