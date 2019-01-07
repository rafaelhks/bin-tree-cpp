#include "Tree.h"
#include <iostream>
#include <vector>

Tree::Tree()
{
    this->root = nullptr;
}

Tree::~Tree()
{
    delete(this);
}

Node* Tree::getRoot(){
    return this->root;
}

//vector<Node*>* Tree::getNodes(){
//    return &nodes;
//}

//void Tree::balanceamento(){
//    Node* atual = this->Root;
//    while(atual->getBalanco()>1){
//        atual = atual->getFilhoDir();
//    }
//    while(atual->getBalanco()<1){
//        atual = atual->getFilhoEsq();
//    }
//}

void Tree::insertRoot(Node* n){
    this->root = n;
    cout<<"     - Root: "<<n->getValue()<<endl;
}
