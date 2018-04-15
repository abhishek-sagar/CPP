#include<iostream>
#include<cstring>
#include<string>
#include <math.h>
#include<map>
using namespace std;

// 2D arrays 

/* 1. Wave print */

// void wave_print(int a[][3],int rows,int cols){
// 	int flag = 1;
// 	int i=0,j=0,column = 0;
// 	while(true){
// 		if(flag == 1){
// 			for(i=0;i<rows;i++){
// 				cout<<a[i][column]<<" ";
// 			}
// 		   column++;
// 		   i--;
// 		   flag = 0;
// 		}
// 		if(column == cols){
// 			break;
// 		}
// 		if(flag == 0){
//              for(i;i>=0;i--){
//                  cout<<a[i][column]<<" ";
//              }
//              column++;
//              i++;
//              flag = 1;
// 		}
// 		if(column == cols){
// 			break;
// 		}
// 	}
// 	return;
// }


/* 1. remove pi by 3.14 */

void remove_pi(char s[],int si){
     int l = strlen(s);
     if(l==0 || l==1 || si == l){
     	return;
     }else{
        if(s[si]=='p' && s[si+1] == 'i'){
            for(int i = l;i>si+1;i--){
            	s[i+2] = s[i];
            }
            s[si] = '3';
            s[si+1] = '.';
            s[si+2] = '1';
            s[si+3] = '4';
            return remove_pi(s,si+4);
        }else{
        	return remove_pi(s,si+1);
        }      
     }
}

/* 2. insert * between two consicutive same char */

void remove_consicutive(char s[],int si){
	int l = strlen(s);
	if(l == 0 || l==1 || si == l){
		return;
	}else{
		if(s[si] == s[si+1]){
           for(int i=l;i>si;i--){
                s[i+1] = s[i];
           }
           s[si+1] = '*';
           return remove_consicutive(s,si+2);
		}
		return remove_consicutive(s,si+1);
	}
}




/* ASSIGNMENT 8 Problems (Dhasu Questions) */

/* 2. Question, hint:- in this question i am coping the ith row ,jth times at 
																kth row */

void twoDArray(char s[][3],float n){  // passing the matrix and the total rows
	float total_rows = (n+1)*(n/2);
	int k = total_rows-1;
    for(int i = n-1;i>=0;i--){
    	int j = n-i;
    	for(k,j;j>0;k--,j--){
    		for(int m=0;m<3;m++){
    			s[k][m] = s[i][m];
    		}
    	}
    }
    for(int i=0;i<total_rows;i++){
    	for(int j=0;j<3;j++){
    		cout<<s[i][j];
    	}
    	cout<<endl;
    }
}


/* 3. Binary Search using recursion  */

int Binary_search_R(int a[],int si,int li,int x){
	if(si>li){
		return -1;
	}else{
		int mid = (si+li)/2;
		if(a[mid] == x){
			return mid;
		}else if(a[mid]>x){
			return Binary_search_R(a,si,mid-1,x);
		}else{
			return Binary_search_R(a,mid+1,li,x);
		}
	}
}


/* 4. Print all Subsequences */

void Subsequences(string s,string out){
	if(s.length() == 0){
		cout<<out<<endl;
		return;
	}else{
		Subsequences(s.substr(1),out);
		Subsequences(s.substr(1),out + s[0]);
	}
}

/* 5. Return total rows of Array of all the Subsequences and Print them */

int subs(string input, char out[][6]){
	int i,j;
	if(input.length() == 0){
		out[0][0] = '\0';
		return 1;
	}else{
		int rows = subs(input.substr(1),out);
		out[rows][0] = input[0];        // for first element 
		for(i=0;i<rows;i++){
			for(j=0;out[i][j]!='\0';j++){
                out[rows+i][0] = input[0];   // always copy the first element 
                out[rows+i][j+1] = out[i][j];  // copying the elements from output.
			}
		    out[i+rows][j+1] = '\0';     
		}
		return rows+i;
	}
}

/* 6. keypad question , hint: kind of similar to subsequences question
    ,first analyse the algo then it will be easy ,do it on paper first. */

