class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int maxmul = 0;
        int left = 0, n = heights.size();
        int right = n-1;
        while(left<right)
        {
            int min_hight = min(heights[left], heights[right]);
            maxmul = max(maxmul,min_hight*(right - left));
            if(heights[left] >= heights[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return maxmul;
    }
};
