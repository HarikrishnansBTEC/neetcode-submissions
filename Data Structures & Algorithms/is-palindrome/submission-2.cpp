class Solution {
public:
    bool isPalindrome(string s) {
        string str;

        for (unsigned char c : s) {
            if (isalnum(c)) {
                str += tolower(c);
            }
        }

        string temp = str;
        reverse(str.begin(), str.end());
        return str == temp;
    }
};
