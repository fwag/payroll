################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Payroll.cpp 

OBJS += \
./src/Payroll.o 

CPP_DEPS += \
./src/Payroll.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Transactions" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/PayrollDatabase" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Model" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Model/PaymentMethod" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Model/PaymentClassification" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Model/PaymentSchedule" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


