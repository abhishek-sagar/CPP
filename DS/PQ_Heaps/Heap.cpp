#include<iostream>
#include<vector>
using namespace std;

void swap(int a[],int s,int e){
	int temp = a[s];
	a[s] = a[e];
	a[e] = temp;
	return;
}

void Heapify(int a[],int n,int rootIndex){
     int l = 2*rootIndex + 1;
     int r = 2*rootIndex + 2;
     int largest = rootIndex;
     if(l<n && a[l] > a[largest]){
     	largest = l;
     }
     if(r<n && a[r] > a[largest]){
     	largest = r;
     }
     if(largest != rootIndex){
     	swap(a,rootIndex,largest);
     	Heapify(a,n,largest);
     }
     return;
}

void HeapSort(int a[],int n){  // O(nlogn) && O(1) space
   for(int i=n/2 -1;i>=0;i--){
   	  Heapify(a,n,i);
   }

   for(int i=n-1;i>=1;i--){
      swap(a,0,i);
      Heapify(a,i,0);
   }
   return;
}

void KlargestEle(int a[],int n,int k){ // O(klogn)
	for(int i = n/2-1;i>=0;i--){ // create the max heap;
		Heapify(a,n,i);
	}
	for(int i=n-1;i>=n-k;i--){
       cout<<a[0]<<",";
       swap(a,i,0);
       Heapify(a,i,0);
	}
	return;
}

void MinHeapify(int a[],int n,int rootIndex){
	int l = 2*rootIndex+1;
	int r = 2*rootIndex+2;
	int minimumI = rootIndex;
	if(l<n && a[l] < a[minimumI]){
		minimumI = l;
	}
	if(r<n && a[r] < a[minimumI]){
		minimumI = r;
	}
	if(minimumI != rootIndex){
		swap(a,rootIndex,minimumI);
		MinHeapify(a,n,minimumI);
	}
}

void KlargestEffective(int a[],int n,int k){  // (n-k)logk
	for(int i=k/2-1;i>=0;i--){  // Heapify first k elements
		MinHeapify(a,k,0);
	}
    for(int i = k;i<n;i++){
    	if(a[i] > a[0]){
    		swap(a,i,0);
    		MinHeapify(a,k,0);
    	}
    }
    for(int i=0;i<k;i++){
    	cout<<a[i]<<",";
    }
    cout<<endl;
    return;
}

//************** Ques : K sorted array ************//
// use the same approach as of the previous question //
// make minheap of size k. remove a[0] at each itr^n and add a[i] element at a[0] then heapify


//************** Ques : Sliding window prob ***********//
// do as same as the privious question istead of MinHeapify us MaxHeapify .


//************** Ques : Merge k sorted arrays ************//
/* method 1:
       put all arrays in a single array and apply any sort (Best is heap sort) O(nk*log(nk))
   method 2:
       1. make a min heap of size k at put all the 0th ele. of each array in it.
       2. MinHeapify it and store the smallest in the resultant array. and put the 
          next element of the array whose element was removed in heap.
       3. repeat the 3rd step for all elements(total ele : nk).
          T.C : O(nk*logk)
*/

void print(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<",";
	}
	cout<<endl;
	return;
}

int main(){
    int a[] = {2,25,31,7,4,33,19,6,8};
    KlargestEffective(a,9,3);
    return 0;
} 