#include<string>
#include<iostream>
#include<vector>

#define MAX_N 1000001
using namespace std;

int n,m;
string needle,haystack;

int P[MAX_N];
vector<int> matches;

void KMP(){
  for(int i=0;i<m;i++){
    P[i]=-1;
  }
  for(int j=-1,i=0;i<m;)
  {
    while(j>-1 && needle[i]!=needle[j])
    {
      j=P[j];
    }
    i++;
    j++;
    P[i]=j;
  }
  for(int i=0,j=0;i<n;)
  {
    while(j>-1 && haystack[i]!=needle[j])
    {
      j=P[j];
    }
    i++;
    j++;
    if(j==m){
      matches.push_back(i-m);
      j=P[j];
    }
  }
}

int main(){
  n=6,m=2;
  haystack="abcabc";
  needle="bc";
  KMP();
  cout<<haystack<<"\n"<<needle<<"\n";
  for(int i=0;i<matches.size();i++){
    cout<<matches[i]+1<<"\n";
  }
  return 0;
}
