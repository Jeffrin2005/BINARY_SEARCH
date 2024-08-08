
// time comp = o(nlog) spce comp =o(1)
class Solution {
public:
    int check(vector<int>& nums, int val){
        int count = 0;
        for(auto&num : nums){
            if(num >= val){
                ++count;
            }
        }
        return count;
    }
    int specialArray(std::vector<int>& nums){
       sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size();
        while(low <= high){
            int mid = low + (high - low) / 2;
            int count = check(nums, mid);
            if(count == mid){
                return mid;
            }else if(count < mid){
                high = mid - 1; 
            }else{
                low = mid + 1; 
            }
        }
        
        return -1;
    }
};
