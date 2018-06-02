#include<iostream>
#include<climits>
using namespace std;

//*** Array Rotation ***//

// search in sorted and rotated array //   in O(logn)

int BinarySearch(int a[],int l,int r, int x){
	if(l<=r){
		int mid = l+(r-l)/2;
		if(a[mid] == x){
			return mid;
		}else if(a[mid]>x){
			return BinarySearch(a,l,mid-1,x);
		}else{
			return BinarySearch(a,mid+1,r,x);
		}
	}else{
		return -1;
	}
}

int FindPivot(int a[],int l,int r){   /// complexity is O(logn)
	if(l<=r){
		int mid = l + (r-l)/2;
		if(a[mid]>a[mid+1]){
			return mid;
		}else if(a[mid]>= a[l]){
			return FindPivot(a,mid+1,r);
		}else{
            return FindPivot(a,l,mid-1);
		}
	}
}

int SearchSR(int a[],int x,int l){
    // int i,pivot;
    // for(i=0;i<l;i++){
    //       if(a[i]>a[i+1]){
    //       	break;
    //       }
    // }
    // pivot = i;           giving complexity O(n);

    int pivot = FindPivot(a,0,l-1);
    if(x>=a[0]){
    	return BinarySearch(a,0,pivot,x);
    }else{
    	return BinarySearch(a,pivot+1,l-1,x);
    }
}

// pair sum equal to x in sorted and rotated array

void SumEqualXSR(int a[],int x,int n){
	int pivot = FindPivot(a,0,n-1);
	int l = pivot+1;
	int r = pivot;
	while(l!=r){
		if(a[l]+a[r] == x){
			cout<<"("<<a[l]<<","<<a[r]<<")"<<",";
			l++;
			r--;
		}else if(a[l]+a[r]>x){
			 r--;
		}else if(a[l]+a[r]<x){
			l++;
		}
		if(r == -1){
		    r = n-1;
		}
		if(l == n){
			l = 0;
		}
	}
	cout<<endl;
	return;
}

// other questions can be easily solved




//*** Arrangement of Array ***//


// Move all zeros to the end in one go


void MoveZeroEnd(int a[],int n){
  int i=n,j=n-1;
  for(j;j>=0;j--){
    if(a[j]!=0){
      j--;
    }else{
      i--;
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      j--;
    }
  }
  return;
}

// even pos +ve and odd position -ve || O(n)

void EvenOddPN(int a[],int n){
  int i=-1,j=0;
  while(j<n){
    if(a[j]>=0){
      j++;
    }else{
      i++;
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      j++;
    }
  }
  i++;
  j=0;
  while(j<n){
    if(a[i]>0 && i%2 == 0){
      i++;
    }
    if(a[j]<0){
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i = i+2;
    }
    j = j+2;
  }
}


//*** Order Stats ***//

// kth largest/Smallest no. question
    // 1. sort the array and find the kth element
    // 2. use quick sort for find kth smallest or largest;


//*** Optimization prob. ***//

// Max contigious subarray sum with indeces also using kadane's theo. 

void KadanesAlgo(int a[],int size){
  int max_so_far=0,max_ending_here=0;
  int s=0,e=0,i,start=0;
  for(i=0;i<size;i++){
    max_ending_here += a[i];
    if(max_ending_here < 0){
      s = i+1;
      max_ending_here = 0;
    }else if(max_so_far < max_ending_here){
      max_so_far = max_ending_here;
      start = s;
      e = i;
    }
  }
  cout<<"indeces are form "<<start<<" to "<<e<<" with sum : "<<max_so_far<<endl;
  return;
}

// min distance b/t two no os an array

void MinDist(int a[],int n,int x,int y){
   /* 1. first find position of both if either of them is not fount return -1
      2. now we have position of both
      3. now from the smaller index one search for the other nad note the dist.
      4. from the other find the first one if exist in smaller distance.
      5. finally return the min distance , if step 4 not exist the ret. the 3rd ans. 
    */
}




int main(){
    // int a[] = {11, 15, 26, 38, 9, 10};
    // int x = SearchSR(a,11,6);
    // if(x==-1){
    // 	cout<<"Not Found"<<endl;
    // }else{
    // 	cout<<"Found at : "<<x<<endl;
    // }

    //SumEqualXSR(a,45,6);
    // int arr[] = {1,0,3,4,0,0,2,0};
    // MoveZeroEnd(arr,8);
    // for(int i=0;i<8;i++){
    //   cout<<arr[i]<<",";
    // }
    // cout<<endl;

    // int a[] = {-1,1,-3,0,2};
    // EvenOddPN(a,5);
    // for(int i=0;i<5;i++){
    //   cout<<a[i]<<",";
    // }
    // cout<<endl;

    int a[] = {-2, -3, 4, -1, -2, -2, -5, 3};
    MinDist(a,8,-1,-2);
    return 0;
}