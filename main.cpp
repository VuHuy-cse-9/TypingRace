#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

static vector<string> arrayOfTokens;
static bool isAssign = false;


void process();
void extractToken();
void print();
void tokenProcessor(string& token);
bool isEndOfFile();

int main() {
    ifstream file;
    string line;
    int curPos = 0;//current posisition
    int edPos = 0;//end position
    file.open("input1.txt", file.binary);
    if (file.eof()) return -1;
    //Extract file.
    getline(file, line);
    //Close file:
    file.close();
    line += '\n';

    while (line[edPos] != '\n') {
        //Find the space or /0 using find, begins from current Pos then return value to edPos
        //find didn't find return npos = -1
        //substring from curPos to edPos - 1(Deliminating space)
        //current position = edPos + 1
        //last token's string doesn't has \0
        edPos = line.find(" ", curPos);
        if (edPos == -1) edPos = line.find('\n', curPos);
        if (edPos == -1) return 0;
        arrayOfTokens.push_back(line.substr(curPos, edPos - curPos));
        curPos = edPos + 1;
    }

    //process();

    //Compare
    //If don't match, replace that token to a new color;
    cout << "\033[32m" ;
    cout << "This is green" << "\033[m" << " back to normal" << endl;
}

void print(){
    system("clear");
    for (int i = 0; i < arrayOfTokens.size(); ++i) {
        cout << arrayOfTokens[i] << " ";
    }
    cout << endl;
}

void tokenProcessor(string& token) {

}

bool isEndOfFile() {
    return false;
}

void process(){
    int index = 0;
    while (/*!isEndOfFile()*/ ++index == 1) {
        //Print -> Process -> Check -> end 
        if (isAssign) {
            isAssign = false;
            arrayOfTokens[index].insert(0, "\033[32m");
        }
        print();
        tokenProcessor(arrayOfTokens[index]);
        
    }
}