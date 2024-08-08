class Solution {
// time comp = O(nlogn + mlogn + kn)
// space comp = o(m + logn) 
    bool check(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                // Remove the element to handle duplicates correctly
                nums.erase(nums.begin() + mid);
                return true;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(), nums2.end());
        vector<int> intersection;
        // Iterate over the first array and use binary search on the second array
        for(auto&num : nums1){
            if(check(nums2, num)){
                intersection.push_back(num);
            }
        }
        return intersection;
    }
};
