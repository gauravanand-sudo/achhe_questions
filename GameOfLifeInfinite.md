#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

class GameOfLifeInfinite {
public:
    set<pair<int,int>> liveCells;

    GameOfLifeInfinite(vector<vector<int>>& board) {
        // Initialize from finite board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 1) {
                    liveCells.insert({i, j});
                }
            }
        }
    }

    void nextGeneration() {
        map<pair<int,int>, int> neighborCount;
        vector<pair<int,int>> dirs = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},        {0,1},
            {1,-1},{1,0},{1,1}
        };

        // Count neighbors for each live cell
        for (auto& cell : liveCells) {
            int x = cell.first, y = cell.second;
            for (auto& d : dirs) {
                int nx = x + d.first, ny = y + d.second;
                neighborCount[{nx, ny}]++;
            }
        }

        set<pair<int,int>> newLiveCells;

        // Apply rules
        for (auto& entry : neighborCount) {
            auto pos = entry.first;
            int cnt = entry.second;
            bool isAlive = liveCells.count(pos);

            if ((isAlive && (cnt == 2 || cnt == 3)) ||
                (!isAlive && cnt == 3)) {
                newLiveCells.insert(pos);
            }
        }

        liveCells = newLiveCells;
    }

    void print(int minX, int maxX, int minY, int maxY) {
        for (int i = minX; i <= maxX; i++) {
            for (int j = minY; j <= maxY; j++) {
                if (liveCells.count({i, j})) cout << "1 ";
                else cout << "0 ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};
