class Solution {
public:
    bool rec(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // Base Case: matched full word
        if (index == word.size()) return true;
        
        // Boundary and character check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        // Mark cell as visited
        char temp = board[i][j];
        board[i][j] = '#';
        
        // Explore 4 directions
        bool found = rec(board, word, i + 1, j, index + 1) ||
                     rec(board, word, i - 1, j, index + 1) ||
                     rec(board, word, i, j + 1, index + 1) ||
                     rec(board, word, i, j - 1, index + 1);
        
        // Restore cell (Backtrack)
        board[i][j] = temp;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (rec(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};