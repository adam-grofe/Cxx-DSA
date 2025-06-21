
#include <gtest/gtest.h>
#include <vector>
#include <binary_search.hpp>

TEST(BinarySearch, TargetInVector_ReturnsIndex)
{
    // Arrange
    auto vec = std::vector<int>{1, 2, 3, 4, 5};
    int target = 3;

    // Act
    auto idx = binary_search(vec, target);

    // Assert
    EXPECT_EQ(idx, 2);
}

TEST(BinarySearch, TargetNotInVector_ReturnsMinuxOne)
{
    // Arrange
    auto vec = std::vector<int>{1, 2, 3, 4, 5};
    int target = 12;

    // Act
    auto idx = binary_search(vec, target);

    // Assert
    EXPECT_EQ(idx, -1);
}

TEST(BinarySearch, TargetAllValues_ReturnsIndex)
{
    // Arrange
    auto vec = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13, 22, 44, 108};

    // Act and Assert
    for (size_t i=0; i<vec.size(); i++)
    {
        auto idx = binary_search(vec,vec[i]);
        EXPECT_EQ(idx, i);
        i++;
    }
}

TEST(BinarySearch, EmptyVector_ReturnsMinusOne)
{
    // Arrange
    auto vec = std::vector<int>{};

    // Act
    auto idx = binary_search(vec, 12);

    // Assert
    EXPECT_EQ(idx, -1);
}