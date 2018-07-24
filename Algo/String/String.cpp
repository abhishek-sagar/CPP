#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void PfxAlsoSfx(string s,int a[]){
	int n = s.length();
	int i=0,j=1;
    a[0] = 0;
    while(j<n){
    	while(s[i]!=s[j] && i!=0){
    		i--;
    		i = a[i];
    	}
    	if(s[i]!=s[j]){
    		a[j] = 0;
    		j++;
    	}else{
    	   a[j] = i+1;
    	   i++;
    	   j++;
        }
    }
    // for(int i=0;i<n;i++){
    // 	cout<<a[i]<<",";
    // }
    // cout<<endl;
    return;
}

void KMP(string s1,string s2){
	int l1 = s1.length();
	int l2 = s2.length();
	if(l2>l1){
		return;
	}
	int a[l2];
	PfxAlsoSfx(s2,a);
    int i=0,j=0;
    while(i<l1 && j<l2){
    	while(s1[i] != s2[j] && j!=0){
    		j--;
    		j = a[j];
    	}
    	if(s1[i] != s2[j]){
    		i++;
    	}else{
    		i++;
    		j++;
    	}
    }
    if(j == l2){
    	cout<<"Yes string is present."<<endl;
    }else cout<<"No"<<endl;
    return;
}

long long int Recalculate(string s,long long int hash,int last,int next,int l2){
	int prime = 53;
	hash = hash-((int)(s[last]));
    hash = hash/prime;
    hash += ((int)(s[next]))*pow(prime,l2-1);
 //   hash %= 1000000007;
    return hash;
}

long long int Hash(string s,int st,int e){
    int prime = 53;
    long long int val = 0;
    for(int i=st,k=0;i<=e;i++,k++){
    	val += ((int)(s[i]))*pow(prime,k);
    	// val %= 1000000007;
    }
    return val;
}

void RobinKarp(string s1,string s2){
	int l1 = s1.length();
	int l2 = s2.length();
	if(l1<l2){
		return;
	}
	int i=0,j=l2-1;
	long long int hash_s2 = Hash(s2,i,j);
	long long int hash_s1 = Hash(s1,i,j);
    // cout<<"hash_s1 : "<<hash_s1<<endl;
    // cout<<"hash_s2 : "<<hash_s2<<endl;
    while(j<l1){
    	if(hash_s1 != hash_s2){
    		if(j+1<l1){
                hash_s1 = Recalculate(s1,hash_s1,i,j+1,l2);
                //cout<<"hash_s1 : "<<hash_s1<<endl;
                i++;
                j++;
            }else{
            	cout<<"No"<<endl;
            	return;
            }
    	}else{
    		int k=0;
    		while(k<l2){
    			if(s1[i+k] == s2[k]){
    				k++;
    			}else{
    				break;
    			}
    		}
    		if(k == l2){
    			cout<<"yes"<<endl;
    			return;
    		}else{
    			i++;
    			j++;
    		}
    	}
    }
}



int main(){
    string s1 = "KEEKFORGEEKSlsfnvwldknfsldkdnvwbfldfnvdnfvfvhovnslvnsjbvlsdmvlsvlksnvljn";
    string s2 = "kdnvwbfldfnvdnfvfvhovnslvnsjbvlsdmvlsvlksnv";
    //PfxAlsoSfx(s);
    KMP(s1,s2);
    //RobinKarp(s1,s2);
    return 0;
}