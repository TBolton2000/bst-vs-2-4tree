#ifndef BST_H
#define BST_H

#include<utility>
#include<stdexcept>
#include<iostream>

template<typename K, typename V>
struct Node{
    Node* parent;
    Node* left;
    Node* right;
    K key;
    V value;
    Node(): parent(nullptr), left(nullptr), right(nullptr), key(K()), value(V()) {

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

    bool isLeaf() {
        if(this == nullptr || this->left == nullptr && this->right == nullptr)
            return true;
        return false;
    }

};

template<typename K,typename V>
class BinarySearchTree {
    private:
        Node<K,V>* root;
        size_t number_of_nodes;

        void deleteHelper(Node<K,V>* toDelete) { //Deletes if the node has at least one leaf child
            if(toDelete->left->isLeaf()) { //Replace toDelete with its right child
                delete toDelete->left;
                if (toDelete == root) {
                    root = toDelete->right;
                    delete toDelete;
                }
                else {
                    Node<K,V>* parent = toDelete->parent;
                    if(toDelete == parent->left)
                        parent->left = toDelete->right;
                    else
                        parent->right = toDelete->right;
                    delete toDelete;
                }
            } //Successfully removed toDelete and replaced it with the right child
            else if(toDelete->right->isLeaf()) { //If the right child is a leaf, replace with its left
                delete toDelete->right;
                if (toDelete == root){
                    root = toDelete->right;
                    delete toDelete;
                }
                Node<K,V>* parent = toDelete->parent;
                if(toDelete == parent->left)
                    parent->left = toDelete->left;
                else
                    parent->right = toDelete->left;
                delete toDelete;
            }
        }

        Node<K,V>* searchTree(K key, Node<K,V>* curr) {
            if(curr->isLeaf())
                return curr;
            else if(curr->key > key)
                return searchTree(key, curr->left);
            else if(curr->key < key)
                return searchTree(key, curr->right);
            else
                return curr;
        }

    public:
        BinarySearchTree(): root(nullptr), number_of_nodes(0) {}

        size_t size() {return number_of_nodes;}
        bool empty() {return number_of_nodes==0;}
        
        Node<K,V>* find(K k) {
            if (empty()) {
                throw std::runtime_error("Tree is currently empty");
            }
            else {
                Node<K,V>* found = searchTree(k,root);
                if (found->isLeaf())
                    throw std::runtime_error("Key is not in tree");
                else
                    return found;
            }
        }

        void insert(K key, V value) {
            Node<K,V>* toInsert = new Node<K,V>(key, value);
            if(empty()) {
                delete root; //If there is anything currently in root/like a dummy node, deletes it
                root = toInsert;
            }
            else {
                Node<K,V>* spot = searchTree(key, root);
                if (spot->isLeaf()) {
                    Node<K,V>* parent = spot->parent;
                    toInsert->parent = parent;
                    if(parent->left == spot)
                        parent->left = toInsert;
                    else
                        parent->right = toInsert;
                    delete spot;
                }
                else { //Key is found in tree and not unique
                    throw std::runtime_error("Key inserted is not unique.");
                }
            }
            number_of_nodes++;
        }

        void remove(K key) {
            Node<K,V>* toDelete = searchTree(key, root);
            if(toDelete->isLeaf())
                throw std::runtime_error("Key does not exist in tree."); //element did not exist
            else if(toDelete->left->isLeaf() || toDelete->right->isLeaf()) { //Replace toDelete with its right child
                deleteHelper(toDelete);
            } //Successfully removed toDelete and replaced it with its left child
            else {
                //Find Successor
                Node<K,V>* successor = toDelete->left;
                while(!(successor->right->isLeaf())) { //CAUSING A SEG FAULT!!!!
                    successor = successor->right;
                }
                //Swap the values of successor to node to delete
                toDelete->key = successor->key;
                toDelete->value = successor->value;
                //Delete the old successor after moving it
                deleteHelper(successor);
            }
            number_of_nodes--;
        }
};

#endif /*BST_H*/
