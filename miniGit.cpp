#include "miniGit.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<cstring>
#include <fstream> 
#include <filesystem>
namespace fs = std::filesystem;

miniGit::miniGit(){
    
    dub->commitNumber=0;
    dub->head=NULL;
    dub->next=NULL;
    dub->previous=NULL;


    
}
void miniGit::Repo()
{
fs::create_directory(".minigit");
}

void miniGit::move(string file, string dest,SLL* curr){

   ifstream infile(file);
   ofstream out(dest+curr->fileVersion);
   string line;
    while(getline(infile,line)){
        out<<line<<endl;
}
}

void miniGit::change(string file, string change){
    ifstream infile(".minigit/"+file);
    ofstream out(change);
    string line;
    while(getline(infile,line)){
        out<<line<<endl;
}
}
void miniGit::MakeSLL(string fName)
{
    DLL* now=dub;
    while(now->next!=NULL){
        now=now->next;
    }
    SLL* by=now->head;
    SLL * tmp= new SLL;
    tmp->fileName = fName;
	tmp->fileVersion = "00"+fName;
	tmp->next = NULL;
        
    if (now->head == NULL)
    {
        now->head = tmp;
        
    }
    else{
        while (by->next!= NULL)
        {
            by = by->next;
        }
        by->next = tmp; 
        tmp->next=NULL;
    }   
    
}

void miniGit::addFile()
{
    string file;
    
    DLL*now=dub;
    while(now->next!=NULL){
        now=now->next;
    }
    SLL* curr=now->head;
    int check=0;
    while(check==0){
        cout<<"enter a filename"<<endl;
        cin>>file;
        if (fs::exists(file)){
            check=1;        
        }
        else{
            cout<<"file does not exist, try another file."<<endl;
        }
    }
    
    while (curr != NULL)
    {
        if(curr->fileName == file)
        {
            cout << "A file by the same name cannot be added twice."<<endl;
            return;
        }
        curr = curr->next;
    }
    
        MakeSLL(file);
        
    
    
}
void miniGit::deleteFile(){
    string file;
    cout<<"enter a file to delete:"<<endl;
    cin>>file;
    
       DLL* now=dub;
       while(now->next!=NULL){
           now=now->next;
       }
        SLL *prev;
        SLL * temp = now->head;

    if (temp != NULL && temp->fileName == file)
    {
        now->head = temp->next;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->fileName!=file)
        {
        prev = temp;
        temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "File Not Present"<<endl;
            return;
        }
        
        prev->next = temp->next;
        delete temp;
        
        }
    }

