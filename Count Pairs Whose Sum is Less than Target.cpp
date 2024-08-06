class Solution {
public:
// time comp =o(nlogn) space comp = o(n)
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++){
            int left = i + 1;
            int right = n;
            int ans = i;
            while(left < right){
                int mid = left + (right - left) / 2;
                if(nums[i] + nums[mid] < target){
                    ans = mid; 
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            count+=(ans - i); 
        }
        return count;
    }
};
