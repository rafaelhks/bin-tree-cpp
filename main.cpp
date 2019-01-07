#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Node.h"
#include "Tree.h"
#include<string>
#include <iomanip>
using namespace std;

Tree* tree = new Tree();

bool readFile(string Path){
    fstream file;
    string line, readNode;
    file.open(Path);

    if(file.is_open()){
        getline(file, line); //Primeira linha

        //tratamento dos dados da primeira linha
        istringstream streamLine(line);

        while(!streamLine.eof()){
            getline(streamLine, readNode, ',');
            cout<<"\nRead node: "<<readNode<<endl;

            //insertNode o ultimo Node lido
            if(tree->getRoot()){
                tree->getRoot()->insertNode(new Node(stoi(readNode)));
            }else{
                tree->insertRoot(new Node(stoi(readNode)));
            }
            //cout<<"\nBalanco da root: "<<Tree->getRoot()->getBalanco()<<endl;
        }
    }else{
        cout<<"Could not open the file tree.txt"<<endl;
        file.close();
        return false;
    }

    file.close();
    return true;
}

void buildTreeFromArray(int nodes[]){
    tree = new Tree();
    tree->insertRoot(new Node(nodes[0]));
    for(int i=1; i<sizeof(nodes); i++){
        tree->getRoot()->insertNode(new Node(nodes[i]));
    }
}

void removeNode(int target){
    Node* tg = tree->getRoot()->removeNode(target);
    if(tg!=nullptr){
        tg=nullptr;
    }
}

void saveFile(string Path){
    ofstream arquivo;
    arquivo.open(Path);

    arquivo.close();
}

void printMenu(){
    char c;
    int v;
    Node* n;
    cout<<"     Menu    "<<endl;
    cout<<"\n1 - Insert New Node"<<endl;
    cout<<"2 - Remove Node"<<endl;
    cout<<"3 - Print Tree"<<endl;
    cout<<"e - Exit"<<endl<<endl;
    cout<<"Insert command: ";
    cin>>c;
    switch(c){
        case '1':
            cout<<"New Node value (int): ";
            cin>>v;
            cout<<"LOG: "<<endl;
            n = new Node(v);
            tree->getRoot()->insertNode(n);
            break;
        case '2':
            cout<<"Node to be removed (value int): ";
            cin>>v;
            cout<<"LOG: ";
            tree->getRoot()->removeNode(v);
            break;
        case '3':
            cout<<"Root ";
            tree->getRoot()->printSubTree();
            break;
        default:
            cout<<"\n***Invalid command***"<<endl;
    }
    if(c!='e') printMenu();
    else return;
}

int main()
{
    cout << "Binary Tree C++" << endl;
    //buildTreeFromArray(new int[4]{0,1,2,30}); para testes rápidos
    if(readFile("tree.txt")){
        removeNode(30);
        printMenu();
    }
    return 0;
}
