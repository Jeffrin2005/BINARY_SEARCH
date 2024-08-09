class Solution {
public:
    bool check(long mid, long n) {
        long current = mid * (mid + 1) / 2;
        return current <= n;
    }
    int arrangeCoins(int n) {
        long left = 0, right = n;
        while (left <= right){
            long mid = left + (right - left) / 2;
            if (check(mid, n)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};
