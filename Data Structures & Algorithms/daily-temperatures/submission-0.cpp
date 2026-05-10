class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        int n = temperatures.size();
        if(n==0) return result;
        // stack<int> st;

        // for(int i=n-1;i>=0;i--)
        // {
        //     st.push(temperatures[i]);
        // }

        // return result;

        for(int i=0;i<n;i++)
        {
            int r = 0;
            for(int j=i+1;j<n;j++)
            {
                if(temperatures[i] < temperatures[j])
                {
                    r = j;
                    break;
                }
            }
            if(r-i > 0)result.push_back(r-i);
            else result.push_back(r);
        }

        return result;
    }
};
