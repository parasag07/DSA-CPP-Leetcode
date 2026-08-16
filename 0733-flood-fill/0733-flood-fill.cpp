class Solution {
private:
    void scan(vector<vector<int>>& image, int i, int j, int color, int orig){
        if(i > 0 && image[i-1][j] == orig){
            image[i-1][j] = color;
            scan(image, i-1, j, color, orig);
        }
        if(j > 0 && image[i][j-1] == orig){
            image[i][j-1] = color;
            scan(image, i, j-1, color, orig);
        }
        if(i+1 < image.size() && image[i+1][j] == orig){
            image[i+1][j] = color;
            scan(image, i+1, j, color, orig);
        }
        if(j+1 < image[i].size() && image[i][j+1] == orig){
            image[i][j+1] = color;
            scan(image, i, j+1, color, orig);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        image[sr][sc] = color;
        if(orig != color) scan(image, sr, sc, color, orig);
        return image;
    }
};