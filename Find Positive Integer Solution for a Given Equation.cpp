class Solution {
   private:
    int check(CustomFunction& customfunction, int x, int z){
        int low = 1 ,high = 1000;
        while (low <= high){
            int mid = low + (high - low) / 2;
            int val = customfunction.f(x, mid);
            if(val == z){
                return mid;
            } else if (val < z) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1; // Return -1 if no valid y is found
    }
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
          vector<vector<int>> result;
        for (int x = 1; x <= 1000; ++x) {
            int y = check(customfunction, x, z);
            if (y != -1) {
                result.push_back({x, y});
            }
        }
        return result;
    }
};
