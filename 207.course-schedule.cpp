// i, ii, iii: wrong answer; iv: TLE
typedef pair<int, set<int>> directions;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        set<int> totalVisited;
        if(prerequisites.size()==0){
            return true;
        }
        map<int, vector<int>> mapping;
        vector<bool> rootv(numCourses, true);
        for(vector<int> el: prerequisites){
            if(el[0] == el[1]){
                return false;
            }
            rootv[el[0]] = false;
            if(mapping.contains(el[1])){
                mapping[el[1]].push_back(el[0]);
            } else {
                mapping[el[1]] = {el[0]};
            }
        }
        bool ans=false;
        deque<directions> stepQue;
        for(int i=0; i<numCourses; ++i){
            if(rootv[i]==false){
                continue;
            }
            totalVisited.insert(i);
            for(int el: mapping[i]){
                totalVisited.insert(el);
                stepQue.push_back({el, {i}});
            }
        }
        if(stepQue.size()==0){
            return false;
        }
        while(!stepQue.empty()){
            int nextNode = stepQue.front().first;
            set<int> visited=stepQue.front().second;
            visited.insert(nextNode);
            vector<int> targetElement=mapping[nextNode];
            for(int teIn: targetElement){
                totalVisited.insert(teIn);
                if(visited.con
            totalVisited.insert(i);tains(teIn)){
                    return false;
                }
                stepQue.push_back({teIn, visited});
            }
            stepQue.pop_front();
        }
        return totalVisited.size()==numCourses;
    }
};
// other solution
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        // 建立鄰接表與計算入度
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        // 將入度為 0 的節點加入隊列
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int visitedCount = 0;

        // 拓撲排序
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visitedCount++;

            for (int neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 如果所有節點都能訪問，則無環
        return visitedCount == numCourses;
    }
};
