//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/vector_access.hpp>

template <int D> struct vec { };

namespace
boost
	{
	namespace
	la
		{
		template <int D>
		struct
		vector_traits< vec<D> >
			{
			typedef int scalar_type;
			static int const dim=D;
			template <int I> static int r( vec<D> const & );
			template <int I> static int & w( vec<D> & );
			};
		}
	}

int
main()
	{
	using namespace boost::la;
	vec<1> v;
	v|Y;
	return 1;
	}
