class Solution {
public:
    void rec(int index, vector<int> current,vector<vector<int>> & result,vector<int>& candidates,int target)
    {
        if(target == 0 )
        {
            result.push_back(current);
            return;
        }
        
        for(int i = index;i<candidates.size();i++)
        {
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(target-candidates[i]<0)
            {
                break;
            }
            
            current.push_back(candidates[i]);
            rec(i+1,current,result,candidates,target-candidates[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        vector<vector<int>> result;
        rec(0,current,result,candidates,target);
        return result;
    }
};