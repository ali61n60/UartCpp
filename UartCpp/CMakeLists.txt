cmake_minimum_required(VERSION 3.15)

project(UartCpp LANGUAGES C CXX ASM)

find_bsp(ID com.sysprogs.arm.stm32
	VERSION 2020.10
	MCU STM32F103C8
	FRAMEWORKS com.sysprogs.arm.stm32.hal com.sysprogs.arm.stm32.ll
	HWREGISTER_LIST_FILE STM32F1xxxx/DeviceDefinitions/stm32f103xb.xml)

add_bsp_based_executable(NAME UartCpp
	SOURCES
		CubeFiles/Src/gpio.c
		CubeFiles/Src/main.c
		CubeFiles/Src/stm32f1xx_hal_msp.c
		CubeFiles/Src/stm32f1xx_it.c
		CubeFiles/Src/system_stm32f1xx.c
		CubeFiles/Src/usart.c
		CubeFiles/Inc/gpio.h
		CubeFiles/Inc/main.h
		CubeFiles/Inc/stm32f1xx_it.h
		CubeFiles/Inc/usart.h
		CubeFiles/Inc/stm32f1xx_hal_conf.h
		DeveloperFiles/Header/Loop.h
		DeveloperFiles/Source/Loop.cpp
		DeveloperFiles/Header/Led.h
		DeveloperFiles/Header/MainClass.h
		DeveloperFiles/Header/Uart.h
		DeveloperFiles/Source/Led.cpp
		DeveloperFiles/Source/MainClass.cpp
		DeveloperFiles/Source/Uart.cpp
		
	GENERATE_BIN
	GENERATE_MAP)
set_source_files_properties(startup_stm32f103xb.s PROPERTIES HEADER_FILE_ONLY TRUE)
