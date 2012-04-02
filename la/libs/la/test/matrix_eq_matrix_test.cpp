//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/matrix_eq_matrix.hpp>
#include <boost/la/matrix_neq_matrix.hpp>
#include "test_la_matrix.hpp"
#include "gold.hpp"

namespace
	{
	template <int Rows,int Cols>
	void
	test()
		{
		using namespace boost::la;
		test_la::matrix<M1,Rows,Cols> const x(42,1);
		for( int i=0; i!=Rows; ++i )
			for( int j=0; j!=Cols; ++j )
				{
					{
					test_la::matrix<M1,Rows,Cols> y(x);
					BOOST_TEST_LA_EQ(x,y);
					y.a[i][j]=0;
					BOOST_TEST_LA_NEQ(x,y);
					}
					{
					test_la::matrix<M2,Rows,Cols> y; assign(y,x);
					BOOST_TEST_LA_EQ(x,y);
					y.a[i][j]=0;
					BOOST_TEST_LA_NEQ(x,y);
					}
				}
		}
	}

int
main()
	{
	test<1,2>();
	test<2,1>();
	test<2,2>();
	test<1,3>();
	test<3,1>();
	test<3,3>();
	test<1,4>();
	test<4,1>();
	test<4,4>();
	test<1,5>();
	test<5,1>();
	test<5,5>();
    return boost::report_errors();
	}
