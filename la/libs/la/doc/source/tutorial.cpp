//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/all.hpp>
using namespace boost::la;

struct float3 { float a[3]; };
struct float4 { float a[4]; };
struct float33 { float a[3][3]; };

namespace
boost
	{
	namespace
	la
		{
		template <>
		struct
		vector_traits<float3>
			{
			static int const dim=3;
			typedef float scalar_type;

			template <int I> static inline scalar_type & w( float3 & v ) { return v.a[I]; }
			template <int I> static inline scalar_type r( float3 const & v ) { return v.a[I]; }

			static inline scalar_type & iw( int i, float3 & v ) { return v.a[i]; }
			static inline scalar_type ir( int i, float3 const & v ) { return v.a[i]; }
			};

		template <>
		struct
		vector_traits<float4>
			{
			static int const dim=4;
			typedef float scalar_type;

			template <int I> static inline scalar_type & w( float4 & v ) { return v.a[I]; }
			template <int I> static inline scalar_type r( float4 const & v ) { return v.a[I]; }

			static inline scalar_type & iw( int i, float4 & v ) { return v.a[i]; }
			static inline scalar_type ir( int i, float4 const & v ) { return v.a[i]; }
			};

		template <>
		struct
		matrix_traits<float33>
			{
			typedef float scalar_type;
			static int const rows=3;
			static int const cols=3;

			template <int R,int C>
			static inline scalar_type & w( float33 & m ) { return m.a[R][C]; }

			template <int R,int C>
			static inline scalar_type r( float33 const & m ) { return m.a[R][C]; }

			static inline scalar_type & iw( int r, int c, float33 & m ) { return m.a[r][c]; }
			static inline scalar_type ir( int r, int c, float33 const & m ) { return m.a[r][c]; }
			};
		}
	}

void
f()
	{
		{
		float3 v;
		v|X = 0;
		v|Y = 0;
		v|Z = 7;
		float vmag = magnitude(v);
		float33 m = rotx_matrix<3>(3.14159f);
		float3 vrot = m * v;
		}

		{
		float v[3] = {0,0,7};
		float3 vrot = rotx_matrix<3>(3.14159f) * v;
		}

		{
		float3 v = {0,0,7};
		float3 vrot = (rotx_matrix<3>(3.14159f) | transpose) * v;
		}

		{
		float3 v = {0,0,7};
		v|YXZ = rotx_matrix<3>(3.14159f) * v;
		}

		{
		float3 v = {0,0,7};
		float4 point = v|XYZ1; //{0,0,7,1}
		float4 vector = v|XYZ0; //{0,0,7,0}
		}

		{
		float3 v = {0,0,7};
		float4 v1 = v|ZZZZ; //{7,7,7,7}
		}

		{
		float v[3] = {0,0,7};
		vref(v) *= 42;
		}

		{
		float3 v1, v2;
		v1 = v2|sw<1,0,2>(); //swaps elements with index 0 and 1
		v1 = v2|sw<_y_,_x_,_z_>(); //same as v2|YXZ;
		}
	}

void
multiply_column1( float33 & m, float scalar )
	{
    m|col<1>() *= scalar;
	}
