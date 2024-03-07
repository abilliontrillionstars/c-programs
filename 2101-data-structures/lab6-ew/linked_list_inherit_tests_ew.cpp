// array_list_tests.cpp (new file in this lab)
#include <gtest/gtest.h>

#define DO_ARRAY_LIST_TESTS 1
#if DO_ARRAY_LIST_TESTS

// Test some foundational things like
// size, append and []
TEST(ArrayListTests, TestTest)
{
	EXPECT_EQ(1, 0);		// If this fails, mark it and continue
	ASSERT_EQ(0, 1);		// If this fails, mark it and stop this test
}

#endif