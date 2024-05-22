#ifndef BIGINT
#define BIGINT 1
#warning If G++ tell you "unused parameter 'a' [-Wunused-parameter]",it is NOT wrong.
#include<cstring>
#include<vector>
#include"FastFTransform.h"
namespace BigInt{
	//unsigned long long long int
	class __BigFloat{
		using ll=Types::_16int;
		static constexpr Types::size_t len=4;
		static constexpr ll base=10000;
		std::vector<ll>nums;
		Types::_32int ratio;
		std::vector<ll>::const_iterator begin()const{return nums.begin();}
		std::vector<ll>::const_iterator end()const{return nums.end();}
		Types::size_t size()const{return nums.size();}
		ll& operator[](const Types::size_t& x){return nums[x];}
		const ll& operator[](const Types::size_t& x)const{return nums[x];}
		friend __BigFloat operator+(const __BigFloat&,const __BigFloat&);
		friend __BigFloat operator-(const __BigFloat&,const __BigFloat&);
		friend __BigFloat operator*(const __BigFloat&,const __BigFloat&);
		__BigFloat(const __BigFloat& x){
			nums=x.nums;
			ratio=x.ratio;
		}
		__BigFloat& operator=(const __BigFloat& x){
			nums=x.nums;
			ratio=x.ratio;
			return *this;
		}
		__BigFloat(){};
	};
	class ulllint{
#ifdef _GLIBCXX_IOMANIP
#ifdef _GLIBCXX_IOSTREAM
		friend std::istream;
		friend std::ostream;
#endif
#endif
		using ll=Types::_16int;
		static constexpr Types::size_t len=4;
		static constexpr ll base=10000;
		std::vector<ll>nums;
		std::vector<ll>::const_iterator begin()const{return nums.begin();}
		std::vector<ll>::const_iterator end()const{return nums.end();}
		Types::size_t size()const{return nums.size();}
		ll& operator[](const Types::size_t& x){return nums[x];}
		const ll& operator[](const Types::size_t& x)const{return nums[x];}
		ulllint(const std::vector<ll>::const_iterator& first,const std::vector<ll>::const_iterator& last){
			nums=std::vector<ll>(first,last);
		}// 用 vector 构造。
		ulllint(const Types::_16int& x,const ll& y){
			nums=std::vector<ll>(x,y);
		}// 用多个相同数构造，不处理进位。
		ulllint(const std::vector<ll>&x){nums=x;}
	public:
		//用整数构造
		ulllint(const Types::size_t& x=0){
			nums=std::vector<ll>(1,x);
			Types::size_t i=0;
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
		static constexpr Types::size_t MAX_SIZE=1000000;
#ifdef _GLIBCXX_IOMANIP
#ifdef _GLIBCXX_IOSTREAM
		friend std::istream& operator>>(std::istream& cin,ulllint& x);
		friend std::ostream& operator<<(std::ostream& cout,const ulllint& x);
#endif
#endif
		friend ulllint operator+(const ulllint&,const ulllint&);
		friend ulllint operator-(const ulllint&,const ulllint&);
		friend ulllint operator*(const ulllint&,const ulllint&);
		friend ulllint operator/(const ulllint&,const ulllint&);
#if __cplusplus >= 202002L	
		friend auto operator<=>(const ulllint&,const ulllint&);
#else 
		friend Types::_8int __comp(const ulllint&,const ulllint&);
		friend bool operator<(const ulllint&,const ulllint&);
		friend bool operator>(const ulllint&,const ulllint&);
		friend bool operator<=(const ulllint&,const ulllint&);
		friend bool operator>=(const ulllint&,const ulllint&);
		friend bool operator!=(const ulllint&,const ulllint&);
#endif
		friend bool operator==(const ulllint&,const ulllint&);
		ulllint operator+=(const ulllint& x){
			if(x.size()>size()){
				nums.resize(x.size()+1);
			}
			for(Types::size_t i=0;i<size();i++){
				nums[i]+=x[i];
				nums[i+1]+=nums[i]/base;
				nums[i]%=base;
			}
			while((size()>1)&&nums[size()-1]==0)nums.pop_back();
			return *this;
		}
		ulllint operator-=(const ulllint& x){
			for(Types::size_t i=0;i<x.size();i++){
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
	};
	char temp[ulllint::MAX_SIZE+1];
	//输入输出，采用 iostream
#ifdef _GLIBCXX_IOMANIP
#ifdef _GLIBCXX_IOSTREAM
	std::istream& operator>>(std::istream& cin,ulllint& x){
		std::cin>>temp;
		const Types::size_t l=strlen(temp);
		Types::size_t j=-1,w=1;
		x.nums=std::vector<ulllint::ll>(l/ulllint::len+2,0);
		for(Types::size_t i=0;i<l;i++){
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
#endif
#endif
	ulllint operator+(const ulllint& x,const ulllint& y){
		if(x.size()==0)return y;
		if(y.size()==0)return x;
		ulllint c(std::max(x.size(),y.size())+1,0);
		for(Types::size_t i=0;i<x.size();i++)c[i]+=x[i];
		for(Types::size_t i=0;i<y.size();i++)c[i]+=y[i];
		for(Types::size_t i=0;i<c.size()-1;i++)c[i+1]+=c[i]/ulllint::base,c[i]%=ulllint::base;
		while(c.size()>1&&c[c.size()-1]==0)c.nums.pop_back();
		return c;
	}
	ulllint operator-(const ulllint& x,const ulllint& y){
		if(y.size()==0)return x;
		ulllint z(x);
		for(Types::size_t i=0;i<y.size();i++){
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
		static Types::complex tmp[ulllint::MAX_SIZE];
		static ulllint c;
		Types::size_t n=x.size()+y.size()-1,s=1;
		while(s<=n)s<<=1;
		c.nums.resize(s);
		for(Types::size_t i=std::max(x.size(),y.size());i<s;i++)tmp[i]=0; 
		for(Types::size_t i=0;i<x.size();i++)tmp[i].real(x[i]);
		for(Types::size_t i=0;i<y.size();i++)tmp[i].imag(y[i]);
		FFT::rundif(tmp,s);
		for(Types::size_t i=0;i<s;i++)tmp[i]*=tmp[i];
		FFT::rundit(tmp,s);
		const Types::_32int kkk=s;
		const Types::f64 change=0.5/kkk;
		Types::u64int _tmp=0;
		for(Types::size_t i=0;i<s;i++){
			_tmp+=(Types::u64int)((tmp[i].imag()*change)+0.5);
			c[i]=_tmp%ulllint::base;
			_tmp/=ulllint::base;
		}
		while(c.size()>1&&c[c.size()-1]==0)c.nums.pop_back();
		return c;
	}
	ulllint operator*=(ulllint& x,const ulllint& y){
		static Types::complex tmp[ulllint::MAX_SIZE];
		Types::size_t n=x.size()+y.size()-1,s=1;
		while(s<=n)s<<=1;
		for(Types::size_t i=std::max(x.size(),y.size());i<s;i++)tmp[i]=0; 
		for(Types::size_t i=0;i<x.size();i++)tmp[i].real(x[i]);
		for(Types::size_t i=0;i<y.size();i++)tmp[i].imag(y[i]);
		FFT::rundif(tmp,s);
		for(Types::size_t i=0;i<s;i++)tmp[i]*=tmp[i];
		FFT::rundit(tmp,s);
		x.nums.resize(s);
		const Types::_32int kkk=s;
		const Types::f64 change=0.5/kkk;
		Types::u64int _tmp=0;
		for(Types::size_t i=0;i<s;i++){
			_tmp+=(Types::u64int)((tmp[i].imag()*change)+0.5);
			x[i]=_tmp%ulllint::base;
			_tmp/=ulllint::base;
		}
		while(x.size()>1&&x[x.size()-1]==0)x.nums.pop_back();
		return x;
	}
#if __cplusplus >= 202002L
	auto operator<=>(const ulllint& x,const ulllint& y){
		if(x.size()<y.size())return -1;
		if(x.size()>y.size())return 1;
		for(int i=x.size()-1;i>=0;i--){
			if(x[i]>y[i])return 1;
			if(x[i]<y[i])return -1;
		}
		return 0;
	}
	bool operator==(const ulllint& x,const ulllint& y){
		return (x<=>y)==0;
	}
#else
	Types::_8int __comp(const ulllint& x,const ulllint& y){
		if(x.size()<y.size())return -1;
		if(x.size()>y.size())return 1;
		for(int i=x.size()-1;i>=0;i--){
			if(x[i]>y[i])return 1;
			if(x[i]<y[i])return -1;
		}
		return 0;
	}
	bool operator<(const ulllint& x,const ulllint& y){return __comp(x,y)<0;}
	bool operator>(const ulllint& x,const ulllint& y){return __comp(x,y)>0;}
	bool operator<=(const ulllint& x,const ulllint& y){return __comp(x,y)<=0;}
	bool operator>=(const ulllint& x,const ulllint& y){return __comp(x,y)>=0;}
	bool operator==(const ulllint& x,const ulllint& y){return __comp(x,y)==0;}
	bool operator!=(const ulllint& x,const ulllint& y){return __comp(x,y)!=0;}
#endif
}
#endif
