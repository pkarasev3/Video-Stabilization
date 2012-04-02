//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/diag_matrix.hpp>
#include <boost/la/diag.hpp>
#include <boost/la/vector_mul_eq_scalar.hpp>
#include <boost/la/array_matrix_traits.hpp>
#include <boost/la/matrix_assign.hpp>
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
		float y[Dim][Dim]; assign(y,x|diag_matrix);
		for( int i=0; i!=Dim; ++i )
			x.b[i]=y[i][i];
		BOOST_TEST_LA_EQ(x.a,x.b);
		test_la::scalar_multiply_v(x.b,x.a,2.0f);
		x|diag_matrix|diag *= 2;
		BOOST_TEST_LA_EQ(x.a,x.b);
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
