#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <stack>

//乘方运算使用^，优先级高于其他四则运算

int pri[256];

std::string trans(std::string str) {//转化为逆波兰式
  if(!str.length()) return std::string();
  int str_tot=0;char ch=str[0];
  std::string ans;
  std::stack<char> st;
  bool tag=0;
  while(1){
    if(ch>'9'||ch<'0'){
      if((ch>'z'||ch<'a')&&!pri[ch]) throw "Invalid Char!";
      if(pri[ch]&&ch!='('&&ch!=')'){
        if(tag) throw "Invalid String!";
        tag=1;
        while(st.size()&&pri[st.top()]>=pri[ch]&&st.top()!='(') ans=ans+st.top(),st.pop();
        st.push(ch);
      }
      if(ch=='(') st.push('('),tag=0;
      if(ch==')'){tag=0;
        while(st.size()&&st.top()!='(') ans=ans+st.top(),st.pop();
        if(!st.size()) throw "No Complete Parenthesis Matching!";
        st.pop();
      }
    }else ans=ans+ch,tag=0;
    if(str_tot+1==str.length()) break;
    ch=str[++str_tot];
  }
  while(st.size()) ans=ans+st.top(),st.pop();
  return ans;
}

int calc(std::string str){

}

std::string query(std::string str) {
  
}

int main(int argc, char** argv) {
  pri['+']=pri['-']=1;
  pri['*']=pri['/']=2;
  pri['^']=3;
  pri['(']=pri[')']=999;
  for (std::uint64_t i = 0;; i++) {
    std::printf("In[%d]: ", i);
    std::string str;
    std::cin >> str;
    if (str == "quit") { return 0; }
    std::printf("Out[%d]: ", i);
    try {
      std::cout << query(str) << std::endl;
    } catch (std::string error) {
      std::cout << "Expection: " << error;
    }
  }
  return 0;
}
