//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/vector_mul_matrix.hpp>
#include <boost/la/mref.hpp>
#include <boost/la/vref.hpp>
#include "test_la_matrix.hpp"
#include "test_la_vector.hpp"
#include "gold.hpp"

namespace
	{
	template <int M,int N>
	void
	test()
		{
		using namespace boost::la;
		using namespace boost::la;
		test_la::vector<V1,M> const x(42,1);
		test_la::matrix<M1,M,N> const y(42,1);
			{
			test_la::vector<V2,N> r=x*y;
			test_la::multiply_vm(r.b,x.b,y.b);
			BOOST_TEST_LA_CLOSE(r.a,r.b,0.0000001f);
			}
			{
			test_la::vector<V2,N> r=vref(x)*y;
			test_la::multiply_vm(r.b,x.b,y.b);
			BOOST_TEST_LA_CLOSE(r.a,r.b,0.0000001f);
			}
			{
			test_la::vector<V2,N> r=x*mref(y);
			test_la::multiply_vm(r.b,x.b,y.b);
			BOOST_TEST_LA_CLOSE(r.a,r.b,0.0000001f);
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
