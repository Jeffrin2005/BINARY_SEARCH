class Solution {
public:
    bool canDistribute( vector<int>& quantities, int maxProducts, int n){
        int neededStores = 0;
        for(auto&quantity : quantities){
            neededStores+=(quantity + maxProducts - 1) / maxProducts; // Ceiling of quantity/maxProducts
            if(neededStores > n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = 1e9;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(quantities, mid, n)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
