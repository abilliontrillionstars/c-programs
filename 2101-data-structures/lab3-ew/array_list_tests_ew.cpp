// array_list_tests.cpp (new file in this lab)
#include <gtest/gtest.h>
#include "array_list_ew_3.h"
#include "foo_ew.h"

#define DO_ARRAY_LIST_TESTS 1
#if DO_ARRAY_LIST_TESTS

// Test some foundational things like
// size, append and []
TEST(ArrayListTests, BasicTest)
{
	ssuds::ArrayList<int> s;
	EXPECT_EQ(s.size(), 0);		// If this fails, mark it and continue
	s.append(15);
	ASSERT_EQ(s.size(), 1);		// If this fails, mark it and stop this test
	EXPECT_EQ(s[0], 15);
}

#endif


/*
// test of ArrayList initializer list constructor
ssuds::ArrayList<float> f = { 1.1f, 2.2f, 3.3f };
ssuds::ArrayList<testing::Foo> f2 = { testing::Foo("Bob", 7),
	testing::Foo("Sue", 9),
	testing::Foo("Joe", 10) };
*/