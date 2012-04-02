//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_06E5D36EB6C211DEA317E19C55D89593
#define UUID_06E5D36EB6C211DEA317E19C55D89593

#include <boost/test/floating_point_comparison.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <iostream>

#define BOOST_TEST_LA_CLOSE(expra,exprb,exprt) ( ::test_la::detail::test_close_impl(#expra, #exprb, #exprt, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expra, exprb, exprt) )
#define BOOST_TEST_LA_EQ(expra,exprb) ( ::test_la::detail::test_eq_impl(#expra, #exprb, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expra, exprb) )
#define BOOST_TEST_LA_NEQ(expra,exprb) ( ::test_la::detail::test_neq_impl(#expra, #exprb, __FILE__, __LINE__, BOOST_CURRENT_FUNCTION, expra, exprb) )

namespace
test_la
	{
	namespace
	detail
		{
		inline
		bool
		close_at_tolerance( float a, float b, float tolerance )
			{
			using namespace boost::test_tools;
			return check_is_close(a,b,fraction_tolerance(tolerance));
			}

		inline
		bool
		close_at_tolerance( double a, double b, double tolerance )
			{
			using namespace boost::test_tools;
			return check_is_close(a,b,fraction_tolerance(tolerance));
			}

		template <class A,class B>
		void
		dump_ab( A a, B b )
			{
			std::cerr << a << '\t' << b << std::endl;
			}

		template <class A,class B,int D>
		void
		dump_ab( A (&a)[D], B (&b)[D] )
			{
			for( int i=0; i!=D; ++i )
				dump_ab(a[i],b[i]);
			}

		template <class A,class B>
		void
		test_eq_impl( char const * expra, char const * exprb, char const * file, int line, char const * function, A a, B b )
			{
			using namespace ::boost::la;
			if( !(a==b) )
				{
				std::cerr << file << "(" << line << "): test '" << expra << "==" << exprb
					<< ")' failed in function '" << function << "'\n";
				dump_ab(a,b);
				++::boost::detail::test_errors();
				}
			}

		template <class A,class B,int M,int N>
		void
		test_eq_impl( char const * expra, char const * exprb, char const * file, int line, char const * function, A (&a)[M][N], B (&b)[M][N] )
			{
			using namespace ::boost::la;
			for( int i=0; i<M; ++i )
				for( int j=0; j<N; ++j )
					if( !(a[i][j]==b[i][j]) )
						{
						std::cerr << file << "(" << line << "): test '" << expra << "==" << exprb
							<< ")' failed in function '" << function << "'\n";
						dump_ab(a,b);
						++::boost::detail::test_errors();
						return;
						}
			}

		template <class A,class B,int D>
		void
		test_eq_impl( char const * expra, char const * exprb, char const * file, int line, char const * function, A (&a)[D], B (&b)[D] )
			{
			using namespace ::boost::la;
			for( int i=0; i<D; ++i )
				if( !(a[i]==b[i]) )
					{
					std::cerr << file << "(" << line << "): test '" << expra << "==" << exprb
						<< ")' failed in function '" << function << "'\n";
					dump_ab(a,b);
					++::boost::detail::test_errors();
					return;
					}
			}

		template <class A,class B>
		void
		test_neq_impl( char const * expra, char const * exprb, char const * file, int line, char const * function, A a, B b )
			{
			using namespace ::boost::la;
			if( !(a!=b) )
				{
				std::cerr << file << "(" << line << "): test '" << expra << "!=" << exprb
					<< ")' failed in function '" << function << "'\n";
				dump_ab(a,b);
				++::boost::detail::test_errors();
				}
			}

		template <class A,class B,int M,int N>
		void
		test_neq_impl( char const * expra, char const * exprb, char const * file, int line, char const * function, A (&a)[M][N], B (&b)[M][N] )
			{
			using namespace ::boost::la;
			for( int i=0; i<M; ++i )
				for( int j=0; j<N; ++j )
					if( a[i][j]!=b[i][j] )
						return;
			std::cerr << file << "(" << line << "): test '" << expra << "!=" << exprb
				<< ")' failed in function '" << function << "'\n";
			dump_ab(a,b);
			++::boost::detail::test_errors();
			}

		template <class A,class B,int D>
		void
		test_neq_impl( char const * expra, char const * exprb, char const * file, int line, char const * function, A (&a)[D], B (&b)[D] )
			{
			using namespace ::boost::la;
			for( int i=0; i<D; ++i )
				if( a[i]!=b[i] )
					return;
			std::cerr << file << "(" << line << "): test '" << expra << "!=" << exprb
				<< ")' failed in function '" << function << "'\n";
			dump_ab(a,b);
			++::boost::detail::test_errors();
			}

		template <class A,class B,class T>
		void
		test_close_impl( char const * expra, char const * exprb, char const * exprt, char const * file, int line, char const * function, A a, B b, T t )
			{
			if( !close_at_tolerance(a,b,t) )
				{
				std::cerr << file << "(" << line << "): test 'close_at_tolerance(" << expra << ',' << b << ',' << t
					<< ")' failed in function '" << function << '\'' << std::endl;
				++::boost::detail::test_errors();
				return;
				}
			}

		template <class A,class B,class T,int M,int N>
		void
		test_close_impl( char const * expra, char const * exprb, char const * exprt, char const * file, int line, char const * function, A (&a)[M][N], B (&b)[M][N], T t )
			{
			for( int i=0; i<M; ++i )
				for( int j=0; j<N; ++j )
					if( !close_at_tolerance(a[i][j],b[i][j],t) )
						{
						std::cerr << file << "(" << line << "): test 'close_at_tolerance(" << expra << ',' << exprb << ',' << exprt
							<< ")' failed in function '" << function << "'\n";
						dump_ab(a,b);
						++::boost::detail::test_errors();
						return;
						}
			}

		template <class A,class B,class T,int D>
		void
		test_close_impl( char const * expra, char const * exprb, char const * exprt, char const * file, int line, char const * function, A (&a)[D], B (&b)[D], T t )
			{
			for( int i=0; i<D; ++i )
				if( !close_at_tolerance(a[i],b[i],t) )
					{
					std::cerr << file << "(" << line << "): test 'close_at_tolerance(" << expra << ',' << exprb << ',' << exprt
						<< ")' failed in function '" << function << "'\n";
					dump_ab(a,b);
					++::boost::detail::test_errors();
					return;
					}
			}
		}
	}

#endif
