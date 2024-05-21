#ifndef CONSTANT
#define CONSTANT 1
namespace Constant{
#ifdef _GLIBCXX_CMATH
	constexpr double pi=acos(-1),pi2=2*pi,pi6=6*pi;
#else
	constexpr double pi=3.141'592'653'589'793'238'46
	,pi2=2*pi,pi6=6*pi;
#endif
}
#endif
