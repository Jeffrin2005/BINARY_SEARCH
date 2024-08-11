class Solution
{
private:
   bool bouquets(vector<int> &bloomDay, int m, int k, int mid){
        int n = bloomDay.size();
        int flower = 0;
        int bouquet = 0;
        for (int i = 0; i < n; i++){
            if(bloomDay[i] <= mid)   flower++;
            else flower = 0;
            if(flower >= k){
                bouquet++;
                flower = 0;
            }
        }
        return bouquet >= m;
    }
public:
    int minDays(vector<int> &bloomDay, int m, int k){
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (bouquets(bloomDay, m, k, mid)){
                right = mid - 1;
            }else{
                left = mid + 1;
        }
        }
        if(bouquets(bloomDay, m, k, left))return left;
        else return -1;
    }
};
