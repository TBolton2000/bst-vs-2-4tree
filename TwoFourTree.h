#ifndef TWOFOURTREE_H
#define TWOFOURTREE_H


template<typename K, typename V>
struct Node {
    Node* parent;
    Node*[] children;
    K[] keys;
    V[] values;
};

template<typename K, typename V>
class TwoFourTree {
    private:
        Node* root;

}

#endif /*TWOFOURTREE_H*/