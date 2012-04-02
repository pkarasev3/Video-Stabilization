//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/vector_mul_scalar.hpp>
#include <boost/la/vref.hpp>
#include "test_la_vector.hpp"
#include "gold.hpp"

namespace
	{
	template <class T,class U> struct same_type_tester;
	template <class T> struct same_type_tester<T,T> { };
	template <class T,class U> void test_same_type( T, U ) { same_type_tester<T,U>(); }

	template <int Dim>
	void
	test()
		{
		using namespace boost::la;
		test_la::vector<V1,Dim> const x(42,1);
		test_la::scalar_multiply_v(x.b,x.a,2.0f);
		test_same_type(x,x*2);
			{
			test_la::vector<V1,Dim> y=x*2;
			BOOST_TEST_LA_EQ(x.b,y.a);
			}
			{
			test_la::vector<V1,Dim> y=vref(x)*2;
			BOOST_TEST_LA_EQ(x.b,y.a);
			}
		}
	}

int
main()
	{
	test<1>();
	test<2>();
	test<3>();
	test<4>();
	test<5>();
    return boost::report_errors();
	}
