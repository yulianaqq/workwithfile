#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "File input.txt does not exist." << endl;
        return 1;
    }

    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    ofstream outputFile("output.txt");
    if (!outputFile) {
        cout << "File output.txt could not be created." << endl;
        return 1;
    }

    for (size_t i = 0; i < lines.size() - 1; ++i) {
        outputFile << lines[i] << endl;
    }

    outputFile.close();

    cout << "Last line removed. Remaining lines written to output.txt." << endl;

    return 0;
}
