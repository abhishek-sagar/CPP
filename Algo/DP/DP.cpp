#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<climits>
#include<limits>
#include<stack>
#include<string>
#include<set>
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

int Matrix(int a[],int n){
    int m[n-1][n-1];
    for(int i=0;i<n-1;i++){
        m[i][i] = 0;
    }
    for(int l=2;l<n;l++){
        for(int i=0;i<n-l;i++){
            int j = l+i-1;
            m[i][j] = 99999;
            for(int k=i;k<j;k++){
                int q = m[i][k] + m[k+1][j] + a[i]*a[k+1]*a[j+1];
                if(q<m[i][j]){
                    m[i][j] = q;
                }
            }
        }
    }
    return m[0][n-2];
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

// 12. Job scheduling prob

static bool compare(pair<pair<int,int>,int> P1,pair<pair<int,int>,int> P2){
	return (P1.second < P2.second);
}

void JobSche(int StartTime[],int EndTime[],int profit[],int n){
	vector<pair<pair<int,int>,int>> v;
	for(int i=0;i<n;i++){
		pair<int,int> p(StartTime[i],profit[i]);
		pair<pair<int,int>,int> P(p,EndTime[i]);
		v.push_back(P);
	}
	sort(v.begin(),v.end(),compare);
    int m[n];
    for(int i=0;i<n;i++){
    	pair<pair<int,int>,int> P = v.at(i);
    	pair<int,int> p = P.first;
    	m[i] = p.second;
    }

	for(int j=1;j<n;j++){
		for(int i=0;i<j;i++){
			pair<pair<int,int>,int> P1 = v.at(i);
			pair<pair<int,int>,int> P2 = v.at(j);
			pair<int,int> p1 = P1.first;
			pair<int,int> p2 = P2.first;
			int end_i = P1.second;
			int start_j = p2.first;
			int profit_j = p2.second;
			if(end_i <= start_j){
               int q = m[i]+profit_j;
               if(q>m[j]){
               	m[j] = q;
               }
			}
		}
	}
	int maxprofit = INT_MIN;
	for(int i=0;i<n;i++){
		if(m[i]>maxprofit){
			maxprofit = m[i];
		}
	}
	cout<<"Max Profit After Job Scheduling is : "<<maxprofit<<endl;
	return;
}

// 13. Egg Dropping Puzzel, minimum no. of tests require to check at which floor,dropping 
//     the egg will result into breaking it.

void EggDrop(int eggs,int floors){
	int m[eggs+1][floors+1];
    for(int i=0;i<=eggs;i++){
    	m[i][0] = 0;
    }
    for(int i=0;i<=floors;i++){
    	m[0][i] = 0;
        m[1][i+1] = i+1; // intializing the first row;
    }

    for(int i=2;i<=eggs;i++){
    	for(int j=1;j<=floors;j++){
    		if(j<i){
    			m[i][j] = m[i-1][j]; // if eggs > floors copy from top
    		}else{
    			// min of ( 1+max(agar kth pe break ho gaya to k-1 floors pe call krdo 
    			// with 1 less egg(i-1) , agar break nhi hua to egg to utne hi h (i)
    			// and call krdo j-k floors ke liye) )
    			int Till_min = INT_MAX;
    			for(int k=1;k<=j;k++){
                   int q = 1+max(m[i-1][k-1],m[i][j-k]);
                   if(q<Till_min){
                   	Till_min = q;
                   }
    			}
    			m[i][j] = Till_min;
    		}
    	}
    }
    cout<<"min tests require to check egg will break are : "<<m[eggs][floors]<<endl;
    return;
}

// 14. Longest common substring

void LCSubStr(char s1[],char s2[],int n1,int n2){
	int m[n2+1][n1+1];
	for(int i=0;i<=n1;i++){
		m[0][i] = 0;
	}
	for(int i=0;i<=n2;i++){
		m[i][0] = 0;
	}

	for(int i=1;i<=n2;i++){
		for(int j=1;j<=n1;j++){
			if(s2[i-1]!=s1[j-1]){
				m[i][j] = 0;
			}else{
				m[i][j] = 1+m[i-1][j-1];
			}
		}
	}

	// iterate though the matrix and find the largest no.
    int max = INT_MIN;
    for(int i=1;i<=n2;i++){
    	for(int j=1;j<=n1;j++){
          if(m[i][j] > max){
          	max = m[i][j];
          }
    	}
    }

	cout<<"Longest common substring : "<<max<<endl;
	return;
}

// Max sum contigious subarray,Kadane's Algo.

pair<pair<int,int>,int> MaxSumSubarray(int a[],int n){ // O(n)
	int i,j,startI,endI,k;
	int Max_sum_till = 0;
	int currentsum = 0;
	for(j=0;j<n;j++){
		currentsum = currentsum+a[j];
		if(currentsum < 0){
			currentsum = 0;
			k = j+1;
		}
		else{
			if(currentsum > Max_sum_till){
				Max_sum_till = currentsum;
				endI = j;
				startI = k;
			}
		}
	}
	pair<int,int> p(startI,endI);
	pair<pair<int,int>,int> P(p,Max_sum_till);
	return P;
}

// 16. Max sum SubRectangle in a 2d Matrix

void MaxSumSubRect(int m[][5],int rows,int cols){
	int a[rows];
    int CurrentSum,MaxSum = INT_MIN,left,right,top,bottom;
    for(int l=0;l<cols;l++){

    	for(int i=0;i<rows;i++){
    		a[i] = 0;
    	}

    	for(int r = l;r<cols;r++){

            for(int i=0;i<rows;i++){
    		   a[i] = a[i] + m[i][r];
            }

            pair<pair<int,int>,int> P = MaxSumSubarray(a,rows);
            pair<int,int> p = P.first;
            CurrentSum = P.second;
            if(CurrentSum>MaxSum){
            	MaxSum = CurrentSum;
            	left = l;
            	right = r;
            	top = p.first;
            	bottom = p.second;
            }

    	}
    }
    cout<<"MaxSum SubRectangle : "<<MaxSum<<endl;
    return;
}

// 17. Max Size Rect of 1's in a 2d matrix;

int AreaUnderHist(int hist[],int n){
    int i=0,MaxArea = INT_MIN;
    stack<int> s;
    while(i<n){
    	if(s.empty() || hist[i] >= hist[s.top()]){
    		s.push(i);
    		i++;
    	}else{
    		int current = s.top();
    		s.pop();
            int CurrentArea = hist[current]*((s.empty())?i:(i-1-s.top()));
            if(CurrentArea > MaxArea){
            	MaxArea = CurrentArea;
            }
    	}
    }
    while(!s.empty()){
    	int current = s.top();
    	s.pop();
        int CurrentArea = hist[current]*((s.empty())?i:(i-1-s.top()));
        if(CurrentArea > MaxArea){
        	MaxArea = CurrentArea;
        }
    }
    return MaxArea;
}

void MaxRectSize(int m[][4],int rows,int cols){
	int a[cols] = {0};
    int MaxSize = INT_MIN;
	for(int t=0;t<rows;t++){
		for(int i=0;i<cols;i++){
			if(m[t][i] == 0){
				a[i] = 0;
			}else{
				a[i] = a[i] + m[t][i];
			}
		}
        int CurrentSize = AreaUnderHist(a,cols);
        if(CurrentSize > MaxSize){
        	MaxSize = CurrentSize;
        }
	}
	cout<<"MaxSize of 1's Rect is : "<<MaxSize<<endl;
	return;
}


// Max Profit Buying or selling Stock at max k transections

void Stock(int a[],int n,int k){
    int m[k+1][n];
    for(int i=0;i<n;i++){
        m[0][i] = 0;   // if 0 transactions so no profit
    }
    for(int i=0;i<=k;i++){
        m[i][0] = 0;  // if only one stock so no profit
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<n;j++){
            int option1 = m[i][j-1]; // do not buy that stock and the profit remain same
            int option2 = -999999;
            // option2 is to check all the stocks from 0 to j-1 and check which give max pro.
            // this loop can be removed by storing maximum (-a[l]+m[i-1][l]) then add to a[j];
            for(int l = 0;l<j;l++){
                int q = a[j]-a[l]+m[i-1][l];  // a[j]-a[l] is for sell at j and buy at l
                if(q>option2){                // m[i-1][l] is for profit for max left   
                    option2 = q;              // (i-1)th transec. 
                }
            }
            m[i][j] = max(option1,option2);
        }
    }
    cout<<m[k][n-1]<<endl;
    return;
}


