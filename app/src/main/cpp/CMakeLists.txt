## For more information about using CMake with Android Studio, read the
## documentation: https://d.android.com/studio/projects/add-native-code.html
#
## Sets the minimum version of CMake required to build the native library.
#
#cmake_minimum_required(VERSION 3.18.1)
#
## Declares and names the project.
#
#project("b")
#
##设置生成的so动态库最后输出的路径
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI})
## Creates and names a library, sets it as either STATIC
## or SHARED, and provides the relative paths to its source code.
## You can define multiple libraries, and CMake builds them for you.
## Gradle automatically packages shared libraries with your APK.
#
#
##生成so
#add_library( # 设置生成库的名字
#        native-lib
#
#        # 生成动态库
#        SHARED
#
#        # 指定源码文件，这里指定test.cpp文件
#        native-lib.cpp )
#
#include_directories(
#        ../cpp/include
#        ../cpp
#        )
#
##依赖的头文件
##include_directories (${CMAKE_CURRENT_SOURCE_DIR})
##INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp)
##include_directories (../cpp/include)
##include_directories (../cpp)
#
#
#
##依赖的add库
#add_library(agent SHARED IMPORTED)
#set_target_properties(agent
#        PROPERTIES IMPORTED_LOCATION
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libmicroxrcedds_agent.so)
#
#add_library(fastcdr SHARED IMPORTED)
#set_target_properties(fastcdr
#        PROPERTIES IMPORTED_LOCATION
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libfastcdr.so)
#
#add_library(fastrtps SHARED IMPORTED)
#set_target_properties(fastrtps
#        PROPERTIES IMPORTED_LOCATION
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libfastrtps.so)
## Searches for a specified prebuilt library and stores the path as a
## variable. Because CMake includes system libraries in the search path by
## default, you only need to specify the name of the public NDK library
## you want to add. CMake verifies that the library exists before
## completing its build.
#
#find_library( # Sets the name of the path variable.
#        log-lib
#
#        # Specifies the name of the NDK library that
#        # you want CMake to locate.
#        log)
#
## Specifies libraries CMake should link to your target library. You
## can link multiple libraries, such as libraries you define in this
## build script, prebuilt third-party libraries, or system libraries.
#
#
#
#target_link_libraries( # Specifies the target library.
#        native-lib
#        agent
#        fastcdr
#        fastrtps
#        # Links the target library to the log library
#        # included in the NDK.
#        ${log-lib})