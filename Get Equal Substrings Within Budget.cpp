class Solution {
private:
    bool check(vector<int>& costs, int length, int maxCost){
       int currentCost = 0;
    int n = costs.size(); 
    // Calculate the cost of transforming the first 'length' characters of s to t
    for (int i = 0; i < length; i++){
        currentCost+=costs[i];
    }

    // Check if the cost of the first substring is within the allowed maxCost
    if(currentCost <= maxCost) return true;

    // Use a sliding window to calculate the cost for all other substrings of the same length
    for(int i = length; i < n;i++){
        // Update the currentCost to include the next character and exclude the first character of the previous window
        currentCost+=costs[i];
        currentCost-=costs[i - length];
        if (currentCost <= maxCost) return true;
    }
    return false;
    }
public:
    int equalSubstring(string s, string t, int maxCost){
        int n = s.size();
        vector<int>costs(n, 0);
        for (int i = 0; i < n; i++){
            costs[i] = abs(s[i] - t[i]);
        }
        //  search for the maximum length
        int low = 0;
        int high = n;
        while(low <= high){
            int mid = (low + high) / 2;
            if(check(costs, mid, maxCost)){
                low = mid + 1; // Move right if the current length is feasible
            }else{
                high = mid - 1; // Move left if the current length is not feasible
            }
        }
        return high;
    }
};