void miniGit::commit(int n){
    DLL* temp=dub;
    cout<<"comitting."<<endl;
    
    while(temp->commitNumber!=n){
            temp=temp->next;
    }
    if(temp->head==NULL){
        DLL* meow=new DLL;
        meow->commitNumber=n+1;
        temp->next=meow;
        meow->previous=temp;
        meow->head=NULL;
        meow->next=NULL;
        cout<<"new version: "<<meow->commitNumber<<endl;
        return;
    }
    SLL* curr;
    ifstream infile;
    ifstream gitfile;
    curr=temp->head;
    while(curr!=NULL){
        if(!fs::exists(".minigit/"+curr->fileVersion)){
            move(curr->fileName,".minigit/",curr);
            cout<<"ha"<<endl;

        }
        else{
            ifstream infile;
            ifstream gitfile;
            string line;
            string sent;
            gitfile.open(".minigit/"+curr->fileVersion);
            infile.open(curr->fileName);
            while(getline(infile,line)&&getline(gitfile,sent)){
                    if(sent!=line){
                        cout<<"not same"<<endl;
                        string attend=curr->fileVersion;
                        int cap=curr->fileVersion.size()-curr->fileName.size();
                        string sub=attend.substr(0,cap);
                        int m= stoi(sub);
                        m++;
                        string all;
                        string neo=to_string(m);
                        if(neo.size()==1){
                            //fs::current_path(".minigit/");
                            all="0"+ neo+curr->fileName;
                            string old=curr->fileVersion;
                            curr->fileVersion=all;
                            move(curr->fileName,".minigit/",curr);
                            //fs::rename(old,all);
                        // fs::current_path("..");
                        }
                        else{
                        // fs::current_path(".minigit/");
                            all=neo+curr->fileName;
                            string old=curr->fileVersion;
                            curr->fileVersion=all;
                            move(curr->fileName,".minigit/",curr);
                            //fs::rename(old, all);
                            //fs::current_path("..");
                        }
                        break;
                    }
    
                        //change(curr->fileName,".minigit/",curr);
                    }
                }
            curr=curr->next;
        }
    SLL* v0=temp->head;

    DLL* pow=new DLL;
    pow->commitNumber=n+1;
    temp->next=pow;
    pow->next=NULL;
    pow->previous=temp;
    SLL* v1=temp->head;
    
    SLL* b=new SLL;
    
    pow->head=b;

    b->fileName=v1->fileName;
    b->fileVersion=v1->fileVersion;
    v1=v1->next;
    
    while(v1!=NULL){
        SLL* v2=new SLL;
        v2->fileName=v1->fileName;
        v2->fileVersion=v1->fileVersion;
        b->next=v2;
        b=b->next;
        v1=v1->next;
    }
    cout<<"new version: "<<pow->commitNumber<<endl;
    


    

}

void miniGit::checkout(int num){
    DLL* temp=dub;
    cout<<"Checking out"<<endl;
    while(temp->next!=NULL&&temp->commitNumber!=num)
    {
            temp=temp->next;
    }
    cout<<temp->commitNumber<<endl;
    SLL *single = temp->head;
    while (single != NULL)
    {
        cout<<single->fileName<<"||"<<single->fileVersion<<endl;
        if (fs::exists(single->fileName))
        {
            fs::remove(single->fileName);
            change(single->fileVersion,single->fileName);
            
        }
        else
        {
            change(single->fileVersion,single->fileName);
        }

        single = single->next;    
   
    }

    
}
void miniGit::print(){
    cout<<endl;
    cout<<"print"<<endl;
    SLL* temp= dub->head;
    DLL* pow=dub;
    while(pow!=NULL){
        temp=pow->head;
        cout<<pow->commitNumber<<endl;
        while(temp!=NULL){
        cout<<temp->fileName<<"||"<<temp->fileVersion<<endl;
        temp=temp->next;
        }
    cout<<endl<<endl;
    cout<<"New double node"<<endl;
    
    pow=pow->next;
    }
}

void miniGit::start(){
    char option;
    fs::create_directory(".minigit");
    int opt=1;
    int com=0;
    int point=0;
    cout<<"A"<<endl;
    while(option!='6'){
        opt=0;
        cout<<"--------MENU--------"<<endl;
        cout<<"Choose an action."<<endl;
        cout<<"(1)Add File"<<endl;
        cout<<"(2)Remove File"<<endl;
        cout<<"(3)Commit"<<endl;
        cout<<"(4)Checkout"<<endl;
        cout<<"(5)Print"<<endl;
        cout<<"(6)Quit"<<endl;
        cin>>option;
        
        switch(option){
            case '1':
                option=0;
                addFile();
                
                break;
            case '2':
                option=0;
                deleteFile();
                break;

            case '3':
                option=0;
                commit(com);
                com++;
                break;

            case '4':
                option=0;
                cout<<"Enter the commit version you want"<<endl;
                cin>>point;
                if(point>com){
                    cout<<"This Commit Version Does Not Exist"<<endl;
                }
                else{
                    checkout(point);
                }
                break;
            case '5':
                option=0;
                print();
                break;
            case '6':
                break;
            default:
                cout<<"invalid option"<<endl;
                break;

        }

    }
    
}