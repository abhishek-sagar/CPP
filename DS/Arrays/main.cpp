#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

// Reversal algo for Array Rotation
// void reverseA(int a[],int s,int e){
//     while(s<e){
//     	int temp = a[s];
//     	a[s] = a[e];
//     	a[e] = temp;
//     	s++;
//     	e--;
//     }
//     return;
// }

// void RotateA(int a[],int d,int n){
//     reverseA(a,0,d-1);
//     reverseA(a,d,n-1);
//     reverseA(a,0,n-1);
//     return;
// }


//**** Rearrange +ve and -ve no. alternatively in O(n)

// void Rearrange(int a[],int n){
// 	int i=-1;
// 	int j=0;
// 	while(j<n){
// 		if(a[j]<0){
// 			i++;
// 			int temp = a[i];
// 			a[i] = a[j];
// 			a[j] = temp;
// 		}
// 		j++;
// 	}
// 	int pos = i+1;
// 	int neg = 0;
// 	while(pos<n && neg<pos && a[neg]<0){
// 		int temp = a[pos];
// 		a[pos] = a[neg];
// 		a[neg] = temp;
// 		neg = neg+2;
// 		pos++;
// 	}
// }


// *** Sort an array in wave form means ek bada then chota then bada like this;


// void SortInWave(int a[],int n){
// 	int i=0;
// 	while(i<n){
// 		if(i>0 && a[i] < a[i-1]){
// 			int temp = a[i];
// 			a[i] = a[i-1];
// 			a[i-1] = temp;
// 		}
// 		else if(i<n && a[i] < a[i+1]){
// 			int temp = a[i];
// 			a[i] = a[i+1];
// 			a[i+1] = temp;
//             i = i+2;
// 		}
// 		else{
// 			i = i+2;
// 		}
// 	}
// }


// ********* Alternate sabse bada then sabse chota in a Sorted Array in O(1) space,Use Formula

// void Rearrange(int a[],int n){
// 	int max_i = n-1, min_i = 0;
// 	int max_e = a[n-1]+1;
// 	for(int i=0;i<n;i++){
// 		if(i%2 == 0){
// 			a[i] = a[i] + (a[max_i]%max_e)*max_e;
// 			max_i--;
// 		}
// 		else{
// 			a[i] = a[i] + (a[min_i]%max_e)*max_e;
// 		    min_i++;
// 		}
// 	}
// 	for(int i=0;i<n;i++){
// 		a[i] = a[i]/max_e;
// 	}
// 	return;
// } 

//******* max product of subarray *******

// int min(int a, int b){
// 	return (a<b? a : b);
// }
// int max(int a,int b){
// 	return (a>b? a : b);
// }

// int MaxProd(int v[],int n) {
//         int i;
//         if(n==0)return 0;
//         if(n==1)return v[0];
//         int pos_product,neg_product,max_product=v[0],past_pos,past_neg;
//         past_pos=pos_product=max(0,v[0]);
//         past_neg=neg_product=min(0,v[0]);
//         for(i=1;i<n;i++){
//             if(v[i]<0){
//                 pos_product=past_neg*v[i];
//                 neg_product=min(v[i],v[i]*past_pos);
//             }
//             else{
//                 pos_product=max(v[i],past_pos*v[i]);
//                 neg_product=past_neg*v[i];
//             }
//             past_pos=pos_product;
//             past_neg=neg_product;
//             max_product=max(pos_product,max_product);
//         }
//         return max_product;
// }

//************ pair sum equal to x; **********//

void PairSumX(int a[],int n,int sum){
	map<int,int> M;
	for(int i=0;i<n;i++){
        int temp = sum-a[i];
        map<int, int>::iterator itr = M.find(temp);
        if(itr != M.end() && itr->second == 1){
              cout<<"("<<temp<<","<<a[i]<<")"<<",";
        }
        M.insert(pair<int,int>(a[i],1));
	}
	return;
}

 
//********Number accuring odd no. of times********//

