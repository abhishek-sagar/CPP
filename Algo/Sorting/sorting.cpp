#include<iostream>
using namespace std;

void InsertionSort(int a[],int n){
	for(int i=0;i<n;i++){
		int temp = a[i];
		int j=i;
		for(j;j>0;j--){
			if(a[j-1]>temp){
               a[j] = a[j-1];
			}else{
				break;
			}
		}
		a[j] = temp;
	}
	return;
}

int findPivot(int a[],int l,int r){
	int pivot = r;
	int i=l-1,j=l;
	while(j<r){
		if(a[j]>a[pivot]){
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
	int temp = a[pivot];
	a[pivot] = a[i];
	a[i] = temp;
	return i;
}

void quickSort(int a[],int l,int r){
	if(l<r){
		int pivot = findPivot(a,l,r);
        quickSort(a,l,pivot-1);
        quickSort(a,pivot+1,r);
	}
	return;
}

void merge(int a[],int l,int mid,int r){
	int n1 = mid-l+1,n2 = r-mid;
	int i=0,j=0;
	int left[n1],right[n2];
	for(int k=0;k<n1;k++){
       left[k] = a[l+k];
	}
	for(int k=0;k<n2;k++){
		right[k] = a[mid+k+1];
	}
	int k=0;
	while(i<n1 && j<n2){
        if(left[i]<right[j]){
        	a[l+k] = left[i];
        	i++;
        	k++;
        }else{
            a[l+k] = right[j];
            j++;
            k++;
        }
	}
	while(i<n1){
		a[l+k] = left[i];
		i++;
		k++;
	}
	while(j<n2){
		a[l+k] = right[j];
		j++;
		k++;
	}
	return;
}

void mergeSort(int a[],int l,int r){
	if(l<r){
         int mid = l+(r-l)/2;
         mergeSort(a,l,mid);
         mergeSort(a,mid+1,r);
         merge(a,l,mid,r);
	}
	return;
}

void heapify(int a[],int n,int i){
	int max_index = i;
	int left_child = 2*i+1;
	int right_child = 2*i+2;
	if(left_child<n && a[left_child]>a[max_index]){
		max_index = left_child;
	}
	if(right_child<n && a[right_child]>a[max_index]){
		max_index = right_child;
	}
	if(max_index == i){
		return;
	}else{
		int temp = a[i];
		a[i] = a[max_index];
		a[max_index] = temp;
		heapify(a,n,max_index);
	}
}

void heapSort(int a[],int n){
    for(int i=n/2;i>=0;i--){
    	heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heapify(a,i,0);
    }
    return;
}

// Topological sort O(V+E); DFS with an extra stack;

int main(){
  int a[9] = {3,-3,1,9,-1,7,-1,5,8};
  heapSort(a,9);
  for(int i=0;i<9;i++){
      cout<<a[i]<<",";
  }
  cout<<endl;
  return 0;
}