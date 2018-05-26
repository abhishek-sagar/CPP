#include<iostream>
#include<map>
#include<math.h>
#include<string>
using namespace std;

//** pair sum equal to x **// 

void PairEqualX(int a[],int l,int x){
   map<int, int> M;
   map<int, int>::iterator itr;
   int i=0;
   while(i<l){
      int sum = x-a[i];
      itr = M.find(sum);
      if(itr!=M.end()){
      	cout<<"("<<a[i]<<","<<sum<<")"<<",";
      }else{
      	M.insert(pair<int,int>(a[i],i));
      }
      i++;
   }
   cout<<endl;
   return;
}

//**Selection Sort**//

void SelectionSort(int a[],int l){
	for(int i=0;i<l;i++){
		int mini = 999999,minindex = -1;
		for(int j=i;j<l;j++){
           if(a[j]<mini){
           	 minindex = j;
           	 mini = a[j];
           }
		}
		int temp = a[i];
		a[i] = mini;
		a[minindex] = temp;
	}
	return;
}

//**Insertion Sort**//

void InsertionSort(int a[],int l){
	for(int i=0;i<l;i++){
		int val = a[i];
		int j;
		for(j=i;j>0;j--){
			if(val<a[j-1]){
				a[j] = a[j-1];
			}else{
				break;
			}
		}
		a[j] = val;
	}
	return;
}

//**BubbleSort **//

void BubbleSort(int a[],int l){
	for(int i=0;i<l;i++){
		for(int j=1;j<l-i;j++){
			if(a[j-1]>a[j]){
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
	return;
}

//** QuickSort **//

int pivot(int a[],int l,int r){
	int i=l-1,j=l,pi = r;
    while(j<r){
    	if(a[j]>a[pi]){
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
    int temp = a[pi];
    a[pi] = a[i];
    a[i] = temp;
    return i;
}

void QuickSort(int a[],int l,int r){
	if(l>r){
		return;
	}else{
		int pivotindex = pivot(a,l,r);
		QuickSort(a,l,pivotindex - 1);
		QuickSort(a,pivotindex + 1,r);
	}
	return;
}

//** Mergesort **//

void merge(int a[],int l,int mid,int r){
	int n1 = mid-l+1, n2 = r-mid, i=0, j=0, k=l;
	int left[n1],right[n2];
	while(i<n1){
		left[i] = a[l+i];
		i++;
	}
	while(j<n2){
		right[j] = a[mid+1+j];
		j++;
	}
	i=0;
	j=0;
	while(i<n1 && j<n2){
		if(left[i] <= right[j]){
			a[k] = left[i];
			i++;
		}else{
			a[k] = right[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]  = left[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k] = right[j];
		j++;
		k++;
	}
	return;
}

void Mergesort(int a[],int l,int r){
  if(l<r){
	int mid = l+(r-l)/2;
	Mergesort(a,l,mid);
	Mergesort(a,mid+1,r);
	merge(a,l,mid,r);
  }
 return;
}


//*** TripletSum ***// minimum complexity O(n^2);
/// all three approaches 

// Direct approach

void TripletDirect(int a[],int n,int x){  // Complexity O(n^3);
    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    	    for(int k=j+1;k<n;k++){
    	    	if(a[i]+a[j]+a[k] == x){
    	    		cout<<"("<<a[k]<<","<<a[i]<<","<<a[j]<<")"<<",";
    	    	}
    	    }
    	}
    }
    cout<<endl;
    return;
}

void TripletHash(int a[],int n,int x){
    for(int i=0;i<n;i++){
		map<int, int> M;
	    map<int, int>::iterator itr;
		for(int j=i+1;j<n;j++){
			int sum  =  x-(a[i]+a[j]);
			itr = M.find(sum);
			if(itr != M.end()){
				cout<<"("<<sum<<","<<a[i]<<","<<a[j]<<")"<<",";
			}else{
				M.insert(pair<int,int>(a[j],j));
			}
		}
	}
	cout<<endl;
	return;
}

void TripletSort(int a[],int n,int x){
    Mergesort(a,0,n-1);
    int i=0;
    for(i=0;i<n;i++){
    	int l=i+1;
    	int r = n-1;
    	while(l<r){
    		if(a[i]+a[l]+a[r] == x){
    			cout<<"("<<a[i]<<","<<a[l]<<","<<a[r]<<")"<<",";
    			l++;
    			r--;
    		}else if(a[i]+a[l]+a[r] < x){
    			l++;
    		}else{
    			r--;
    		}
    	}
    }
    cout<<endl;
    return;
}


//** put * b/w consicutive char **//   hel*lo

void ConsiChar(char s[],int si){
	if(s[si] == '\0' || s[si+1] == '\0'){
	  return;
	}else{
		if(s[si]== s[si+1]){
			int i=0;
			while(s[i]!='\0'){
				i++;
			}
			for(i;i>si;i--){
				s[i+1] = s[i];
			}
			s[si+1] = '*';
			ConsiChar(s,si+2);
		}else{
			ConsiChar(s,si+1);
		}
	}
	return;
}

//** integer to str **//

void IntToStr(int n){
	char s[10];
	int x = n,i=0;
	while(x!=0){
       x = x/10;
       i++;
	}
	s[i] = '\0';
	i--;
	while(i>=0){
       x = n%10;
       n = n/10;
       s[i] = char(48 + x);
       i--;  
	}
	cout<<s<<endl;
	return;
}

void ItoS_R(int n,char s[],int l,int si){
	if(n%10 == n){
        s[0] = char(48+n);
        s[l] = '\0';
	}else{
        s[l-si-1] = char(n%10 + 48);
        ItoS_R(n/10,s,l,si+1); 
	}
	return;
}

int main(){
    int a[] = {2,5,1,4,0,2,-1,-1,0,2};
    int n = 44562;
    char s[15];
    ItoS_R(n,s,5,0);
    cout<<s<<endl;
    //TripletSort(a,10,4);
    // for(int i=0;i<9;i++){
    // 	cout<<a[i]<<",";
    // }
    // cout<<endl;
    return 0;
}