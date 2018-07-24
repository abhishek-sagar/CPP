#include<iostream>
#include "Heap.h"
using namespace std;

void swap(int a[],int i,int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	return;
}

void heapify(int a[],int i,int n){
	int maxi = i;
    int lc = 2*i+1;
    int rc = 2*i+2;
    if(lc<n && a[lc]>a[maxi]){
        maxi = lc;
    }
    if(rc<n && a[rc]>a[maxi]){
        maxi = rc;
    }
    if(maxi == i){
        return;
    }else{
       swap(a,i,maxi);
       heapify(a,maxi,n);
       return;
    }
}

void MinHeapify(int a[],int i,int n){
	int mini = i;
    int lc = 2*i+1;
    int rc = 2*i+2;
    if(lc<n && a[lc]<a[mini]){
        mini = lc;
    }
    if(rc<n && a[rc]<a[mini]){
        mini = rc;
    }
    if(mini == i){
        return;
    }else{
       swap(a,i,mini);
       MinHeapify(a,mini,n);
       return;
    }
}

void HeapSort(int a[],int n){  // O(nlogn) && O(1) space
   for(int i=n/2 -1;i>=0;i--){
   	  heapify(a,i,n);
   }

   for(int i=n-1;i>=1;i--){
   	  swap(a,0,i);
      heapify(a,0,i);
   }
   return;
}

void SortKSortedArray(int a[],int n,int k){
	for(int i=k/2-1;i>=0;i--){
		MinHeapify(a,i,k);
	}
	for(int i=n-1;i>=1;i--){
	    swap(a,0,i);
	    if(k<i){
		  MinHeapify(a,0,k);
		}else MinHeapify(a,0,i);
	}
	for(int i=0,j=n-1;i<j;i++,j--){
        swap(a,i,j);
	}
	return;
}

void SlidingWindow(int a[],int n,int k){
   for(int i=k/2-1;i>=0;i--){
   	  heapify(a,i,k);
   }
   cout<<a[0]<<",";
   for(int i=k;i<n;i++){
   	 if(a[i]>a[0]){
   	 	swap(a,0,i);
   	 	heapify(a,0,k);
   	 }
   	 cout<<a[0]<<",";
   }
   cout<<endl;
   return;
}

int main(){
	Heap h;
	h.insert(4);
	h.insert(2);
	cout<<h.getMin()<<endl;
	h.print();
	h.insert(1);
	cout<<h.getMin()<<endl;
	h.print();
	h.insert(3);
	h.insert(5);
	h.insert(0);
	cout<<h.getMin()<<endl;
	h.print();
	h.RemoveMin();
	h.print();
	h.RemoveMin();
	h.print();
    cout<<h.getMin()<<endl;

    int a[] = {-7,4,-1,4,0,1,6,9,2};
    HeapSort(a,9);
    for(int i=0;i<9;i++){
    	cout<<a[i]<<",";
    }
    cout<<endl;

    int arr[] = {2, 6, 3, 12, 56, 8};
    SortKSortedArray(arr,6,3);
    for(int i=0;i<6;i++){
    	cout<<arr[i]<<",";
    }
    cout<<endl;
    int ar[] = {2, 6, 3, 12, 56, 8};
    SlidingWindow(ar,6,3);
    return 0;
}