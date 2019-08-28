################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/PayrollDatabase/PayrollDatabase.cpp 

OBJS += \
./src/PayrollDatabase/PayrollDatabase.o 

CPP_DEPS += \
./src/PayrollDatabase/PayrollDatabase.d 


# Each subdirectory must supply rules for building sources it contributes
src/PayrollDatabase/%.o: ../src/PayrollDatabase/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Transactions" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/PayrollDatabase" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Model" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Model/PaymentMethod" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Model/PaymentClassification" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Model/PaymentSchedule" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


