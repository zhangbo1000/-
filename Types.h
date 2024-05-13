#ifndef TYPES
#define TYPES 1
namespace Types{
	using size_t=unsigned int;
	using uint=unsigned int;
	using u32int=unsigned long int;
	using u64int=unsigned long long int;
	using _64int=signed long long int;
	using _32int=signed long int;
	using _16int=signed short int;
	using f64=double;
	using f32=float;
	using flong=long double;
	class complex{
		f64 a,b;
	public:
		constexpr complex(const complex& x):a(x.a),b(x.b){}
		complex(){}
		constexpr complex(const f64& x,const f64& y):a(x),b(y){}
		constexpr complex(const f64& x):a(x),b(0){}
		const complex operator=(const f64& x){return a=x;}
		const complex operator=(const complex& x){
			a=x.a;b=x.b;
			return *this;
		}
		const complex operator+(const complex& x)const{
			return complex(a+x.a,b+x.b);
		}
		const complex operator-(const complex& x)const{
			return complex(a-x.a,b-x.b);
		}
		const complex operator*(const complex& x)const{
			return complex(a*x.a-b*x.b,a*x.b+b*x.a);
		}
		const complex operator+=(const complex& x){
			a+=x.a;
			b+=x.b;
			return *this;
		}
		const complex operator-=(const complex& x){
			a-=x.a;
			b-=x.b;
			return *this;
		}
		const complex operator*=(const complex& x){
			return (*this)=(*this)*x;
		}
		f64 real()const{return a;}
		f64 imag()const{return b;}
		f64 real(const double& x){return a=x;}
		f64 imag(const double& x){return b=x;}
	};
	using cp=complex;
}
#endif
