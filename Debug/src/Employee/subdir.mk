################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Employee/Employee.cpp 

OBJS += \
./src/Employee/Employee.o 

CPP_DEPS += \
./src/Employee/Employee.d 


# Each subdirectory must supply rules for building sources it contributes
src/Employee/%.o: ../src/Employee/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Employee" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/PayrollDatabase" -I"/home/tmbnxvmuser/Devel/TBM2/Payroll/inc/Transactions" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


