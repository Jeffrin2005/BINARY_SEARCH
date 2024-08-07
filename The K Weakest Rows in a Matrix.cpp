class Solution {
    private:
    int countSoldiers(vector<int>&row) {
        int low = 0;
        int high = row.size();
        while(low < high){
            int mid = low + (high - low) / 2;
            if(row[mid] == 1){
                low = mid + 1;
            }else {
                high = mid;
            }
        }
        return low; // The number of 1's in the row
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>strength; // To store the strength and index of each row
        for(int i = 0; i < mat.size(); i++){
            int count = countSoldiers(mat[i]);
            strength.push_back({count, i});
        }
        // sort on the basis of strength 
        sort(strength.begin(), strength.end());
        vector<int>result;
        for(int i = 0; i < k; i++){
            result.push_back(strength[i].second);
        }

        return result;
    }

};
