# - Build subscript for the MPAGSCipher library unit tests

# Most basic tests
add_executable(testCatch testCatch.cpp)
target_include_directories(testCatch PRIVATE ${CMAKE_CURRENT_LIST_DIR})
add_test(NAME test-catch COMMAND testCatch)

# Test TransformChar
add_executable(testTransformChar testTransformChar.cpp)
target_include_directories(testTransformChar PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(testTransformChar MPAGSCipher)
add_test(NAME test-transformchar COMMAND testTransformChar)