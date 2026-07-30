class Solution {
public:
    vector<int> current;
    vector<vector<int>> result;
    void rec(vector<int>& nums,int l)
    {
        if(nums.size()==l)
        {
            result.push_back(nums);
            return ;
        }

        for(int i=l;i<nums.size();i++)
        {
            swap(nums[i],nums[l]);
            rec(nums,l+1);
            swap(nums[i],nums[l]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        rec(nums,0);
        return result;
    }
};
