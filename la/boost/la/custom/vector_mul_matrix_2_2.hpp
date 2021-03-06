//Copyright (c) 2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LA_CUSTOM_VECTOR_MUL_MATRIX_2_2_HPP_INCLUDED
#define BOOST_LA_CUSTOM_VECTOR_MUL_MATRIX_2_2_HPP_INCLUDED

//This file was generated by a program. Do not edit manually.

#include <boost/la/config.hpp>
#include <boost/la/deduce_vector.hpp>
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
            matrix_traits<B>::rows==2 && matrix_traits<B>::cols==2 &&
            vector_traits<A>::dim==2,
            deduce_vector2<A,B,2> >::type
        operator*( A const & a, B const & b )
            {
            typedef typename vector_traits<A>::scalar_type Ta;
            typedef typename matrix_traits<B>::scalar_type Tb;
            Ta const a0 = vector_traits<A>::template r<0>(a);
            Ta const a1 = vector_traits<A>::template r<1>(a);
            Tb const b00 = matrix_traits<B>::template r<0,0>(b);
            Tb const b01 = matrix_traits<B>::template r<0,1>(b);
            Tb const b10 = matrix_traits<B>::template r<1,0>(b);
            Tb const b11 = matrix_traits<B>::template r<1,1>(b);
            typedef typename deduce_vector2<A,B,2>::type R;
            BOOST_STATIC_ASSERT(vector_traits<R>::dim==2);
            R r;
            vector_traits<R>::template w<0>(r)=a0*b00+a1*b10;
            vector_traits<R>::template w<1>(r)=a0*b01+a1*b11;
            return r;
            }

        namespace
        la_detail
            {
            template <int M,int N>
            struct vector_mul_matrix_defined;

            template <>
            struct
            vector_mul_matrix_defined<2,2>
                {
                static bool const value=true;
                };
            }
        }
    }

#endif
