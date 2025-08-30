class Solution {
public:
    bool grid(vector<vector<char>>& board, int r, int c){
        unordered_map<char, int> count;
        for(int i = r; i<r+3; i++){
            
            for(int j = c; j<c+3; j++){
                char ch = board[i][j];
                if(ch!='.'){
                    count[ch]++;
                }
            }
            for(auto i:count){
                if(i.second >1){
                    return false; 
                }
            }
        }
        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            unordered_map<char, int> count;
            for(int j = 0; j<9; j++){
                char ch = board[i][j];
                if(ch!='.'){
                    count[ch]++;
                }
            }
            for(auto i:count){
                if(i.second >1){
                    return false; 
                }
            }
        }
        for(int i = 0; i<9; i++){
            unordered_map<char, int> count;
            for(int j = 0; j<9; j++){
                char ch = board[j][i];
                if(ch!='.'){
                    count[ch]++;
                }
            }
            for(auto i:count){
                if(i.second >1){
                    return false; 
                }
            }
        }
        for(int i = 0; i<9; i+=3){
            for(int j = 0; j<9; j+=3){
                if(!grid(board, i, j)){
                    return false;
                }
            }
        }
        return true;
    }
};