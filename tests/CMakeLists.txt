include(GoogleTest)

add_executable(DSATests Main.cpp BinarySearchTests.cpp HeapTests.cpp)

target_link_libraries(DSATests 
    PRIVATE 
        BinarySearch 
        Heap
        GTest::GTest 
        GTest::Main
)

gtest_discover_tests(DSATests)

