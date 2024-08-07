class Solution {
    private:
    bool binarySearch(const vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) {
                return true;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return false;
    }
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      set<int> resultSet;
       sort(nums1.begin(), nums1.end()); // Sort nums1 to use binary search on it
        for(auto&num : nums2){
            if(binarySearch(nums1, num)){
                resultSet.insert(num);
            }
        }
       return vector<int>(resultSet.begin(), resultSet.end());
    }

};
