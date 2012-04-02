//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/vector_magnitude.hpp>
#include <boost/la/vref.hpp>
#include "test_la_vector.hpp"
#include "gold.hpp"

namespace
	{
	template <int Dim>
	void
	test()
		{
		using namespace boost::la;

		test_la::vector<V1,Dim> const x(42,1);
		float m1=magnitude(x);
		float m2=magnitude(vref(x));
		float m3=sqrtf(test_la::dot<float>(x.a,x.a));
		BOOST_TEST_LA_CLOSE(m1,m3,0.000001f);
		BOOST_TEST_LA_CLOSE(m2,m3,0.000001f);
		}
	}

int
main()
	{
	test<2>();
	test<3>();
	test<4>();
	test<5>();
    return boost::report_errors();
	}
