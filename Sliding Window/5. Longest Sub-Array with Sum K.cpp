/*
https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1#

Following code is valid only when array contains all positive numbers only

*/


// { 	Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
	int lenOfLongSubarr(int arr[], int n, int k)
	{
		int i = 0, j = 0, mx = 0;
		long sum = 0;
		while (j < n)
		{
			sum += arr[j];
			if (sum < k)
			{
				j++;
			}
			else if (sum == k)
			{
				mx = max(j - i + 1, mx);
				j++;
			}
			else if (sum > k)
			{
				while (sum > k)
				{
					sum -= arr[i];
					i++;
				}
				if (sum == k)
				{
					mx = max(j-i+1, mx);
				}
				j++;
			}
		}

		return mx;
	}
};

// { 	Driver Code Starts.

int main()
{
	//code

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];
		Solution ob;
		cout << ob.lenOfLongSubarr(a, n, k) << endl;

	}

	return 0;
}	// } Driver Code Ends
