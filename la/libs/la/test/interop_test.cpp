//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/all.hpp>

namespace
my_stuff
	{
	struct
	mat1
		{
		float a[3][3];
		};

	struct
	vec1
		{
		float a[3];
		};
	}

namespace
boost
	{
	namespace
	la
		{
		template <>
		struct
		matrix_traits<my_stuff::mat1>
			{
			typedef float scalar_type;
			static int const rows=3;
			static int const cols=3;

			template <int R,int C>
			static
			scalar_type &
			w( my_stuff::mat1 & m )
				{
				BOOST_STATIC_ASSERT(R>=0);
				BOOST_STATIC_ASSERT(R<rows);
				BOOST_STATIC_ASSERT(C>=0);
				BOOST_STATIC_ASSERT(C<cols);
				return m.a[R][C];
				}

			template <int R,int C>
			static
			scalar_type
			r( my_stuff::mat1 const & m )
				{
				BOOST_STATIC_ASSERT(R>=0);
				BOOST_STATIC_ASSERT(R<rows);
				BOOST_STATIC_ASSERT(C>=0);
				BOOST_STATIC_ASSERT(C<cols);
				return m.a[R][C];
				}

			static
			inline
			scalar_type &
			iw( int r, int c, my_stuff::mat1 & m )
				{
				BOOST_ASSERT(r>=0);
				BOOST_ASSERT(r<rows);
				BOOST_ASSERT(c>=0);
				BOOST_ASSERT(c<cols);
				return m.a[r][c];
				}

			static
			inline
			scalar_type
			ir( int r, int c, my_stuff::mat1 const & m )
				{
				BOOST_ASSERT(r>=0);
				BOOST_ASSERT(r<rows);
				BOOST_ASSERT(c>=0);
				BOOST_ASSERT(c<cols);
				return m.a[r][c];
				}
			};

		template <>
		struct
		vector_traits<my_stuff::vec1>
			{
			static int const dim=3;
			typedef float scalar_type;

			template <int I>
			static
			scalar_type &
			w( my_stuff::vec1 & m )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return m.a[I];
				}

			template <int I>
			static
			scalar_type
			r( my_stuff::vec1 const & m )
				{
				BOOST_STATIC_ASSERT(I>=0);
				BOOST_STATIC_ASSERT(I<dim);
				return m.a[I];
				}

			static
			inline
			scalar_type &
			iw( int i, my_stuff::vec1 & m )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return m.a[i];
				}

			static
			inline
			scalar_type
			ir( int i, my_stuff::vec1 const & m )
				{
				BOOST_ASSERT(i>=0);
				BOOST_ASSERT(i<dim);
				return m.a[i];
				}
			};
		}
	}

namespace
my_stuff
	{
	mat1 &
	operator/=( mat1 & x, float y )
		{
		return boost::la::operator/=(x,y);
		}

	vec1 &
	operator/=( vec1 & x, float y )
		{
		return boost::la::operator/=(x,y);
		}

	mat1 &
	operator*=( mat1 & x, float y )
		{
		return boost::la::operator*=(x,y);
		}

	vec1 &
	operator*=( vec1 & x, float y )
		{
		return boost::la::operator*=(x,y);
		}

	mat1
	operator/( mat1 const & x, float y )
		{
		return boost::la::operator/(x,y);
		}

	vec1
	operator/( vec1 const & x, float y )
		{
		return boost::la::operator/(x,y);
		}

	mat1
	operator*( mat1 const & x, float y )
		{
		return boost::la::operator*(x,y);
		}

	vec1
	operator*( vec1 const & x, float y )
		{
		return boost::la::operator*(x,y);
		}

	mat1 &
	operator*=( mat1 & x, mat1 const & y )
		{
		return boost::la::operator*=(x,y);
		}

	mat1
	operator*=( mat1 const & x, mat1 const & y )
		{
		return boost::la::operator*(x,y);
		}

	vec1
	operator*( mat1 const & x, vec1 const & y )
		{
		return boost::la::operator*(x,y);
		}

	vec1
	operator*( vec1 const & x, mat1 const & y )
		{
		return boost::la::operator*(x,y);
		}

	bool
	operator==( mat1 const & x, mat1 const & y )
		{
		return boost::la::operator==(x,y);
		}

	bool
	operator!=( mat1 const & x, mat1 const & y )
		{
		return boost::la::operator!=(x,y);
		}

	bool
	operator==( vec1 const & x, vec1 const & y )
		{
		return boost::la::operator==(x,y);
		}

	bool
	operator!=( vec1 const & x, vec1 const & y )
		{
		return boost::la::operator!=(x,y);
		}
	}

int
main()
	{
	using namespace boost::la;
	using namespace my_stuff;
	typedef mat<double,3,3> mat2;
	typedef vec<double,3> vec2;

	mat1 ma1,mb1;
	vec1 va1, vb1;
	mat2 ma2, mb2;
	vec2 va2, vb2;

	ma1/=2;
	va1/=2;
	ma2/=2;
	va2/=2;

	ma1*=2;
	va1*=2;
	ma2*=2;
	va2*=2;

	mb1=ma1/2;
	vb1=va1/2;
	mb2=make<mat2>(ma1/2);
	vb2=make<vec2>(va1/2);
	mb1=scalar_cast<float>(ma2/2);
	vb1=scalar_cast<float>(va2/2);

	mb1=ma1*2;
	vb1=va1*2;
	mb2=make<mat2>(ma1*2);
	vb2=make<vec2>(va1*2);
	mb1=scalar_cast<float>(ma2*2);
	vb1=scalar_cast<float>(va2*2);

	ma1*=mb1;
	ma1*=scalar_cast<float>(ma2);
	ma2*=ma1;

	va1=ma1*va1;
	va1=scalar_cast<float>(ma2*va1);
	va1=scalar_cast<float>(ma1*va2);
	va1=scalar_cast<float>(ma2*va2);

	va2=make<vec2>(ma1*va1);
	va2=ma2*va1;
	va2=ma1*va2;
	va2=ma2*va2;

	va1=va1*ma1;
	va1=scalar_cast<float>(va1*ma2);
	va1=scalar_cast<float>(va2*ma1);
	va1=scalar_cast<float>(va2*ma2);

	va2=make<vec2>(va1*ma1);
	va2=va1*ma2;
	va2=va2*ma1;
	va2=va2*ma2;

	ma1==mb1;
	ma1==ma2;
	ma2==ma1;

	ma1!=mb1;
	ma1!=ma2;
	ma2!=ma1;

	va1==vb1;
	va1==va2;
	va2==va1;

	va1!=vb1;
	va1!=va2;
	va2!=va1;

	return 0;
	}
