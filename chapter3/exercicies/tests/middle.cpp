#include <gtest/gtest.h>
#include "../headers/utils.hpp"

TEST(MiddleT__Test, BasicAssertions) {
    vector_middle vec1 = {1, 2, 3, 4, 5};
    int expected1 = 3;
    EXPECT_EQ(find_middle_index(vec1), expected1);

    vector_middle vec2 = {1, 2, 3, 4};
    float expected2 = 2.5f;
    EXPECT_EQ(find_middle_index(vec2), expected2);

    vector_middle vec3 = {10};
    int expected3 = 10;
    EXPECT_EQ(find_middle_index(vec3), expected3);

}

TEST(MiddleT_Test, ASSERT_THROW){
    vector_middle vec_empty = {};
    EXPECT_THROW(find_middle_index(vec_empty), invalid_argument);
}

TEST(MiddleT__Test, NegativeNumbers) {
    vector_middle vec = {-15, -54, -37, -2, -110};
    int expected = -37;
    EXPECT_EQ(find_middle_index(vec), expected);
}