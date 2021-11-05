//
// Created by Alexis Lafrance on 10/8/21.
//
#include <gtest/gtest.h>
#include "../vector.hpp"
#include <vector>

using namespace ::testing;

class MyVectorTest: public Test {
public:
	ft::vector<int> myvector;
	std::vector<int> vector;
};

TEST_F(MyVectorTest, DefaultConstructorCreatesNoElements) {
	EXPECT_TRUE(vector.empty());
}
