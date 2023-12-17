#include <vector>
#include <iostream>
using namespace std;

//超时
// class Solution {
// private:
//         bool backTrace(vector<vector<bool>>& rows, vector<vector<bool>>& cols, vector<vector<bool>>& boxs, vector<vector<char>>& board, int x, int y) {
//             if(x == board.size()){
//                 //成功
//                 return true;
//             }
//             if(board[x][y] == '.'){
//                 //for
//                 for(int i = 1; i <= 9; i++){
//                     char c = i + '0';
//                     if(rows[x][i - 1] == true || cols[y][i - 1] == true || boxs[(x / 3) * 3 + (y / 3)][i - 1] == true){
//                         //不合格
//                         continue;
//                     }
//                     board[x][y] = c;
//                     rows[x][i - 1] = true;
//                     cols[y][i - 1] = true;
//                     boxs[(x / 3) * 3 + (y / 3)][i - 1] = true;
//                     if (backTrace(rows, cols, boxs, board, x + ((y + 1)/ 9), (y + 1) % 9) == true){
//                         return true;
//                     }
//                     rows[x][i - 1] = false;
//                     cols[y][i - 1] = false;
//                     boxs[(x / 3) * 3 + (y / 3)][i - 1] = false;
//                 }
//                 board[x][y] = '.';  //backtrace
//             }else{
//                 //only one
//                     int i = board[x][y] - '0';
//                     if(rows[x][i - 1] == true || cols[y][i - 1] == true || boxs[(x / 3) * 3 + (y / 3)][i - 1] == true){
//                         //不合格
//                         return false;
//                     }
//                     rows[x][i - 1] = true;
//                     cols[y][i - 1] = true;
//                     boxs[(x / 3) * 3 + (y / 3)][i - 1] = true;
//                     if ( backTrace(rows, cols, boxs, board, x + ((y + 1)/ 9), (y + 1) % 9) == true){
//                         return true;
//                     }
//                     rows[x][i - 1] = false;
//                     cols[y][i - 1] = false;
//                     boxs[(x / 3) * 3 + (y / 3)][i - 1] = false;
//             }

//             return false;
//         }
// public:

//     void solveSudoku(vector<vector<char>>& board) {
//         vector<vector<bool>> rows(board.size(), vector<bool>(9, false));
//         vector<vector<bool>> cols(board.size(), vector<bool>(9, false));
//         vector<vector<bool>> boxs(board.size(), vector<bool>(9, false));

//         backTrace(rows, cols, boxs, board, 0, 0);
//     }
// };



class Solution {
private:
        bool backTrace(vector<vector<bool>>& rows, vector<vector<bool>>& cols, vector<vector<bool>>& boxs, vector<vector<char>>& board, int x, int y) {
            if(x == board.size()){
                //成功
                return true;
            }
            if(board[x][y] == '.'){
                //for
                for(int i = 1; i <= 9; i++){
                    char c = i + '0';
                    if(rows[x][i - 1] == true || cols[y][i - 1] == true || boxs[(x / 3) * 3 + (y / 3)][i - 1] == true){
                        //不合格
                        continue;
                    }
                    board[x][y] = c;
                    rows[x][i - 1] = true;
                    cols[y][i - 1] = true;
                    boxs[(x / 3) * 3 + (y / 3)][i - 1] = true;
                    if (backTrace(rows, cols, boxs, board, x + ((y + 1)/ 9), (y + 1) % 9) == true){
                        return true;
                    }
                    rows[x][i - 1] = false;
                    cols[y][i - 1] = false;
                    boxs[(x / 3) * 3 + (y / 3)][i - 1] = false;
                }
                board[x][y] = '.';  //backtrace
            }else{
                //only one
                    if ( backTrace(rows, cols, boxs, board, x + ((y + 1)/ 9), (y + 1) % 9) == true){
                        return true;
                    }
            }

            return false;
        }
public:

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(board.size(), vector<bool>(9, false));
        vector<vector<bool>> cols(board.size(), vector<bool>(9, false));
        vector<vector<bool>> boxs(board.size(), vector<bool>(9, false));

        for(int i = 0; i < board.size(); i++){
            for(int j = 0 ; j < board.size(); j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';

                    rows[i][num - 1] = true;
                    cols[j][num - 1] = true;
                    boxs[(i / 3) * 3 + (j / 3)][num - 1] = true;
                }
            }
        }
        backTrace(rows, cols, boxs, board, 0, 0);
    }
};



int main(){
    vector<vector<char>> b = {{'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};

    Solution s;

    s.solveSudoku(b);

    for(int i = 0; i < b.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}