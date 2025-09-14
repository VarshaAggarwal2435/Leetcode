
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        auto toLower = [](const string& s) {
            string t = s;
            for (char &c : t) c = tolower(c);
            return t;
        };

        auto maskVowels = [&](const string& s) {
            string t = s;
            for (char &c : t) {
                char lc = tolower(c);
                if (lc=='a' || lc=='e' || lc=='i' || lc=='o' || lc=='u')
                    c = '*';
                else
                    c = lc;
            }
            return t;
        };

        unordered_set<string> exact(wordlist.begin(), wordlist.end());

        unordered_map<string,string> caseMap;
        for (auto &w : wordlist) {
            string lw = toLower(w);
            if (!caseMap.count(lw)) caseMap[lw] = w;
        }

        unordered_map<string,string> vowelMap;
        for (auto &w : wordlist) {
            string mw = maskVowels(w);
            if (!vowelMap.count(mw)) vowelMap[mw] = w;
        }

        vector<string> ans;
        for (auto &q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lq = toLower(q);
            if (caseMap.count(lq)) {
                ans.push_back(caseMap[lq]);
                continue;
            }
            string mq = maskVowels(q);
            if (vowelMap.count(mq)) {
                ans.push_back(vowelMap[mq]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};