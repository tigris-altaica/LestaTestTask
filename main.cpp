#include <random>
#include <gtest/gtest.h>

#include "Task1/Task1.h"
#include "Task2/Task2.h"
#include "Task3/Task3.h"

TEST(Task1Suite, CaseOdd) {
    ASSERT_FALSE(Task1::isEven1(15));
    ASSERT_FALSE(Task1::isEven2(15));
}
TEST(Task1Suite, CaseEven) {
    ASSERT_TRUE(Task1::isEven1(18));
    ASSERT_TRUE(Task1::isEven2(18));
}
TEST(Task1Suite, CaseNegOdd) {
    ASSERT_FALSE(Task1::isEven1(-15));
    ASSERT_FALSE(Task1::isEven2(-15));
}
TEST(Task1Suite, CaseNegEven) {
    ASSERT_TRUE(Task1::isEven1(-18));
    ASSERT_TRUE(Task1::isEven2(-18));
}
TEST(Task1Suite, CaseZero) {
    ASSERT_TRUE(Task1::isEven1(0));
    ASSERT_TRUE(Task1::isEven2(0));
}

TEST(Task2Suite, CaseArray) {
    Task2::ArrayRingBuffer<char, 3> arrayRingBuffer;

    arrayRingBuffer.push('a');
    arrayRingBuffer.push('b');
    ASSERT_EQ(arrayRingBuffer.pop(), 'a');
    arrayRingBuffer.push('c');
    arrayRingBuffer.push('d');
    ASSERT_THROW(arrayRingBuffer.push('e'), Task2::RingBufferFull);
    ASSERT_EQ(arrayRingBuffer.pop(), 'b');
    ASSERT_EQ(arrayRingBuffer.pop(), 'c');
    ASSERT_EQ(arrayRingBuffer.pop(), 'd');
    ASSERT_THROW(arrayRingBuffer.pop(), Task2::RingBufferEmpty);
}
TEST(Task2Suite, CaseVector) {
    Task2::VectorRingBuffer<char> vectorRingBuffer(3);

    vectorRingBuffer.push('a');
    vectorRingBuffer.push('b');
    ASSERT_EQ(vectorRingBuffer.pop(), 'a');
    vectorRingBuffer.push('c');
    vectorRingBuffer.push('d');
    ASSERT_THROW(vectorRingBuffer.push('e'), Task2::RingBufferFull);
    ASSERT_EQ(vectorRingBuffer.pop(), 'b');
    ASSERT_EQ(vectorRingBuffer.pop(), 'c');
    ASSERT_EQ(vectorRingBuffer.pop(), 'd');
    ASSERT_THROW(vectorRingBuffer.pop(), Task2::RingBufferEmpty);
}
TEST(Task2Suite, CaseList) {
    Task2::ListRingBuffer<char> listRingBuffer(3);

    listRingBuffer.push('a');
    listRingBuffer.push('b');
    ASSERT_EQ(listRingBuffer.pop(), 'a');
    listRingBuffer.push('c');
    listRingBuffer.push('d');
    ASSERT_THROW(listRingBuffer.push('e'), Task2::RingBufferFull);
    ASSERT_EQ(listRingBuffer.pop(), 'b');
    ASSERT_EQ(listRingBuffer.pop(), 'c');
    ASSERT_EQ(listRingBuffer.pop(), 'd');
    ASSERT_THROW(listRingBuffer.pop(), Task2::RingBufferEmpty);
}

TEST(Task3Suite, CaseVector) {
    const size_t n = 1'000'000;
    std::vector<unsigned int> v;
    std::random_device rnd;
    std::mt19937 gen(rnd());

    for (int i = 0; i < n; ++i) {
        v.push_back(gen());
    }

    Task3::mergeSort(std::span(v));

    for (int i = 0; i < n - 1; ++i) {
        ASSERT_LE(v[i], v[i + 1]);
    }
}
TEST(Task3Suite, CaseArray) {
    int arr[]{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    Task3::mergeSort(std::span(std::begin(arr), std::end(arr)));

    for (int i = 0; i < std::size(arr) - 1; ++i) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
