# CMakeList.txt: dbus-linux-test 的 CMake 项目，在此处包括源代码并定义
cmake_minimum_required (VERSION 3.8)

#允许gdb调试
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

#添加C++11支持及其他选项
set(CMAKE_CXX_FLAGS 
"-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -Wno-deprecated"
)

#使用 pkg-config 查找工具链中的库路径，以及头文件路径，其结果将自动返回以 xxx_LIBRARYS / XXX_INCLUDE_DIRS
find_package(PkgConfig)
pkg_search_module(DBUS-1 REQUIRED dbus-1)
pkg_search_module(DBUS-GLIB-1 REQUIRED dbus-glib-1)
pkg_search_module(GLIB-2 REQUIRED glib-2.0)

#当前目录下所有源文件赋给DIR_SRCS
AUX_SOURCE_DIRECTORY(. DIR_SRCS) 
add_executable (dbus_async_sample
${DIR_SRCS}
)

#设置依赖库
target_link_libraries(dbus_async_sample ${DBUS-1_LIBRARIES})
target_link_libraries(dbus_async_sample ${DBUS-GLIB-1_LIBRARIES})
target_link_libraries(dbus_async_sample ${GLIB-2_LIBRARIES})

#设置头文件路径
include_directories(
${DBUS-1_INCLUDE_DIRS}
${DBUS-GLIB-1_INCLUDE_DIRS}
${GLIB-2_INCLUDE_DIRS}
)


