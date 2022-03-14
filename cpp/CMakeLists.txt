cmake_minimum_required(VERSION 3.12)
project(dojorobocup)

set(sources
    game_service.cc game_service.h
    test_service.cc test_service.h
    serialization_helper.cc serialization_helper.h
    string_helper.cc string_helper.h)

add_executable(server
    server.cc ${sources})

target_include_directories(server PRIVATE restbed/source)
target_compile_features(server PRIVATE cxx_std_17)
target_compile_options(server PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
target_link_libraries(server PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:restbed-shared>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:restbed>
)
target_link_directories(server PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:${CMAKE_CURRENT_SOURCE_DIR}/restbed/debug>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:${CMAKE_CURRENT_SOURCE_DIR}/restbed/distribution/library>
)
