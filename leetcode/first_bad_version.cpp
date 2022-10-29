// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int aux(int left, int right) {
        int mid = ((long) left + right) / 2;
        if (isBadVersion(mid) && (mid == 1 || !isBadVersion(mid - 1)))
            return mid;
        else if (!isBadVersion(mid))
            return aux(mid + 1, right);
        else
            return aux(left, mid - 1);
    }

    int firstBadVersion(int n) {
       return aux(1, n);
    }
};
