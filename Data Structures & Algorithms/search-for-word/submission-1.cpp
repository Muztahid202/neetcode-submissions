class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool findWord(vector<vector<char>>& board, int i, int j, int idx, string& word){
        if(idx == word.size()) return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;

        if(board[i][j] == '#') return false;

        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(findWord(board, new_i, new_j, idx + 1, word)) {
                board[i][j] = temp; 
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && findWord(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
