class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        map<char, int> m;
        m[num[0]]++;
        m[num[1]]++;
        m[num[2]]++;
        int ans = -1;
        for(auto i:m){
            if(i.second == 3){
                ans = i.first-'0';
            }
        }
        for(int i = 3; i<n; i++){
            m[num[i-3]]--;
            m[num[i]]++;
            if(m[num[i]]==3){
                ans = max(num[i]-'0', ans);
            }
        }

        if(ans == -1){
            return "";
        }

        string res(3, ans + '0');
        return res;
    }
};