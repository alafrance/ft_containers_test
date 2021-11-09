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


//TEST(MyVector, DefaultConstructorCreatesNoElements) {
//	std::vector<int> realVector(4, 42);
//	ft::vector<int> myvector2(4, 42);
//	std::deque<int> Deque(2, 4);
//	std::vector<int> vector(Deque.begin(), Deque.end());
//	std::cout << *vector.begin() << std::endl;
//	EXPECT_TRUE(abigvector.empty());
//}
