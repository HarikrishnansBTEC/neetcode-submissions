class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map <char,int> hash1,hash2;

        if(s.length()!= t.length()) return false;
        for(int i=0;i<s.length();i++)
        {
            hash1[s[i]]++;
            hash2[t[i]]++;
        }

        if(hash1 == hash2) return true;
        return false;


    }
};
