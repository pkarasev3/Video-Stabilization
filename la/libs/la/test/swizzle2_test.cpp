//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/sw.hpp>
#include <boost/la/custom/swizzle_2.hpp>
#include <boost/la/custom/vector_eq_vector_2.hpp>
#include <boost/la/custom/vector_mul_eq_scalar_2.hpp>
#include "test_la_vector.hpp"

int
main()
	{		
	using namespace boost::la;
	test_la::vector<V1,4> v1;
	v1.a[0]=42.0f;
	v1.a[1]=43.0f;
	v1.a[2]=44.0f;
	v1.a[3]=45.0f;
		{
		test_la::vector<V2,2> r;
		r.a[0]=v1.a[0];
		r.a[1]=v1.a[0];
		test_la::vector<V2,2> v2=v1|XX;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,2> r;
		r.a[0]=v1.a[0];
		r.a[1]=v1.a[1];
		test_la::vector<V2,2> v2=v1|XY;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,2> r;
		r.a[0]=v1.a[0];
		r.a[1]=v1.a[2];
		test_la::vector<V2,2> v2=v1|XZ;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,2> r;
		r.a[0]=v1.a[0];
		r.a[1]=v1.a[3];
		test_la::vector<V2,2> v2=v1|XW;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,2> r;
		r.a[0]=v1.a[0];
		r.a[1]=0;
		test_la::vector<V2,2> v2=v1|X0;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,2> r;
		r.a[0]=v1.a[0];
		r.a[1]=1;
		test_la::vector<V2,2> v2=v1|X1;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,2> v2=v1|XY;
		v1|XY *= 2;
		v2 *= 2;
		test_la::vector<V2,2> v3=v1|XY;
		BOOST_TEST_LA_EQ(v2,v3);
		}
    return boost::report_errors();
	}
