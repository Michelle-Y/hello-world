//Ziyang Yang
//03/09/2016
//TA:Amber Womack
//Assignment7
#include "MovieTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;



int main()
{
    MovieTree MT;

    int ranking;
    string title;
    int year;
    int quantity;
    ifstream inFile;
    inFile.open("Assignment6Movies.txt");
    string allinfo;
    while(getline(inFile,allinfo)){

        stringstream ss(allinfo);
        getline(ss,allinfo,',');
        //cout<<allinfo<<endl;
        istringstream(allinfo)>>ranking;
        //cout<<ranking<<endl;
        getline(ss,allinfo,',');
        title=allinfo;
        //cout<<title<<endl;
        getline(ss,allinfo,',');
        istringstream(allinfo)>>year;
        //cout<<year<<endl;
        //cout<<allinfo<<endl;
        getline(ss,allinfo,',');
        //cout<<allinfo<<endl;
        istringstream(allinfo)>>quantity;
        //cout<<quantity<<endl;
        //cout<<ranking<<title<<year<<quantity<<endl;
        MT.addMovieNode(ranking,title,year,quantity);

    }

    bool condition=true;
    while(condition==true){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Find a movie"<<endl;
        cout<<"2. Rent a movie"<<endl;
        cout<<"3. Print the inventory"<<endl;
        cout<<"4. Delete a movie"<<endl;
        cout<<"5. Count the movies"<<endl;
        cout<<"6. Return a movie"<<endl;
        cout<<"7. Movie Details"<<endl;
        cout<<"8. History"<<endl;
        cout<<"9. Quit"<<endl;
        string selection;
        getline(cin,selection);
        if(selection=="1"){
            string FM;
            cout<<"Enter title:"<<endl;
            getline(cin,FM);
            MT.findMovie(FM);

        }else if(selection=="2"){
            string RN;
            cout<<"Enter title:"<<endl;
            getline(cin,RN);
            MT.rentMovie(RN);
        }else if(selection=="3"){
            MT.printMovieInventory();
        }else if(selection=="4"){
            string DM;
            cout<<"Enter title:"<<endl;
            getline(cin,DM);
            MT.deleteMovieNode(DM);
        }else if(selection=="5"){
            cout<<"Tree contains: "<<MT.countMovieNodes()<<" movies."<<endl;
        }
        else if(selection=="6"){
            string name;
            cout<<"Enter title:"<<endl;
            getline(cin,name);
            MT.returnMovie(name);
        }
        else if(selection=="7")
        {
            string ti;
            cout<<"Enter title:"<<endl;
            getline(cin, ti);
            MT.ShowMovies(ti);
        }
        else if(selection=="8")
        {
            //MT.CompareTime();
            ifstream mywFile;
            mywFile.open("Historyfile.txt");
            string line;
            if (mywFile.is_open())
            {
                while (getline(mywFile,line) )
                {
                    cout << line << endl;
                }
                mywFile.close();
            }
        }
        else if(selection=="9"){
            condition=false;
            cout<<"Goodbye!"<<endl;
            fstream log;
            log.open ("Historyfile.txt", std::fstream::in | std::fstream::out | std::fstream::app);
            log<<"===================="<<endl;
            //MT.DeleteAll();
        }
    }
    //cout << "Hello world!" << endl;
    return 0;
}
