class Solution {
private:
    int canMoveChips(vector<int>& position, int target) {
        int cost = 0;
        for (int pos : position) {
            int dist = abs(pos - target);
            cost += dist % 2; // Cost is 1 for each odd distance (even distance cost = 0 , odd distance cost = 1 )
        }
        return cost;
    }
public:
    int minCostToMoveChips(vector<int>& position) {
        int minPos = 0;
        int maxPos = 1e9;
        int low = minPos, high = maxPos;
        while (low <= high) { 
            int mid = low + (high - low) / 2;
            if (canMoveChips(position, mid) <= canMoveChips(position, mid + 1)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Return the minimum cost from either side of the final search space
        int leftCost = canMoveChips(position, high);
        int rightCost = canMoveChips(position, low);
        return min(leftCost, rightCost); // Return the minimum of costs from both sides
    }
};
