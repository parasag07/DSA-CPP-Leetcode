class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> keys;
        // visited can be renamed as keyFound for better optics 
        vector<int> visited;
        for(int i = 0; i < rooms[0].size(); i++){
            if(find(visited.begin(), visited.end(), rooms[0][i]) == visited.end()){
                keys.push(rooms[0][i]);
                visited.push_back(rooms[0][i]);
            }
        }

        while(!keys.empty()){
            int i = keys.front();
            keys.pop();
            for(int j = 0; j < rooms[i].size(); j++){
                if(find(visited.begin(), visited.end(), rooms[i][j]) == visited.end()){
                    keys.push(rooms[i][j]);
                    visited.push_back(rooms[i][j]);
                }
            }
        }

        if(find(visited.begin(), visited.end(), 0) == visited.end())
            return visited.size()+1 == rooms.size();
        else
            return visited.size() == rooms.size();

    }
};