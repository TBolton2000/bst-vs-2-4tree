#ifndef NODEDATA_H
#define NODEDATA_H
#include<utility>
#include<iostream>

template<typename K, typename V>
class NodeData{
private:
    K key;
    V value;
public:
    NodeData(K key, V value): key(key), value(value) {}
    K getKey() {return key;}
    V getValue() {return value;}
    void setKey(K key) {key = key;}
    void setValue() {value = value;}
    std::pair<K,V> getPair() {return std::make_pair(key,value);}
    bool operator<(NodeData const second) {
        return this.key < second.key;
    }
    bool operator>(NodeData const second) {
        return this.key > second.key;
    }
    bool operator==(NodeData const second) {
        return this.key == second.key;
    }
};



#endif /*NODEDATA_H*/