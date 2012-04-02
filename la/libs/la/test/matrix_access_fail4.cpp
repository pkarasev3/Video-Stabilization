//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/matrix_access.hpp>

template <int R,int C> struct mat { };

namespace
boost
	{
	namespace
	la
		{
		template <int R,int C>
		struct
		matrix_traits< mat<R,C> >
			{
			typedef int scalar_type;
			static int const rows=R;
			static int const cols=C;
			template <int Row,int Col> static int r( mat<R,C> const & );
			template <int Row,int Col> static int & w( mat<R,C> & );
			};
		}
	}

int
main()
	{
	using namespace boost::la;
	mat<1,1> m;
	m|A11();
	return 1;
	}
