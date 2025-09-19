class Spreadsheet {
public:
    vector<vector<int>> mat;
    Spreadsheet(int rows) {
        mat.resize(rows, vector<int>(26, 0));
    }
    pair<int, int> getCoordinates(string cell){
        int y = cell[0]-'A';
        string s = cell.substr(1);
        int x = stoi(s)-1;
        return {x, y};
    }
    
    void setCell(string cell, int value) {
        pair<int, int> p = getCoordinates(cell);
        mat[p.first][p.second] = value;
    }
    
    void resetCell(string cell) {
        pair<int, int> p = getCoordinates(cell);
        mat[p.first][p.second] = 0;
    }
    
    int getValue(string formula) {
        int i = 1;
        int n = formula.size();
        int num1 = 0;
        int num2 = 0;
        string str="";
        while(formula[i]!='+'){
            str+=formula[i];
            i++;   
        }
        if(str[0]>='A' && str[0]<='Z'){
            pair<int, int> p = getCoordinates(str);
            num1 = mat[p.first][p.second];
        }
        else{
            num1 = stoi(str);
        }
        str = "";
        i++;
        while(i<n){
            str+=formula[i];
            i++;   
        }
        if(str[0]>='A' && str[0]<='Z'){
            pair<int, int> p = getCoordinates(str);
            num2 = mat[p.first][p.second];
        }
        else{
            num2 = stoi(str);
        }
        return num1+num2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */