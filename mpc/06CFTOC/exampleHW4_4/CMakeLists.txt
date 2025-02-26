cmake_minimum_required(VERSION 3.16)

project(exampleHW4_4 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets PrintSupport)

set(LIB_PATH  D:/lib)

include_directories(
${CMAKE_CURRENT_SOURCE_DIR}
${LIB_PATH}/eigen-3.4.0
${LIB_PATH}/qpOASES-master/include
)

set(LINK_LIBS_LIST "")
macro (ADD_LIBRARIES)
foreach(mod ${ARGN})
    MESSAGE("add lib: " ${mod})
set(LINK_LIBS_LIST ${LINK_LIBS_LIST} ${mod})
endforeach()
endmacro(ADD_LIBRARIES)



ADD_LIBRARIES(D:/lib/qpOASES-master/out/build/x64-Debug/libs/qpOASES.lib)

set(PROJECT_SOURCES
        main.cpp



        qcustomplot.h
        qcustomplot.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(exampleHW4_4
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        mpc_controller.h mpc_controller.cpp
        plotter.h plotter.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET exampleHW4_4 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(exampleHW4_4 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(exampleHW4_4
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(exampleHW4_4 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(exampleHW4_4 PRIVATE Qt${QT_VERSION_MAJOR}::PrintSupport )
message("EXTERN LIB = " ${LINK_LIBS_LIST})
TARGET_LINK_LIBRARIES(exampleHW4_4 PRIVATE ${LINK_LIBS_LIST})


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.exampleHW4_4)
endif()
set_target_properties(exampleHW4_4 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS exampleHW4_4
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(exampleHW4_4)
endif()