// 18. Word Break Problem

void WordBreak(string s,int n,set<string> dictionary){
	bool m[n][n];
	for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             m[i][j] = 0;
         }
    }
	for(int i=0;i<n;i++){
		char test[3];
		int len = s.copy(test,1,i);
		test[len] = '\0';
		set<string>::iterator it = dictionary.find(test);
		if(it!=dictionary.end()){
			m[i][i] = true;
		}else{
			m[i][i] = false;
		}
	}

	for(int l = 2;l<=n;l++){
		for(int i=0;i<n-l+1;i++){
			int j = l+i-1;
			char check[20];
			int len = s.copy(check,j-i+1,i);
            check[len] = '\0';
            set<string>::iterator it = dictionary.find(check);
            if(it != dictionary.end()){
            	m[i][j] = true;
            }else{
            	for(int k=i;k<j;k++){
            		if(m[i][k] && m[k+1][j]){
            			m[i][j] = true;
            			break;
            		}else{
            			m[i][j] = false;
            		}
            	}
            }
		}
	}

    if(m[0][n-1]){
    	cout<<"'"<<s<<"'"<<" can be formed using dictionary."<<endl;
    }else{
    	cout<<"'"<<s<<"'"<<" cannot be formed."<<endl;
    }
    return;
} 

// 19. minimum cost path

