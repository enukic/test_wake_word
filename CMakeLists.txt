cmake_minimum_required(VERSION 3.5)

set(EXTRA_COMPONENT_DIRS
    ./components/hardware_driver
    ../../components/esp-sr
    ../../components/player
    ../../components/sr_ringbuf
    )

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(wake_word_detection)
