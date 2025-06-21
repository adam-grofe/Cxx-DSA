include(GoogleTest)

add_executable(DSATests Main.cpp BinarySearchTests.cpp)

target_link_libraries(DSATests 
    PRIVATE 
        BinarySearch 
        GTest::GTest 
        GTest::Main
)

gtest_discover_tests(DSATests)

