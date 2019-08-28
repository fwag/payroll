################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Model/PaymentClassification/HourlyClassification.cpp \
../src/Model/PaymentClassification/PaymentClassification.cpp \
../src/Model/PaymentClassification/SalariedClassification.cpp 

OBJS += \
./src/Model/PaymentClassification/HourlyClassification.o \
./src/Model/PaymentClassification/PaymentClassification.o \
./src/Model/PaymentClassification/SalariedClassification.o 

CPP_DEPS += \
./src/Model/PaymentClassification/HourlyClassification.d \
./src/Model/PaymentClassification/PaymentClassification.d \
./src/Model/PaymentClassification/SalariedClassification.d 


# Each subdirectory must supply rules for building sources it contributes
src/Model/PaymentClassification/%.o: ../src/Model/PaymentClassification/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model/PaymentClassification" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model/PaymentMethod" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model/PaymentSchedule" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/PayrollDatabase" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Transactions" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


