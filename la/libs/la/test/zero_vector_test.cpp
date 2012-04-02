//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/zero_vector.hpp>
#include "test_la_vector.hpp"

namespace
	{
	template <int Dim>
	void
	test()
		{
		using namespace boost::la;
		test_la::vector<V1,Dim> v=zero_vector<float,Dim>();
		for( int i=0; i!=Dim; ++i )
				BOOST_TEST(!v.a[i]);
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
