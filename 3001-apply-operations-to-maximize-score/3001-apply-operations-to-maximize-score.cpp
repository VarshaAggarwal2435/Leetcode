unordered_map<int, int> primes; 
class Solution {
public:
    int maxi = 100000; 
    int mod = 1000000007; 
    void calSieve() {
        vector<bool> p(maxi+1, true); 
        
        for(int i = 2; i <= maxi; i++) {
            if(p[i]) {
                primes[i]++; 
                for(int j = 2; i*j <= maxi; j++) {
                    p[i*j] = false;
                }
            }
        }
    } 

    int powe(long long a, long long b) {
        int res = 1; 
        while(b) {
            if(b%2) {
                res = ((res%mod)*(a%mod))%mod;
            }
            b /= 2; 
            a = ((a%mod)*(a%mod))%mod;
        }
        return res; 
    }

    int maximumScore(vector<int>& nums, int k) {
        if(primes.size() == 0) {
            calSieve();
        }

        int n = nums.size(); 
        vector<int> ps(n), nge(n, n), pge(n, -1);
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int cnt = 0; 
            for(int j = 1; j*j <= num; j++) {
                if(num%j == 0) {
                    if(primes.find(j) != primes.end()) {
                        cnt++; 
                    }
                    int temp = num/j; 
                    if(temp != j) {
                        if(primes.find(temp) != primes.end()) {
                            cnt++; 
                        }
                    }
                } 
            }
            ps[i] = cnt; 
        }

        stack<int> st; 

        for(int i = 0; i < n; i++) {
            if(st.size() == 0) {
                st.push(i); 
            } else {
                while(!st.empty() && ps[st.top()] < ps[i]) {
                    nge[st.top()] = i; 
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--) {
            if(st.size() == 0) {
                st.push(i); 
            } else {
                while(!st.empty() && ps[st.top()] <= ps[i]) {
                    pge[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }

        priority_queue<pair<int, int>> pq; 
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int idx = i; 
            pq.push({num, idx});
        }
        long long ans = 1; 
        k = (long long)k; 
        while(!pq.empty() && k) {
            int num = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            int ng = nge[i];
            int pg = pge[i];

            long long left = (i - ng - 1);
            long long right = (pg - i - 1);

            long long totalSubs = (left + right + left*right + 1);  
            if(k >= totalSubs) {
                k -= (totalSubs); 
            } else {
                totalSubs = k; 
                k = 0; 
            }
            ans = ((ans%mod)*(powe(num, totalSubs)%mod))%mod; 
        }

        return ans%mod; 
    }
};