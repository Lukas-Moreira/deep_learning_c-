#include <boost/math/distributions/students_t.hpp>
#include <boost/math/distributions/chi_squared.hpp>

using namespace boost::math;

bool chi_squared_test(float population_std,float sample_std,int sample_size,float confidence);
bool t_test(float population_mean,float sample_mean,float sample_std_dev,int sample_size,float confidence);