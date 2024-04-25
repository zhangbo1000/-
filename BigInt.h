#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<iomanip>
#include<complex>
namespace Bigint{
	const size_t MAX_SIZE=1000000;
	char temp[MAX_SIZE+1];
	// Fast Fourier Transform
	using cp=std::complex<double>;
	const double pi=acos(-1),pi2=2*acos(-1),pi6=6*acos(-1);
	using ll=long long;
	template<const int n>
	void dif(cp a[]){
		constexpr int half=n/2,quarter=n/4;
		cp w(1,0),w3(1,0);
		constexpr cp wn(cos(pi2/n),sin(pi2/n)),wn3(cos(pi6/n),sin(pi6/n));
		for(int i=0;i<quarter;i++){
			if(!(i%2048))w=cp(cos(pi2*i/n),sin(pi2*i/n)),w3=w*w*w;
			const cp tmp1=a[i],tmp2=a[i+quarter],tmp3=a[i+half],tmp4=a[i+half+quarter];
			cp x=tmp1-tmp3,y=tmp2-tmp4;
			y=cp(y.imag(),-y.real());
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
	void dif<1>(cp a[]){}
	template<>
	void dif<0>(cp a[]){}
	template<>
	void dif<2>(cp a[]){
		const cp x=a[0],y=a[1];
		a[0]=x+y;
		a[1]=x-y;
	}
	void rundif(cp a[],const int& n){
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
	template<const int n>
	void dit(cp a[]){
		constexpr int half=n/2,quarter=n/4;
		dit<half>(a);
		dit<quarter>(a+half);
		dit<quarter>(a+half+quarter);
		cp w(1,0),w3(1,0);
		constexpr cp wn(cos(pi2/n),-sin(pi2/n)),wn3(cos(pi6/n),-sin(pi6/n));
		for(int i=0;i<quarter;i++){
			if(!(i%2048))w=cp(cos(pi2*i/n),-sin(pi2*i/n)),w3=w*w*w;
			const cp tmp1=w*a[i+half],tmp2=w3*a[i+half+quarter];
			const cp x=a[i],y=tmp1+tmp2;
			cp x1=a[i+quarter],y1=tmp1-tmp2;
			y1=cp(y1.imag(),-y1.real());
			a[i]+=y;
			a[i+quarter]+=y1;
			a[i+half]=x-y;
			a[i+half+quarter]=x1-y1;
			w*=wn;
			w3*=wn3;
		}
	}
	template<>
	void dit<1>(cp a[]){}
	template<>
	void dit<0>(cp a[]){}
	template<>
	void dit<2>(cp a[]){
		const cp x=a[0],y=a[1];
		a[0]=x+y;
		a[1]=x-y;
	}
	void rundit(cp a[],const int& n){
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
	class ulllint{
		friend std::istream;
		friend std::ostream;
		using ll=long long;
		using size_t=unsigned int;
		static constexpr size_t len=4;
		static constexpr size_t base=10000;
		std::vector<ll>nums;
		inline std::vector<ll>::const_iterator begin()const{return nums.begin();}
		inline std::vector<ll>::const_iterator end()const{return nums.end();}
		inline size_t size()const{return nums.size();}
		inline ll& operator[](const size_t& x){return nums[x];}
		inline const ll& operator[](const size_t& x)const{return nums[x];}
		ulllint(const std::vector<ll>::const_iterator& first,const std::vector<ll>::const_iterator& last){
			nums=std::vector<ll>(first,last);
		}// 用 vector 构造。
		ulllint(const short& x,const ll& y){
			nums=std::vector<ll>(x,y);
		}// 用多个相同数构造，不处理进位。
		ulllint(const std::vector<ll>&x){nums=x;}
	public:
		//用整数构造
		ulllint(const size_t& x=0){
			nums=std::vector<ll>(1,x);
			int i=0;
			while(nums[i]>base)nums.push_back(nums[i]/base),nums[i++]%=base;
		}
		//复制
		ulllint(const ulllint& x){
			nums=x.nums;
		}
		ulllint& operator=(const ulllint& x){
			nums=x.nums;
			return *this;
		}
		friend std::istream& operator>>(std::istream& cin,ulllint& x);
		friend std::ostream& operator<<(std::ostream& cout,const ulllint& x);
		friend ulllint operator+(const ulllint& x,const ulllint& y);
		friend ulllint operator-(const ulllint& x,const ulllint& y);
		friend ulllint operator*(const ulllint& x,const ulllint& y);
	};
	// input and output,use iostream
	std::istream& operator>>(std::istream& cin,ulllint& x){
		std::cin>>temp;
		const size_t l=strlen(temp);
		size_t j=-1,w=1;
		x.nums=std::vector<long long>(l/ulllint::len+2,0);
		for(size_t i=0;i<l;i++){
			if(!(i%ulllint::len))j++,w=1;
			x[j]+=(temp[l-i-1]^'0')*w;
			w*=10;
		}
		while(x.size()&&x[x.size()-1]==0)x.nums.pop_back();
		return cin;
	}
	std::ostream& operator<<(std::ostream& cout,const ulllint& x){
		if(x.size()==0)return cout;
		cout<<x[x.size()-1];
		for(signed int i=((int)x.size())-2;i>=0;i--){
			cout<<std::setfill('0')<<std::setw(ulllint::len)<<x[i];
		}
		return cout;
	}
	ulllint operator+(const ulllint& x,const ulllint& y){
		if(x.size()==0)return y;
		if(y.size()==0)return x;
		ulllint c(std::max(x.size(),y.size())+1,0);
		for(size_t i=0;i<x.size();i++)c[i]+=x[i];
		for(size_t i=0;i<y.size();i++)c[i]+=y[i];
		for(size_t i=0;i<c.size()-1;i++)c[i+1]+=c[i]/ulllint::base,c[i]%=ulllint::base;
		while(c.size()>1&&c[c.size()-1]==0)c.nums.pop_back();
		return c;
	}
	ulllint operator-(const ulllint& x,const ulllint& y){
		if(y.size()==0)return x;
		ulllint z(x);
		for(size_t i=0;i<y.size();i++){
			if(z[i]<y[i]){
				z[i]+=ulllint::base;
				z[i+1]--;
			}
			z[i]-=y[i];
		}
		while(z.size()>1&&z[z.size()-1]==0)z.nums.pop_back();
		return z;
	}
	ulllint operator*(const ulllint& x,const ulllint& y){
		static cp tmp[MAX_SIZE];
		static ulllint c;
		ulllint::size_t n=x.size()+y.size(),s=1;
		while(s<n)s<<=1;
		c.nums.resize(s);
		for(ulllint::size_t i=0;i<s;i++)tmp[i]=0; 
		for(ulllint::size_t i=0;i<x.size();i++)tmp[i].real(x[i]);
		for(ulllint::size_t i=0;i<y.size();i++)tmp[i].imag(y[i]);
		rundif(tmp,s);
		for(ulllint::size_t i=0;i<s;i++)tmp[i]*=tmp[i];
		rundit(tmp,s);
		const int kkk=s;
		const double change=0.5/kkk;
		for(ulllint::size_t i=0;i<s;i++){
			c[i]+=llround(tmp[i].imag()*(change));
			c[i+1]+=c[i]/10000;
			c[i]%=10000;
		}
		while(c.size()>1&&c[c.size()-1]==0)c.nums.pop_back();
		return c;
	}
}
