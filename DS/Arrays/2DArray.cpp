#include<iostream>
#include<string>
#include<map>
using namespace std;

//** Wave Print **//(in this we print like 123654789)

void WavePrint(int a[][3],int row,int col){
    int flag = 0;
    int i=0,j=0;
    while(i<row){
        if(flag == 0){
           while(j<col){
           	cout<<a[i][j]<<",";
           	j++;
           }
           flag = 1;
           j--;
           i++;
        }else if(flag == 1){
        	while(j>=0){
        		cout<<a[i][j]<<",";
        		j--;
        	}
        	flag = 0;
        	j++;
        	i++;
        }
    }
    cout<<endl;
    return;
}


// Assignment 8 Problems //

// 2nd Question

void Question2(char a[][3],float n){
	float total_rows = (n+1)*(n/2);
	int i=n-1;
	for(i;i>=0;i--){
		int times = n-i;
		for(times;times>0;times--){
			int j=0;
			for(int k=total_rows-1;j<3;j++){
				a[k][j] = a[i][j];
			}
			total_rows--;
		}
	}
	return;
}

//** BinarySearch Using Recursion **//

int BinarySearch_R(int a[],int l,int r,int x){
   if(l>r){
   	return -1;
   }else{
   	  int mid = l+(r-l)/2;
   	  if(a[mid] == x){
   	  	return mid;
   	  }else if(a[mid]>x){
   	    return BinarySearch_R(a,l,mid-1,x);
   	  }else{
   	  	return BinarySearch_R(a,mid+1,r,x);
   	  }
   }
}


//** Subsiquences **//

void PrintSubs(string a,string out){
	if(a[0] == '\0'){
		cout<<out<<endl;
	}else{
		PrintSubs(a.substr(1),out);
		PrintSubs(a.substr(1),out+a[0]);
	}
	return;
}

int ReturnSubs(string s,char out[][6],int si){
   if(s.length() == si){
   	  out[0][0] = '\0';
   	  return 1;
   }else{
   	   int row = ReturnSubs(s,out,si+1);
   	   int i=0;
   	   out[row][0] = s[si];
   	   for(i;i<row;i++){
   	   	 int j=0;
   	     for(j;out[i][j]!='\0';j++){
   	       out[row+i][0] = s[si];	
   	   	   out[row+i][j+1] = out[i][j];
   	     }
   	     out[row+i][j+1] = '\0';
   	   }
    return (row+i);
   }
}

// stair n step prob //

long long int n_step(long long int stairs,long long int a[]){
	if(stairs == 1){
		a[1] = 1;
		return 1;
	}else if(stairs == 2){
		a[2] = 2;
		return 2;
	}else if(stairs == 3){
		a[3] = 3;
		return 4;
	}else if(a[stairs]!=0){
		return a[stairs];
	}
	else{
		long long int n = n_step(stairs-1,a)+ n_step(stairs-2,a) + n_step(stairs-3,a);
		a[stairs] = n;
		return n;
	}
}


//** Keypad **//

int Keypad(int a[],char out[][6],int si,int e,map<int,string> M){
	if(si == e){
        map<int,string>::iterator itr;
        itr = M.find(a[si]);
        string s = itr->second;
        int i=0;
        while(i<s.length()){
        	out[i][0] = s[i];
        	out[i][1] = '\0';
        	i++;
        }
        return i;
	}else{
		int row = Keypad(a,out,si+1,e,M);
		int i=0,n=0;
		map<int,string>::iterator itr;
        itr = M.find(a[si]);
		string x = itr->second;
		for(i;x[i+1]!='\0';i++){
		    for(int q=0;q<row;q++,n++){
			    out[row+n][0] = x[i];
			    int j=0;
			    for(j;out[q][j]!='\0';j++){
				  out[row+n][j+1] = out[q][j];
			    }
		    	out[row+n][j+1] = '\0';
		    }
	    }
		for(int k=row-1;k>=0;k--){
			int l = 0,j=0;
			while(out[k][j]!='\0'){
				l++;
				j++;
			}
			l++;
			while(l>0){
				out[k][l] = out[k][l-1];
				l--;
			}
			out[k][l] = x[i];
		}
		return (row+n);
	}
}

int main(){
   // char a[15][3];
   // for(int i=0;i<4;i++){
   // 	for(int j=0;j<3;j++){
   // 		cout<<"enter the "<<i<<"th row's "<<j<<"th col :- ";
   // 		cin>>a[i][j];
   // 	}
   // }
   // Question2(a,4);
   // for(int i=0;i<10;i++){
   // 	for(int j=0;j<3;j++){
   // 		cout<<a[i][j]<<" ";
   // 	}
   // 	cout<<endl;
   // }
   
   // int a[] = {-1,-1,0,1,2,2,4,5};
   // int n = BinarySearch_R(a,0,7,9);
   // if(n==-1){
   // 	cout<<"Not Found"<<endl;
   // }else{
   // 	cout<<a[n]<<endl;
   // }

   // string s = "abcde";
   // char out[100][6];
   // int n = ReturnSubs(s,out,0);
   // for(int i=0;i<n;i++){
   // 	 for(int j=0;out[i][j]!='\0';j++){
   // 	 	cout<<out[i][j];
   // 	 }
   // 	 cout<<endl;
   // }


   // long long  int n;
   // cout<<"enter stairs :- ";
   // cin>>n;
   // long long int a[n+1] = {0};
   // long long int out = n_step(n,a);
   // cout<<out<<endl;

    map<int, string> M;
    M.insert(pair<int,string>(1,""));
    M.insert(pair<int,string>(2,"abc"));
    M.insert(pair<int,string>(3,"def"));
    M.insert(pair<int,string>(4,"ghi"));
    M.insert(pair<int,string>(5,"jkl"));
    M.insert(pair<int,string>(6,"mno"));
    M.insert(pair<int,string>(7,"pqrs"));
    M.insert(pair<int,string>(8,"tuv"));
    M.insert(pair<int,string>(9,"wxyz"));
    M.insert(pair<int,string>(0," "));


    int a[10] = {2,7,9,9};
    char out[200][6];
    int row = Keypad(a,out,0,3,M);
    for(int i=0;i<row;i++){
  	  for(int j=0;out[i][j]!='\0';j++){
  		cout<<out[i][j];
  	  }
  	 cout<<endl;
    }

    return 0;
}
