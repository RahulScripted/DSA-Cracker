#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0) {}
    Node(int v) : val(v) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        map<Node*, Node*> mp;
        queue<Node*> q;
        Node* clone = new Node();
        clone->val = node->val;
        mp[node] = clone;
        q.push(node);

        while (!q.empty()) {
            Node* u = q.front();
            q.pop();

            for (auto neighbor : u->neighbors) {
                if (mp.find(neighbor) == mp.end()) {
                    Node* neighborClone = new Node();
                    neighborClone->val = neighbor->val;
                    mp[neighbor] = neighborClone;
                    q.push(neighbor);
                }
                mp[u]->neighbors.push_back(mp[neighbor]);
            }
        }

        return mp[node];
    }
};

void printGraph(Node* node) {
    if (!node) return;
    set<int> visited;
    queue<Node*> q;
    q.push(node);
    visited.insert(node->val);
    while (!q.empty()) {
        Node* u = q.front(); q.pop();
        cout << u->val << " -> [";
        for (int i = 0; i < u->neighbors.size(); i++) {
            cout << u->neighbors[i]->val;
            if (i + 1 < u->neighbors.size()) cout << ", ";
            if (!visited.count(u->neighbors[i]->val)) {
                visited.insert(u->neighbors[i]->val);
                q.push(u->neighbors[i]);
            }
        }
        cout << "]\n";
    }
}

bool verifyClone(Node* original, Node* clone) {
    if (!original && !clone) return true;
    if (!original || !clone) return false;
    map<int, pair<Node*, Node*>> seen;
    queue<pair<Node*, Node*>> q;
    q.push({original, clone});
    seen[original->val] = {original, clone};
    while (!q.empty()) {
        auto [o, c] = q.front(); q.pop();
        if (o == c) return false;
        if (o->val != c->val) return false;
        if (o->neighbors.size() != c->neighbors.size()) return false;
        for (int i = 0; i < o->neighbors.size(); i++) {
            int nval = o->neighbors[i]->val;
            if (!seen.count(nval)) {
                seen[nval] = {o->neighbors[i], c->neighbors[i]};
                q.push({o->neighbors[i], c->neighbors[i]});
            }
        }
    }
    return true;
}

void freeGraph(Node* node) {
    if (!node) return;
    set<Node*> visited;
    queue<Node*> q;
    q.push(node);
    visited.insert(node);
    while (!q.empty()) {
        Node* u = q.front(); q.pop();
        for (auto nb : u->neighbors)
            if (!visited.count(nb)) { visited.insert(nb); q.push(nb); }
    }
    for (auto n : visited) delete n;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    cout << "=== Original Graph ===\n";
    printGraph(n1);

    Solution solution;
    Node* cloned = solution.cloneGraph(n1);

    cout << "\n=== Cloned Graph ===\n";
    printGraph(cloned);

    cout << "\nDeep copy verified: " << (verifyClone(n1, cloned) ? "YES" : "NO") << "\n";

    freeGraph(n1);
    freeGraph(cloned);
    return 0;
}
