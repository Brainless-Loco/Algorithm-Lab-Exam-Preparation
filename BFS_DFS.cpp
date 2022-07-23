#include<bits/stdc++.h>
using namespace std;

enum {
    INFINITY = std::numeric_limits<int>::max()
};

enum Color {
    WHITE,
    GREY,
    BLACK
};

struct Vertex {
    int id;

    // BFS properties
    Color color;
    int discovery;
    Vertex* parent;

    // DFS properties
    int finish;
};

// adjacenty list representation (Figure 22.1 (b) of CLRS 3rd ed.)
struct Graph {
    std::vector<Vertex> vertices;
    std::vector< std::vector<Vertex*> > adjacent;
};

void breadth_first_search(Graph& g, Vertex* s)
{
    for (auto& v: g.vertices)
        if (v.id == s->id) continue;
        v.color = WHITE;
        v.discovery = INFINITY;
        v.parent = nullptr;
    }
    s->color = GRAY;
    s->discovery = 0;
    s->parent = nullptr;
    std::queue<Vertex*> q;
    q.push(s);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v: G.adjacent[u->id])) {
            if (v->color == WHITE) {
                v->color = GRAY;
                v->discovery = u->discovery + 1;
                v->parent = u;
                q.push(v);
            }
        }
        u->color = BLACK;
    }
}
// post-condition: graph with initialized vertex color and discovery times

void depth_first_search(Graph& g)
{
    for (auto& u: g.vertices) {
        u.color = WHITE;
        u.parent = nullptr;
    }

    for (auto& u: g.vertices) {
        if (u.color == WHITE)
            depth_first_search_visit(g, &u, 1)
    }
}

void depth_first_search_visit(Graph& g, Vertex* u, int time)
{
    u->color = GRAY;
    u->discovery = time;
    for (auto v: g.adjacent[u->id]) {
        if (v->color == WHITE) {
            v->parent = u;
            depth_first_search_visit(G, u, time + 1)
        }
    }
    u->color = BLACK;
    u->finish = time + 1;
}
