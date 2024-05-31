#ifndef FASTFTRANSFORM
#define FASTFTRANSFORM 1
#include<cmath>
#warning If GCC tells you "unused parameter 'a' [-Wunused-parameter]",it is NOT wrong.
#include"Types.h"
#include"Constant.h"
namespace FFT{
	constexpr Types::size_t MAX_FFT_LENGTH=1<<19;
	//Fast Fourier Transform
	template<const Types::size_t n>
	void dif(Types::complex a[]){
		constexpr Types::size_t half=n>>1,quarter=n>>2;
		Types::complex w(1,0),w3(1,0);
		const Types::complex wn(cos(Constant::pi2/n),sin(Constant::pi2/n)),wn3(cos(Constant::pi6/n),sin(Constant::pi6/n));
		for(Types::size_t i=0;i<quarter;i++){
			if(!(i&2047))w=Types::complex(cos(Constant::pi2*i/n),sin(Constant::pi2*i/n)),w3=w*w*w;
			const Types::complex tmp1=a[i],tmp2=a[i+quarter],tmp3=a[i+half],tmp4=a[i+half+quarter];
			const Types::complex x=tmp1-tmp3;
			Types::complex y=tmp2-tmp4;
			y=Types::complex(y.imag(),-y.real());
			a[i]+=tmp3;
			a[i+quarter]+=tmp4;
			a[i+half]=(x-y)*w;
			a[i+half+quarter]=(x+y)*w3;
			w*=wn;
			w3*=wn3;
		}
		dif<half>(a);
		dif<quarter>(a+half);
		dif<quarter>(a+half+quarter);
	}
	template<>
	void dif<1>(Types::complex a[]){}
	template<>
	void dif<0>(Types::complex a[]){}
	template<>
	void dif<2>(Types::complex a[]){
		const Types::complex x=a[0],y=a[1];
		a[0]+=y;
		a[1]=x-y;
	}
	template<>
	void dif<4>(Types::complex a[]){
		const Types::complex tmp1=a[0],tmp2=a[1],tmp3=a[2],tmp4=a[3];
		const Types::complex x=tmp1-tmp3;
		Types::complex y=tmp2-tmp4;
		y=Types::complex(y.imag(),-y.real());
		a[0]+=tmp3;
		a[1]+=tmp4;
		a[2]=x-y;
		a[3]=x+y;
		dif<2>(a);
	}
	void rundif(Types::complex a[],const size_t& n){
		switch (n) {
			case 1<<1:dif<1<<1>(a);break;
			case 1<<2:dif<1<<2>(a);break;
			case 1<<3:dif<1<<3>(a);break;
			case 1<<4:dif<1<<4>(a);break;
			case 1<<5:dif<1<<5>(a);break;
			case 1<<6:dif<1<<6>(a);break;
			case 1<<7:dif<1<<7>(a);break;
			case 1<<8:dif<1<<8>(a);break;
			case 1<<9:dif<1<<9>(a);break;
			case 1<<10:dif<1<<10>(a);break;
			case 1<<11:dif<1<<11>(a);break;
			case 1<<12:dif<1<<12>(a);break;
			case 1<<13:dif<1<<13>(a);break;
			case 1<<14:dif<1<<14>(a);break;
			case 1<<15:dif<1<<15>(a);break;
			case 1<<16:dif<1<<16>(a);break;
			case 1<<17:dif<1<<17>(a);break;
			case 1<<18:dif<1<<18>(a);break;
			case 1<<19:dif<1<<19>(a);break;
			case 1<<20:dif<1<<20>(a);break;
			throw("Cannot support FFT for such a long sequence.");
		}
	}
	template<const Types::size_t n>
	void dit(Types::complex a[]){
		constexpr Types::size_t half=n>>1,quarter=n>>2;
		dit<half>(a);
		dit<quarter>(a+half);
		dit<quarter>(a+half+quarter);
		Types::complex w(1,0),w3(1,0);
		const Types::complex wn(cos(Constant::pi2/n),-sin(Constant::pi2/n)),wn3(cos(Constant::pi6/n),-sin(Constant::pi6/n));
		for(Types::size_t i=0;i<quarter;i++){
			if(!(i&2047))w=Types::complex(cos(Constant::pi2*i/n),-sin(Constant::pi2*i/n)),w3=w*w*w;
			const Types::complex tmp1=w*a[i+half],tmp2=w3*a[i+half+quarter];
			const Types::complex x=a[i],y=tmp1+tmp2;
			const Types::complex x1=a[i+quarter];
			Types::complex y1=tmp1-tmp2;
			y1=Types::complex(y1.imag(),-y1.real());
			a[i]+=y;
			a[i+quarter]+=y1;
			a[i+half]=x-y;
			a[i+half+quarter]=x1-y1;
			w*=wn;
			w3*=wn3;
		}
	}
	template<>
	void dit<1>(Types::complex a[]){}
	template<>
	void dit<0>(Types::complex a[]){}
	template<>
	void dit<2>(Types::complex a[]){
		const Types::complex x=a[0],y=a[1];
		a[0]+=y;
		a[1]=x-y;
	}
	template<>
	void dit<4>(Types::complex a[]){
		dit<2>(a);
		const Types::complex tmp1=a[2],tmp2=a[3];
		const Types::complex x=a[0],y=tmp1+tmp2;
		const Types::complex x1=a[1];
		Types::complex y1=tmp1-tmp2;
		y1=Types::complex(y1.imag(),-y1.real());
		a[0]+=y;
		a[1]+=y1;
		a[2]=x-y;
		a[3]=x1-y1;
	}
	void rundit(Types::complex a[],const Types::size_t& n){
		switch (n) {
			case 1<<1:dit<1<<1>(a);break;
			case 1<<2:dit<1<<2>(a);break;
			case 1<<3:dit<1<<3>(a);break;
			case 1<<4:dit<1<<4>(a);break;
			case 1<<5:dit<1<<5>(a);break;
			case 1<<6:dit<1<<6>(a);break;
			case 1<<7:dit<1<<7>(a);break;
			case 1<<8:dit<1<<8>(a);break;
			case 1<<9:dit<1<<9>(a);break;
			case 1<<10:dit<1<<10>(a);break;
			case 1<<11:dit<1<<11>(a);break;
			case 1<<12:dit<1<<12>(a);break;
			case 1<<13:dit<1<<13>(a);break;
			case 1<<14:dit<1<<14>(a);break;
			case 1<<15:dit<1<<15>(a);break;
			case 1<<16:dit<1<<16>(a);break;
			case 1<<17:dit<1<<17>(a);break;
			case 1<<18:dit<1<<18>(a);break;
			case 1<<19:dit<1<<19>(a);break;
			case 1<<20:dit<1<<20>(a);break;
			throw("Cannot support FFT for such a long sequence.");
		}
	}
}
#endif
