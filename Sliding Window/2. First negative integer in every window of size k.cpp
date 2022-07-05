/*
https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function printFirstNegativeInteger() which takes the array A[], its size N and an integer K as inputs and returns the first negative number in every window of size K starting from the first till the end. If a window does not contain a negative integer , then return 0 for that window.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N <= 105
-105 <= A[i] <= 105
1 <= K <= N

*/

----------------------------------------------------------------------------------------
  
  Gist of the logic used:-

1. We're creating a list to store all the negative elements of a current window. At a particular point of time, the list holds negative numbers which are there in the current running window and not all the negative elements in the array. So, that we can retrieve first negative number from the current window.
2. When we reached the window size, we need to perform two operations:-
-> First, we have to retrieve the answer that is the first negative number from the current window. We're checking if the list is empty or not. If it is empty, then there is no negative number in the current window. In that case we'll push 0 in the vector.
If it's not empty, then the first element in the list is the first negative number of the current window., pushing that into the vector.
-> Second, we need to slide the window. For that we need to remove the first element of the current window, and add the next element from the array to the window. But before removing the first element, we need to check whether it belongs to the list or not. If it belongs to the list, we need to remove it from the list, as it will not be a part of our next window. So, if the first element is found to be a negative number, then we have to remove it from the list, and this number is happened to be the front element of the list. Then, incrementing the values of i and j to slide the window.
  
  
  ------------------------------------------------------------------------------------------
  
  
  
  // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector < long long > printFirstNegativeInteger(long long int arr[],
	long long int n, long long int k)
{
	vector < long long > ans;
	deque < long long > dq;
	int i = 0, j = 0;
	while (j < n)
	{
		if (arr[j] < 0)
		{
			dq.push_back(arr[j]);
		}
		if (j - i + 1 < k)
		{
			j++;
		}
		else if (j - i + 1 == k)
		{
			if (dq.size() == 0)
			{
				ans.push_back(0);
			}
			else
			{
				ans.push_back(dq.front());
			}
			if (arr[i] < 0)
			{
				dq.pop_front();
			}
			i++;
			j++;
		}
	}
	return ans;
}

int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



