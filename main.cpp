#include"BST.h"
#include<iostream>

using namespace std;

int main() {

    BinarySearchTree<int,char> bst;
    //cout << bst.empty() << endl;

    cout << bst.size() << endl;

    try {
        //bst.find(10);
        bst.remove(10);

    }
    catch(exception &e) {
        cout << "Error found in Main: " << e.what() << endl;
    }
    bst.insert(10, 'a');
    bst.insert(15, 'b');
    bst.insert(20, 'c');
    bst.insert(5, 'd');
    bst.insert(400, 'e');
    cout << bst.find(10)->key << ", " << bst.find(10)->value << endl;
    cout << bst.find(15)->key << ", " << bst.find(15)->value << endl;
    cout << bst.find(400)->key << ", " << bst.find(400)->value << endl;
    cout << bst.size() << endl;
    bst.remove(10);
    bst.remove(15);
    bst.remove(5);
    bst.remove(400);
    bst.remove(20);
    //cout << bst.find(20)->key << ", " << bst.find(20)->value << endl;
    //cout << bst.find(5)->key << ", " << bst.find(15)->value << endl;
    //cout << bst.find(400)->key << ", " << bst.find(400)->value << endl;
    cout << bst.size() << endl;
    bst.insert(10,'c');
    cout << bst.find(10)->key << ", " << bst.find(10)->value << endl;
    return 0;
}