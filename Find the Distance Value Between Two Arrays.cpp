
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        for(auto&num : arr1){
            // Binary search to find the closest element
            auto it = lower_bound(arr2.begin(), arr2.end(), num);
            bool valid = true;
            // Check the closest higher or equal element
            if(it != arr2.end() && abs(*it - num) <= d){
                valid = false;
            }
            // Check the closest lower element
            if (it != arr2.begin() && std::abs(*(it - 1) - num) <= d) {
                valid = false;
            }
            if(valid==true){
                count++;
            }
        }

        return count;
    }
};
