// Not completed

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename E>
class VectorTree {
private:
    vector<E> V;
public:
    typedef typename vector<E>::iterator Position; // a position in the tree
    VectorTree() : V(1) { } // constructor
    int size() const { return V.size() - 1; }
    Position left(const Position& p) { return pos(2*idx(p)); }
    Position right(const Position& p) { return pos(2*idx(p) + 1); }
    Position parent(const Position& p) { return pos(idx(p)/2); }
    bool hasLeft(const Position& p) { return pos(2*idx(p)) <= size(); } 
    bool hasRight(const Position& p) { return pos(2*idx(p) + 1) <= size(); } 
    bool isRoot(const Position& p) { return idx(p) == 1; }
    Position root() { return pos(1); }
    Position last() { return pos(size()); }
    void addLast(const E& e) { V.push_back(e); }
    void removeLast() { V.pop_back(); }
    void swap(const Position &p, const Position &q) {
        E e = *q;
        *q = *p;
        *p = e;
    }
protected:
    Position pos(int i) { return V.begin() + i; } // map an index to a position
    int idx(const Position& p) const { return p - V.begin(); } // map a position to an index
};

template <typename E>
class Heap {
public:
    int size() const;
    bool empty() const;
    void insert(const E& e);
    const E& min();
    void removeKey(const E& key);
private:
    VectorTree<E> T;
    
    typedef typename VectorTree<E>::Position Position;
};

template <typename E>
int Heap<E>::size() const {
    return T.size();
}

template <typename E>
bool Heap<E>::empty() const {
    return T.size() == 0;
}

template <typename E>
void Heap<E>::insert(const E& e) {
    T.addLast(e);
    Position v = T.last();
    while(!T.isRoot(v)) {
        Position u = T.parent(v);
        if(*v < *u) break;
        T.swap(u, v);
        v = u;
    }
}

template <typename E>
const E& Heap<E>::min() {
    return *(T.root());
}

template <typename E>
void Heap<E>::removeKey(const E& key) {
    Position u = T.root();
    if(key == *u) {
        T.swap(u, T.last());
        T.removeLast();
        while(T.hasLeft(u)) {
            Position v = T.left(u);
            if(T.hasRight(u) && (*(T.right(u)) > *v))
                v = T.right(u);
            if(*v < *u) {
                T.swap(u, v);
                u = v;
            }
            else break;
        }
    } else {
        while(T.hasLeft(u)) {
            if(key < *(T.left(u))) {
                
            } else if(key > *(T.right(u))) {
                
            }
        } 
    }
}

int main() {
    int count = 0;
    Heap<int> h;
    int c, v;
    cin >> count;
    switch(c) {
        case 1: 
            cin >> v;
            h.insert(v);
        case 2:
            cin >> v;
            h.removeKey(v);
        case 3:
            cout << h.min() << endl;
    }
    return 0;
}
