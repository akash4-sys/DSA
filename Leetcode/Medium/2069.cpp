#include "../../headers.h"

class Robot
{
    int pos = 0, width, height, start = 0;
    vector<vector<int>> perimeter;

public:
    Robot(int width, int height)
    {
        this->width = width - 1;
        this->height = height - 1;
        for (int i = 0; i < width; i++)
            perimeter.push_back({i, 0});
        for (int j = 1; j < height; j++)
            perimeter.push_back({width - 1, j});
        for (int i = width - 2; i >= 0; i--)
            perimeter.push_back({i, height - 1});
        for (int j = height - 2; j > 0; j--)
            perimeter.push_back({0, j});
    }

    void step(int n) {
        pos = (pos + n) % perimeter.size();
        start = 1;
    }

    vector<int> getPos() {
        return perimeter[pos];
    }

    string getDir()
    {
        int x = perimeter[pos][0], y = perimeter[pos][1];
        if (!start)
            return "East";
        if (x == 0 && y == 0)
            return "South";
        if (y == 0)
            return "East";
        if (x == width)
            return "North";
        if (y == height)
            return "West";
        return "South";
    }
};