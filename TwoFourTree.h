#ifndef TWOFOURTREE_H
#define TWOFOURTREE_H
#include<vector>


template<typename K, typename V>
struct NodeTwo {
    NodeTwo* parent;
    std::vector<NodeTwo*> children;
    std::vector<std::pair<K,V>> pair;
    NodeTwo(): parent(nullptr), children() {
        
    }

    NodeTwo(K key, V value): parent(nullptr), children(), pair(){
        pair.push_back(std::make_pair(key,value));
    }
};

template<typename K, typename V>
class TwoFourTree {
    private:
        NodeTwo<K,V>* root;
        size_t total;

        void split(NodeTwo<K,V>* curr) {
            if(curr == root) {
                if(curr->pair.size() == 3) {
                    root = new NodeTwo(curr->pair.at(1).first,curr->pair.at(1).second)
                    root->children.push_back(curr);
                    NodeTwo<K,V>* newRightNode = 
                }
                else if(curr->pair.size() == 4) {

                }
            }
        }

    public:
        TwoFourTree(): root(nullptr), total(0) {}

        int size() {return total;}

        bool empty() {return total == 0;}

        NodeTwo<K,V>* searchTree(K key, NodeTwo<K,V>* curr) {
            for(int i = 0; i < curr->pair.size(); i++) {
                if (key < curr->pair.at(i).first)
                    return searchTree(key, curr->children.at(i));
                if (key == curr->pair.at(i).first)
                    return curr;
            }
            return searchTree(key, curr->children.at(curr->pair.size()));
        }

        void insert(K key, V value) {
            if(empty()) {
                root = new NodeTwo<K,V>(key, value);
            }
        }
};

#endif /*TWOFOURTREE_H*/