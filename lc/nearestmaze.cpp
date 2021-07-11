class Solution {
public:
    bool validpos(vector<vector<char>>& maze, int x, int y) {
        return x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == '.';
    }
    
    bool isexit(vector<vector<char>>& maze, int x, int y) {
        return x == 0 || y == 0 || x == maze.size() - 1 || y == maze[0].size() - 1;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> visit;
        
        vector<vector<int>> dist(maze.size(), vector<int>(maze[0].size()));
        
        visit.push({entrance[0], entrance[1]});
        
        
        while (!visit.empty()) {
            auto cur = visit.front();            
            visit.pop();
            
            maze[cur.first][cur.second] = '+';
            
            if (validpos(maze, cur.first + 1, cur.second)) {
                dist[cur.first + 1][cur.second] = dist[cur.first][cur.second] + 1;
                
                if (isexit(maze, cur.first + 1, cur.second)) {
                    return dist[cur.first + 1][cur.second];
                }
                
                visit.push({cur.first + 1, cur.second});
                maze[cur.first + 1][cur.second] = '+';
            }
            
            if (validpos(maze, cur.first - 1, cur.second)) {
                dist[cur.first - 1][cur.second] = dist[cur.first][cur.second] + 1;
                
                if (isexit(maze, cur.first - 1, cur.second)) {
                    return dist[cur.first - 1][cur.second];
                }
                
                visit.push({cur.first - 1, cur.second});
                maze[cur.first - 1][cur.second] = '+';
            }
            
            if (validpos(maze, cur.first, cur.second + 1)) {
                dist[cur.first][cur.second + 1] = dist[cur.first][cur.second] + 1;
                
                if (isexit(maze, cur.first, cur.second + 1)) {
                    return dist[cur.first][cur.second + 1];
                }
                
                visit.push({cur.first, cur.second + 1});
                maze[cur.first][cur.second + 1] = '+';
            }
            
            if (validpos(maze, cur.first, cur.second - 1)) {
                dist[cur.first][cur.second - 1] = dist[cur.first][cur.second] + 1;
                
                if (isexit(maze, cur.first, cur.second - 1)) {
                    return dist[cur.first][cur.second - 1];
                }
                
                visit.push({cur.first, cur.second - 1});
                maze[cur.first][cur.second - 1] = '+';
            }
        
        }
        
        return -1;
    }
};