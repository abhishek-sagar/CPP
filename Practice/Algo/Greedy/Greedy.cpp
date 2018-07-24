#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool compare(pair<int,char> p1,pair<int,char> p2){
	return (p1.first < p2.first);
}

void TotalPlatforms(int arr[],int dep[],int n){
   vector<pair<int,char>> v;
   for(int i=0;i<n;i++){
   	 pair<int,char> p(arr[i],'a');
   	 v.push_back(p);
   }
   for(int i=0;i<n;i++){
   	pair<int,char> p(dep[i],'d');
   	v.push_back(p);
   }
   sort(v.begin(),v.end(),compare);
   int platforms = 0;
   int current = 0;
   for(int i=0;i<v.size();i++){
      pair<int,char> p = v.at(i);
      if(p.second == 'a'){
      	current++;
      }else{
      	if(platforms < current){
      		platforms = current;
      	}
      	current--;
      	if(current < 0){
      		current = 0;
      	}
      }
   }
   cout<<"total platforms required : "<<platforms<<endl;
   return;
}

int main(){
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    TotalPlatforms(arr,dep,6);
    return 0;
}