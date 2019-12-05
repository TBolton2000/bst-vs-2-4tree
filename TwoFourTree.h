#ifndef TWOFOURTREE_H
#define TWOFOURTREE_H
#include"NodeTwo.h"
#include<iostream>


template<typename K, typename V>
class TwoFourTree {
    private:
        NodeTwo<K,V>* root;
        int total;
        
    public:
        TwoFourTree(): root(nullptr), total(0) {}

        int size() {return total;}

        bool empty() {return total == 0;}

        NodeTwo<K,V>* searchTree(K key, NodeTwo<K,V>* curr) {
            if(curr->size() == 3) {
                curr->split();
                if(curr == root)
                    root = curr->getParent();
                curr = curr->getParent();
            }
            if(!(curr->isLeaf()) && curr->findIndex(key) == -1) { // NOT HERE KEEP LOOKING
                return searchTree(key,curr->getNext(key));
            }
            return curr;
        }

        std::pair<K,V> find(K key){
            NodeTwo<K,V>* found = searchTree(key, root);
            int index = found->findIndex(key);
            if(index == -1)
                throw std::runtime_error("Key not found");
            else
                return found->getPair(key);
        }

        void insert(K key, V value) {
            if(empty()) {
                root = new NodeTwo<K,V>(key, value);
                total++;
            }
            else {
                NodeTwo<K,V>* insertHere = searchTree(key, root);
                insertHere->addPair(key,value);
                total++;
            }
        }

        
};

#endif /*TWOFOURTREE_H*/