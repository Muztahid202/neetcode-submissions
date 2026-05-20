class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int rows = board.size();
        int cols = board[0].size();

        //O(n^2)
        //check if the rows contain duplicate
        for(int i = 0; i < rows; i++)
        {
            unordered_set<char> seen; //O(9* 9)
            for(int j = 0; j < cols; j++)
            {
                if(board[i][j] == '.') continue;
                if(seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }

        //O(n^2)
        //check if the cols contain duplicate
        for(int j = 0; j < cols; j++)
        {
            unordered_set<char> seen; //O(9* 9)
            for(int i = 0; i < rows; i++)
            {
                if(board[i][j] == '.') continue;
                if(seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }

        //O(9 * 3 * 3) = O(1)
       //check in the squares
       for(int square = 0; square < 9; square++)
       {
            unordered_set<char> seen; //O(9* 9)
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if(board[row][col] == '.') continue;
                    if(seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
       }

       return true;
        
    }
};

//TC = O(n^2)
//SC = O(n^2) as n = 9
