#include<iostream>
#include<string>

#define MAX_N 5001
using namespace std;

int n;
int arr[MAX_N];

inline void bubble_sort()
{
  bool swapped;
  int it=0;
  do{
    swapped=false;
    for(int i=0;i<n-it-1;i++)
    {
      if(arr[i]>arr[i+1])
      {
        swap(arr[i],arr[i+1]);
        swapped=true;
      }
    }
    it++;
  }while(swapped);
}

int main(){
  n=5;
  arr[0]=4;
  arr[1]=2;
  arr[2]=5;
  arr[3]=1;
  arr[4]=3;
  bubble_sort();
  for(int i=0;i<n;i++){
    cout<<arr[i]<<"\n";
  };
  return 0;
}
