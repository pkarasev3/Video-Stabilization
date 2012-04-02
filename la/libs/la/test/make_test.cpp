//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/matrix_make.hpp>
#include <boost/la/vector_make.hpp>
#include <boost/la/array_matrix_traits.hpp>
#include <boost/la/array_vector_traits.hpp>
#include "test_la_matrix.hpp"
#include "test_la_vector.hpp"
#include "gold.hpp"

namespace
	{
	template <int Rows,int Cols>
	void
	test_matrix()
		{
		using namespace boost::la;
		test_la::matrix<M1,Rows,Cols> const x(42,1);
		test_la::matrix<M2,Rows,Cols> const y=make< test_la::matrix<M2,Rows,Cols> >(x);
		BOOST_TEST_LA_EQ(x.a,y.a);
		}

	template <int Dim>
	void
	test_vector()
		{
		using namespace boost::la;
		test_la::vector<V1,Dim> const x(42,1);
		test_la::vector<V2,Dim> const y=make< test_la::vector<V2,Dim> >(x);
		BOOST_TEST_LA_EQ(x.a,y.a);
		}
	}

int
main()
	{
	test_matrix<1,2>();
	test_matrix<2,1>();
	test_matrix<2,2>();
	test_matrix<1,3>();
	test_matrix<3,1>();
	test_matrix<3,3>();
	test_matrix<1,4>();
	test_matrix<4,1>();
	test_matrix<4,4>();
	test_matrix<1,5>();
	test_matrix<5,1>();
	test_matrix<5,5>();
	test_vector<2>();
	test_vector<3>();
	test_vector<4>();
	test_vector<5>();
    return boost::report_errors();
	}
