class Solution {
private:
    int binarySearch( vector<int>& numbers, int left, int right, int target){
        while (left <= right){
            int mid = left + (right - left) / 2;
            if(numbers[mid] == target){
                return mid; 
            }else if (numbers[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1; 
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        for (int i = 0; i < numbers.size(); i++){
            int rem = target - numbers[i];
            int index = binarySearch(numbers, i + 1, numbers.size() - 1, rem);
            if (index != -1) {
                return {i + 1, index + 1}; // +1 for 1-indexed result
            }
        }
        return {}; 
    }
};
