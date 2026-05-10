class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }

        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find the delimiter '#'
            while (s[j] != '#') {
                j++;
            }

            // Length of the next string
            int len = stoi(s.substr(i, j - i));
            j++; // move past '#'

            // Extract the string of length 'len'
            result.push_back(s.substr(j, len));
            // Move index to the next encoded part
            i = j + len;
        }

        return result;
    }
};