void MinimumCostPath(int m[][3],int rows,int cols){
	int out[rows][cols];
	out[0][0] = m[0][0];
	for(int i=1;i<rows;i++){
		out[i][0] = out[i-1][0]+m[i][0];
	}
	for(int i=1;i<cols;i++){
		out[0][i] = out[0][i-1]+m[0][i];
	}

	for(int i=1;i<rows;i++){
		for(int j=1;j<cols;j++){
			out[i][j] = m[i][j]+min(out[i-1][j],out[i][j-1]);
		}
	}
	// for(int i=0;i<rows;i++){
	// 	for(int j=0;j<cols;j++){
	// 		cout<<out[i][j]<<",";
	// 	}
	// 	cout<<endl;
	// }
	cout<<"min cost path : "<<out[rows-1][cols-1]<<endl;
}

// 20. minimum jumps to reach end of an array

void MinJumps(int a[],int n){
	int jumps[n]; // it stores the no. of jumps till jth element
	int actualjump[n]; // it stores that from which index the jumps is taken
	if(a[0] == 0){
        cout<<"-1"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        jumps[i] = INT_MAX;
    }
    jumps[0] = 0;
    
    for(int i=0;i<n;i++){
        if(a[i] == 0 && a[i-1] == 1){
            cout<<"-1"<<endl;
            return;
        }
        int val = min(i+a[i],n-1);
        for(int j=i+1;j<=val;j++){
            jumps[j] = min(jumps[j],jumps[i]+1);
            actualjump[j] = i;
        }
    }
    cout<<"Min jumps require to reach end : "<<jumps[n-1]<<endl;
    return;
}


// 21. Max Sub square matrix;

void MaxSubSqMat(int input[][5],int rows,int cols){
    int m[rows+1][cols+1];
    for(int i=0;i<=rows;i++){
    	m[i][0] = 0;
    }
    for(int i=0;i<=cols;i++){
    	m[0][i] = 0;
    }
    for(int i=1;i<=rows;i++){
    	for(int j=1;j<=cols;j++){
    		if(input[i][j] == 0){
    			m[i][j] = 0;
    		}else{
    			m[i][j] = 1 + min(m[i][j-1],min(m[i-1][j-1],m[i-1][j]));
    		}
    	}
    }
    int MaxSubArraySize = INT_MIN;
    for(int i=1;i<=rows;i++){
    	for(int j=1;j<=cols;j++){
    		if(m[i][j] > MaxSubArraySize){
    			MaxSubArraySize = m[i][j];
    		}
    	}
    }
    cout<<"The Max Sub Square Matrix Size is : "<<MaxSubArraySize<<endl;
    return;
}

