#ifndef BST_H
#define BST_H

#include<utility>
#include<stdexcept>

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

    K returnKey() {
        return key;
    }

    V returnValue() {
        return value;
    }

    bool isLeaf() {
        if(this->left == nullptr && this->right == nullptr)
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
                Node<K,V>* parent = toDelete->parent;
                if(toDelete == parent->left)
                    parent->left = toDelete->right;
                else
                    parent->right = toDelete->right;
                delete toDelete;
            } //Successfully removed toDelete and replaced it with the right child
            else if(toDelete->right->isLeaf()) { //If the right child is a leaf, replace with its left
                delete toDelete->right;
                Node<K,V>* parent = toDelete->parent;
                if(toDelete == parent->left)
                    parent->left = toDelete->left;
                else
                    parent->right = toDelete->left;
                delete toDelete;
            }
        }
    
    public:
        BinarySearchTree(): root(nullptr), number_of_nodes(0) {}

        int size() {return number_of_nodes;}
        int empty() {return number_of_nodes==0;}
        Node<K,V>* search(K key) {
            if(empty())
                throw std::runtime_error("Tree is empty");
            Node<K,V>* curr = root;
            while(curr->key != key && !curr->isLeaf()) {
                if (curr->key > key)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
            return curr;
        }

        void insert(K key, V value) {
            Node<K,V>* toInsert = new Node<K,V>(key, value);
            if(empty()) {
                root = toInsert;
            }
            else {
                Node<K,V>* spot = search(key);
                if (spot->isLeaf()) {
                    Node<K,V>* parent = spot->parent;
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
            Node<K,V>* toDelete = search(key);
            if(toDelete->isLeaf())
                throw std::runtime_error("Key does not exist in tree."); //element did not exist
            else if(toDelete->left->isLeaf() || toDelete->right->isLeaf()) { //Replace toDelete with its right child
                deleteHelper(toDelete);
            } //Successfully removed toDelete and replaced it with its left child
            else {
                //Find Successor
                Node<K,V>* successor = toDelete->left;
                while(!(successor->right->isLeaf())) {
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
