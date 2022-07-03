/* print all subsequences of an array

We can do this using iterative approach i.e. using Power Set and recursively as well
We used approach of picking up or not picking up the element in the array

*/

#include<iostream>
#include<vector>
using namespace std;

void printSubsequence(int idx, vector<int> &ds, int arr[], int n){
	if(idx == n){
		for(auto it: ds){
			cout<<it<<" ";
		}
		if(ds.size() == 0){
			cout<<"{}";
		}
		cout<<endl;
		
		return;
	}
	
	//take or pick, this element is added to your subsequence
	ds.push_back(arr[idx]);
	printSubsequence(idx+1, ds, arr, n);
	ds.pop_back();
	
	//not take condition, this element is not added to your subsequence
	
	printSubsequence(idx+1, ds, arr, n);
}

int main(){
	
	int arr[] = {3,1,2};
	vector<int> ds;
	printSubsequence(0, ds, arr, 3);
	
	return 0;
}



// TC: O(2^n * n)
// SC: O(n)
