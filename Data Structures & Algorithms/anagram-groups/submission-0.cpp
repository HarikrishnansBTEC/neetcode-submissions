class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> hash;

        vector<vector<string>> result;
        for(string str : strs)
        {
            string s = str;
            sort(s.begin(),s.end());
            hash[s].push_back(str);
        }

        for(auto &it : hash)
        {
            result.push_back(it.second);
        }
        return result;
    
    }
};
