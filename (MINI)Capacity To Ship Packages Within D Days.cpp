class Solution {
    private:
    bool check(vector<int>& weights, int days, int capacity){
        int currentWeight = 0;
        int dayCount = 1; // Start counting from the first day
        for(auto&weight : weights){
            if(currentWeight + weight > capacity){
                dayCount++; // Need an additional day
                currentWeight = 0; // Reset the current day's weight
            }
            currentWeight+=weight;
            if(dayCount > days){ // If the days exceed the limit, return false
                return false;
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());; // Minimum capacity must be at least the heaviest package
        int right = accumulate(weights.begin(), weights.end(), 0); // Maximum capacity is the sum of all weights
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(weights, days, mid)){
                right = mid - 1; // Try a smaller capacity if possible
            }else{
                left = mid + 1; // Increase capacity
            }
        }

        return left;
    }
};
