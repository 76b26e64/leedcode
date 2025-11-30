/*
79. Word Search
Solved
Medium
Topics
conpanies icon
Companies
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?

*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        for(int x = 0; x < m; x++){
            for(int y = 0; y < n; y++){
                if(board[x][y] == word[0]){
                    if(word.length() == 1){
                        return true;
                    }
                    
                    if(search(board, x, y, word, 0)){
                        return true;
                    }
                }

            }
        }
        return false; 
    }

private:
    int m, n;
    bool valid(vector<vector<char>>& board, int x, int y, string& word, int index) {
        if(x < 0 || m <= x || y < 0 || n <= y){
            return false;
        }else if(board[x][y] != word[index]){
            return false;
        }
        return true;
    }
     
    bool search(vector<vector<char>>& board, int x, int y, string& word, int index) {
        if(index == word.length()){
            return true;
        }

        if(!valid(board, x, y, word, index)){
            return false;
        }

        char saved = board[x][y];
        board[x][y] = '-';
        bool found = search(board, x-1, y,   word, index + 1) ||
                     search(board, x+1, y,   word, index + 1) ||
                     search(board, x,   y-1, word, index + 1) || 
                     search(board, x,   y+1, word, index + 1);
        board[x][y] = saved; 
        return found;
    }
};

