
# Source files (except the main for the executable):
set(word_counting_src
  word_counting.cpp
)

# Compile the library
add_library(${WORD_COUNTING_LIB_NAME} ${WORD_COUNTING_LIB_TYPE} ${word_counting_src})

# Compile the executable
add_executable(word_counting_exe main.cpp)

# Link the executable to the word_counting library (and thread/math libs).
target_link_libraries(word_counting_exe ${WORD_COUNTING_LIB_NAME} ${CMAKE_THREAD_LIBS_INIT} ${MATH_LIBS})

# How and what to install
install(TARGETS ${WORD_COUNTING_LIB_NAME} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(TARGETS word_counting_exe RUNTIME DESTINATION bin)
install(DIRECTORY ../include/word_counting DESTINATION include)


