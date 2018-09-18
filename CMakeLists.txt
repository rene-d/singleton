
cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_VERBOSE_MAKEFILE ON)

#add_compile_options(-flto)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

enable_testing()

#
# composant 1
#
add_library(a STATIC
    a1.cpp a2.cpp)
target_include_directories(a
    PUBLIC include)

#
# composant 2
#
add_library(b STATIC
    b.cpp)
target_link_libraries(b PUBLIC a)

#
# ici, on perd le singleton...
#
add_executable(z1 z.cpp)
target_link_libraries(z1
    PRIVATE b)
add_test(NAME z1 COMMAND $<TARGET_FILE:z1> 0)

#
# solution avec -all_load
#
add_executable(z2 z.cpp)
target_link_libraries(z2
    PRIVATE b)
set_target_properties(z2
    PROPERTIES
    LINK_FLAGS -all_load)
add_test(NAME z2 COMMAND $<TARGET_FILE:z2>  1)

#
# solution avec target de Object Library
#
add_library(aa OBJECT
    a1.cpp a2.cpp)
target_include_directories(aa
    PUBLIC include)

add_library(bb OBJECT
    b.cpp)
target_include_directories(bb
    PUBLIC $<TARGET_PROPERTY:aa,INTERFACE_INCLUDE_DIRECTORIES>)

add_executable(z3 z.cpp
    $<TARGET_OBJECTS:aa>
    $<TARGET_OBJECTS:bb>)
target_include_directories(z3
    PUBLIC $<TARGET_PROPERTY:bb,INTERFACE_INCLUDE_DIRECTORIES>)
add_test(NAME z3 COMMAND $<TARGET_FILE:z3>  1)

#
# solution avec librairie statique et appel
#
add_executable(z4 z.cpp)
target_link_libraries(z4
    PRIVATE b)
target_compile_definitions(z4 PRIVATE USE_A2)
add_test(NAME z4 COMMAND $<TARGET_FILE:z4> 1)