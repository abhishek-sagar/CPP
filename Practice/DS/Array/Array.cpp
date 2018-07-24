#include<iostream>
#include<set>
using namespace std;

// pair sum equal to x

void Pair(int a[],int n,int x){
   set<int> m;
   for(int i=0;i<n;i++){
   	  int sum = x-a[i];
   	  set<int>:: iterator it = m.find(sum);
   	  if(it != m.end()){
   	  	cout<<"("<<a[i]<<","<<sum<<")"<<",";
   	  }else{
   	  	m.insert(a[i]);
   	  }
   }
   cout<<endl;
   return;
}

bool Triplet(int a[],int n,int x){ // 0.04
	for(int i=0;i<n-2;i++){
		set<int> m;
		int x1 = x-a[i];
		for(int j=i+1;j<n;j++){
			int sum = x1-(a[j]);
            set<int>::iterator it = m.find(sum);
            if(it!=m.end()){
            	return true;
            }else{
            	m.insert(a[j]);
            }
		}
	}
	return false;
}

// better triplet
// array is sorted passed to this function.
// bool Triplet(int a[],int n,int x){  //0.01
// 	for(int i=0;i<n-2;i++){
// 		int l = i+1;
// 		int r = n-1;
// 		while(l<r){
// 		    if(a[i]+a[l]+a[r] == x){
// 		        return true;
// 		    }else if(a[i]+a[l]+a[r] < x){
// 		        l++;
// 		    }else r--;
// 		}
// 	}
// 	return false;
// }

int main(){
   int a[] = {2,-1,0,3,1,2,5,7,1};
   Pair(a,9,4);
   return 0;
}