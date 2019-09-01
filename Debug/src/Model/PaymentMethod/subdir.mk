################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Model/PaymentMethod/HoldMethod.cpp \
../src/Model/PaymentMethod/MailMethod.cpp \
../src/Model/PaymentMethod/PaymentMethod.cpp 

OBJS += \
./src/Model/PaymentMethod/HoldMethod.o \
./src/Model/PaymentMethod/MailMethod.o \
./src/Model/PaymentMethod/PaymentMethod.o 

CPP_DEPS += \
./src/Model/PaymentMethod/HoldMethod.d \
./src/Model/PaymentMethod/MailMethod.d \
./src/Model/PaymentMethod/PaymentMethod.d 


# Each subdirectory must supply rules for building sources it contributes
src/Model/PaymentMethod/%.o: ../src/Model/PaymentMethod/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model/PaymentClassification" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model/PaymentMethod" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model/PaymentSchedule" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model/Affiliation" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/PayrollDatabase" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Transactions" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Utils" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


