class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.size(), b.size()) + 1;
        int sum, carry;

        a.insert(a.begin(), n - a.size(), '0');
        b.insert(b.begin(), n - b.size(), '0');
        sum = carry = 0;

        for (int i = n - 1; i >= 0; i--) {
            sum = a[i] - '0' + b[i] - '0' + carry;
            a[i] = (char) (sum % 2) + '0';
            carry = sum / 2;
        }

        if (a[0] == '0' && n > 1) a.erase(0, 1);
        return a;
    }
};
