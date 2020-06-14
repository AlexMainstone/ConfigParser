#pragma once

#include<vector>

struct pf_Node{
    int x, y;
    int cost;
    int lastx, lasty;
    pf_Node() {
        cost = 0;
    }
    pf_Node(int c, int x, int y, int lx, int ly) {
        cost = c;
        this->x = x;
        this->y = y;
        lastx = lx;
        lasty = ly;
    }
};

inline std::vector<std::vector<pf_Node>> pf_dijkstra(std::vector<std::vector<int>> area, int startx, int starty) {
    std::vector<std::vector<pf_Node>> dijkstra_map(area.size(), std::vector<pf_Node>(area[0].size(), pf_Node()));
    area[startx][starty] = -1;

    std::vector<pf_Node> unsorted_pf_Nodes;
    unsorted_pf_Nodes.push_back(pf_Node(-1, startx, starty, startx, starty));
    int currentx, currenty;
    int i = 0;
    do {
        if(!unsorted_pf_Nodes.empty()) {
            currentx = unsorted_pf_Nodes.back().x;
            currenty = unsorted_pf_Nodes.back().y;
            unsorted_pf_Nodes.pop_back();
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
                        pf_Node n(dijkstra_map[currentx][currenty].cost + area[currentx + dx][currenty + dy], currentx, currenty, currentx + dx, currenty + dy);
                        unsorted_pf_Nodes.push_back(n);
                        dijkstra_map[currentx + dx][currenty + dy] = n;
                        continue;
                    }
                }
            }
        }

    } while(!unsorted_pf_Nodes.empty());
    return dijkstra_map;
}
