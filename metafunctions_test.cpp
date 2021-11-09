//
// Created by Alexis Lafrance on 11/9/21.
//

#include <gtest/gtest.h>
#include "../ft_containers/metafunctions/is_integral.hpp"

class MetaFunctions: public ::testing::Test{
public:
	MetaFunctions(): testIntegral(false) {}
	bool testIntegral;
	class A {};
	template<typename T>
	void testIntegralFundamentalsTypes(T a) {
		(void)a;
		testIntegral = ft::is_integral<T>::value_type;
		EXPECT_EQ(testIntegral, true);
	}
};


TEST(MetaFunctionsWitoutFixture, TestEnableIfWithSimplesConditions) {
	class A {};
	ft::enable_if<ft::is_integral<int>::value_type, int>::type a;
	(void)a;
	ft::enable_if<!ft::is_integral<A>::value_type, int>::type c;
	(void)c;
	SUCCEED();
}

TEST_F(MetaFunctions, TestValueTypeIsTrueWithFundamentalTypes) {
	unsigned char a = 0;
	testIntegralFundamentalsTypes(a);
	bool b = 0;
	testIntegralFundamentalsTypes(b);
	char c = 0;
	testIntegralFundamentalsTypes(c);
	char16_t d = 0;
	testIntegralFundamentalsTypes(d);
	char32_t e = 0;
	testIntegralFundamentalsTypes(e);
	wchar_t f = 0;
	testIntegralFundamentalsTypes(f);
	signed char g = 0;
	testIntegralFundamentalsTypes(g);
	short int h = 0;
	testIntegralFundamentalsTypes(h);
	int i = 0;
	testIntegralFundamentalsTypes(i);
	long int j = 0;
	testIntegralFundamentalsTypes(j);
	long long int k = 0;
	testIntegralFundamentalsTypes(k);
	unsigned short int l = 0;
	testIntegralFundamentalsTypes(l);
	unsigned int m = 0;
	testIntegralFundamentalsTypes(m);
	unsigned long int n = 0;
	testIntegralFundamentalsTypes(n);
	unsigned long long int o = 0;
	testIntegralFundamentalsTypes(o);
}