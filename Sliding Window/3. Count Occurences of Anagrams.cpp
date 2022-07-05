/*
https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
Your Task:
Complete the function search() which takes two strings pat, txt, as input parameters and returns an integer denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 105
Both string contains lowercase english letters.

*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    vector<int> ans(26,0);
	    vector<int> arr(26,0);
	    for(int i=0;i<pat.length();i++){
	        ans[pat[i]-'a']++;
	    }
	    int i=0;
	    int j=0;
	    int count=0;
	    while(j<txt.length()){
	        arr[txt[j]-'a']++;
	        if(j-i+1<pat.length()){
	            j++;
	        }
	        else if(j-i+1==pat.length()){
	            if(ans==arr) count++;
	            arr[txt[i]-'a']--;
	            i++;
	            j++;
	        }
	}
	return count;
}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
