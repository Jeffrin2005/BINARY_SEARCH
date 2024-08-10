class Solution {
private:
    //  check if we can form `k` groups
    bool check(int k, int n) {
        // Using the formula for the sum of the first k natural numbers
        // to determine if we have enough students to form k groups
          long long neededStudents = (k) * (k + 1) / 2;
        return neededStudents <= n;
    }
public:
    int maximumGroups(std::vector<int>& grades) {
        int n = grades.size();
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if(check(mid, n)){
                left = mid + 1; // If possible to form mid groups, try for more
            }else{
                right = mid - 1; // If not possible, reduce the number of groups
            }
        }
        return right;
    }
};
