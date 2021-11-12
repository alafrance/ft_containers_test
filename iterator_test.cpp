//
// Created by Alexis Lafrance on 11/4/21.
//


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../ft_containers/vector.hpp"
#include <vector>

using namespace ::testing;


TEST(MyVector, IteratorBeginAndEndTesting) {
	ft::vector<int> hello(1, 100);
	hello.push_back(200);
	hello.push_back(300);
	hello.push_back(400);
	ft::vector<int>::iterator it = hello.begin();
	ft::vector<int>::iterator ite = hello.end();
	ft::vector<int>::iterator itcp(it);
//	EXPECT_TRUE(it ==  itcp);
//	itcp = ite;
//	EXPECT_TRUE(itcp == ite);
	EXPECT_EQ(*it, 100);
	EXPECT_EQ(*(++it), 200);
	EXPECT_EQ(*(--it), 100);
	ft::vector<int>::iterator it2 = it + 2;
	EXPECT_EQ(*it2, 300);
//	itcp = it;
	it += 2;
	EXPECT_EQ(*it, 300);
//	EXPECT_EQ(it - itcp, 100);
}
