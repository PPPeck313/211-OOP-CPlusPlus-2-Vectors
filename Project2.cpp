#include "File.h"
#include "Image.h"
#include "Text.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
Due: Final Exam
Write a menu driven application that is going to use the hierarchy that you have written
for homework 8 and the functions that you have written for homework 9. You will keep
track of the collection of Files in a vector (File pointers, since File is an abstract class).
The menu should contain the following options:
1. Read from a File (Read descriptions of Files from "files.txt" creating appropriate
File object and putting it inside your vector. The file.txt will be provided)
2. Create an Image File (Creates a single Image File asking the user for its properties)
3. Create a Text File (Creates a single Text File asking the user for its properties)
4. Print All Files (You must use functions written for homework 9)
5. Print Image Files (You must use functions written for homework 9)
6. Print Text Files (You must use functions written for homework 9)
7. Delete a file by file name and type (Removes a file from a vector)
8. Quit (Terminate the program)
*/

void outputForwards(vector<File*> files, int index);
void outputChop(vector<File*> files);
//vector<File*> selectBackwards(vector<File*> files, int start, string extension);
vector<File*> selectChop(vector<File*> files, string extension);


int main() {
    vector<File*> files;
    ifstream inFile;
    string storeInFile;
    ofstream outfile;
    string option;
    string name;
    string type;
    int rows;
    int columns;
    int colorDepth;
    int characters;
    cout<<endl<<"Welcome to Project 2!"<<endl<<endl
        
        <<"     1) Read from a File"<<endl
        <<"     2) Create an Image File"<<endl
        <<"     3) Create a Text File"<<endl
        <<"     4) Print All Files"<<endl
        <<"     5) Print Image Files"<<endl
        <<"     6) Print Text Files"<<endl
        <<"     7) Delete a File"<<endl
        <<"     8) Quit"<<endl<<endl
        
        <<"Please select an option from the menu above (1/2/3/4/5/6/7/8): ";
    cin>>option;
        
    while (option != "8") {
        while (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7" && option != "8") {
			cout<<"Please select an option from the menu above (1/2/3/4/5/6/7/8): ";
			cin>>option;
        }
        
        cout<<endl;
        
        if (option == "1") {//Read from a File
            cout<<"Enter file name: ";
            cin>>storeInFile;
            inFile.open(storeInFile);
            if (!inFile.is_open()) {
                cerr<<"File failed to open!"<<endl;
                return 0;
            }
            
            getline(inFile, storeInFile);
            
            while(!inFile.eof()) {
                if (storeInFile == "gif") {
                    getline(inFile, storeInFile);
                    name = storeInFile;
                    getline(inFile, storeInFile, ' ');
                    rows = stoi(storeInFile);
                    getline(inFile, storeInFile, 'x');
                    getline(inFile, storeInFile, ' ');
                    getline(inFile, storeInFile);    
                    columns = stoi(storeInFile);
                    getline(inFile, storeInFile);
                    colorDepth = stoi(storeInFile);
                    File* f = new Image(name, rows, columns, colorDepth);
                    files.push_back(f);           
                }
                if (storeInFile == "txt") {
                    getline(inFile, storeInFile);
                    name = storeInFile;
                    getline(inFile, storeInFile);
                    characters = stoi(storeInFile);
                    File* f = new Text(name, characters);
                    files.push_back(f);                
                }
                getline(inFile, storeInFile);                             
            }
        }
        
        else if (option == "2") {//Create an Image File
            cout<<"Creating new image file..."<<endl<<endl;
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter number of rows: ";
            cin>>rows;
            cout<<"Enter number of columns: ";
            cin>>columns;
            cout<<"Enter color depth: ";
            cin>>colorDepth;
            File* f = new Image(name, rows, columns, colorDepth);
            files.push_back(f);
        }
        
        else if (option == "3") {//Create a Text File
            cout<<"Creating new text file..."<<endl<<endl;
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter number of characters: ";
            cin>>characters;
            File* f = new Text(name, characters);
            files.push_back(f);
        }
        
        else if (option == "4") {//Print All Files
            outputChop(files);
        }
        
        else if (option == "5") {//Print Image Files
            outputChop(selectChop(files, ".gif"));
        }
        
        else if (option == "6") {//Print Text Files
            outputChop(selectChop(files, ".txt"));
        }
        
        else if (option == "7") {//Delete a File
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter file type: ";
            cin>>type;
            for (int i = 0; i < files.size(); i++) {
                if (files[i]->getName() == name && files[i]->getType() == type) {
                    files.erase(files.begin() + i);
                }
            }
        }
        
    cout<<endl<<"Operation completed!"<<endl
        <<"Returning to main menu..."<<endl<<endl
        
        <<"     1) Read from a File"<<endl
        <<"     2) Create an Image File"<<endl
        <<"     3) Create a Text File"<<endl
        <<"     4) Print All Files"<<endl
        <<"     5) Print Image Files"<<endl
        <<"     6) Print Text Files"<<endl
        <<"     7) Delete a File"<<endl
        <<"     8) Quit"<<endl<<endl
        
        <<"Please select an option from the menu above (1/2/3/4/5/6/7/8): ";
    cin>>option;
        
    }
}


void outputForwards(vector<File*> files, int index) {
    if (index != files.size()) {
        files[index]->output();
        outputForwards(files, index + 1);
    }
}

void outputChop(vector<File*> files) {
    if (files.size() != 0) {
        File* f = files[files.size() - 1];
        files.resize(files.size() - 1);
        outputChop(files);
        f->output();
    }
}

/*vector<File*> selectBackwards(vector<File*> files, int index, string extension) {
    if (index == files.size()) {
        vector<File*> v;
        return v;
    }
    selectForwards(files, start + 1, extension);
    if (files[index]->getType() == extension) {
        v.push_back(files[index]);
    }
}*/

vector<File*> selectChop(vector<File*> files, string extension) {
    if (files.size() == 0) {
        vector<File*> v;
        return v;
    }
    File* f = files[files.size() - 1];
    files.resize(files.size() - 1);
    vector<File*> v = selectChop(files, extension);
    if (f->getType() == extension) {
        v.push_back(f);
        return v;
    }
    return v;
}