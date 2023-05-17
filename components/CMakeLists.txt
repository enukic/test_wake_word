if(CONFIG_ESP32_S3_CUSTOM_HW)
    message(STATUS "Current board name is " CONFIG_ESP32_S3_CUSTOM_HW)
    list(APPEND COMPONENT_ADD_INCLUDEDIRS ./esp32s3-custom-hw)
    set(COMPONENT_SRCS
    ./esp32s3-custom-hw/bsp_board.c
    )
endif()

register_component()