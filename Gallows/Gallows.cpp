#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime> 
using namespace std;

class Gallow {
public:
    int n, miss, win;
    char ch;
    int* mass;
    string s, ss = "", misses = "";
    Gallow() {
        n = 1 + rand() % 9;
        miss = 0;
        ifstream file("Words.txt");
        if (file.is_open()) {
            int num = 1;
            while (getline(file, s)) {
                if (num == n) {
                    break;
                }
                num++;
            }
            win = s.length();
        }
        else {
            cout << "ERROR: failed to open files" << endl;
        }
        Translate();
        s = ss;
        mass = new int[win];
        for (int i = 0; i < win; i++) {
            mass[i] = 0;
        }

    }
    void Translate() {
        for (auto a : s) {
            if (a == 'b') {
                ss += 'm';
            }
            else if (a == 'd') {
                ss += 'e';
            }
            else if (a == 'f') {
                ss += 't';
            }
            else if (a == 'c') {
                ss += 'o';
            }
            else if (a == 'a') {
                ss += 'r';
            }
            else if (a == 't') {
                ss += 's';
            }
            else if (a == 'm') {
                ss += 'c';
            }
            else if (a == 'n') {
                ss += 'a';
            }
            else if (a == 'k') {
                ss += 'u';
            }
            else if (a == 'g') {
                ss += 'l';
            }
            else if (a == 'h') {
                ss += 'n';
            }
            else if (a == 's') {
                ss += 'd';
            }
            else if (a == 'i') {
                ss += 'h';
            }
            else if (a == 'l') {
                ss += 'b';
            }
            else if (a == 'p') {
                ss += 'y';
            }
            else if (a == 'y') {
                ss += 'i';
            }
            else if (a == 'u') {
                ss += 'j';
            }
        }
    }
    void Print() {
        for (int i = 0; i < win; i++) {
            if (mass[i] == 0) {
                cout << "_";
            }
            else if(mass[i] == 1) {
                cout << s[i];
            }
        }
        cout << "\n";
        cout << "Misses: " << miss << "\n";
    }
    void Enter() {
        int f = 0, b = 0;
        cout << "Enter your letter: ";
        ch = _getch();        
        cout << "\n";
        if (ch == 27)
            return;
        for (auto a : misses) {
            if (a == ch) {
                cout << "This letter has already been entered\n";
                return;
            }
        }
        for (int i = 0; i < win; i++) {
            if (s[i] == ch) {
                if (mass[i] == 0) {
                    mass[i] = 1;
                    b = 1;
                    cout << "you opened the letter " << ch << "\n";                    
                    //return;
                }
                else {
                    cout << "This letter has already been entered\n";
                    return;
                }
            }
            else {
                f++;
            }
        }
        
        if (f != 0 && b == 0) {            
            misses += ch;
            miss++;
            cout << "You missed\n";           
        }
    }
    bool Chech() {
        int f = 0;
        bool b = true;
        for (int i = 0; i < win; i++) {
            if (mass[i] == 0) {
                b = false;
                return b;
            }
        }
    }
};

int main()
{
    srand(time(0));
    double start = clock();
    Gallow G;
    cout << "Warning!!! Works only on English keyboard layout\nIf you give up or don't want to play anymore, press Esc\nHave fun\n";
    system("pause");
    while (!G.Chech()) {
        system("cls");
        G.Print();
        G.Enter();
        if (G.ch == 27)
            break;
        system("pause");

    }
    double finish = clock();
    double res = (finish - start) / 1000;
    system("cls");
    if (G.Chech()) {
        cout << "Well done!\nYou guessed the word \"" << G.s << "\"\nTotal misses: "<<G.miss<<"(";
        for (auto a : G.misses) {
            cout << a << ", ";
        }
        cout << ")\nTime spent: "<<res<<" sec";
    }
    else {
        cout << "The word you guessed: \"" << G.s<<"\"";
        cout<< "\nTotal misses: " << G.miss << "(";
        for (auto a : G.misses) {
            cout << a << ", ";
        }
        cout << ")\nTime spent: " << res << " sec";
    }

}