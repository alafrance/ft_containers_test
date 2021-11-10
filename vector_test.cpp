//
// Created by Alexis Lafrance on 10/8/21.
//
#include <gtest/gtest.h>
#include "../ft_containers/vector.hpp"
#include <vector>
#include <array>
#include <deque>

using namespace ::testing;

class MyVectorTestEmpty: public Test {
public:
	ft::vector<int> myvector;
	std::vector<int> vector;
};

TEST(MyVector, ConstructorTestWithIterators) {
	int myints[] = {1, 2, 3, 4};
	ft::vector<int> john(myints, myints + 5); // THIS DOESN'T WORKS

//	int myints[] = {1, 2, 3, 4};
// 	ft::vector<int> john(myints, myints + 5); // THIS DOESN'T WORKS
//	ft::vector<int>::iterator it = john.begin();
//	ft::vector<int>::iterator ite = john.end();
//	ite--;
//	EXPECT_EQ((*it),1);
//	EXPECT_EQ((*ie),4);
//
//	ft::vector<int> myvector2(4, 42);
//	it = myvector2.begin();
//	EXPECT_EQ(*it, 42);
//
//	std::deque<int> Deque(2, 4);
//	ft::vector<int> ftvector(Deque.begin(), Deque.end());
//	std::cout << *ftvector.begin() << std::endl;
//
//	ft::vector<int> newVector();
//	EXPECT_TRUE(newVector.empty());
}
