class Solution {
private:
    bool check(vector<int>& nums, int maxOperations, int maxPenalty){
        int operations = 0;
        for(auto&num : nums){
            if (num > maxPenalty){
                operations+=(num - 1) / maxPenalty; // Calculate the number of splits needed
            }
            if (operations > maxOperations) return false; // If operations exceed maxOperations, return false
        }
        return true;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int  right = *max_element(nums.begin(), nums.end());
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (check(nums, maxOperations, mid)) {
                right = mid - 1; // Try a smaller maximum if possible
            } else {
                left = mid + 1; // Increase the penalty size
            }
        }
        return left;
    }
};
