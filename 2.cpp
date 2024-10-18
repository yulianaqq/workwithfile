#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Statystyka {
    int symbol;
    int line;
    int vowelletter;
    int consonantletter;
    int number;
};

bool isVowel(char ch) {
    char vowels[] = "AEIOUaeiou";
    for (char vowel : vowels) {
        if (ch == vowel) {
            return true;
        }
    }
    return false;
}

bool isConsonant(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isNumber(char ch) {
    return ch >= '0' && ch <= '9';
}

int main() {
    ifstream file1("1.txt");
    if (!file1) {
        cout << "File 1.txt does not exist." << endl;
        return 1;
    }

    ofstream file2("2.txt");
    if (!file2) {
        cout << "File 2.txt could not be created." << endl;
        return 1;
    }

    Statystyka stats = {0, 0, 0, 0, 0};
    string line;

    do {
        if (getline(file1, line)) {
            stats.line++;
            for (char ch : line) {
                if (isConsonant(ch)) {
                    stats.symbol++;
                    if (isVowel(ch)) {
                        stats.vowelletter++;
                    } else {
                        stats.consonantletter++;
                    }
                } else if (isNumber(ch)) {
                    stats.number++;
                    stats.symbol++;
                } else if (ch != ' ' && ch != '\t' && ch != '\n') {
                    stats.symbol++;
                }
            }
        }
    } while (!line.empty());

    file2 << "Total Characters: " << stats.symbol << endl;
    file2 << "Total Lines: " << stats.line << endl;
    file2 << "Total Vowels: " << stats.vowelletter << endl;
    file2 << "Total Consonants: " << stats.consonantletter << endl;
    file2 << "Total Digits: " << stats.number << endl;

    file1.close();
    file2.close();

    cout << "Statistics written to file 2.txt." << endl;

    return 0;
}
