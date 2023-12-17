#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(board.size(), vector<bool>(9, false));
        vector<vector<bool>> cols(board.size(), vector<bool>(9, false));
        vector<vector<bool>> boxs(board.size(), vector<bool>(9, false));

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] != '.'){
                    //数字
                    int num = (board[i][j] - '0') - 1;
                    if(rows[i][num] == true || cols[j][num] == true || boxs[(i / 3) * 3 + (j / 3)][num] == true){
                        return false;
                    }else{
                        rows[i][num] = true;
                        cols[j][num] = true;
                        boxs[(i / 3) * 3 + (j / 3)][num] = true;
                    }
                }else{
                    //空.
                }
            }
        }

        return true;
    }
};

// [".",".",".",".","5",".",".","1","."],
// [".","4",".","3",".",".",".",".","."],
// [".",".",".",".",".","3",".",".","1"],
// ["8",".",".",".",".",".",".","2","."],
// [".",".","2",".","7",".",".",".","."],
// [".","1","5",".",".",".",".",".","."],
// [".",".",".",".",".","2",".",".","."],
// [".","2",".","9",".",".",".",".","."],
// [".",".","4",".",".",".",".",".","."]