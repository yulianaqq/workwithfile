#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("text.txt");
    if (!inputFile) {
        cout << "File text.txt does not exist." << endl;
        return 1;
    }

    string line;
    size_t maxLength = 0;

    for (; getline(inputFile, line); ) {
        maxLength = max(maxLength, line.length());
    }

    inputFile.close();

    cout << "The length of the longest line is: " << maxLength << " characters." << endl;

    return 0;
}
