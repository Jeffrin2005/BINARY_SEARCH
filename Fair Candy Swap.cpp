#include <vector>
#include <algorithm>

class Solution {
private:
 bool binarySearch(const vector<int>& data, int target) {
        int low = 0, high = data.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (data[mid] == target) {
                return true;
            } else if (data[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice = 0, sumBob = 0;
        for (int candy : aliceSizes) sumAlice += candy;
        for (int candy : bobSizes) sumBob += candy;        
        int delta = (sumBob - sumAlice) / 2; // This is the amount Bob needs to lose or Alice needs to gain
        // Sort Bob's sizes to use binary search
        sort(bobSizes.begin(), bobSizes.end());
        // Now we try to find a pair such that Alice's candy + delta = Bob's candy
        for (int candyAlice : aliceSizes){
            int targetBob = candyAlice + delta;
            if(binarySearch(bobSizes, targetBob)){
                return {candyAlice, targetBob};
            }
        }
        return {}; 
    }
};
