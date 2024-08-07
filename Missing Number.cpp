
// The use of binary search in this problem is based on the principle that if the numbers are sorted and none are missing, 
// each number should match its index
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); 
        int left = 0;
        int  right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid){
                right = mid; // The missing number is in the left half
            } else {
                left = mid + 1; // The missing number is in the right half
            }
        }
        
        return left; 
    }
};
// For nums = [3, 0, 1]:
// After sorting: [0, 1, 3]
// The binary search finds that at index 2, the value 3 is present instead of 2. 
//  because 3 is greater than 2 (the index), indicating the missing number is 2.
