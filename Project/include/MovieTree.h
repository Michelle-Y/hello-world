#ifndef MOVIETREE_H
#define MOVIETREE_H
#include <string>
using namespace std;

struct MovieNode{
    int ranking;
    string title;
    int year;
    int quantity;
    int RentTime=0;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(int in_ranking, string in_title, int in_year, int in_quantity)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
        parent=NULL;
        leftChild=NULL;
        rightChild=NULL;
    }

};

class MovieTree
{
    public:

        MovieTree();
        ~MovieTree();
        void printMovieInventory();
        int countMovieNodes();
        void deleteMovieNode(string title);
        void addMovieNode(int ranking, string title, int releaseYear, int quantity);
        void findMovie(string title);
        void rentMovie(string title);
        void returnMovie(string title);
        void countMostTime(string title);
        void ShowMovies(string title);
        //void CompareTime();
        void WriteHistory(MovieNode *Writenode);



    protected:
    private:
        //void WriteHistory(MovieNode *Writenode);
        void DeleteAll(MovieNode * node); //use this for the post-order traversal deletion of the tree
        void printMovieInventory(MovieNode * node);
        void countMovieNodes(MovieNode *node, int *c);
        //void CompareTimeLeft(MovieNode *tmp_node, MovieNode *node);
        //void CompareTimeRight(MovieNode *tmp_node, MovieNode *node);
        MovieNode* search(string title);
        MovieNode* treeMinimum(MovieNode *node);
        MovieNode *root=NULL;

};

#endif // MOVIETREE_H
