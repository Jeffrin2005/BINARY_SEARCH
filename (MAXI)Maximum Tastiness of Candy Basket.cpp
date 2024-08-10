class Solution {
public:
    bool check(vector<int>& price, int k, int minDiff) {
        int count = 1; // Start with the first candy selected
        int last = 0; // Last selected candy index
        for (int i = 1; i < price.size();i++){
            if (price[i] - price[last] >= minDiff) {
                count++;
                last = i;
                if(count == k) return true;
            }
        }
        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int low = 0;
        int high = 1e9;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if(check(price, k, mid)){
                low = mid + 1; // This tastiness is achievable, try for a higher one
            }else{
                high = mid - 1; // This tastiness is too high, try a lower one
            }
        }
        return high;
    }
};
