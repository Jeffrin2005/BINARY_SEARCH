#include <bits/stdc++.h>
#define ll long long 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub; // This will hold the smallest tail of all increasing subsequences
        for(auto&x : nums){
            auto it = lower_bound(sub.begin(), sub.end(), x); // Find the first element >= x
            if(it == sub.end()){
                sub.push_back(x); // x extends largest subsequence
            }else{
                *it = x; // Update the element to keep subsequence minimal
            }
        }
        return sub.size(); // The size of sub is the length of the longest increasing subsequence
    }
};
