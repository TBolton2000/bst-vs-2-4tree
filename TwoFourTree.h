#ifndef TWOFOURTREE_H
#define TWOFOURTREE_H
#include<vector>


template<typename K, typename V>
struct Node {
    Node* parent;
    std::vector<Node*> children;
    std::vector<K> keys;
    std::vector<V> values;
    Node(): parent(nullptr), children() {
        
    }
};

template<typename K, typename V>
class TwoFourTree {
    private:
        Node* root;
    public:
        TwoFourTree() {

        }
};

#endif /*TWOFOURTREE_H*/