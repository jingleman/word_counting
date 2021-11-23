
set(CMAKE_CXX_STANDARD 20) # cmake 3.1 supports '98', '11' or '14'. cmake 3.8 or later support '17'.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(word_counting_src
load_query.cpp
database.cpp)
add_library(${WORD_COUNTING_LIB_NAME} ${WORD_COUNTING_LIB_TYPE} ${word_counting_src})
add_executable(word_counting_driver word_counting_driver.cpp)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
add_library(widget widget.cpp)
add_executable(driver driver.cpp)
target_link_libraries(widget Eigen3::Eigen)
target_link_libraries(driver widget)

# Snippets adapted from cppreference.com:
add_executable(any any.cpp)
add_executable(decltype decltype.cpp)
add_executable(manipulation manipulation.cpp)
add_executable(move move.cpp)
add_executable(pinch pinch.cpp)
add_executable(variant variant.cpp)

# Link the executable to the word_counting library (and thread/math libs).
target_link_libraries(word_counting_driver ${WORD_COUNTING_LIB_NAME} ${CMAKE_THREAD_LIBS_INIT} ${MATH_LIBS})

# How and what to install
install(TARGETS ${WORD_COUNTING_LIB_NAME} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(TARGETS word_counting_driver driver RUNTIME DESTINATION bin)
install(DIRECTORY ../include/word_counting DESTINATION include)


