class Solution {
    private:
    bool check(vector<int>&position, int m, int minDist) {
        int count = 1; // Place the first ball
        int lastPosition = position[0]; // Start with the first position
        for (int i = 1; i < position.size();i++){
//For each position, it checks if the distance from the lastPosition (where the last ball was placed) to the current position is at least minDist.
            if (position[i] - lastPosition >= minDist){
                // Place next ball
                lastPosition = position[i];
                count++;
                if(count == m) return true; // If all balls are placed
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1; // Minimum possible distance
        int high = 1e9; // Maximum possible distance
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(position, m, mid)){
                low = mid + 1; // Try for a larger distance
            }else{
                high = mid - 1; // Try for a smaller distance
            }
        }
        return high; 
    }
    
};
