# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.1)

project ("dbus-sample")

# 包含子项目。
add_subdirectory ("async")
add_subdirectory ("sync")
add_subdirectory ("signal")
add_subdirectory ("method_call")