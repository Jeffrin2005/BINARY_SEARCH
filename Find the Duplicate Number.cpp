class Solution {
private:
    int check(vector<int>& nums, int value) {
        int count = 0;
        // value = mid ; 
        for (auto&num : nums){
            if(num <= value){
                count++;
            }
        }
        return count;
        // return count;
    }
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (check(nums, mid) > mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