// 22. optimal strategy for the game

void OptimalStrategy(int a[],int n){
	pair<int,int> m[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		   pair<int,int> p(0,0);
		   m[i][j] = p;
		}
	}
	for(int i=0;i<n;i++){
		pair<int,int> p(a[i],0);
		m[i][i] = p;
	}
    
    for(int l=2;l<=n;l++){
       for(int i=0;i<n-l+1;i++){
       	int j = l+i-1;
        (m[i][j]).first =  max(a[i]+(m[i+1][j]).second ,
        	                   a[j]+(m[i][j-1]).second);
        (m[i][j]).second =  min((m[i+1][j]).first,(m[i][j-1]).first);	                    
       }
    }
    pair<int,int> p = m[0][n-1];
    cout<<"Max score of first player : "<<p.first<<endl;
    return;
}

// 23. staircase problem

int Staircase(int stairs,int a[]){ // Not Optimal solution
	if(stairs == 0){
		return 0;
	}else if(stairs == 1){
        return 1;
	}else if(stairs == 2){
		return 2;
	}else if(stairs == 3){
		return 4;
	}else if(a[stairs]){
		return a[stairs];
	}else{
		int val = Staircase(stairs-1,a)+Staircase(stairs-2,a)+Staircase(stairs-3,a);
        a[stairs] = val;
        return val;
	} 
}

//Best solution for StairCase

// int main()
//  {
// 	int x;
// 	int dp[100001];
// 	dp[0] = 0;
// 	dp[1] = 1;
// 	dp[2] = 2;
// 	for(int i=3;i<=100001;i++){
// 	    dp[i] = dp[i-1]+dp[i-2];
// 	    dp[i] = dp[i]%1000000007;
// 	}
// 	cin>>x;
// 	while(x--){
// 	    int n;
// 	    cin>>n;
// 	    cout<<dp[n]<<endl;
// 	}
// 	return 0;
// }



// 23. Max Sum non adjacents elements of array

void MaxNonAdjSum(int input[],int n){
	int incl = input[0];
	int excl = 0;
	for(int i=1;i<n;i++){
		int temp = incl;
		incl = max(incl,excl+input[i]);
		excl = temp;
	}
	cout<<"MaxNonAdjSum : "<<incl<<endl;
}

// 24. Longest Bitonic subseq.

void LBS(int input[],int n){
	int increasing[n];
	int decreasing[n];
	int ans[n];
	for(int i=0;i<n;i++){
		increasing[i] = 1;
        decreasing[i] = 1;
	}
	for(int j=1;j<n;j++){
		for(int i=0;i<j;i++){
			if(input[j]>input[i]){
				increasing[j] = max(increasing[j],increasing[i]+1);
			}
		}
	}
	for(int j = n-2;j>=0;j--){
		for(int i=n-1;i>j;i--){
			if(input[j]>input[i]){
				decreasing[j] = max(decreasing[j],decreasing[i]+1);
			}
		}
	}
	for(int i=0;i<n;i++){
        ans[i] = increasing[i]+decreasing[i] -1;
	}
	int lbs = INT_MIN;
	for(int i=0;i<n;i++){
        if(ans[i]>lbs){
        	lbs = ans[i];
        }
	}
    cout<<"LBS : "<<lbs<<endl;
    return;
}


// 25. total paths from top to bottom right in 2d matrix

void totalpaths(int input[][4],int rows,int cols){
	int m[rows][cols];
	for(int i=0;i<rows;i++){
		m[i][0] = 1;
	}
	for(int i=0;i<cols;i++){
		m[0][i] = 1;
	}

	for(int i=1;i<rows;i++){
		for(int j=1;j<cols;j++){
			m[i][j] = m[i][j-1]+m[i-1][j];
		}
	}
	cout<<"total paths : "<<m[rows-1][cols-1]<<endl;
	return;
}

// 26. count total BST with n nodes
// Total binary trees are : totalBST * n!;

void totalBST(int n){
	int T[n+1] = {0};
	T[0] = 1;
	T[1] = 1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			T[i] += T[j]*T[i-j-1];
		}
	}
	cout<<"Total BST : "<<T[n]<<endl;
	return;
}

// best catalan's no. ans;

