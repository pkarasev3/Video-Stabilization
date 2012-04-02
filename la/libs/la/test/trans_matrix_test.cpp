//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/trans_matrix.hpp>
#include <boost/la/array_matrix_traits.hpp>
#include <boost/la/matrix_assign.hpp>
#include <boost/la/vector_mul_eq_scalar.hpp>
#include <boost/la/delr.hpp>
#include <boost/la/col.hpp>
#include "test_la_vector.hpp"
#include "gold.hpp"

namespace
	{
	template <int Dim>
	void
	test()
		{
		using namespace boost::la;
		test_la::vector<V1,Dim-1> x(42,1);
		float r1[Dim][Dim];
		test_la::translation(r1,x.a);
		float r2[Dim][Dim];
		assign(r2,x|trans_matrix);
		BOOST_TEST_LA_EQ(r1,r2);
		test_la::scalar_multiply_v(x.b,x.a,2.0f);
		x|trans_matrix|delr<Dim-1>()|col<Dim-1>() *= 2;
		BOOST_TEST_LA_EQ(x.a,x.b);
		}
	}

int
main()
	{
	test<3>();
	test<4>();
	test<5>();
	return boost::report_errors();
	}
