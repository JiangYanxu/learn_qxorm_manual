cmake_minimum_required(VERSION 3.15)
project(QxOrmDemo)

set(QT_ROOT "C:/Qt/5.15.2")

set(CMAKE_AUTOMOC ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.runtime)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
    message(STATUS 
        "======== No build type is specified, used default: ${CMAKE_BUILD_TYPE}. "
        "-DCMAKE_BUILD_TYPE:STRING=[Debug|Release|RelWithDebInfo|MinSizeRel|<custom>]")
endif()

# include(./QxOrm.cmake)

list(APPEND CMAKE_PREFIX_PATH ${QT_HOME})
find_package(Qt5 REQUIRED COMPONENTS Core Sql)

add_library(QxOrmDll INTERFACE)
file(REAL_PATH "D:/Program_Files_built_using_mingw/QxOrmDll" QxOrmDll_HOME)
find_library(QxOrmDll_LIBRARY NAMES QxOrmd PATHS ${QxOrmDll_HOME}/lib NO_DEFAULT_PATH REQUIRED)
target_include_directories(QxOrmDll INTERFACE ${QxOrmDll_HOME}/include ${QxOrmDll_HOME}/inl)
target_link_libraries(QxOrmDll INTERFACE ${QxOrmDll_LIBRARY} Qt5::Core Qt5::Sql)


file(REAL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/inc ${PROJECT_NAME}_INC_PATH)
file(GLOB_RECURSE ${PROJECT_NAME}_SOURCES CONFIGURE_DEPENDS inc/*.hpp src/*.cpp)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${${PROJECT_NAME}_INC_PATH})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Sql QxOrmDll)
target_compile_definitions(${PROJECT_NAME} PRIVATE _BUILD_MY_DEMO)

add_custom_target(windeployqt
    COMMAND ${QT_HOME}/bin/windeployqt.exe --no-translations ${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}
    COMMENT "Copy Qt's Dll required for ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX}"
)

# cmake -G "MinGW Makefiles" --system-information "MinGW System Information.txt"
# cmake -G "Visual Studio 17 2022" --system-information "VS 17 2022 System Information.txt"