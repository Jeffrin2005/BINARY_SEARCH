class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]){
                // If the middle element is less than the next one, the peak must be to the right
                left = mid + 1;
            } else {
                // Otherwise, the peak is to the left or at mid
                right = mid - 1;
            }
        }
        return left; 
    }
};
