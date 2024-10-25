#include <gtest/gtest.h>
#include "eliminate_unset_bits.h"

TEST(EliminateUnsetBitsTest, BasicTests) {
    EXPECT_EQ(eliminate_unset_bits("101010101010101"), 255);
    EXPECT_EQ(eliminate_unset_bits("111"), 7);
    EXPECT_EQ(eliminate_unset_bits("1000000"), 1);
    EXPECT_EQ(eliminate_unset_bits("000"), 0);
}

TEST(EliminateUnsetBitsTest, EmptyString) {
    EXPECT_EQ(eliminate_unset_bits(""), 0);
}

TEST(EliminateUnsetBitsTest, AllOnes) {
    EXPECT_EQ(eliminate_unset_bits("1111111"), 127);
}

TEST(EliminateUnsetBitsTest, NoOnes) {
    EXPECT_EQ(eliminate_unset_bits("0000000"), 0);
}

TEST(EliminateUnsetBitsTest, MixedCharacters) {
    EXPECT_EQ(eliminate_unset_bits("abc1101def"), 7);
    EXPECT_EQ(eliminate_unset_bits("1a0b1c0"), 3);
}
