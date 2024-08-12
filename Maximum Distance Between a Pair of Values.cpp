#include <vector>
#include <algorithm>

class Solution {
public:
    bool check(int i, int j, const vector<int>& nums1, const vector<int>& nums2) {
        return nums1[i] <= nums2[j];
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            int low = i, high = nums2.size() - 1;
            while (low <= high){
                int mid = low + (high - low) / 2;
                if (check(i, mid, nums1, nums2)) {
                    maxDist = max(maxDist, mid - i);
                    low = mid + 1; // Move right to find the farthest valid `j`
                } else {
                    high = mid - 1;
                }
            }
        }
        return maxDist;
    }
};
