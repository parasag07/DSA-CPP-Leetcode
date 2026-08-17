class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> keys;
        // visited can be renamed as keyFound for better optics 
        vector<int> visited(rooms.size());
        visited[0] = 1;
        int count = 1;
        for(int i = 0; i < rooms[0].size(); i++){
            if(visited[rooms[0][i]] == 0){
                keys.push(rooms[0][i]);
                visited[rooms[0][i]] = 1;
            }
        }

        while(!keys.empty()){
            int i = keys.front();
            keys.pop();
            count++;
            for(int j = 0; j < rooms[i].size(); j++){
                if(visited[rooms[i][j]] == 0){
                    keys.push(rooms[i][j]);
                    visited[rooms[i][j]] = 1;
                }
            }
        }

        return count == rooms.size();
    }
};