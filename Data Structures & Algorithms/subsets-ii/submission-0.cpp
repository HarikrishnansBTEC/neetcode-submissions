class Solution {
public:
    void rec(int index, vector<int> &nums, vector<int> &current, vector<vector<int>> &result)
    {
        // Every state is a valid subset
        result.push_back(current);

        for(int i = index; i < nums.size(); i++)
        {
            // Skip duplicates
            if(i > index && nums[i] == nums[i - 1])
                continue;

            // Choose
            current.push_back(nums[i]);

            // Explore
            rec(i + 1, nums, current, result);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> current;

        rec(0, nums, current, result);

        return result;
    }
};