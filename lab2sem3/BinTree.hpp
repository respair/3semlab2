#pragma once
#include <iostream>
#include "Sort.hpp"
#include <stdlib.h>
using namespace std;

template <class T>
class BinaryTree {
private:
    struct node {
        node(T val) : data(val), height(1), left(nullptr), right(nullptr) {}
        T data;
        int height;
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

    node* inserter(node* p, T item) {
        if (!p)
            return new node(item);
        if (item < p->data)
            p->left = inserter(p->left, item);
        else
            p->right = inserter(p->right, item);
        return balance(p);
    }
    node* balance(node* p) {
        fixheight(p);

        if (balance_factor(p) == 2) {
            if (balance_factor(p->right) < 0)
                p->right = rotate_right(p->right);
            return rotate_left(p);
        }

        if (balance_factor(p) == -2) {
            if (balance_factor(p->left) > 0)
                p->left = rotate_left(p->left);
            return rotate_right(p);
        }

        return p;
    }
    int balance_factor(node*p) {
        return height(p->right) - height(p->left);
    }
    node* rotate_right(node* p) {
        //правый поворот вокруг р если разница между высотами равна +-2
        node* q = p->left; //изначально q левее p
        p->left = q->right;
        q->right = p;
        fixheight(p);
        fixheight(q);

        return q;
    }
    node* rotate_left(node* q) {
        node* p = q->right;
        q->right = p->left;
        p->left = q;
        fixheight(q);
        fixheight(p);

        return p;
    }
    void fixheight(node* p) {
        int h_left = height(p->left);        //!
        int h_right = height(p->right);

        p->height = (h_left > h_right ? h_left : h_right) + 1;
    }
    int height(node* p) {
        return p ? p->height : 0;
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
            else if (branch->left == nullptr && branch->right != nullptr) {
                node* tmp = branch;
                branch = branch->right;
                delete tmp;
                return balance(branch);
            }
            else if (branch->right == nullptr && branch->left != nullptr) {
                node* tmp = branch;
                branch = branch->left;
                delete tmp;
                return balance(branch);
            }
            else {
                 node* tmp = min();
                 branch->data = tmp->data;
                 branch->right = deleter(tmp->data, branch->right);
                /*node* q = branch->left;
                node* r = branch->right;

                branch->left = nullptr;
                branch->right = nullptr;
                delete branch;*/

               // if (r == nullptr) return q;

               /* node* min_ = min();
                min_->right = remove_min_el(r);
                min_->left = q;
                return balance(min_);*/
            }
        }
        return balance(branch);
    }
    node* remove_min_el(node* p) {
        if (p->left == nullptr)
            return p->right;
        p->left = remove_min_el(p->left);
        return balance(p);
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


    int bsheight(node* p) {
        int t;
        if (p == nullptr)
            return -1;
        else {
            t = p->height;
            return t;
        }
    }

   
    int max(int value1, int value2)
    {
        return ((value1 > value2) ? value1 : value2);
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

    node* Max() {
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
        //this->count++;
        if (this->tree != nullptr)
            this->tree = inserter(this->tree, item);
        else {
            this->tree = new node(item);
           // tree->height = 1;
           // this->tree->data = item;
           // this->tree->right = nullptr;
           // this->tree->left = nullptr;
            this->count++;
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
