#ifndef BST_h
#define BST_h

#include "TNode.h"
#include <queue>

using namespace std;


template <class T>
class BST {
private:
    TNode<T>* root;
    void printTree(TNode<T>* aux, int level);
    int children(TNode<T>* aux);
    void preOrder(TNode<T>* aux);
    void inOrder(TNode<T>* aux);
    void postOrder(TNode<T>* aux);
    void levelByLevel(TNode<T>* aux);
    int height(TNode<T>* node);
    bool displayAncestors(TNode<T>* node, T data);
    int getLevel(TNode<T>* node, T data, int level);
    
public:
    BST();
    void insert(T data);
    bool find(T data);
    bool remove(T data);
    void visit(int order);
    void print();
    bool isEmpty();
    int height();
    void ancestors(T data);
    int whatLevelAmI(T data);
    
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
void BST<T>::insert(T data) {
    if (isEmpty()) {
        root = new TNode<T>(data);
    } else {
        TNode<T>* aux = root;
        while (aux != nullptr) {
            if (data < aux->data) {
                if (aux->left == nullptr) {
                    aux->left = new TNode<T>(data);
                    return;
                } else {
                    aux = aux->left;
                }
            } else {
                if (aux->right == nullptr) {
                    aux->right = new TNode<T>(data);
                    return;
                } else {
                    aux = aux->right;
                }
            }
        }
    }
}

template <class T>
bool BST<T>::find(T data) {
    TNode<T>* aux = root;
    while (aux != nullptr) {
        if (aux->data == data) {
            return true;
        } else if (data < aux->data) {
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }
    return false;
}

template <class T>
bool BST<T>::remove(T data) {
    TNode<T>* parent = nullptr;
    TNode<T>* aux = root;
    while (aux != nullptr) {
        if (aux->data == data) {
            if (children(aux) == 0) {
                if (parent == nullptr) {
                    root = nullptr;
                } else if (parent->left == aux) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
                delete aux;
            } else if (children(aux) == 1) {
                TNode<T>* temp;
                if (aux->left != nullptr) {
                    temp = aux->left;
                } else {
                    temp = aux->right;
                }
                if (parent == nullptr) {
                    root = temp;
                } else if (parent->left == aux) {
                    parent->left = temp;
                } else {
                    parent->right = temp;
                }
                delete aux;
            } else {
                TNode<T>* temp = aux->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                T tempData = temp->data;
                remove(tempData);
                aux->data = tempData;
            }
            return true;
        } else if (data < aux->data) {
            parent = aux;
            aux = aux->left;
        } else {
            parent = aux;
            aux = aux->right;
        }
    }
    return false;
}

template<class T>
int BST<T>::children(TNode<T>* aux) {
    int count = 0;
    if (aux->left != nullptr) count++;
    if (aux->right != nullptr) count++;
    return count;
}

template<class T>
void BST<T>::preOrder(TNode<T>* aux) {
    if (aux != nullptr) {
        cout << aux->data << " ";
        preOrder(aux->left);
        preOrder(aux->right);
    }
}

template<class T>
void BST<T>::inOrder(TNode<T>* aux) {
    if (aux != nullptr) {
        inOrder(aux->left);
        cout << aux->data << " ";
        inOrder(aux->right);
    }
}

template<class T>
void BST<T>::postOrder(TNode<T>* aux) {
    if (aux != nullptr) {
        postOrder(aux->left);
        postOrder(aux->right);
        cout << aux->data << " ";
    }
}

template<class T>
void BST<T>::levelByLevel(TNode<T>* aux) {
    queue<TNode<T>*> q;
    q.push(aux);
    while (!q.empty()) {
        TNode<T>* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != nullptr) q.push(temp->left);
        if (temp->right != nullptr) q.push(temp->right);
    }
}

template<class T>
void BST<T>::visit(int order) {
    switch(order) {
        case 1:
            preOrder(root);
            break;
        case 2:
            inOrder(root);
            break;
        case 3:
            postOrder(root);
            break;
        case 4:
            levelByLevel(root);
            break;
        default:
            break;
    }
}

template<class T>
void BST<T>::printTree(TNode<T>* aux, int level) {
    if (aux != nullptr) {
        printTree(aux->right, level+1);
        for (int i=0; i<level; i++) cout << "   ";
        cout << aux->data << endl;
        printTree(aux->left, level+1);
    }
}

template<class T>
void BST<T>::print() {
    printTree(root, 0);
}

template<class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

template <class T>
int BST<T>::height() {
    return height(root);
}

template <class T>
int BST<T>::height(TNode<T>* node) {
    if (node == nullptr) {
        return -1;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return 1 + max(leftHeight, rightHeight);
    }
}

template <class T>
void BST<T>::ancestors(T data) {
    displayAncestors(root, data);
}

template <class T>
bool BST<T>::displayAncestors(TNode<T>* node, T data) {
    if (node == nullptr) {
        return false;
    }
    
    if (node->data == data) {
        return true;
    }
    
    if (displayAncestors(node->left, data) || displayAncestors(node->right, data)) {
        cout << node->data << " ";
        return true;
    }
    
    return false;
}

template <class T>
int BST<T>::whatLevelAmI(T data) {
    return getLevel(root, data, 0);
}

template <class T>
int BST<T>::getLevel(TNode<T>* node, T data, int level) {
    if (node == nullptr) {
        return -1;
    }
    
    if (node->data == data) {
        return level;
    }
    
    int leftLevel = getLevel(node->left, data, level + 1);
    if (leftLevel != -1) {
        return leftLevel;
    }
    
    int rightLevel = getLevel(node->right, data, level + 1);
    if (rightLevel != -1) {
        return rightLevel;
    }
    
    return -1;
}




#endif
