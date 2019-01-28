#ifndef PATHFINDING_H_
#define PATHFINDING_H_

#include<vector>

namespace pathfinding {
    struct Node{
        int x, y;
        int cost;
        int lastx, lasty;
        Node() {
            cost = 0;
        }
        Node(int c, int x, int y, int lx, int ly) {
            cost = c;
            this->x = x;
            this->y = y;
            lastx = lx;
            lasty = ly;
        }
    };

    inline std::vector<std::vector<Node>> dijkstra(std::vector<std::vector<int>> area, int startx, int starty) {
        std::vector<std::vector<Node>> dijkstra_map(area.size(), std::vector<Node>(area[0].size(), Node()));
        area[startx][starty] = -1;

        std::vector<Node> unsorted_nodes;
        unsorted_nodes.push_back(Node(-1, startx, starty, startx, starty));
        int currentx, currenty;
        int i = 0;
        do {
            if(!unsorted_nodes.empty()) {
                currentx = unsorted_nodes.back().x;
                currenty = unsorted_nodes.back().y;
                unsorted_nodes.pop_back();
            }
            for(int dx = -1; dx <= 1; dx++) {
                for(int dy = -1; dy <= 1; dy++) {
                    if((dx != 0 || dy != 0)) {
                        // if out of bounds
                        if(currentx + dx < 0 || currentx + dx >= dijkstra_map.size() || currenty + dy < 0 || currenty + dy >= dijkstra_map.size()) {
                            continue;
                        }

                        if(area[currentx + dx][currenty + dy] < 0) {
                            continue;
                        }

                        // if cheaper
                        if(dijkstra_map[currentx+dx][currenty+dy].cost == 0 || dijkstra_map[currentx + dx][currenty + dy].cost > dijkstra_map[currentx][currenty].cost + area[currentx + dx][currenty + dy]) {
                            Node n(dijkstra_map[currentx][currenty].cost + area[currentx + dx][currenty + dy], currentx, currenty, currentx + dx, currenty + dy);
                            unsorted_nodes.push_back(n);
                            dijkstra_map[currentx + dx][currenty + dy] = n;
                            continue;
                        }
                    }
                }
            }

        } while(!unsorted_nodes.empty());
        return dijkstra_map;
    }
};
#endif // PATHFINDING_H_
