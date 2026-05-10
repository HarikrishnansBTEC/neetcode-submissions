class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size(); // Correctly get column count

    for(int i = 0; i < n; i++) {
        // Correct the range check logic
        if(target >= matrix[i][0] && target <= matrix[i][m-1]) {
            int left = 0, right = m - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2; // Update mid inside the loop
                if(matrix[i][mid] == target) {
                    return true;
                }
                else if(matrix[i][mid] < target) {
                    left = mid + 1; // Correct: move left up
                }
                else {
                    right = mid - 1; // Correct: move right down
                }
            }
        }
    }
    return false;
}
};
