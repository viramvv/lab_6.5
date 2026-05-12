#include <gtest/gtest.h>
#include <string>
#include "Deque.h" // Має бути в тій же папці

// Тестування для типу int
TEST(DequeIntTest, PushAndPop) {
    Deque<int> d;
    d.push_back(10);
    d.push_front(20);

    EXPECT_EQ(d.front(), 20);
    EXPECT_EQ(d.back(), 10);
    EXPECT_EQ(d.size(), 2);

    d.pop_front();
    EXPECT_EQ(d.front(), 10);
}

// Тестування винятків (Exception Handling)
TEST(DequeExceptionTest, EmptyPopThrows) {
    Deque<double> d;

    // Перевіряємо, чи генерується runtime_error при видаленні з порожнього дека
    EXPECT_THROW(d.pop_back(), std::runtime_error);
    EXPECT_THROW(d.front(), std::logic_error);
}

// Тестування типу std::string
TEST(DequeStringTest, StringOperations) {
    Deque<std::string> d;
    d.push_back("World");
    d.push_front("Hello");

    EXPECT_EQ(d.front() + " " + d.back(), "Hello World");

    d.clear();
    EXPECT_TRUE(d.empty());
}

// Тестування методу clear
TEST(DequeLogicTest, ClearMethod) {
    Deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.clear();
    EXPECT_EQ(d.size(), 0);
    EXPECT_TRUE(d.empty());
}