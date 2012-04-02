//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/deduce_matrix.hpp>

template <class T,class U>
struct same_type;

template <class T>
struct
same_type<T,T>
	{
	};

template <class A,class B,int R,int C,class Result>
struct
check
	{
	same_type<typename boost::la::deduce_matrix2<A,B,R,C>::type,Result> a;
	same_type<typename boost::la::deduce_matrix2<B,A,R,C>::type,Result> b;
	};

template <class T,int R,int C> struct m;

namespace
boost
	{
	namespace
	la
		{
		template <class T,int R,int C>
		struct
		matrix_traits< m<T,R,C> >
			{
			typedef T scalar_type;
			static int const rows=R;
			static int const cols=C;
			};					   
		}
	}

int
main()
	{
	same_type< boost::la::deduce_matrix< m<int,4,2> >::type, m<int,4,2> >();
	same_type< boost::la::deduce_matrix< m<int,4,2>, 4, 4, float >::type, boost::la::mat<float,4,4> >();
	check< m<int,4,2>, m<int,4,2>, 4, 2, m<int,4,2> >();
	check< m<int,4,2>, m<float,4,2>, 4, 4, boost::la::mat<float,4,4> >();
	}
