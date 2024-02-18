#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
    vector<vector<int>> dirs = {{1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}};
    bool backTrace(int x, int y, int index, vector<vector<char>>& board, string& word){
        if(index >= word.length()) return true;

        if(x < 0 || x >= board.size() || y < 0 || y >= board.back().size() || board[x][y] == 0 || word[index] != board[x][y]){
            return false;
        }
        char temp = board[x][y];
        board[x][y] = 0;
        for(int i = 0; i < dirs.size(); i++){
            if(backTrace(x + dirs[i][0], y + dirs[i][1], index + 1, board, word) == true){
                return true;
            }
        }
        board[x][y] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string& word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.back().size(); j++){
                if(word.front() == board[i][j] && backTrace(i, j, 0, board, word)){
                    return true;
                }
            }
        }

        return false;
    }
};