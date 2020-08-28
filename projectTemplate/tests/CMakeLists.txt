#need to install googletest first
# sudo apt install libgtest-dev google-mock
# cd /usr/src/gtest
# sudo cmake CMakeLists.txt
# sudo make
# sudo cp *.a /usr/lib
include(GoogleTest)
add_executable(tests CanTest.cpp AnotherTest.cpp ../src/SumFunc.cpp)
target_link_libraries(tests GTest::GTest)
gtest_discover_tests(tests)
