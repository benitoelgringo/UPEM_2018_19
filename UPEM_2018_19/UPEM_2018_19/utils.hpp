#pragma once

#include "boost/shared_ptr.hpp"
#include "boost/function.hpp"

template<typename T>
using ptr = boost::shared_ptr<T>;

using sde_function = boost::function2<double, double, double>;
