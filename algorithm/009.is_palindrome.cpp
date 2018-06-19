class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;

        int digits[10];
        int len = 0;
        while (x != 0) {
            digits[len++] = x % 10;
            x /= 10;
        }

        for (size_t i = 0; i < len / 2; i++) {
            if (digits[i] != digits[len - i - 1]) return false;
        }

        return true;
    }
};