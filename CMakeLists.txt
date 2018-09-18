
cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options(-Wall -Wextra)
#add_compile_options(-flto)
#add_compile_options(-fvisibility=hidden -fvisibility-inlines-hidden)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

enable_testing()

#
# composant 1
#
add_library(a STATIC a1.cpp a2.cpp)
target_include_directories(a PUBLIC include)

#
# composant 2
#
add_library(b STATIC b.cpp)
target_link_libraries(b PUBLIC a)

#
# ici, on perd le singleton...
#
add_executable(z1 z.cpp)
target_link_libraries(z1 PRIVATE b)
add_test(NAME z1 COMMAND $<TARGET_FILE:z1> 0)

#
# solution avec -all_load ou --whole-archive
#
add_executable(z2 z.cpp)
if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    target_link_libraries(z2 PRIVATE b)
    set_target_properties(z2 PROPERTIES LINK_FLAGS -all_load)
    add_test(NAME z2 COMMAND $<TARGET_FILE:z2> 1)
else()
    target_link_libraries(z2 -Wl,--whole-archive b -Wl,--no-whole-archive)
endif()

#
# solution avec target de Object Library
#
add_library(aa OBJECT a1.cpp a2.cpp)
target_include_directories(aa PUBLIC include)

add_library(bb OBJECT b.cpp)
target_include_directories(bb
    PUBLIC $<TARGET_PROPERTY:aa,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(z3 z.cpp
    $<TARGET_OBJECTS:aa>
    $<TARGET_OBJECTS:bb>)
target_include_directories(z3
    PUBLIC $<TARGET_PROPERTY:bb,INTERFACE_INCLUDE_DIRECTORIES>)
add_test(NAME z3 COMMAND $<TARGET_FILE:z3> 1)

#
# solution avec librairie statique et appel
#
add_executable(z4 z.cpp)
target_link_libraries(z4 PRIVATE b)
target_compile_definitions(z4 PRIVATE USE_FUNC_A2)
add_test(NAME z4 COMMAND $<TARGET_FILE:z4> 1)

#
# solution avec librairie statique et variable
#
add_executable(z5 z.cpp)
target_link_libraries(z5 PRIVATE b)
target_compile_definitions(z5 PRIVATE USE_VAR_A2)
add_test(NAME z5 COMMAND $<TARGET_FILE:z5> 1)
