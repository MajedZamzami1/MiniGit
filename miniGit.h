#ifndef MINIGIT_H
#define MINIGIT_H
#include<vector>
#include<iostream>
#include<fstream>
#include<filesystem>
using namespace std;

struct SLL
{
    std::string fileName;
    std::string fileVersion;
    SLL *next;
};
struct DLL
{
    int commitNumber;
    SLL *head;
    DLL *previous;
    DLL * next;
};



class miniGit
{
    public:
    miniGit();
    
    void start();

    void move(string file, string dest,SLL* curr);
    void change(string file, string change);
    
    void MakeSLL(string fName);
    
    void addFile();
    void deleteFile();
    void commit(int n);
    void checkout(int num);

    void print();
    void Repo();

    private:
    DLL* dub;
    SLL* s;
};


#endif