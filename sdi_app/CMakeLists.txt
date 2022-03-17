cmake_minimum_required(VERSION 3.5)

project(sdi_app LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -no-pie")

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
          gui/application.cpp
          gui/application.h
          gui/application.ui
          gui/menu_driver.cpp
          gui/menu_driver.h
          gui/menu_driver.ui
          gui/menu_forwarder.cpp
          gui/menu_forwarder.h
          gui/menu_forwarder.ui
          gui/menu_company.cpp
          gui/menu_company.h
          gui/menu_company.ui
          gui/menu_owner.cpp
          gui/menu_owner.h
          gui/menu_owner.ui
          )
else()
  add_executable(sdi_app
          src/main.cpp
          gui/application.cpp
          gui/application.h
          gui/application.ui
          gui/menu_driver.cpp
          gui/menu_driver.h
          gui/menu_driver.ui
          gui/menu_forwarder.cpp
          gui/menu_forwarder.h
          gui/menu_forwarder.ui
          gui/menu_company.cpp
          gui/menu_company.h
          gui/menu_company.ui
          gui/menu_owner.cpp
          gui/menu_owner.h
          gui/menu_owner.ui
          headers/cargo_owner.h headers/forwarder.h headers/driver.h headers/transp_company.h src/cargo_owner.cpp src/driver.cpp src/forwarder.cpp src/transp_company.cpp headers/user.h src/user.cpp headers/cargo.h src/cargo.cpp)
endif()

target_link_libraries(sdi_app PRIVATE Qt5::Widgets -lpqxx -lpq)
