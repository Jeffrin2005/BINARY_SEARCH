
class Solution {
public:
    bool binarySearch(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

    int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
        for(auto&num : nums1) {
            if(binarySearch(nums2, num)) {
                return num; 
            }
        }
        return -1;
    }
};
