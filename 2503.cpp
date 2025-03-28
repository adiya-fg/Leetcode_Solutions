#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>

#define SZ 1001

class Solution {
private:
    std::vector<int> dx = {-1, 0, 0, 1};
    std::vector<int> dy = {0, -1, 1, 0};

public:
    std::vector<int> maxPoints(std::vector<std::vector<int>>& grid, std::vector<int>& queries) {

        int n = grid.size();
        int m = grid[0].size();

        std::vector<int> ans(queries.size());
        std::unordered_map<int, int> answerMap;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
        std::vector<std::pair<int, int>> queryIndex(queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            queryIndex[i] = std::make_pair(queries[i], i);
        }

        std::sort(queryIndex.begin(), queryIndex.end());

        priority_queue<pair<int, int>> steps;

        int total = 0, cur = 0;

        if (n > 0 && n > 0) {
            steps.push(std::make_pair(-1*grid[0][0], 0));
            vis[0][0] = true;
        }

        while (!steps.empty() && cur < queries.size()) {
            int val = -1*steps.top().first;
            int position = steps.top().second;
            steps.pop();

            while (cur < queries.size() && queryIndex[cur].first <= val) {
                ans[queryIndex[cur].second] = total;
                cur++;
            }

            int x = position / SZ;
            int y = position % SZ;

            for (int i = 0; i < 4; i++) {
                int newX = dx[i] + x;
                int newY = dy[i] + y;

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY]) {
                    vis[newX][newY] = true;
                    steps.push(std::make_pair(-1*grid[newX][newY], newX * SZ + newY));
                }
            }
            total++;
        }

        while (cur < queries.size()) {
            ans[queryIndex[cur].second] = total;
            cur++;
        }

        return ans;
    }
};