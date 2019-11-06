# - Build subscript for the MPAGSCipher library unit tests

# Create interfaces Library for catch
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Most basic tests
add_executable(testCatch testCatch.cpp)
target_link_libraries(testCatch PRIVATE Catch)
add_test(NAME test-catch COMMAND testCatch)

# Test TransformChar
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-transformchar COMMAND testTransformChar)

# Test ProcessCommandLine
add_executable(testProcessCommandLine testProcessCommandLine.cpp)
target_link_libraries(testProcessCommandLine MPAGSCipher Catch)
add_test(NAME test-processcommandline COMMAND testProcessCommandLine)

# Test CaesarCipher
add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher MPAGSCipher Catch)
add_test(NAME test-caesarcipher COMMAND testCaesarCipher)
