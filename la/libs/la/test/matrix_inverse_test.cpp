//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/matrix_inverse.hpp>
#include <boost/la/mref.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include "test_la_matrix.hpp"
#include "gold.hpp"

namespace
	{
	template <class T,class U> struct same_type_tester;
	template <class T> struct same_type_tester<T,T> { };
	template <class T,class U> void test_same_type( T, U ) { same_type_tester<T,U>(); }

	template <int D>
	void
	test()
		{
		using namespace boost::la;
		test_la::matrix<M1,D,D> x;
		test_la::rotation_z(x.a,42.0f);
		test_la::inverse(x.b,x.a);
		test_same_type(x,inverse(x));
			{
			test_la::matrix<M1,D,D> y=inverse(x);
			BOOST_TEST_LA_CLOSE(x.b,y.a,0.000001f);
			}
			{
			test_la::matrix<M1,D,D> y=inverse(mref(x));
			BOOST_TEST_LA_CLOSE(x.b,y.a,0.000001f);
			}
		}
	}

int
main()
	{
	try
		{
		test<2>();
		test<3>();
		test<4>();
		test<5>();
	    return boost::report_errors();
		}
	catch(
	... )
		{
		std::cerr << "Uncaught exception:\n" << boost::current_exception_diagnostic_information();
		return 1;
		}
	}
