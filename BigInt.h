#ifndef BIGINT
#define BIGINT 1
#warning If G++ tell you "unused parameter 'a' [-Wunused-parameter]",it is NOT wrong.
#include<cstring>
#include<vector>
#include<iostream>
#include<iomanip>
#include"FastFTranslaform.h"
namespace BigInt{
	//unsigned long long long int
	using size_t=Types::size_t;
	using f64=Types::f64;
	using u64int=Types::u64int;
	using _32int=Types::_32int;
	class ulllint{
		friend std::istream;
		friend std::ostream;
		using ll=Types::_16int;
		static constexpr size_t len=4;
		static constexpr ll base=10000;
		std::vector<ll>nums;
		std::vector<ll>::const_iterator begin()const{return nums.begin();}
		std::vector<ll>::const_iterator end()const{return nums.end();}
		size_t size()const{return nums.size();}
		ll& operator[](const size_t& x){return nums[x];}
		const ll& operator[](const size_t& x)const{return nums[x];}
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
		static constexpr size_t MAX_SIZE=1000000;
		friend std::istream& operator>>(std::istream& cin,ulllint& x);
		friend std::ostream& operator<<(std::ostream& cout,const ulllint& x);
		friend ulllint operator+(const ulllint& x,const ulllint& y);
		friend ulllint operator-(const ulllint& x,const ulllint& y);
		friend ulllint operator*(const ulllint& x,const ulllint& y);
		friend ulllint operator/(const ulllint& x,const ulllint& y);
		ulllint operator+=(const ulllint& x){
			if(x.size()>size()){
				nums.resize(x.size()+1);
			}
			for(size_t i=0;i<size();i++){
				nums[i]+=x[i];
				nums[i+1]+=nums[i]/base;
				nums[i]%=base;
			}
			while((size()>1)&&nums[size()-1]==0)nums.pop_back();
			return *this;
		}
		ulllint operator-=(const ulllint& x){
			for(size_t i=0;i<x.size();i++){
				if(nums[i]<x[i]){
					nums[i+1]--;
					nums[i]+=base;
				}
				nums[i]-=x[i];
			}
			while(size()>1&&nums[size()-1]==0)nums.pop_back();
			return *this;
		}
		friend ulllint operator*=(ulllint& x,const ulllint& y);
		//	ulllint operator*=(const ulllint& x){(*this)=(*this)*x;return *(this);}
	};
	char temp[ulllint::MAX_SIZE+1];
	//输入输出，采用 iostream
	std::istream& operator>>(std::istream& cin,ulllint& x){
		std::cin>>temp;
		const size_t l=strlen(temp);
		size_t j=-1,w=1;
		x.nums.resize(l/ulllint::len+2);
		for(size_t i=0;i<l;i++){
			if(!(i%ulllint::len))j++,w=1;
			x[j]+=(temp[l-i-1]^'0')*w;
			w*=10;
		}
		while(x.size()>1&&x[x.size()-1]==0)x.nums.pop_back();
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
		static FFT::complex tmp[ulllint::MAX_SIZE];
		static ulllint c;
		size_t n=x.size()+y.size()-1,s=1;
		while(s<=n)s<<=1;
		c.nums.resize(s);
		for(size_t i=std::max(x.size(),y.size());i<s;i++)tmp[i]=0; 
		for(size_t i=0;i<x.size();i++)tmp[i].real(x[i]);
		for(size_t i=0;i<y.size();i++)tmp[i].imag(y[i]);
		FFT::rundif(tmp,s);
		for(size_t i=0;i<s;i++)tmp[i]*=tmp[i];
		FFT::rundit(tmp,s);
		const _32int kkk=s;
		const f64 change=0.5/kkk;
		u64int _tmp=0;
		for(size_t i=0;i<s;i++){
			_tmp+=(u64int)((tmp[i].imag()*change)+0.5);
			c[i]=_tmp%ulllint::base;
			_tmp/=ulllint::base;
		}
		while(c.size()>1&&c[c.size()-1]==0)c.nums.pop_back();
		return c;
	}
	ulllint operator*=(ulllint& x,const ulllint& y){
		static FFT::complex tmp[ulllint::MAX_SIZE];
		size_t n=x.size()+y.size()-1,s=1;
		while(s<=n)s<<=1;
		for(size_t i=std::max(x.size(),y.size());i<s;i++)tmp[i]=0; 
		for(size_t i=0;i<x.size();i++)tmp[i].real(x[i]);
		for(size_t i=0;i<y.size();i++)tmp[i].imag(y[i]);
		FFT::rundif(tmp,s);
		for(size_t i=0;i<s;i++)tmp[i]*=tmp[i];
		FFT::rundit(tmp,s);
		x.nums.resize(s);
		const int kkk=s;
		const double change=0.5/kkk;
		unsigned long long int _tmp=0;
		for(size_t i=0;i<s;i++){
			_tmp+=(unsigned long long int)((tmp[i].imag()*change)+0.5);
			x[i]=_tmp%ulllint::base;
			_tmp/=ulllint::base;
		}
		while(x.size()>1&&x[x.size()-1]==0)x.nums.pop_back();
		return x;
	}
}
#endif
