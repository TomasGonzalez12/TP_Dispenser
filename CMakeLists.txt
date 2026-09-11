# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.3.1)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.1)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico2_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(TP_Dispenser C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable
add_executable(TP_Dispenser

        main.c

        # OLED
        Oled/picoOled.c

        # VL53L0X
        VL53LOX/tof.c
)

pico_set_program_name(TP_Dispenser "TP_Dispenser")
pico_set_program_version(TP_Dispenser "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(TP_Dispenser 0)
pico_enable_stdio_usb(TP_Dispenser 0)

# Libraries
target_link_libraries(TP_Dispenser
        pico_stdlib
        hardware_i2c
)

# Include directories
target_include_directories(TP_Dispenser PRIVATE

        ${CMAKE_CURRENT_LIST_DIR}

        ${CMAKE_CURRENT_LIST_DIR}/Oled

        ${CMAKE_CURRENT_LIST_DIR}/VL53LOX
)

pico_add_extra_outputs(TP_Dispenser)

