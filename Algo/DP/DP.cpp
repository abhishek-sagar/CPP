#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<limits>
using namespace std;

// 1. 0/1 knapsack prob

int knapsack(int wt[],int val[],int n,int w){
    int a[n+1][w+1];
    for(int i=0;i<=n;i++){
    	a[i][0] = 0;
    }
    for(int j=0;j<=w;j++){
    	a[0][j] = 0;
    }
    // upto this step we constructed an 2d array with first row and column are filled with 0;

    for(int i=1;i<=n;i++){
    	for(int j=1;j<=w;j++){
            if(j<wt[i-1]){
            	a[i][j] = a[i-1][j];
            }else{
                a[i][j] = max(val[i-1]+a[i-1][j-wt[i-1]] , a[i-1][j]);
            }
    	}
    }
    return a[n][w];
}

// 2. LCS

int LongCommSubs(char s1[],char s2[],int n1,int n2){ // taking s2 as row and s1 as col.
	int a[n2+1][n1+1];
	for(int i=0;i<=n1;i++){
		a[0][i] = 0;
	}
	for(int i=0;i<=n2;i++){
		a[i][0] = 0;
	}
    // upto this step we constructed an 2d array with first row and column are filled with 0;

	for(int i=1;i<=n2;i++){
		for(int j=1;j<=n1;j++){
			if(s2[i-1] == s1[j-1]){
				a[i][j] = a[i-1][j-1]+1;
			}else{
				a[i][j] = max(a[i-1][j],a[i][j-1]);
			}
		}
	}

    return a[n2][n1];
}

// 3. matrix chain multiplication cost 

int MatrixMulti(int p[],int n){ // O(n^3)
	int m[n][n];
	for(int i=0;i<n;i++){
		m[i][i] = 0;
	}
    int q;
	for(int l=2;l<n;l++){
		for(int i=1;i<n-l+1;i++){
			int j = i+l-1;
			m[i][j] = INT_MAX;
			for(int k=i;k<j;k++){
               q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
               if(q<m[i][j]){
               	m[i][j] = q;
               }
			}
		}
	}
	return m[1][n-1];
}

// 4. subset sum problem

bool SubsetSum(int a[],int n,int x){
    bool m[n+1][x+1];
    for(int i=0;i<=n;i++){
    	m[i][0] = true;
    }
    for(int i=1;i<=x;i++){
    	m[0][i] = false;
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=x;j++){
           if(j<a[i-1]){
           	  m[i][j] = m[i-1][j];
           }else{
           	 if(m[i-1][j] == true){
                m[i][j] = m[i-1][j];
           	 }else{
           	 	m[i][j] = m[i-1][j-a[i-1]];
             }
           }
    	}
    }
    return m[n][x];
}


// 5. Optimal BST

int OptimalBST(int nodes[],int freq[],int n){ // similar to 3rd problem
	int m[n][n];
	for(int i=0;i<n;i++){
		m[i][i] = freq[i];
	}
    int q;
	for(int l=2;l<=n;l++){
		for(int i=0;i<n-l+1;i++){
			int j = l+i-1;
            m[i][j] = INT_MAX;
			int freq_sum = 0;
			for(int p=0;p<l;p++){
				freq_sum += freq[i+p];
			}
  	 		for(int k=i;k<=j;k++){
              q = freq_sum + ( (k-1 < i ? 0 : m[i][k-1]) + (k+1 > j ? 0 : m[k+1][j]) );
              if(q<m[i][j]){
              	m[i][j] = q;
              }
			}
		}
	}
	return m[0][n-1];
}

// 6. coin exchange problem , this method is optimum one

int CoinExchange(int coins[],int n,int x){
	long int m[x+1];   // it stores the no. of coins require to get the given value.
	int a[x+1];   // used to store the that from which coin the indexed no. is formed.

    for(int i=0;i<=x;i++){
       m[i] = INT_MAX;
       a[i] = -1;
    }
    m[0] = 0;  // as we reqiore 0 coins to make 0.

 	for(int i=0;i<n;i++){
		for(int j=0;j<=x;j++){
			if(j>=coins[i]){
				long int q = 1+m[j-coins[i]];
				if(q<m[j]){
					m[j] = q;
					a[j] = i; // the value at m[j] is comming from ith index of coins
				}
			}
		}
	}
	return m[x];
}

// 7.number of ways to get the total

