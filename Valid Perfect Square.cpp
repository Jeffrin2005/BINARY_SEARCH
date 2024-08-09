class Solution {
public:
    bool isPerfectSquare(int num) {
      if (num < 2) return true;

        long long left = 2, right = num / 2, mid, guess;
        while (left <= right) {
            mid = left + (right - left) / 2;
            guess = mid * mid;
            if (guess == num) {
                return true;
            } else if (guess < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
