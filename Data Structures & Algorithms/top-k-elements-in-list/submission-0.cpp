class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map <int,int> mp;
        vector<int>result;

        for(int i : nums)
        {
            mp[i]++;
        }
        
        vector<pair<int,int>> vecfreq(mp.begin(),mp.end());

        sort(vecfreq.begin(),vecfreq.end(),[](const pair<int,int> &a, const pair<int,int> &b) {
            return a.second > b.second;
        } );

        for(int i=0;i<k;i++)
        {
            result.push_back(vecfreq[i].first);
        }
        return result;
    }
};
