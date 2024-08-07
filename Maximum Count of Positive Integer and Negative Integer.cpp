#include <bits/stdc++.h>
#define ll long long 
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // Use lower_bound to find the first non-negative number
        ll  firstNonNeg = lower_bound(nums.begin(), nums.end(), 0);
        // Use upper_bound to find the first positive number
        ll  firstPos = upper_bound(nums.begin(), nums.end(), 0);
        ll negCount = firstNonNeg - nums.begin(); // Number of negative numbers
        ll posCount = nums.end() - firstPos;      // Number of positive numbers

        return max(negCount, posCount);
    }
};
