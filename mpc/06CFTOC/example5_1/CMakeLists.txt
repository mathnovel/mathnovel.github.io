# CMakeList.txt: example5_1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("example5_1")

# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 确保该要求是必须的


set(LIB_PATH  D:/lib)
include_directories(
${LIB_PATH}/eigen-3.4.0
${LIB_PATH}/qpOASES-master/include
)

set(INK_LIBS_LIST "")

macro (ADD_LIBRARIES)
foreach(mod ${ARGN})
    MESSAGE("add lib: " ${mod})
set(INK_LIBS_LIST ${INK_LIBS_LIST} ${mod})
endforeach()
endmacro(ADD_LIBRARIES)

 

ADD_LIBRARIES(D:/lib/qpOASES-master/out/build/x64-Debug/libs/qpOASES.lib)

# 将源代码添加到此项目的可执行文件。
add_executable (example5_1 "example5_1.cpp" "example5_1.h" "BatchImplement.h" "BatchImplement.cpp" "RecursiveImplement.h" "RecursiveImplement.cpp")


SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${INK_LIBS_LIST})

