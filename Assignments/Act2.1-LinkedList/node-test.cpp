#include <iostream>
using namespace std;
#include "node.hpp"

int main(){
    Node<int>* node1;
    Node<int>* node2;

    node1 = new Node<int>(5);
    node2 = new Node<int>(10, node1);
    cout << &node1 << endl;
    cout << node1 << endl;
    cout << node1 -> data << endl;
    cout << &node2 << endl;
    cout << node2 << endl;
    cout << node2 -> data << endl;
    cout << node2 -> next << endl;

}