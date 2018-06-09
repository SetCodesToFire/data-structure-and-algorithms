#include<iostream>

#define MAX_N 1000001
#define MAX_K 1000001
using namespace std;

int n;
int arr[MAX_N];
int count[MAX_K];

void counting_sort(){
  for(int i=0;i<n;i++)
    count[arr[i]]++;
  int ii=0;
  for(int i=0;i<MAX_K;i++)
  {
    while(count[i]>0){
      arr[ii++]=i;
      count[i]--;
    }
  }
}

int main(){
  n=5;
  arr[0]=4;
  arr[1]=2;
  arr[2]=5;
  arr[3]=1;
  arr[4]=3;
  counting_sort();
  for(int i=0;i<n;i++){
    cout<<arr[i]<<"\n";
  };
  return 0;
}
