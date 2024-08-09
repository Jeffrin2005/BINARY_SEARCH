// bool isBadVersion(int version); // API provided

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left < right) {
            int mid = left + (right - left) / 2; // Prevent potential overflow
            if (isBadVersion(mid)) {
                right = mid; // Narrow down the right boundary if mid is bad
            } else {
                left = mid + 1; // Narrow down the left boundary if mid is good
            }
        }
        return left; // left will be the first bad version
    }
};