// void OddAccuring(int a[],int n){
// 	map<int,int> m;
// 	map<int,int>::iterator itr;
// 	for(int i=0;i<n;i++){
// 		itr = m.find(a[i]);
// 		if(itr != m.end()){
// 			itr->second += 1; 
// 		}
// 		else{
// 			m.insert(pair<int,int>(a[i],1));
// 		}
// 	}
//     itr = m.begin();
//     for(itr;itr!=m.end();itr++){
//     	if(itr->second > 1 && (itr->second)%2 != 0){
//     		cout<<itr->first<<endl;
//     	    break;
//     	}
//     }
//     return;
// }


//******* Triplet sum equal to x **********//

void merge(int a[],int s,int m,int e){
	int n1 = m-s+1;
	int n2 = e-m;
	int a1[n1],a2[n2];
	int i,j,k;
	for(i=0;i<n1;i++){
		a1[i] = a[i+s];
	}
	for(j=0;j<n2;j++){
		a2[j] = a[j+m+1];
	}
	i=0;
	j=0;
	k=s;
	while(i<n1 && j<n2){
		if(a1[i]<=a2[j]){
			a[k] = a1[i];
			i++;
		}
		else{
			a[k] = a2[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k] = a1[i];
		i++;
		k++;
	}
    while(j<n2){
		a[k] = a2[j];
		j++;
		k++;
	}
	return;
}

void mergesort(int a[],int s,int e){
  if(s<e){
	int mid = s+(e-s)/2;
	mergesort(a,s,mid);
	mergesort(a,mid+1,e);
	merge(a,s,mid,e);
  }
 return;
}

// int find(int a[],int l,int r,int x){
// 	if(l>r){
// 		return -999999;
// 	}
// 	int mid = l+(r-l)/2;
// 	if(a[mid] == x){
// 		return (a[mid]);
// 	}
// 	else if(a[mid]>x){
// 		find(a,l,mid-1,x);
// 	}
// 	else{
// 		find(a,mid+1,r,x);
// 	}
// }


// void Triplet(int a[],int n,int x){
//     mergesort(a,0,n-1);
//     int l=0,r = n-1;
//     while(l<r){
//        if((a[l]+a[r]) > x){
       	   
//        	   int third = find(a,l+1,r-1,(x-(a[l]+a[r])));
//        	   if(third != -999999){
//        	   	 cout<<"("<<a[l]<<","<<third<<","<<a[r]<<")"<<",";
//        	   }
//        	   r--;
//        }       
//        else if(a[l]+a[r] < x){
           
//        	   int third = find(a,l+1,r-1,(x-(a[l]+a[r])));
//        	   if(third != -999999){
//        	   	 cout<<"("<<a[l]<<","<<third<<","<<a[r]<<")"<<",";
//        	   }
//        	   l++;
//        } 
//        else{
//           int third = find(a,l+1,r-1,0);
//        	   if(third == 0){
//        	   	 cout<<"("<<a[l]<<","<<third<<","<<a[r]<<")"<<",";
//        	   }
//        	   l++;
//        	   r--;
//        }
//     }
//     return;
// }


//***** sum of all substrings of a string representing a no. in O(n) *******//

// int toDigit(char c){
// 	return ((int)c - (int)'0');
// }

// void SumSubStr(string s,int l){
//     int totalsum = toDigit(s[0]);
//     int prevsum = toDigit(s[0]);
//     for(int i=1;i<l;i++){
//          prevsum = toDigit(s[i])*toDigit(s[i]) + 10*prevsum;
//          totalsum = totalsum + prevsum;
//     }
//     cout<<totalsum<<endl;
//     return;
// }


// ***** Sort elements by their frequency ******//
void SortByFreq(int a[],int n){

}


//****** Subsequences of a String********//

void print_subs(string input,string output){
	if(input.length() == 0){
		cout<<output<<endl;
		return;
	}
	print_subs(input.substr(1),output);
	print_subs(input.substr(1),output+input[0]);
	return;
}

int main(){
   int a[8] = {3,5,-1,1,2,4,7,0};
   PairSumX(a,8,4);
   return 0;
}