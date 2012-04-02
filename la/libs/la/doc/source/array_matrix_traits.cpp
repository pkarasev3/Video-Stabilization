//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/all.hpp>
using namespace boost::la;

void
f()
	{
	float a[4][4];
	float det = determinant(a);
	mref(a) *= 42;
	}