// #include<iostream>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using namespace std;
// int main()
//  {
// 	int x;
// 	cpp_int dp[101];
// 	dp[0] = 1;
// 	dp[1] = 1;
// 	dp[2] = 2;
// 	for(int i=3;i<101;i++){
// 	    for(int j=0;j<i;j++){
// 	        dp[i] += (dp[j]*dp[i-j-1]);
	        
// 	    }
// 	}
// 	cin>>x;
// 	for(int k=0;k<x;k++){
// 	   int n;
// 	   cin>>n;
// 	   cout<<dp[n]<<endl;
// 	}
// 	return 0;
// }

// 27. WildCard Matching 

void WildCard(char s1[],char s2[],int n1,int n2){
	bool m[n1+1][n2+1];
	for(int i=0;i<=n1;i++){
		for(int j=0;j<=n2;j++){
			m[i][j] = false;
		}
	}
	m[0][0] = true;

	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			if(s1[i-1] == s2[j-1] || s2[j-1] =='?'){
				m[i][j] = m[i-1][j-1];
			}else if(s2[j-1] == '*'){
				m[i][j] = ((m[i][j-1] == true)? true : m[i-1][j]);
			}
		}
	}
	cout<<"WildCard Matching is : "<<m[n1][n2]<<endl;
	return;
}

// 28. Max Sum Increasing Subs

void IncSubs(int a[],int n){
    int sum[n];
    for(int i=0;i<n;i++){
        sum[i] = a[i];
    }
    for(int j=1;j<n;j++){
        for(int i=0;i<j;i++){
            if(a[i]<a[j]){
                sum[j] = max(sum[j],sum[i]+a[j]);
            }
        }
    }
    int maxsum = 0;
    for(int i=0;i<n;i++){
        if(sum[i]>maxsum){
            maxsum = sum[i];
        }
    }
    cout<<maxsum<<endl;
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

   int StartTime[] = {4,2,6,7,1,5};
   int EndTime[] = {6,5,7,9,3,8};
   int Profit[] = {5,6,4,2,5,11};
   JobSche(StartTime,EndTime,Profit,6);

   EggDrop(2,6);

   char s5[] = {'a','b','c','d','a','f'};
   char s6[] = {'z','b','c','d','f'};
   LCSubStr(s5,s6,6,5);


   int input[][5] = {{ 2,  1, -3, -4,  5},
                    { 0,  6,  3,  4,  1},
                    { 2, -2, -1,  4, -5},
                    {-3,  3,  1,  0,  3}};
   MaxSumSubRect(input,4,5);


   int input1[][4] = {{1,1,1,0},
                      {1,1,1,1},
                      {0,1,1,0},
                      {0,1,1,1},
                      {1,0,0,1},
                      {1,1,1,1}};
   MaxRectSize(input1,6,4);


   set<string> dictionary;
   dictionary.insert("I");
   dictionary.insert("am");
   dictionary.insert("ace");
   WordBreak("Iamace",6,dictionary);

   int cost[][3] = {{1,2,3},{4,8,2},{1,5,3},{6,2,9}};
   MinimumCostPath(cost,4,3);

   int j[] = {2,3,1,1,2,4,2,0,1,1}; 
   MinJumps(j,10);

   int input2[][5] = {{0,0,1,1,1},
                      {1,0,1,1,1},
                      {0,1,1,1,1},
                      {1,0,1,1,1}};
   MaxSubSqMat(input2,4,5);

   int l[] = {3,9,1,2};
   OptimalStrategy(l,4);

   int stairs[7] = {0};
   cout<<"total ways of upstaris : "<<Staircase(6,stairs)<<endl;

   int input3[] = {4,1,1,4,2,1};
   MaxNonAdjSum(input3,6);

   int input4[] = {2,-1,4,3,5,-1,3,2};
   LBS(input4,8);


   int input5[][4] = {{0,0,1,1},
                      {1,0,1,1},
                      {0,1,1,1},
                      {1,0,1,1}};
   
   totalpaths(input5,4,4);

   totalBST(5);

   char s7[] = {'x','a','y','l','m','z'};
   char s8[] = {'x','?','y','*','z'};
   WildCard(s7,s8,6,5);
   return 0;
}