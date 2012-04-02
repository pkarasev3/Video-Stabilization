//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/sw.hpp>
#include <boost/la/custom/swizzle_1.hpp>
#include "test_la_vector.hpp"

template <class T,class U> struct same_type;
template <class T> struct same_type<T,T> { };

template <class T,class U>
void
check_type( U x )
	{
	same_type<T,U>();
	}

int
main()
	{		
	using namespace boost::la;
	test_la::vector<V1,4> v;
	v.el[0]=42.0f;
	v.el[1]=43.0f;
	v.el[2]=44.0f;
	v.el[3]=45.0f;
	BOOST_TEST_EQ(v|X,v.el[0]);
	BOOST_TEST_EQ(v|Y,v.el[1]);
	BOOST_TEST_EQ(v|Z,v.el[2]);
	BOOST_TEST_EQ(v|W,v.el[3]);
	check_type<float>(v|X);
	check_type<float>(v|Y);
	check_type<float>(v|Z);
	check_type<float>(v|W);
	test_la::vector<V1,4> v1=v;
	v|X *= 2;
	BOOST_TEST_EQ(v.el[0],v1.el[0]*2);
	v|Y *= 2;
	BOOST_TEST_EQ(v.el[1],v1.el[1]*2);
	v|Z *= 2;
	BOOST_TEST_EQ(v.el[2],v1.el[2]*2);
	v|W *= 2;
	BOOST_TEST_EQ(v.el[3],v1.el[3]*2);
    return boost::report_errors();
	}
