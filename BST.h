#ifndef BST_H
#define BST_H

#include<utility>

template<typename K, typename V>
struct Node{
    Node* parent;
    Node* left;
    Node* right;
    K key;
    V value;
    Node(): parent(nullptr), left(nullptr), right(nullptr), key(nullptr), value(nullptr) {

    };

    Node(K key,V value): parent(nullptr), key(key), value(value) { //Construct a node with two dummy nodes.
        Node* left = new Node();
        Node* right = new Node();
        left->parent = this;
        right->parent = this;
        this->left = left;
        this->right = right;
    };

    std::pair<K,V> returnPair() {
        return std::make_pair(key,value);
    }

    bool isLeaf(Node* curr) {
        if(curr.left == nullptr && curr.right == nullptr)
            return true;
        return false;
    }

};

template<typename K,typename V>
class BinarySearchTree {
    private:
        Node<K,V>* root;
        size_t number_of_nodes;
    public:
        int size() {return number_of_nodes;}
        int empty() {return number_of_nodes==0;}
        Node* search(K key) {
            Node* curr = root;
            while(curr->key != key && !curr.isLeaf()) {
                if (curr->key > key)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
        }

        void insert(K key, V value) {

        }

        void delete(K key) {

        }


};

#endif /*BST_H*/
