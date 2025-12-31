
void move(string file, string dest,SLL* curr);
    this is my copy function. I read current file and copy it to minigit with ofstream out(".minigit/"+fileversion)
    
    void change(string file, string change);
        same as move function but I do the reverse. I read from minigit and copy it to directory
        this is only used for checkout


void MakeSLL(string fName);

This function was created to make a node of the added file and attach it to the current resposirtory linked list
it really doesnt have anything special




void miniGit::addFile()
    first I looped untile our current commitnumber ( double linked list)
    second I made sure if the file given is in directory
    then i called the makesll function mentioned above
  



void miniGit::removeFile(string filename)
This function was created to delete nodes from the linked list







void miniGit::commit(int n)
n is the current commit number. I traverse the dll to the one withe same commit number.
I also check edge cases where given list is null so I would stop the list right there and make 
the new commit without having to read files which would result in error

Then I read and compared all files with getline, as soon as there is a difference I stop and call the move function
before calling the move function I adjust the file version with this

                        string attend=curr->fileVersion;
                        int cap=curr->fileVersion.size()-curr->fileName.size();
                        string sub=attend.substr(0,cap);
                        int m= stoi(sub);
                        m++;
                        string all;
                        string neo=to_string(m);
Basically I have the version in the beginning so I make a new substr convert it to int increment then return it to string

lastly,
I copy the linked list to new linked list





void miniGit::checkout(int num)

first I looped untile our chosen current commitnumber ( double linked list)
then I remove the files in directory and then copy files from minigit to directory;
also I print the linked list to know what version I checkout()


void start();
this is the menu. it calls all functions needed. it is what I put in drivere so it looks clean


void print();
prints linked list for every commit