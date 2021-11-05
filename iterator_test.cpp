//
// Created by Alexis Lafrance on 11/4/21.
//


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../vector.hpp"
#include <vector>

using namespace ::testing;


TEST(bidirectional_iterator, IS_CANONICAL_FORM) {
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator it2(it);
	ft::vector<int>::iterator it3;
	EXPECT_EQ(typeid(it), typeid(it2));
	EXPECT_EQ(typeid(it3), typeid(it));
}

TEST(bidirectional_iterator, iterator_begin_end_works) {
	ft::vector<char> myvector("hola amigo");
	ft::vector<char>::iterator it = myvector.begin();
//	EXPECT_EQ(*it, 'h');

//	it++;
//	EXPECT_EQ(*it, "o");
}


