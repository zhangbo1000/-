#ifndef TYPES
#define TYPES 1
namespace Types{
	using ulong=unsigned long int;
	using size_t=unsigned int;
	using uint=unsigned int;
	using u8int=unsigned char;
	using u16int=unsigned short int;
	using u32int=unsigned long int;
	using u64int=unsigned long long int;
	using uint8=unsigned char;
	using uint16=unsigned short int;
	using uint32=unsigned long int;
	using uint64=unsigned long long int;
	using _8int=signed char;
	using _16int=signed short int;
	using _32int=signed long int;
	using _64int=signed long long int;
	using int8=signed char;
	using int16=signed short int;
	using int32=signed long int;
	using int64=signed long long int;
	using fshort=float;
	using fl=double;
	using fll=long double;
	using flong=long double;
	using f32=float;
	using f64=double;
	using f80=long double;
	using f128=long double;
	class complex{
		f64 a,b;
	public:
		complex(const complex& x):a(x.a),b(x.b){}
		complex(){}
		complex(const f64& x,const f64& y):a(x),b(y){}
		complex(const f64& x):a(x),b(0){}
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
}
#endif
