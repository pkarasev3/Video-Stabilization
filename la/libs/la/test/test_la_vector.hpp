//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_02C176D6B3AB11DE979F9A0D56D89593
#define UUID_02C176D6B3AB11DE979F9A0D56D89593

#include <boost/la/deduce_vector.hpp>
#include <boost/static_assert.hpp>
#include <boost/assert.hpp>
#include "test_la.hpp"

namespace
test_la
	{
	template <class Tag,int Dim,class T=float>
	struct
	vector
		{
		T a[Dim];
		mutable T b[Dim];

		explicit
		vector( T start=T(0), T step=T(0) )
			{
			for( int i=0; i!=Dim; ++i,start+=step )
				a[i]=b[i]=start;
			}
		};

	template <int Dim,class Tag1,class T1,class Tag2,class T2>
	void
	dump_ab( vector<Tag1,Dim,T1> const & a, vector<Tag2,Dim,T2> const & b )
		{
		detail::dump_ab(a.a,b.a);
		}
	}

namespace
boost
	{
	namespace
	la
		{
		template <class Tag,int Dim,class T>
		struct
		vector_traits< test_la::vector<Tag,Dim,T> >
			{
			static int const dim=Dim;
			typedef T scalar_type;

			template <int I>
			static
			scalar_type &
			w( test_la::vector<Tag,Dim,T> & m )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return m.a[I];
				}

			template <int I>
			static
			scalar_type
			r( test_la::vector<Tag,Dim,T> const & m )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return m.a[I];
				}

			static
			inline
			scalar_type &
			iw( int i, test_la::vector<Tag,Dim,T> & m )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return m.a[i];
				}

			static
			inline
			scalar_type
			ir( int i, test_la::vector<Tag,Dim,T> const & m )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return m.a[i];
				}
			};

		template <class Tag,class T,int D1,int D2,int Dim>
		struct
		deduce_vector2<test_la::vector<Tag,D1,T>,test_la::vector<Tag,D2,T>,Dim>
			{
			typedef test_la::vector<Tag,Dim,T> type;
			};
		}
	}

namespace
	{
	struct V1;
	struct V2;
	struct V3;
	}

#endif
