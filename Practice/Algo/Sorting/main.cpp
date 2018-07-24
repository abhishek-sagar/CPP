#include<iostream>
using namespace std;

void Merge(int a[],int l,int m,int r){
	int n1 = m-l+1, n2 = r-m;
	int a1[n1],a2[n2];
	int i=0,j=0;
	while(i<n1){
		a1[i] = a[l+i];
		i++;
	}
	while(j<n2){
		a2[j] = a[m+j+1];
		j++;
	}
    i=0;
    j=0;
    int k=0;
    while(i<n1 && j<n2){
    	if(a1[i]<=a2[j]){
    		a[l+k] = a1[i];
    		i++;
    		k++;
    	}else{
    		a[l+k] = a2[j];
    		j++;
    		k++;
    	}
    }
    while(i<n1){
    	a[l+k] = a1[i];
    	i++;
    	k++;
    }
    while(j<n2){
    	a[l+k] = a2[j];
    	j++;
    	k++;
    }
    return;
}

void MergeSort(int a[],int l,int r){
	if(l<r){
		int mid = l+(r-l)/2;
		MergeSort(a,l,mid);
		MergeSort(a,mid+1,r);
		Merge(a,l,mid,r);
	}
	return;
}

int main(){
   int a[] = {-5,2,0,-8,6,2,7,4};
   MergeSort(a,0,8);
   for(int i=0;i<8;i++){
   	cout<<a[i]<<",";
   }
   cout<<endl;
   return 0;
}