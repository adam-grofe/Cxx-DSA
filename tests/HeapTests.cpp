
#include <gtest/gtest.h>
#include <heap.hpp>
#include <vector>

TEST(MaxHeap, Insert_OneElement_ReturnsElement)
{
    // Arrange
    auto value = 1;
    auto priority = 2;
    auto heap = Heap::MaxHeap<int, int>();

    // Act
    heap.insert(priority, value);
    int top = heap.top();

    // Assert
    EXPECT_EQ(value, top);
}

TEST(MaxHeap, Insert_ManyInorderElements_ReturnsInOrderOfPriority)
{
    // Arrange
    auto values = std::vector<int>{1, 2, 3, 4, 5};
    auto priorities = std::vector<int>{15, 14, 13, 12, 11};
    auto heap = Heap::MaxHeap<int, int>();
    auto expectedValues = std::vector<int>{1, 2, 3, 4, 5};

    // Act
    EXPECT_EQ(values.size(), priorities.size());
    for (size_t i = 0; i < values.size(); i++)
    {
        heap.insert(priorities[i], values[i]);
    }

    // Assert
    EXPECT_EQ(expectedValues.size(), values.size());
    for (size_t i = 0; i < expectedValues.size(); i++)
    {
        int result = heap.top();
        EXPECT_EQ(expectedValues[i], result);
    }
}

TEST(MaxHeap, Insert_ManyOutOfOrderElements_ReturnsInOrderOfPriority)
{
    // Arrange
    auto values = std::vector<int>{1, 2, 3, 4, 5};
    auto priorities = std::vector<int>{13, 15, 11, 14, 12};
    auto heap = Heap::MaxHeap<int, int>();
    auto expectedValues = std::vector<int>{2, 4, 1, 5, 3};

    // Act
    EXPECT_EQ(values.size(), priorities.size());
    for (size_t i = 0; i < values.size(); i++)
    {
        heap.insert(priorities[i], values[i]);
    }

    // Assert
    EXPECT_EQ(expectedValues.size(), values.size());
    for (size_t i = 0; i < expectedValues.size(); i++)
    {
        int result = heap.top();
        EXPECT_EQ(expectedValues[i], result);
    }
}

TEST(MaxHeap, Insert_ChangeBranching_ReturnsInOrderOfPriority)
{
    // Arrange
    size_t branching = 2;
    auto values = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8};
    auto priorities = std::vector<int>{13, 15, 11, 14, 12, 8, 10, 5};
    auto heap = Heap::MaxHeap<int, int>(branching);
    auto expectedValues = std::vector<int>{2, 4, 1, 5, 3, 7, 6, 8};

    // Act
    EXPECT_EQ(values.size(), priorities.size());
    for (size_t i = 0; i < values.size(); i++)
    {
        heap.insert(priorities[i], values[i]);
    }

    // Assert
    EXPECT_EQ(expectedValues.size(), values.size());
    for (size_t i = 0; i < expectedValues.size(); i++)
    {
        int result = heap.top();
        EXPECT_EQ(expectedValues[i], result);
    }
}

TEST(MaxHeap, Constructor_InvalidBranchingFactor_ThrowsRuntimeError)
{
    // Arrange
    size_t invalidBranchingFactor = 1;
    
    // Act & Assert
    EXPECT_THROW((Heap::MaxHeap<int,int>(invalidBranchingFactor)), std::runtime_error);
}