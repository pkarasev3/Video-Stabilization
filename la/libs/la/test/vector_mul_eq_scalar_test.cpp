//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/vector_mul_eq_scalar.hpp>
#include "test_la_vector.hpp"
#include "gold.hpp"

namespace
	{
	template <int Dim>
	void
	test()
		{
		using namespace boost::la;
		test_la::vector<V1,Dim> x(42,1);
		test_la::scalar_multiply_v(x.b,x.a,2.0f);
		x*=2;
		BOOST_TEST_LA_EQ(x.a,x.b);
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
