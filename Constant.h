#ifndef CONSTANT
#define CONSTANT 1
namespace Constant{
	template<typename _Tp>
	_Tp max(const _Tp& a,const _Tp& b){
		return a<b?b:a;
	}
	template<typename First_Tp,typename... Rest_Tp>
	First_Tp max(const First_Tp& first,const Rest_Tp&...rest){
		return max(first,max(rest...));
	}
	template<typename _Tp>
	_Tp min(const _Tp& a,const _Tp& b){
		return a<b?a:b;
	}
	template<typename First_Tp,typename... Rest_Tp>
	First_Tp min(const First_Tp& first,const Rest_Tp&...rest){
		return min(first,min(rest...));
	}
#ifdef _GLIBCXX_CMATH
	constexpr double pi=acos(-1),pi2=2*pi,pi6=6*pi;
#else
	constexpr double pi=3.141'592'653'589'793'238'46
	,pi2=2*pi,pi6=6*pi;
#endif
}
#endif
