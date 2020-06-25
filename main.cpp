#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


int main(int argc, char *argv[]){
    char a;
    string str;
    FILE *p;
    p = fopen(argv[1], "r");
    a = getc(p);
    while (a != EOF){
        str += a;
        a = getc(p);
    }

    vector<char> container;

    for (char b : str) {
        switch (b) {
        case '(':
            container.push_back(b);
            break;
        case '{':
            container.push_back(b);
            break;
        case '[':
            container.push_back(b);
            break;
        case ')':
            if (container.empty() || container.back() != '('){
                    return 0;
                } else {
                    container.pop_back();
                }
            break;
        case '}':
            if (container.empty() || container.back() != '{'){
                return 0;
            } else {
                container.pop_back();
            }
            break;
        case ']':
            if (container.empty() || container.back() != '['){
                return 0;
            } else {
                container.pop_back();
            }
            break;
        }
    }
    return container.empty();
}
