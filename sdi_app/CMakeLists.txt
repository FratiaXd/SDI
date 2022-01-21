cmake_minimum_required(VERSION 3.5)

project(sdi_app LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(sdi_app SHARED
          src/main.cpp
    login.cpp
          headers/login.h
    login.ui
  )
else()
  add_executable(sdi_app
          src/main.cpp
    login.cpp
          headers/login.h
    login.ui
          headers/cargo_owner.h headers/forwarder.h headers/driver.h headers/transp_company.h headers/cargo_receiver.h src/cargo_owner.cpp src/cargo_receiver.cpp src/driver.cpp src/forwarder.cpp src/transp_company.cpp headers/user.h src/user.cpp)
endif()

target_link_libraries(sdi_app PRIVATE Qt5::Widgets)
