cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

include(pico_extras_import_optional.cmake)


include("cmake/usb/cmake_install.cmake")

project(my_project C CXX ASM )
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


pico_sdk_init()

add_executable(main
    main.cpp
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(main pico_stdlib)


# enable usb output, disable uart output
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

pico_add_extra_outputs(main)

if (TARGET tinyusb_device)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()