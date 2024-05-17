#ifndef FASTFTRANSLAFORM
#define FASTFTRANSLAFORM 1
#include"Types.h"
#include"Constant.h"
namespace FFT{
	//complex numbers
	using size_t=Types::size_t;
	//Fast Fourier Transform
	using complex=Types::complex;
	template<const size_t n>
	void dif(complex a[]){
		constexpr size_t half=n>>1,quarter=n>>2;
		complex w(1,0),w3(1,0);
		const complex wn(cos(Constant::pi2/n),sin(Constant::pi2/n)),wn3(cos(Constant::pi6/n),sin(Constant::pi6/n));
		for(size_t i=0;i<quarter;i++){
			if(!(i&2047))w=complex(cos(Constant::pi2*i/n),sin(Constant::pi2*i/n)),w3=w*w*w;
			const complex tmp1=a[i],tmp2=a[i+quarter],tmp3=a[i+half],tmp4=a[i+half+quarter];
			complex x=tmp1-tmp3,y=tmp2-tmp4;
			y=complex(y.imag(),-y.real());
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
	void dif<1>(complex a[]){}
	template<>
	void dif<0>(complex a[]){}
	template<>
	void dif<2>(complex a[]){
		const complex x=a[0],y=a[1];
		a[0]+=y;
		a[1]=x-y;
	}
	void rundif(complex a[],const size_t& n){
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
			case 1<<21:dif<1<<21>(a);break;
		}
	}
	template<const size_t n>
	void dit(complex a[]){
		constexpr size_t half=n>>1,quarter=n>>2;
		dit<half>(a);
		dit<quarter>(a+half);
		dit<quarter>(a+half+quarter);
		complex w(1,0),w3(1,0);
		const complex wn(cos(Constant::pi2/n),-sin(Constant::pi2/n)),wn3(cos(Constant::pi6/n),-sin(Constant::pi6/n));
		for(size_t i=0;i<quarter;i++){
			if(!(i&2047))w=complex(cos(Constant::pi2*i/n),-sin(Constant::pi2*i/n)),w3=w*w*w;
			const complex tmp1=w*a[i+half],tmp2=w3*a[i+half+quarter];
			const complex x=a[i],y=tmp1+tmp2;
			complex x1=a[i+quarter],y1=tmp1-tmp2;
			y1=complex(y1.imag(),-y1.real());
			a[i]+=y;
			a[i+quarter]+=y1;
			a[i+half]=x-y;
			a[i+half+quarter]=x1-y1;
			w*=wn;
			w3*=wn3;
		}
	}
	template<>
	void dit<1>(complex a[]){}
	template<>
	void dit<0>(complex a[]){}
	template<>
	void dit<2>(complex a[]){
		const complex x=a[0],y=a[1];
		a[0]+=y;
		a[1]=x-y;
	}
	void rundit(complex a[],const size_t& n){
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
			case 1<<21:dit<1<<21>(a);break;
		}
	}
}
#endif
