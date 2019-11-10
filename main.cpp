#include"BST.h"
#include<iostream>

using namespace std;

int main() {

    BinarySearchTree<int,char> bst;
    //cout << bst.empty() << endl;

    cout << bst.size() << endl;

    try {
        //bst.search(10);
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
    cout << bst.search(10)->returnKey() << ", " << bst.search(10)->returnValue() << endl;
    cout << bst.search(15)->returnKey() << ", " << bst.search(15)->returnValue() << endl;
    cout << bst.search(400)->returnKey() << ", " << bst.search(400)->returnValue() << endl;
    cout << bst.size() << endl;
    bst.remove(10);
    cout << bst.search(20)->returnKey() << ", " << bst.search(20)->returnValue() << endl;
    cout << bst.search(15)->returnKey() << ", " << bst.search(15)->returnValue() << endl;
    cout << bst.search(400)->returnKey() << ", " << bst.search(400)->returnValue() << endl;
    cout << bst.size() << endl;
    return 0;
}