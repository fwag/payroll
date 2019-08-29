################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Transactions/AddEmployeeTransaction.cpp \
../src/Transactions/AddSalariedEmployee.cpp 

OBJS += \
./src/Transactions/AddEmployeeTransaction.o \
./src/Transactions/AddSalariedEmployee.o 

CPP_DEPS += \
./src/Transactions/AddEmployeeTransaction.d \
./src/Transactions/AddSalariedEmployee.d 


# Each subdirectory must supply rules for building sources it contributes
src/Transactions/%.o: ../src/Transactions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model/PaymentClassification" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model/PaymentMethod" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Model/PaymentSchedule" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/PayrollDatabase" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Transactions" -I"/home/tmbnxvmuser/Devel/TBM2/payroll/inc/Utils" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


