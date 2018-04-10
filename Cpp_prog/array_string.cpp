//This file contains simple code blocks codes upto arrays and string.Advanced array and string 
// in the DS folder okay lets start


#include<iostream>
#include<math.h>
#include<iomanip>
#include<map>
#include<string>
using namespace std;



// Patterns for basic logic building



// int main(){

	/* 1. ppt 1 time to try question no. 3 */
 
    //    int n;
	// cout<<"enter the value of n : ";
	// cin>>n;
	// int row = 0;
	// while(row<n){
	// 	int space = n-row-1;
	// 	while(space>0){
	// 		cout<<" ";
	// 		space--;
	// 	}
	// 	int col = 0;
	// 	int val = row+1;
 //        while(col<= row){
 //        	cout<<val;
 //        	val++;
 //        	col++;
 //        }
 //        row++;
 //        cout<<endl;
	// }
  

    /* 2. square root */

    // int n,d;
    // cout<<"enter n:- ";
    // cin>>n;
    // cout<<"enter decimal places: ";
    // cin>>d;
    // int k=d;
    // float i=1;
    // float increment = 1.0;
    // while(i*i<=n){
    // 	i = i+increment;
    //     while(i*i>n && d>0){
    //     	i = i-increment;
    //     	increment = 0.1*increment;
    //     	i = i+increment;
    //     	d--;
    //     }
    // }
    // cout<<std::fixed;
    // cout<<std::setprecision(k)<<(i-increment)<<endl;


    /* 3. cin vs cin.get() */


    // char c;
	// c = cin.get();
	// int count = 0;
	// while (c != '$') {
	// 	count++;
	// 	c = cin.get();
	// }
	// cout << count << endl;

    
    /* 4. Pattern ABCDEEDCBA for n=5 */

    // int n;
    // cout<<"enter n : ";
    // cin>>n;
    // int row=0;
    // while(row<n){
    // 	int col = n-row;
    //     char c = 'A';
    // 	while(col>0){
    // 		cout<<c;
    // 		c = (int)c + 1;
    // 		col--;
    // 	}
    // 	c = (int)c -1;
    //     while(col<(n-row)){
    //         cout<<c;
    //         c = (int)c -1;
    //         col++;
    //     }
         
    // 	row++;
    // 	cout<<endl;
    // }

// 	return 0;

// }






// Arrays and strings basics 

/* 1. pair sum equal to x. in O(n)*/

// void PairSumTo_x(int a[],int n,int x){
//    map<int,int> M;
//    map<int,int>::iterator it;
//    for(int i=0;i<n;i++){
//    	int val = x-a[i];
//     it = M.find(val);
//     if(it!=M.end()){
//         cout<<"("<<val<<","<<a[i]<<")"<<",";
//     }
//     M.insert(pair<int,int>(a[i],i));
//    }
//    return;
// }


 /* 2. sort array containing only 0 & 1. in O(n) */

// void SortZero_One(int a[],int n){
// 	int i=-1,j=0;
// 	while(j<n){
// 		if(a[j]==0){
//             i++;
//             if(a[i]==0){
//             	j++;
//             }else{
//             	int temp = a[i];
//             	a[i] = a[j];
//             	a[j] = temp;
//             	j++;
//             }
// 		}else{
// 			j++;
// 		}
// 	}
// 	return;
// }


/* 3. selection sort */

// void selection_sort(int a[], int n){
//     for(int i=0;i<n;i++){
//         int min = 999999;
//         int min_index;
//         for(int j=i;j<n;j++){
//             if(a[j] < min){
//                 min = a[j];
//                 min_index = j;
//             }
//         }
//         int temp = a[i];
//         a[i] = min;
//         a[min_index] = temp;
//     }
// }


/* 4. insertion sort */

// void insertion_sort(int a[],int n){
//      int j;
//      for(int i=1;i<n;i++){
//         int val = a[i];
//         for(j=i;j>0;j--){
//              if(val<a[j-1]){
//                 a[j] = a[j-1];
//              }
//              else{
//                 break;
//              }
//         }
//         a[j] = val;
//      }
// }

/* 5. bubble sort */

// void bubble_sort(int a[],int n){
//     for(int i=0;i<n;i++){
//         for(int j=1;j<n;j++){
//             if(a[j-1]>a[j]){
//                 int temp = a[j];
//                 a[j] = a[j-1];
//                 a[j-1] = temp;
//             }
//         }
//     }
// }


/* 6. print_array */

// void PrintArray(int a[],int n){
// 	for(int i=0;i<n;i++){
//    	  cout<<a[i]<<",";
//     }
//     cout<<endl;
//     return;
// }


/* 7. remove duplicates from a string */

void remove_dup(string &s){
  int i,j;
  for(i=0,j=1;s[j]!='\0';i++,j++){
    if(s[i] == s[j]){
        for(int k=j;s[k]!='\0';k++){
            s[k] = s[k+1];
        }
    }
  }
}

int main(){
   string str;
   cin>>str;
   remove_dup(str);
   cout<<str<<endl;
   return 0;
}
