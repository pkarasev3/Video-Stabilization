//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/identity_matrix.hpp>
#include "test_la_matrix.hpp"

namespace
	{
	template <int Dim>
	void
	test()
		{
		using namespace boost::la;
		test_la::matrix<M1,Dim,Dim> m=identity_matrix<float,Dim>();
		for( int i=0; i!=Dim; ++i )
			for( int j=0; j!=Dim; ++j )
				BOOST_TEST(m.a[i][j]==float(i==j));
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
