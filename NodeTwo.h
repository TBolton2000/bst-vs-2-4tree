#ifndef NODETWO_H
#define NODETWO_H
#include<utility>
#include<iostream>

template<typename K, typename V>
class NodeTwo {
private:
    const int MAX_SIZE = 4;
    int numKeys;
    NodeTwo<K,V>* parent;
    NodeTwo<K,V>** childrenArr = new NodeTwo<K,V>*[MAX_SIZE];
    K* keyArr = new K[MAX_SIZE-1];
    V* valArr = new V[MAX_SIZE-1];

public:

    NodeTwo(K key,V val): numKeys(1), parent(nullptr){
        keyArr[0] = key;
        valArr[0] = val;
        childrenArr[0] = nullptr;
        childrenArr[1] = nullptr;
        childrenArr[2] = nullptr;
        childrenArr[3] = nullptr;
    } 
    
    int findIndex(K key) {
        if(keyArr[0] == key || numKeys < 1)
            return 0;
        if(keyArr[1] == key || numKeys < 2)
            return 1;
        if(keyArr[2] == key || numKeys < 3)
            return 2;
        return -1;
    }

    NodeTwo<K,V>* getParent() {
        return parent;
    }

    NodeTwo<K,V>* getNext(K key) {
        if(key < keyArr[0])
            return childrenArr[0];
        if(numKeys == 1 || key < keyArr[1])
            return childrenArr[1];
        if(numKeys == 2 || key < keyArr[2])
            return childrenArr[2];
        return childrenArr[3];
    }

    bool isLeaf() {
        return (childrenArr[0] == nullptr);
    }

    int size() {return numKeys;}

    std::pair<K,V> getPair(K key) {
        int index = findIndex(key);
        std::cout << "index: " << index << std::endl;
        return std::make_pair(keyArr[index],valArr[index]);
    }

    void addChild(NodeTwo<K,V>* newNode, int child_num) {
        childrenArr[child_num] = newNode;
    }

    void removeChild(int child_num) {
        childrenArr[child_num] = nullptr;
    };

    void addPair(K key, V val) {
        if(numKeys == 0) {
            keyArr[0] = key;
            valArr[0] = val;
            numKeys = 1;
        }
        else if(numKeys == 1) {
            if (key < keyArr[0]) {
                keyArr[1] = keyArr[0];
                valArr[1] = valArr[0];
                keyArr[0] = key;
                valArr[0] = val;
                childrenArr[1]=childrenArr[0];
                childrenArr[2]=childrenArr[1];
            }
            else {
                keyArr[1] = key;
                valArr[1] = val;
            }
            numKeys = 2;
        }
        else if(numKeys == 2) {
            if (key < keyArr[0]) {
                keyArr[1] = keyArr[0];
                valArr[1] = valArr[0];
                keyArr[0] = key;
                valArr[0] = val;
                childrenArr[1]=childrenArr[0];
                childrenArr[2]=childrenArr[1];
                childrenArr[3]=childrenArr[2];
            }
            else if (key < keyArr[1]) {
                keyArr[2] = keyArr[1];
                valArr[2] = valArr[1];
                keyArr[1] = key;
                valArr[1] = val;
                childrenArr[]
            }
            else {
                keyArr[2] = key;
                valArr[2] = val;
            }
            numKeys = 3;
        }
        else {
            return; //split(key, val);
        }
    }

    /* void split(K key, V val) { //Split when adding a node that would cause an overflow
        if(numKeys == 3) {
            split();

        }
    } *///THIS IS NEVER NEEDED AS LONG AS YOU SPLIT EVERYTHING THAT HAS 3 NODES EVERY TIME YOU NAVIGATE DOWN THE TREE.

    bool split() { //Use this split on the way down when navigating for an insert
        if(numKeys == 3) {
            if (parent == nullptr) {
                NodeTwo<K,V>* newParent = new NodeTwo<K,V>(keyArr[1],valArr[1]);
                NodeTwo<K,V>* newRight = new NodeTwo<K,V>(keyArr[2],keyArr[2]);
                newRight->parent = newParent;
                this->parent = newParent;
                newParent->addChild(this, 0);
                newParent->addChild(newRight, 1);
                newRight->addChild(childrenArr[2],0);
                newRight->addChild(childrenArr[3],1);
                this->removeChild(3);
                this->removeChild(4);
                this->numKeys = 1;
            }
            else {
                NodeTwo<K,V>* newRight = new NodeTwo<K,V>(keyArr[2],valArr[2]);
                newRight->parent = parent;
                parent->addPair(keyArr[1],valArr[1]);
                int index = parent->findIndex(keyArr[1]);
                parent->addChild(this, index);
                parent->addChild(newRight, index+1);
                newRight->addChild(childrenArr[2],0);
                newRight->addChild(childrenArr[3],1);
                this->removeChild(3);
                this->removeChild(4);
                this->numKeys = 1;
            }
            return true;
        }
        else { //Not 3 keys currently in node, so don't do anything
            return false;
        }
    }

};

    /* struct NodeTwo {
        NodeTwo* parent;
        std::vector<NodeTwo*> children;
        std::vector<std::pair<K,V>> pair;
        NodeTwo(): parent(nullptr), children() {
            
        }

        NodeTwo(K key, V value): parent(nullptr), children(), pair(){
            pair.push_back(std::make_pair(key,value));
        }

        bool isDummy() {return false;}
    };

    template<typename K, typename V>

    struct DummyNode {
        NodeTwo<K,V>* parent;
        DummyNode(NodeTwo*<K,V> parent): parent(parent) {}
        bool isDummy() {return true;}
    };
}
 */
#endif /*NODETWO_H*/