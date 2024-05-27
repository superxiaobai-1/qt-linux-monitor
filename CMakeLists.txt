cmake_minimum_required(VERSION 3.10)

project(system-monitor VERSION 0.0.121 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets PrintSupport)

set(SOURCES
    main.cpp
    mainwindow.cpp
    processinformationworker.cpp
    workerthread.cpp
    resourcesworker.cpp
    filesystemworker.cpp
    processpropertiesdialogue.cpp
    processtools.cpp
    aboutdialogue.cpp
    qcustomplot.cpp
    cputools.cpp
    preferencesdialogue.cpp
    memoryconverter.cpp
    colourhelper.cpp
)

set(HEADERS
    mainwindow.h
    processinformationworker.h
    tablenumberitem.h
    workerthread.h
    resourcesworker.h
    tablememoryitem.h
    filesystemworker.h
    processpropertiesdialogue.h
    processtools.h
    aboutdialogue.h
    qcustomplot.h
    cputools.h
    preferencesdialogue.h
    hashqstring.h
    memoryconverter.h
    colourhelper.h
)

set(FORMS
    mainwindow.ui
    processpropertiesdialogue.ui
    aboutdialogue.ui
    preferencesdialogue.ui
)

# Generate MOC, UIC and RCC targets
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Include source directory for headers and UI files
include_directories(${CMAKE_SOURCE_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS})

# Link against Qt libraries
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::PrintSupport pthread)

# Define version macros
add_definitions(-DVERSION_MAJOR=${PROJECT_VERSION_MAJOR} -DVERSION_MINOR=${PROJECT_VERSION_MINOR} -DVERSION_BUILD=${PROJECT_VERSION_PATCH})

# Custom libraries
find_library(PROCPS_LIBRARY procps libprocps6)
if (PROCPS_LIBRARY)
    target_link_libraries(${PROJECT_NAME} ${PROCPS_LIBRARY})
else()
    message(FATAL_ERROR "libprocps not found")
endif()

# Installation directives
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION /tmp)
install(FILES  test.jpeg  DESTINATION /tmp)
install(FILES system-monitor.desktop DESTINATION /usr/share/applications)

# Uncomment and edit the following lines if you have an icon to install
# install(FILES system-monitor.png DESTINATION /usr/share/icons/hicolor/48x48/apps)