int ToalWays(int coins[],int n,int x){
	int m[n+1][x+1];
	for(int i=1;i<=n;i++){
		m[i][0] = 1;
	}
	for(int i=0;i<=x;i++){
		m[0][i] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			if(j<coins[i-1]){
				m[i][j] = m[i-1][j];
			}else{
				m[i][j] = m[i-1][j]+m[i][j-coins[i-1]];
			}
		}
	}
	cout<<"No. of ways to return the change : "<<m[n][x]<<endl;
}


// 8. minimum edit distance

int MinimumEdit(char s1[],char s2[],int n1,int n2){
	int a[n1+1][n2+1];
	for(int i=0;i<=n1;i++){
		a[i][0] = i;
	}
	for(int i=0;i<=n2;i++){
		a[0][i] = i;
	}

	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			if(s1[i-1] == s2[j-1]){
				a[i][j] = a[i-1][j-1];
			}else{
				a[i][j] = min(a[i][j-1],min(a[i-1][j-1],a[i-1][j]))+1;
			}
		}
	}
	return a[n1][n2];
}

// 9. longest increasing subseq.

int LongIncSubs(int a[],int n){
	int ans[n];
	for(int i=0;i<n;i++){
		ans[i] = 1;
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i]){
				ans[i] = max(ans[j]+1,ans[i]);
			}
		}
	}
    int longIncSub=0;
	int index;
	for(int i=0;i<n;i++){
       if(ans[i]>longIncSub){
       	longIncSub = ans[i];
       	index = i;
       }
	}
    // cout<<"values contributing to LIS : "<<a[index]<<",";
    // for(int i=index-1;i>=0;i--){
    //      if(a[i]<a[index]){
    //      	cout<<a[i]<<",";
    //      }
    // }
    return longIncSub;
}

// 10. max palindromic subsequence length

void MaxPalindromicSubs(char s[],int n){
    int m[n][n];
    for(int i=0;i<n;i++){
    	m[i][i] = 1;
    }
    for(int l=2;l<=n;l++){
    	for(int i=0;i<n-l+1;i++){
    		int j = l+i-1;
            if(s[i]==s[j]){
                m[i][j] = 2+m[i+1][j-1];
            }else{
            	m[i][j] = max(m[i][j-1],m[i+1][j]);
            }
    	}
    }

    cout<<"max palindromic subsequence length : "<<m[0][n-1]<<endl;
    return;
}

// 11. Rod Cutting Prob

int RodCutting(int RodParts[],int EachValue[],int n,int rodlength){
	int m[n+1][rodlength+1];
	for(int i=0;i<=n;i++){
		m[i][0] = 0;
	}
	for(int i=0;i<=rodlength;i++){
		m[0][i] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=rodlength;j++){
			if(j<RodParts[i-1]){
				m[i][j] = m[i-1][j];
			}else{
			m[i][j] = max(m[i-1][j],
			 max(EachValue[i-1]+m[i][j-RodParts[i-1]],EachValue[i-1]+m[i-1][j-RodParts[i-1]]));
			}
		}
	}
	cout<<"maximum profit is : "<<m[n][rodlength]<<endl;
}

int main(){
   int wt[] = {40,10,20,24};
   int val[] = {280,100,120,120};
   cout<<"total value in knapsack : "<<knapsack(wt,val,4,60)<<endl;

   char s1[] = {'a','b','c','d','a','f'};
   char s2[] = {'a','c','b','c','f'};
   cout<<"LCS : "<<LongCommSubs(s1,s2,6,5)<<endl;

   int a[] = {2,3,6,4,5};
   cout<<MatrixMulti(a,5)<<endl;

   int b[] = {2,3,7,8,10};
   if(SubsetSum(b,5,11)){
   	cout<<"Yes"<<endl;
   }else cout<<"No"<<endl;

   int nodes[] = {10,12,16,21};
   int freq[] = {4,2,6,3};
   cout<<"cost of BST : "<<OptimalBST(nodes,freq,4)<<endl;

   int coins[] = {7,2,3,6};
   cout<<"total coins require : "<<CoinExchange(coins,4,13)<<endl;

   int coins2[] = {1,2,3};
   ToalWays(coins2,3,5);

   char s4[] = {'a','b','c','d','e','f'};
   char s3[] = {'a','z','c','e','d'};
   cout<<"minimum edits require : "<<MinimumEdit(s3,s4,5,6)<<endl;

   int x[] = {3,4,-1,0,6,2,3};
   cout<<"LongIncSubs : "<<LongIncSubs(x,7)<<endl;

   char s[] = {'a','g','b','d','b','a'};
   MaxPalindromicSubs(s,6);

   int RodParts[] = {1,2,3,4};
   int EachValue[] = {2,5,7,8};
   RodCutting(RodParts,EachValue,4,5);

   
   return 0;
}