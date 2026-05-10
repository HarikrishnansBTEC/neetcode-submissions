class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,bool> hash;
        int result = -1;
        for(int i : nums)
        {
            if(hash[i])
            {
                result =  i;
            }
            hash[i] = true;
        }
        return result;
    }
};
