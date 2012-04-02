//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/sw.hpp>
#include <boost/la/custom/swizzle_4.hpp>
#include <boost/la/custom/vector_eq_vector_4.hpp>
#include <boost/la/custom/vector_mul_eq_scalar_4.hpp>
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
		test_la::vector<V2,4> r;
		r.a[0]=v1.a[0];
		r.a[1]=v1.a[0];
		r.a[2]=v1.a[0];
		r.a[3]=v1.a[0];
		test_la::vector<V2,4> v2=v1|XXXX;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,4> r;
		r.a[0]=v1.a[0];
		r.a[1]=v1.a[0];
		r.a[2]=v1.a[0];
		r.a[3]=v1.a[1];
		test_la::vector<V2,4> v2=v1|XXXY;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,4> r;
		r.a[0]=v1.a[0];
		r.a[1]=v1.a[0];
		r.a[2]=v1.a[0];
		r.a[3]=v1.a[2];
		test_la::vector<V2,4> v2=v1|XXXZ;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,4> r;
		r.a[0]=v1.a[0];
		r.a[1]=v1.a[0];
		r.a[2]=v1.a[0];
		r.a[3]=v1.a[3];
		test_la::vector<V2,4> v2=v1|XXXW;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,4> r;
		r.a[0]=v1.a[0];
		r.a[1]=v1.a[0];
		r.a[2]=v1.a[0];
		r.a[3]=0;
		test_la::vector<V2,4> v2=v1|XXX0;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,4> r;
		r.a[0]=v1.a[0];
		r.a[1]=v1.a[0];
		r.a[2]=v1.a[0];
		r.a[3]=1;
		test_la::vector<V2,4> v2=v1|XXX1;
		BOOST_TEST_LA_EQ(v2,r);
		}
		{
		test_la::vector<V2,4> v2=v1|XYZW;
		v1|XYZW *= 2;
		v2 *= 2;
		test_la::vector<V2,4> v3=v1|XYZW;
		BOOST_TEST_LA_EQ(v2,v3);
		}
    return boost::report_errors();
	}
