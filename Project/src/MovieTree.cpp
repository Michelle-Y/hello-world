#include "MovieTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

MovieTree::MovieTree()
{
    //ctor
}

MovieTree::~MovieTree()
{
    //dtor
    DeleteAll(root);
}

void MovieTree::addMovieNode(int ranking,string title,int year,int quanity){

        MovieNode *tmp=root;
        MovieNode *node= new MovieNode;
        MovieNode *p=NULL;
        node->parent=NULL;
        node->leftChild=NULL;
        node->rightChild=NULL;
        node=new MovieNode(ranking, title, year, quanity);
        while(tmp!=NULL){
            p=tmp;
            if(node->title<tmp->title){
                tmp=tmp->leftChild;
            }else{
                tmp=tmp->rightChild;
            }
        }

        if(p==NULL){
            root=node;
        }else if(node->title<p->title){
            p->leftChild=node;
            node->parent=p;
        }else{
            p->rightChild=node;
            node->parent=p;
        }

}

void MovieTree::findMovie(string title){
    MovieNode *node=root;
    bool cond=false;
    while(node!=NULL && cond==false){
        if(node->title>title){
            node=node->leftChild;
        }else if(node->title<title){
            node=node->rightChild;
        }else{
            cout<<"Movie Info:"<< endl;
            cout<<"==========="<< endl;
            cout<<"Ranking:"<<node->ranking<<endl;
            cout<<"Title:"<<node->title<<endl;
            cout<<"Year:"<<node->year<<endl;
            cout<<"Quantity:"<<node->quantity<<endl;
            cond=true;
        }
    }
    if(cond==false){
        cout<<"Movie not found."<<endl;

    }
}

