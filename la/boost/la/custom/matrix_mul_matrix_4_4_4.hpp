//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_MATRIX_MUL_MATRIX_4_4_4_HPP_INCLUDED
#define BOOST_LA_CUSTOM_MATRIX_MUL_MATRIX_4_4_4_HPP_INCLUDED

//This file was generated by a program. Do not edit manually.

#include <boost/la/config.hpp>
#include <boost/la/deduce_matrix.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/static_assert.hpp>

namespace
boost
    {
    namespace
    la
        {
        template <class A,class B>
        BOOST_LA_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            matrix_traits<A>::rows==4 && matrix_traits<B>::rows==4 &&
            matrix_traits<A>::cols==4 && matrix_traits<B>::cols==4,
            deduce_matrix2<A,B,4,4> >::type
        operator*( A const & a, B const & b )
            {
            typedef typename matrix_traits<A>::scalar_type Ta;
            typedef typename matrix_traits<B>::scalar_type Tb;
            Ta const a00 = matrix_traits<A>::template r<0,0>(a);
            Ta const a01 = matrix_traits<A>::template r<0,1>(a);
            Ta const a02 = matrix_traits<A>::template r<0,2>(a);
            Ta const a03 = matrix_traits<A>::template r<0,3>(a);
            Ta const a10 = matrix_traits<A>::template r<1,0>(a);
            Ta const a11 = matrix_traits<A>::template r<1,1>(a);
            Ta const a12 = matrix_traits<A>::template r<1,2>(a);
            Ta const a13 = matrix_traits<A>::template r<1,3>(a);
            Ta const a20 = matrix_traits<A>::template r<2,0>(a);
            Ta const a21 = matrix_traits<A>::template r<2,1>(a);
            Ta const a22 = matrix_traits<A>::template r<2,2>(a);
            Ta const a23 = matrix_traits<A>::template r<2,3>(a);
            Ta const a30 = matrix_traits<A>::template r<3,0>(a);
            Ta const a31 = matrix_traits<A>::template r<3,1>(a);
            Ta const a32 = matrix_traits<A>::template r<3,2>(a);
            Ta const a33 = matrix_traits<A>::template r<3,3>(a);
            Tb const b00 = matrix_traits<B>::template r<0,0>(b);
            Tb const b01 = matrix_traits<B>::template r<0,1>(b);
            Tb const b02 = matrix_traits<B>::template r<0,2>(b);
            Tb const b03 = matrix_traits<B>::template r<0,3>(b);
            Tb const b10 = matrix_traits<B>::template r<1,0>(b);
            Tb const b11 = matrix_traits<B>::template r<1,1>(b);
            Tb const b12 = matrix_traits<B>::template r<1,2>(b);
            Tb const b13 = matrix_traits<B>::template r<1,3>(b);
            Tb const b20 = matrix_traits<B>::template r<2,0>(b);
            Tb const b21 = matrix_traits<B>::template r<2,1>(b);
            Tb const b22 = matrix_traits<B>::template r<2,2>(b);
            Tb const b23 = matrix_traits<B>::template r<2,3>(b);
            Tb const b30 = matrix_traits<B>::template r<3,0>(b);
            Tb const b31 = matrix_traits<B>::template r<3,1>(b);
            Tb const b32 = matrix_traits<B>::template r<3,2>(b);
            Tb const b33 = matrix_traits<B>::template r<3,3>(b);
            typedef typename deduce_matrix2<A,B,4,4>::type R;
            BOOST_STATIC_ASSERT(matrix_traits<R>::rows==4);
            BOOST_STATIC_ASSERT(matrix_traits<R>::cols==4);
            R r;
            matrix_traits<R>::template w<0,0>(r)=a00*b00+a01*b10+a02*b20+a03*b30;
            matrix_traits<R>::template w<0,1>(r)=a00*b01+a01*b11+a02*b21+a03*b31;
            matrix_traits<R>::template w<0,2>(r)=a00*b02+a01*b12+a02*b22+a03*b32;
            matrix_traits<R>::template w<0,3>(r)=a00*b03+a01*b13+a02*b23+a03*b33;
            matrix_traits<R>::template w<1,0>(r)=a10*b00+a11*b10+a12*b20+a13*b30;
            matrix_traits<R>::template w<1,1>(r)=a10*b01+a11*b11+a12*b21+a13*b31;
            matrix_traits<R>::template w<1,2>(r)=a10*b02+a11*b12+a12*b22+a13*b32;
            matrix_traits<R>::template w<1,3>(r)=a10*b03+a11*b13+a12*b23+a13*b33;
            matrix_traits<R>::template w<2,0>(r)=a20*b00+a21*b10+a22*b20+a23*b30;
            matrix_traits<R>::template w<2,1>(r)=a20*b01+a21*b11+a22*b21+a23*b31;
            matrix_traits<R>::template w<2,2>(r)=a20*b02+a21*b12+a22*b22+a23*b32;
            matrix_traits<R>::template w<2,3>(r)=a20*b03+a21*b13+a22*b23+a23*b33;
            matrix_traits<R>::template w<3,0>(r)=a30*b00+a31*b10+a32*b20+a33*b30;
            matrix_traits<R>::template w<3,1>(r)=a30*b01+a31*b11+a32*b21+a33*b31;
            matrix_traits<R>::template w<3,2>(r)=a30*b02+a31*b12+a32*b22+a33*b32;
            matrix_traits<R>::template w<3,3>(r)=a30*b03+a31*b13+a32*b23+a33*b33;
            return r;
            }

        namespace
        la_detail
            {
            template <int M,int N,int P>
            struct matrix_mul_matrix_defined;

            template <>
            struct
            matrix_mul_matrix_defined<4,4,4>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif
