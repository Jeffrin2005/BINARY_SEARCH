class Solution {
public:
    bool path(vector<int>& stones, int k) {
        int curr = 0;
        set<int> st;
        vector<int> remain;
        // Making a path with max length k.
        while (curr + k < stones.back()) {
            auto it = upper_bound(stones.begin(), stones.end(), curr + k);
            it--;
            if (*it == curr) return false; 
            curr = *it;
            st.insert(curr);
        }
        // adding the remainng stones which is not included in the st
        for (int i = 0; i < stones.size(); i++){
            if (st.count(stones[i]) == 0) remain.push_back(stones[i]);
        }
        // Checking if a path from the remaining stones exists
        for (int i = 1; i < remain.size(); i++){
            if(remain[i] - remain[i - 1] > k) return false;
        }
        return true;
    }

    int maxJump(vector<int>& stones) {
        int left = 0, right = stones.back();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (path(stones, mid)) {
                right = mid - 1; // Found a valid path, try a smaller maximum jump
            } else {
                left = mid + 1; // No valid path, need a larger maximum jump
            }
        }
        return left; 
    }
};
