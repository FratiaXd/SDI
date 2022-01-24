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
          gui/registration.cpp gui/menu_cargoown.cpp gui/user_type.cpp gui/start.cpp gui/menu_cargoown.cpp gui/menu_trcomp.cpp gui/menu_forwarder.cpp gui/menu_driver.cpp gui/driver_reg.cpp gui/menu_receiver.cpp gui/order_history.cpp
          gui/registration.h gui/menu_cargoown.h gui/user_type.h gui/start.h gui/menu_cargoown.h gui/menu_trcomp.h gui/menu_forwarder.h gui/menu_driver.h gui/driver_reg.h gui/menu_receiver.h gui/order_history.h
          gui/registration.ui gui/menu_cargoown.ui gui/user_type.ui gui/start.ui gui/menu_cargoown.ui gui/menu_trcomp.ui gui/menu_forwarder.ui gui/menu_driver.ui gui/driver_reg.ui gui/menu_receiver.ui gui/order_history.ui
  )
else()
  add_executable(sdi_app
          src/main.cpp
          gui/registration.cpp gui/menu_cargoown.cpp gui/user_type.cpp gui/start.cpp gui/menu_cargoown.cpp gui/menu_trcomp.cpp gui/menu_forwarder.cpp gui/menu_driver.cpp gui/driver_reg.cpp gui/menu_receiver.cpp gui/order_history.cpp
          gui/registration.h gui/menu_cargoown.h gui/user_type.h gui/start.h gui/menu_cargoown.h gui/menu_trcomp.h gui/menu_forwarder.h gui/menu_driver.h gui/driver_reg.h gui/menu_receiver.h gui/order_history.h
          gui/registration.ui gui/menu_cargoown.ui gui/user_type.ui gui/start.ui gui/menu_cargoown.ui gui/menu_trcomp.ui gui/menu_forwarder.ui gui/menu_driver.ui gui/driver_reg.ui gui/menu_receiver.ui gui/order_history.ui
          headers/cargo_owner.h headers/forwarder.h headers/driver.h headers/transp_company.h src/cargo_owner.cpp src/driver.cpp src/forwarder.cpp src/transp_company.cpp headers/user.h src/user.cpp headers/cargo.h src/cargo.cpp)
endif()

target_link_libraries(sdi_app PRIVATE Qt5::Widgets)
