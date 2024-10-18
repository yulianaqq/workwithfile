#include <iostream>
#include <fstream>
#include <string>

#define E endl
using namespace std;

int main() {
    ifstream file1("1.txt");
    if (!file1) {
        cout << "File 1.txt does not exist" << E;
        return 1;
    }

    ifstream file2("2.txt");
    if (!file2) {
        cout << "File 2.txt does not exist" << E;
        return 1;
    }

    string line1;
    string line2;
    int numberofline = 1;
    bool filecompare = true;

    while (true) {
        bool readfile1 = getline(file1, line1) ? true : false;
        bool readfile2 = getline(file2, line2) ? true : false;

        if (!readfile1 && !readfile2) {
         
            break;
        } else if (readfile1 && readfile2) {
           
            if (line1 != line2) {
                filecompare = false;
                cout << "Line: " << numberofline << " does not match" << E;
                cout << "1.txt: " << line1 << E;
                cout << "2.txt: " << line2 << E;
            }
        } else if (readfile1) {
          
            filecompare = false;
            cout << "Line: " << numberofline << " is only in 1.txt: " << line1 << E;
        } else if (readfile2) {
           
            filecompare = false;
            cout << "Line: " << numberofline << " is only in 2.txt: " << line2 << E;
        }
        numberofline++;
    }

    if (filecompare) {
        cout << "All lines match" << E;
    }

    file1.close();
    file2.close();

    return 0;
}
