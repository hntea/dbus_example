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



add_executable (dbus_signale_sender_sample
"./dbus_signal_sender.cpp"
)

#设置依赖库
target_link_libraries(dbus_signale_sender_sample ${DBUS-1_LIBRARIES})
target_link_libraries(dbus_signale_sender_sample ${DBUS-GLIB-1_LIBRARIES})
target_link_libraries(dbus_signale_sender_sample ${GLIB-2_LIBRARIES})

#设置头文件路径
include_directories(
${DBUS-1_INCLUDE_DIRS}
${DBUS-GLIB-1_INCLUDE_DIRS}
${GLIB-2_INCLUDE_DIRS}
)


add_executable (dbus_signale_recv_sample
"./dbus_signal_recver.cpp"
)

#设置依赖库
target_link_libraries(dbus_signale_recv_sample ${DBUS-1_LIBRARIES})
target_link_libraries(dbus_signale_recv_sample ${DBUS-GLIB-1_LIBRARIES})
target_link_libraries(dbus_signale_recv_sample ${GLIB-2_LIBRARIES})


add_executable (dbus_signale_recv_sample_2
"./dbus_signal_recv_2.c"
)

#设置依赖库
target_link_libraries(dbus_signale_recv_sample_2 ${DBUS-1_LIBRARIES})
target_link_libraries(dbus_signale_recv_sample_2 ${DBUS-GLIB-1_LIBRARIES})
target_link_libraries(dbus_signale_recv_sample_2 ${GLIB-2_LIBRARIES})

add_executable (dbus_signale_sender_sample_2
"./dbus_signal_send_2.c"
)

#设置依赖库
target_link_libraries(dbus_signale_sender_sample_2 ${DBUS-1_LIBRARIES})
target_link_libraries(dbus_signale_sender_sample_2 ${DBUS-GLIB-1_LIBRARIES})
target_link_libraries(dbus_signale_sender_sample_2 ${GLIB-2_LIBRARIES})

add_executable (dbus_signale_test
"./dbus_signal_test.c"
)

#设置依赖库
target_link_libraries(dbus_signale_test ${DBUS-1_LIBRARIES})
target_link_libraries(dbus_signale_test ${DBUS-GLIB-1_LIBRARIES})
target_link_libraries(dbus_signale_test ${GLIB-2_LIBRARIES})