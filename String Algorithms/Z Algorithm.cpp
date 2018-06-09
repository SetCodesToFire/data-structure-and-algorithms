#include<string>
#include<iostream>
#include<vector>

#define MAX_N 1000001
using namespace std;

int n,m;
string needle,haystack;

int Z[MAX_N];
vector<int> matches;

inline void Z_Algorithm(string S){
  int len=S.length();
  int L=0,R=0;
  for(int i=1;i<len;i++){
    if(i>R){
      L=R=i;
      while(R<len && S[R-L]==S[R])
        R++;
      Z[i]=R-L;
      R--;
    }
    else{
      int k=i-L;
      if(Z[k]<R-i+1)
        Z[i]=Z[k];
      else{
        L=i;
        while(R<len && S[R-L]==S[R])
          R++;
          Z[i]=R-L;
          R--;
      }
    }
    if(Z[i]==m){matches.push_back(i-m-1);}
  }
}

int main(){
  n=6,m=2;
  haystack="abcabc";
  needle="bc";
  Z_Algorithm(needle+"#"+haystack);
  cout<<haystack<<"\n"<<needle<<"\n";
  for(int i=0;i<matches.size();i++){
    cout<<matches[i]+1<<"\n";
  }
  return 0;
}
