#pragma once
#include <iostream>
#include "Sort.hpp"
using namespace std;

template <class T>
class BinaryTree {
private:
    struct node {
        T data;
        node* left = nullptr;
        node* right = nullptr;
    };
    node* tree = nullptr;
    int count = 0;
    int (*cmp)(T, T);
private:
    void deconstructer(node* delet) {
        if (delet != nullptr) {
            deconstructer(delet->left);
            deconstructer(delet->right);
            delete delet;
        }
    }

    void inserter(node* tmp, T item) {
        node* temp = tmp;
        if (this->cmp(temp->data, item)!=0 && this->cmp(item, temp->data)!=0) {
            this->count--;
            return;
        }
        else if (this->cmp(temp->data, item)) {
            if (temp->left != nullptr)
                inserter(temp->left, item);
            else {
                temp->left = new node;
                temp->left->data = item;
                temp->left->left = nullptr;
                temp->left->right = nullptr;
            }
        }
        else if (this->cmp(item, temp->data)) {
            if (temp->right != nullptr)
                inserter(temp->right, item);
            else {
                temp->right = new node;
                temp->right->data = item;
                temp->right->left = nullptr;
                temp->right->right = nullptr;
            }
        }
    }

    node* searcher(T item, node* tmp) {
        node* temp = tmp;
        if (temp != nullptr) {
            if (!this->cmp(tmp->data, item) && !this->cmp(item, tmp->data))
                return temp;
            else if (this->cmp(temp->data, item))
                return searcher(item, temp->left);
            else
                return searcher(item, temp->right);
        }
        else
            return nullptr;
    }

    void printer(node* temp) {
        node* tmp = temp;
        if (tmp != nullptr) {
            if (tmp->left)
                printer(tmp->left);
            cout << tmp->data << " ";
            if (tmp->right)
                printer(tmp->right);
        }
        else
            return;
    }

    node* deleter(T item, node* branch) {
        if (!branch) {
            return nullptr;
        }
        if (this->cmp(branch->data, item)) {
            branch->left = deleter(item, branch->left);
        }
        else if (this->cmp(item, branch->data)) {
            branch->right = deleter(item, branch->right);
        }

        else {
            if (branch->left == nullptr && branch->right == nullptr) { 
                delete branch;
                branch = nullptr;
                return branch;
            }
            else if (branch->left == nullptr &&  branch->right != nullptr) { 
                node* tmp = branch;
                branch = branch->right;
                delete tmp;
                return branch;
            }
            else if (branch->right == nullptr && branch->left != nullptr) {
                node* tmp = branch;
                branch = branch->left;
                delete tmp;
                return branch;
            }
            else {
                node* tmp = min();                            
                branch->data = tmp->data;
                branch->right = deleter(tmp->data, branch->right);
            }
        }
        return branch;
    }

    /*ArraySequence<T>* LKP_help(node* n, ArraySequence<T>* arr) { ///////////////////////////////////////////////
        node* tmp = n; // KLP
        if (tmp) {
            LKP_help(n->left, arr);
            arr->Append(n->data);
            LKP_help(n->right, arr);
        }
        return arr;
    }*/

    bool sub_(node* tmp, node* tmp_) {
        if (tmp_ == nullptr)
            return 1;
        return (!this->cmp(tmp->data, tmp_->data) && !this->cmp(tmp_->data, tmp->data)) &&
            sub_(tmp->left, tmp_->left) &&
            sub_(tmp->right, tmp_->right);
    }

public:
    BinaryTree(int (*cmp) (T, T)) {
        this->tree = nullptr;
        this->count = 0;
        this->cmp = cmp;
    };

    ~BinaryTree() {
        deconstructer(this->tree);
    };

    bool empty() {
        if (this->tree != nullptr)
            return 0;
        return 1;
    }

    /*T what_in_root() {
        return this->tree->data;
    }*/
   
    node* max() {
        node* max = this->tree;
        while (max->right) {
            max = max->right;
        }
        return max;
    }

    node* min() {
        node* min = this->tree;
        while (min->left) {
            min = min->left;
        }
        return min;
    }

   /* ArraySequence<T>* LKP() {
        ArraySequence<T>* cur = new  ArraySequence<T>(this->count);
        return LKP_help(this->root, cur);
    }*/

    void insert(T item) {
        this->count++;
        if (this->tree != nullptr)
            inserter(this->tree, item);
        else {
            this->tree = new node;
            this->tree->data = item;
            this->tree->right = nullptr;
            this->tree->left = nullptr;
        }
    }

    void clear() {
        deconstructer(this->tree);
        this->tree = nullptr;
        this->count = 0;
    }

    node* search(T item) {
        return searcher(item, this->tree);
    }

    void delete_(T item) {
        if (search(item)) {
            this->count--;
        }
        this->tree = deleter(item, this->tree);
    }

    int GetSize() {
        return this->count;
    }

    bool subtree(BinaryTree<T>* sub_tree) {
        if (empty()) {
            return 0;
        }
        if (sub_tree->empty()) {
            return 1;
        }
        node* tmp = sub_tree->search(sub_tree->data);
        if (!tmp)
            return 0;
        if (sub_(this->tree, tmp)) {
            return 1;
        }
        return 0;
    }

    void print() {
        printer(this->tree);
        cout << endl;
    }

    /*BST<T>* eject(node* cur) {
        BST<T>* new_tree = new BST<T>(this->cmp);
        return KLP_for_eject(cur, new_tree);
    }
    T what_in_node(node* cur) {
        return cur->data;
    }*/
    T what_in_node(node* cur) {
        return cur->data;
    }
};

/*int compare_int_for_BST(int a, int b) {
    if (a > b)
        return 1;
    return 0;
}*/
/*template <class T>
int cmp(T a, T b) {
    if (a > b) return 1;
    else return 0;
}*/