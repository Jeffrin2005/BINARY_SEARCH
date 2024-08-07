class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        // Find the first occurrence of the target using binary search
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // If the target is not present in the array, return an empty list
        if(left == nums.size() || nums[left] != target){
            return {};
        }
        // Find the last occurrence of the target using binary search
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        //  taking indices
        vector<int>result;
        for(int i = left; i < right;i++){
            result.push_back(i);
        }
        return result;
    }
};
