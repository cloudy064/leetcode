class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;

        std::vector<int> digits;
        while (x != 0) {
            digits.push_back(x % 10);
            x /= 10;
        }

        size_t len = digits.size();
        for (size_t i = 0; i < len / 2; i++) {
            if (digits[i] != digits[len - i - 1]) return false;
        }

        return true;
    }
};