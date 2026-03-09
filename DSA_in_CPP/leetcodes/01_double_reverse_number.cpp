class Solution {
public:
    int reverse(int num) {
        int ans{}, mod{};
        while (num != 0) {
            mod = num % 10;
            ans = (ans * 10) + mod;
            num /= 10;
        }
        return ans;
    }

    bool isSameAfterReversals(int num) {
        if (num == 0)
            return true;

        int reversed1 = reverse(num);
        int reversed2 = reverse(reversed1);

        if (reversed2 == num)
            return true;
        else
            return false;
    }
};