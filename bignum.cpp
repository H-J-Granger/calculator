/*
 * @Author: BilyHurington
 * @Date: 2020-09-01 13:27:57
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-01 13:52:46
 */
#include<bits/stdc++.h>
class BigNumber{
    private:
    std::vector<int> bit_;
    public:
    BigNumber(int len=0){bit_.clear();bit_.resize(len);}
    BigNumber(std::string s){
        bit_.clear();
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            if(s[i]>'9'||s[i]<'0') throw "Invalid String";
        }
        while(s.length()&&s.back()=='0') s.pop_back();
        if(!s.length()) bit_.push_back(0);
        else{
            bit_.resize(s.length());
            for(int i=0;i<s.length();i++) bit_[i]=s[i]-'0';
        }
    }
    int length() const {return bit_.size();}
    int& operator [](int x){return bit_[x];}
    int& at(int x){return bit_.at(x);}
    BigNumber operator + (const BigNumber &A) const& {
        BigNumber Ans(std::max((int)bit_.size(),A.length()));
        for(int i=0;i<bit_.size();i++) Ans[i]=bit_[i];
        
    }
};
int main(){
    
    return 0;
}