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


template<typename T>
void testContentOfVector(T content, size_t size, ft::vector<T> a) {
	size_t count = 0;
	T *array;
	if (std::is_integral<T>::value)
		array = new T[size];
	for (size_t i = 0; i < size; ++i)
		array[i] = content;
	for (typename ft::vector<T>::iterator it = a.begin(); it < a.end(); it++) {
		if (count > size)
			break;
		EXPECT_EQ(*it, array[count]);
		count++;
	}
	EXPECT_EQ(count, size);
	if (std::is_integral<T>::value)
		delete[] array;
}

template<typename T>
void testContentOfVector(T content, size_t size) {
	size_t count = 0;
	ft::vector<T> a(size, content);
	T *array = nullptr;
	if (std::is_integral<T>::value)
		array = new T[size];
	for (size_t i = 0; i < size; ++i)
		array[i] = content;
	for (typename ft::vector<T>::iterator it = a.begin(); it < a.end(); it++) {
		if (count > size)
			break;
		EXPECT_EQ(*it, array[count]);
		count++;
	}
	EXPECT_EQ(count, size);
	if (std::is_integral<T>::value)
		delete[] array;
	if (size != 0)
		EXPECT_FALSE(a.empty());
	else
		EXPECT_TRUE(a.empty());
}

//TODO: -Deep copy operator=
//		-SIZE=0 et capacity=? quand tu clear et apres utilise les getters

TEST(MyVector, DISABLED_ConstructorAndOperatorEqualTestWithDifferentsTypes) {

	ft::vector<int> g;

	EXPECT_EQ(g.empty(), true);
	EXPECT_EQ(g.size(), (size_t)0);
	EXPECT_EQ(g.capacity(), (size_t)0);

	size_t size_a = 1000;
	ft::vector<char> a(size_a, 'b');
	testContentOfVector('b', size_a, a);

	const ft::vector<char>& c(a);
	EXPECT_EQ(a, c);
	const ft::vector<char>& d = a;
	EXPECT_EQ(a, d);
	testContentOfVector(1, 4200);
	testContentOfVector("blablou", 0);
	testContentOfVector(true, 4200);
	testContentOfVector(static_cast<unsigned long long int>(199), 100);
	ft::vector<std::string> testVec(2, "coucou");
	EXPECT_EQ(static_cast<std::string>(*testVec.begin()), "coucou");
	std::string end = *(testVec.end() - 1);
	EXPECT_EQ(end, "coucou");
	EXPECT_NE(*testVec.end(), "coucou");

//	int myints[] = {1, 2, 3, 4};
//	ft::vector<int> john(myints, myints + 5); // THIS DOESN'T WORKS
//	std::deque<int> Deque(2, 4);
//	ft::vector<int> ftvector(Deque.begin(), Deque.end());

}
