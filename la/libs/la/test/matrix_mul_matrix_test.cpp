//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/matrix_mul_matrix.hpp>
#include <boost/la/mref.hpp>
#include "test_la_matrix.hpp"
#include "gold.hpp"

namespace
	{
	template <int M,int N,int P>
	void
	test()
		{
		using namespace boost::la;
		test_la::matrix<M1,M,N> const x(42,1);
		test_la::matrix<M2,N,P> const y(42,1);
			{
			test_la::matrix<M3,M,P> r=x*y;
			test_la::multiply_m(r.b,x.b,y.b);
			BOOST_TEST_LA_CLOSE(r.a,r.b,0.0000001f);
			}
			{
			test_la::matrix<M3,M,P> r=mref(x)*y;
			test_la::multiply_m(r.b,x.b,y.b);
			BOOST_TEST_LA_CLOSE(r.a,r.b,0.0000001f);
			}
			{
			test_la::matrix<M3,M,P> r=x*mref(y);
			test_la::multiply_m(r.b,x.b,y.b);
			BOOST_TEST_LA_CLOSE(r.a,r.b,0.0000001f);
			}
		}
	}

int
main()
	{
	test<1,2,2>();
	test<2,2,1>();
	test<2,2,2>();
	test<1,3,3>();
	test<3,3,1>();
	test<3,3,3>();
	test<1,4,4>();
	test<4,4,1>();
	test<4,4,4>();
	test<1,5,5>();
	test<5,5,1>();
	test<5,5,5>();
	test<2,3,4>();
    return boost::report_errors();
	}
