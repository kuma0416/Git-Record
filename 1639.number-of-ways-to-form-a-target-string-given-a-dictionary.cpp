class Solution {
    int MOD = 1000000007;
    int n, m;
    vector<vector<int>> cache;
public:
    int numWays(vector<string>& words, string target) {
        n = words[0].size(), m = target.size();
        vector<array<int, 26>> cnts(n);
        for (auto& w : words) {
            for (int i = 0; i < n; i++) {
                cnts[i][w[i] - 'a']++;
            }
        }
        cache.resize(n, vector<int>(m, -1));
        return dfs(cnts, target, 0, 0);
    }
    int dfs(vector<array<int, 26>>& cnts, string& target, int i, int j) {
        if (j == m) return 1;
        if (m - j > n - i) return 0;
        if (cache[i][j] > -1) return cache[i][j];
        long long cnt = cnts[i][target[j] - 'a'];
        int ans = dfs(cnts, target, i + 1, j);
        if (cnt > 0) {
            ans = (ans + cnt * dfs(cnts, target, i + 1, j + 1)) % MOD;
        }
        return cache[i][j] = ans;
    }
};