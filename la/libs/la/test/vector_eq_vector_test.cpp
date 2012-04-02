//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/vector_eq_vector.hpp>
#include <boost/la/vector_neq_vector.hpp>
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
		for( int i=0; i!=Dim; ++i )
			{
				{
				test_la::vector<V1,Dim> y(x);
				BOOST_TEST_LA_EQ(x,y);
				y.a[i]=0;
				BOOST_TEST_LA_NEQ(x,y);
				}
				{
				test_la::vector<V2,Dim> y; assign(y,x);
				BOOST_TEST_LA_EQ(x,y);
				y.a[i]=0;
				BOOST_TEST_LA_NEQ(x,y);
				}
			}
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
