class Solution {
    private:
    bool check(const vector<int>& arr, int target, int skipIndex) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target && mid != skipIndex) {
                return true;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++){
            if(check(arr, 2 * arr[i], i)){
                return true;
            }
        }
        return false;
    }
};
