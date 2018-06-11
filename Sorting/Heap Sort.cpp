#include<iostream>
#define MAX_N 1000001
using namespace std;

int n;
int arr[MAX_N];
int heap_size;

inline void Heapify(int pos){
  if(pos>heap_size) return;
  int ret=pos;
  int left=pos*2;
  int right=pos*2+1;
  if(left<=heap_size && arr[left]>arr[ret]) ret=left;
  if(right<=heap_size && arr[right]>arr[ret]) ret=right;
  if(ret!=pos){
    swap(arr[pos],arr[ret]);
    Heapify(ret);
  }
}

inline void Pop()
{
  int pos=1;
  swap(arr[pos],arr[heap_size--]);
  while(pos<=heap_size){
    int ret=pos;
    int left=pos*2;
    int right=pos*2+1;
    if(left<=heap_size && arr[left]>arr[ret]) ret=left;
    if(right<=heap_size && arr[right]>arr[ret]) ret=right;
    if(ret!=pos){
      swap(arr[pos],arr[ret]);
      pos=ret;
    }
    else break;
  }
}

int main(){
  n=5;
  arr[1]=4;
  arr[2]=2;
  arr[3]=5;
  arr[4]=1;
  arr[5]=3;
  heap_size=n;
  for(int i=n/2;i>=1;i--){
    Heapify(i);
  }
  while(heap_size>1) Pop();
  for(int i=1;i<=n;i++){
    cout<<arr[i]<<"\n";
  };
  return 0;
}