int keypad(int a[],int si,int l,map<int,string> M, char out[][5]){
  map<int,string>::iterator itr;
  int i,j,k,m;
  if(si == l){
  	return -1;
  }else if(si+1 == l){  //Base case
  	itr = M.find(a[si]);
  	for(j=0;itr->second[j]!='\0';j++){
  		out[j][0] = itr->second[j];
  		out[j][1] = '\0';
  	}
  	return j;
  }else{
  	int row = keypad(a,si+1,l,M,out);
  	itr = M.find(a[si]);   // find string at a[si];
  	m=0;
  	for(k=0;itr->second[k+1]!='\0';k++){ // only for first two char of string
  	    for(i=0,m;i<row;i++,m++){        // for the total rows in output
  		    for(j=0;out[i][j]!='\0';j++){  // for coping each col val 
  			    out[row+m][0] = itr->second[k];
  			    out[row+m][j+1] = out[i][j];   
  		    }
  		    out[row+m][j+1] = '\0';
  	    }
    }
    // for the last char of string , handled seprately
    for(i=0;i<row;i++){
  		int n=0;
  		while(out[i][n] !='\0'){ // finding the length of each row
  			n++;
  		}
  		for(n;n>=0;n--){  // shifting each row one unit right
  			out[i][n+1] = out[i][n];  
  		}  
  		out[i][0] = itr->second[k]; // putting the last char at front 
  	}
    return row + m;
  }
}


/* 7. stairs and n step problem , Using DP*/  

long long int N_step(long long int stairs,long long int a[]){
   if(stairs == 1 || stairs == 0){
   	return 1;
   }else if(stairs == 2){
   	return 2;
   }else if(a[stairs]!=0){
   	return a[stairs];
   }
   else{
   	    long long int result = N_step(stairs-3,a)+N_step(stairs-2,a)+N_step(stairs-1,a);
   	    a[stairs] = result;
   	    return result;
   }
}


int main(){
  // char s[10][3];
  // for(int i=0;i<4;i++){
  // 	for(int j=0;j<3;j++){
  // 		cout<<"enter the "<<i<<"th rows "<<j<<"th element :- ";
  // 		cin>>s[i][j];
  // 	}
  // }
  // twoDArray(s,4);
 


  // char s[10] = "Helllo";
  // cout<<s<<endl;
  // remove_consicutive(s,0);
  // cout<<s<<endl;


  // int a[10] = {1,2,3,4,5,6};
  // int x = Binary_search_R(a,0,5,4);
  // cout<<"index of 4: "<<x<<endl;


  // string s;
  // cin>>s;
  // char out[100][6];
  // int row = subs(s,out);   //sending an input array with an empty output array 
  // for(int i=0;i<row;i++){
  // 	for(int j=0;out[i][j]!='\0';j++){
  // 		cout<<out[i][j];
  // 	}
  // 	cout<<endl;
  // }


  // map<int, string> M;
  // M.insert(pair<int,string>(1,""));
  // M.insert(pair<int,string>(2,"abc"));
  // M.insert(pair<int,string>(3,"def"));
  // M.insert(pair<int,string>(4,"ghi"));
  // M.insert(pair<int,string>(5,"jkl"));
  // M.insert(pair<int,string>(6,"mno"));
  // M.insert(pair<int,string>(7,"pqrs"));
  // M.insert(pair<int,string>(8,"tuv"));
  // M.insert(pair<int,string>(9,"wxyz"));
  // M.insert(pair<int,string>(0," "));

  // int a[10] = {2,3,4};
  // char out[200][5];
  // int row = keypad(a,0,3,M,out);
  // for(int i=0;i<row;i++){
  // 	for(int j=0;out[i][j]!='\0';j++){
  // 		cout<<out[i][j];
  // 	}
  // 	cout<<endl;
  // }



  long long int stairs;
  cin>>stairs;
  long long int a[stairs+1] = {0};
  long long int step = N_step(stairs,a);
  cout<<"total ways : "<<step<<endl;
  return 0;
}