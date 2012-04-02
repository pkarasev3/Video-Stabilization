//Copyright (c) 2008-2009 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/la/deduce_scalar.hpp>

struct foo;
typedef boost::la::deduce_scalar<foo,int>::type user_defined_types_require_specialization;