void MovieTree::rentMovie(string title){
    MovieNode *node=root;
    bool cond=false;
    while(node!=NULL && cond==false){
        if(node->title>title){
            node=node->leftChild;
        }else if(node->title<title){
            node=node->rightChild;
        }else{
            cond=true;
            if(node->quantity!=0){
                countMostTime(title);
                cout<<"Movie has been rented."<<endl;
                cout<<"Movie Info:"<<endl;
                cout<<"==========="<<endl;
                cout<<"Ranking:"<<node->ranking<<endl;
                cout<<"Title:"<<node->title<<endl;
                cout<<"Year:"<<node->year<<endl;
                node->quantity=node->quantity-1;
                cout<<"Quantity:"<<node->quantity<<endl;
                cout<<"Rent Time:"<<node->RentTime<<endl;
                //ofstream log("Historyfile.txt", ios_base::app | ios_base::out);
                fstream log;
                log.open ("Historyfile.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                log<<"Rent item: ";
                log.close();
                WriteHistory(node);
                if (node->quantity==0){
                    deleteMovieNode(title);
                }
                //If movie is out of stock
            }else{
                cout<<"Movie out of stock."<<endl;
            }
        }
    }
    if(cond==false){
        cout<<"Movie not found."<<endl;

    }
}

void MovieTree::countMostTime(string title)
{
    MovieNode *node=search(title);
    node->RentTime=node->RentTime+1;
}

void MovieTree::ShowMovies(string title)
{
    MovieNode *node=search(title);
    cout<<"Movie Info:"<<endl;
    cout<<"==========="<<endl;
    cout<<"Ranking:"<<node->ranking<<endl;
    cout<<"Title:"<<node->title<<endl;
    cout<<"Year:"<<node->year<<endl;
    cout<<"Rent Time:"<<node->RentTime<<endl;
}

//void MovieTree::CompareTime()
//{
//    MovieNode *node=root;
//    MovieNode *tmp_node=node;
//    CompareTime(tmp_node, node);
//    CompareTimeRight(tmp_node, node);
//    cout<<"Most Popular Movie: "<<tmp_node->title<<"  "<<"Rent Times:"<<tmp_node->RentTime<<endl;
//}
//
//void MovieTree::CompareTime(MovieNode *tmp_node, MovieNode *node)
//{
//    //cout<<"Enter MovieTree::CompareTime: "<<node->title<<"  "<<"Rent Times:"<<node->RentTime<<endl;
//
//    if(node->title=="Se7en")
//    {
//        cout<<"Se7en "<<node->title<<endl;
//        cout<<"Se7en "<<node->RentTime<<endl;
//    }
//    if(node->leftChild!=NULL)
//    {
//        node=node->leftChild;
//        if(tmp_node->RentTime<=node->RentTime)
//            tmp_node=node;
//        CompareTimeLeft(tmp_node, node);
//    }
//
//    if(node->rightChild!=NULL)
//    {
//        node=node->rightChild;
//        if(tmp_node->RentTime<=node->RentTime)
//            tmp_node=node;
//        CompareTimeRight(tmp_node, node);
//    }
//}






void MovieTree::returnMovie(string title)
{
    MovieNode *node=root;
    bool cond=false;
    while(node!=NULL && cond==false)
    {
        if(node->title>title)
            node=node->leftChild;
        else if(node->title<title)
            node=node->rightChild;
        else
        {
            cond=true;
            //if(search(title)!=NULL){
            if(node->quantity!=0)
            {
                cout<<"Movie has been returned."<<endl;
                cout<<"Movie Info:"<<endl;
                cout<<"==========="<<endl;
                cout<<"Ranking:"<<node->ranking<<endl;
                cout<<"Title:"<<node->title<<endl;
                cout<<"Year:"<<node->year<<endl;
                node->quantity=node->quantity+1;
                cout<<"Quantity:"<<node->quantity<<endl;
                //ofstream log("Historyfile.txt", ios_base::app | ios_base::out);
                fstream log;
                log.open ("Historyfile.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                log<<"Return item: ";
                log.close();
                WriteHistory(node);

            }
            //}
            //if quantity==0
//            if(search(title)==NULL)
//            {
//                //MovieNode *temp=root;
//                MovieNode *n=new MovieNode;
//                //bool cont=false;
//                n->parent=NULL;
//                n->leftChild=NULL;
//                n->rightChild=NULL;
//                n->title=title;
//                while(node!=NULL)
//                {
//                    n->parent=node;
//                    if(n->title<node->title)
//                        node=node->leftChild;
//                    else
//                    {
//                        node=node->rightChild;
//                    }
//                }
//                if(n->parent==NULL)
//                    root=n;
//                else if(n->title<n->parent->title)
//                {
//                    n->parent->leftChild=n;
//                }
//                else{
//                    n->parent->rightChild=n;
//                }
//            }

        }
    }

}



void MovieTree::printMovieInventory(){

        MovieNode *node=root;
        printMovieInventory(node);



}

void MovieTree::WriteHistory(MovieNode *Writenode)
{
    //ofstream log("Historyfile.txt", ios_base::app | ios_base::out);
    fstream log;
    log.open ("Historyfile.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    log<<"Ranking:"<<Writenode->ranking<<"  "<<Writenode->title<<"  "<<Writenode->year<<"  "<<"Rent Time:"<<Writenode->RentTime<<endl;
    log.close();

}

void MovieTree::printMovieInventory(MovieNode *node)
{
            //
            if(node->leftChild!=NULL){
                printMovieInventory(node->leftChild);
        }
        cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
        if(node->rightChild!=NULL){
            printMovieInventory(node->rightChild);
        }
}

MovieNode* MovieTree::treeMinimum(MovieNode *node){
    MovieNode *Min=node;
    while(Min->leftChild!=NULL){
        Min=Min->leftChild;
    }
    return Min;
}

MovieNode* MovieTree::search(string title)
{
    MovieNode *node=root;
    while (node!=NULL)
    {
        if (node->title > title)
            node=node->leftChild;
        else if (node->title < title)
            node=node->rightChild;
        else
            return node;
    }
    return NULL;
}
void MovieTree::deleteMovieNode(string title)
{
    if (search(title)==NULL)
        cout<<"Movie not found."<<endl;
    else
    {
        MovieNode *node=search(title);
        if (node->leftChild==NULL && node->rightChild==NULL)
        {
            if (node->parent->leftChild->title==title)
                node->parent->leftChild=NULL;
            else
                node->parent->rightChild=NULL;
        }
        else if (node->leftChild==NULL && node->rightChild!=NULL)
        {
            if (node->parent->leftChild->title==title)
                node->parent->leftChild=node->rightChild;
            else
                node->parent->rightChild=node->rightChild;
            node->rightChild->parent=node->parent;
        }
        else if (node->leftChild!=NULL && node->rightChild==NULL)
        {
            if (node->parent->leftChild->title==title)
                node->parent->leftChild=node->leftChild;
            else
                node->parent->rightChild=node->leftChild;
            node->leftChild->parent=node->parent;
        }
        else if (node->leftChild!=NULL && node->rightChild!=NULL)
        {
            MovieNode *min=treeMinimum(node->rightChild);
            if (node->parent->leftChild->title==title)
            {
                if (min==node->rightChild)
                {
                    node->parent->leftChild=min;
                    min->parent=node->parent;
                    min->leftChild=node->leftChild;
                    node->leftChild->parent=min;
                }
                else
                {
                    min->parent->leftChild=min->rightChild;
                    min->rightChild->parent=min->parent;
                    min->parent=node->parent;
                    node->parent->leftChild=min;
                    min->leftChild=node->leftChild;
                    node->leftChild->parent=min;
                    min->rightChild=node->rightChild;
                    node->rightChild->parent=min;
                }
            }
            else
            {
                if (min==node->rightChild)
                {
                    node->parent->rightChild=min;
                    min->parent=node->parent;
                    min->leftChild=node->leftChild;
                    node->leftChild->parent=min;
                }
                else
                {
                    min->parent->leftChild=min->rightChild;
                    min->rightChild->parent=min->parent;
                    min->parent=node->parent;
                    node->parent->rightChild=min;
                    min->leftChild=node->leftChild;
                    node->leftChild->parent=min;
                    min->rightChild=node->rightChild;
                    node->rightChild->parent=min;
                }
            }
        }
        delete node;
    }
}

void MovieTree::countMovieNodes(MovieNode* node, int *c)
{
    if (node->leftChild!=NULL)
        countMovieNodes(node->leftChild, c);
    *c=*c+1;
    if (node->rightChild!=NULL)
        countMovieNodes(node->rightChild, c);
}

int MovieTree::countMovieNodes()
{
    int *c=new int;
    countMovieNodes(root, c);
    return *c;
}

void MovieTree::DeleteAll(MovieNode* node)
{
    if (node->leftChild!=NULL)
        DeleteAll(node->leftChild);
    if (node->rightChild!=NULL)
        DeleteAll(node->rightChild);
    cout<<"Deleting: "<<node->title<<endl;
}

