#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream file;
    vector<string> arrayOfTokens;
    int curPos = 0;//current posisition
    int edPos = 0;//end position
    file.open("input1.txt", file.binary);
    if (file.eof()) return -1;
    string line;
    //Extract file.
    getline(file, line);
    //Close file:
    file.close();
    line += '\n';
    cout << line << endl;
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
    //cout << "\033[32m" << "This is green" << "\033[m" << " back to normal" << endl;
}