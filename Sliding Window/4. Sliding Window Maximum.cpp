/*
https://leetcode.com/problems/sliding-window-maximum/

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

*/

-------------------------------------------------------------------------
  
  
  Gist of the logic:-


1.	We have to create such a data structure which is open from both the sides, so that we can push and pop elements from any corner, and list is one such data structure. The first element of the list will contain maximum value of current window, the subsequent elements in the list are the candidate or possible maximum values for subsequent or future windows.
2.	For jth value calculation- if the list is empty at first, then whatever comes first in the array will be pushed as maximum value in the list. In the list we need to store only those values which can become candidate maximum values for next sliding windows. So comparing jth value with the back of the list, if it comes out to be greater than the back of the list, then the back of the list becomes unused, as it can never become a maximum value for future windows, so all these values which are less than the jth value needs to be deleted. If the jth value is less than the back of the list, it might not serve as the maximum value for the current window, but it can serve as the maximum value for future windows, so we need to preserve this, pushing them into the list for future use.
3.	For retrieving the answer- the max value for the current window is always available at the front of the list, because all the values which are less than this value are deleted from the list, so the maximum value always occupies the first place in the list.
4.	For sliding the window-   before moving i and j iterators, we need to check whether the ith value belongs to the list or not. And it happens to belong to the list only if it has served as the maximum value for current window. If it hasn’t served as the max value, then there’s no chance that it can be found in the list. So deleting the front element of the list if it equals to ith value. Then i++ and j++.

  
  -------------------------------------------------------------------------------
  
  
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();
        int i = 0, j = 0;
        while(j<n){
            //condition
            while(dq.size()>0 && dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                //answer
                ans.push_back(dq.front());
                //sliding window
                if(nums[i] == dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
