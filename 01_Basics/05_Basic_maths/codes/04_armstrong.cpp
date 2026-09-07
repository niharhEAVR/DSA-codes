class Solution {
public:
    int power(int base, int exp) {
        int ans = 1;
        while (exp--) {
            ans *= base;
        }
        return ans;
    }

    bool isArmstrong(int n) {
        if (n < 0) return false;

        if (n == 0) return true;

        int original = n;
        int temp = n;
        int digits = 0;

        // Count digits
        while (temp > 0) {
            digits++;
            temp /= 10;
        }

        temp = n;
        long long sum = 0;

        // Calculate Armstrong sum
        while (temp > 0) {
            int digit = temp % 10;
            sum += power(digit, digits);
            temp /= 10;
        }

        return sum == original;
    }
};