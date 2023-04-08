
//#include "headers/solutions.h"

#include <iostream>
#include <set>
#include <map>

using namespace std;



int main() {

    map<string, set<string>> synonyms;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "ADD"){
            string word, synonym;
            cin >> word >> synonym;
            synonyms[word].insert(synonym);
            synonyms[synonym].insert(word);
        }else if (s == "COUNT"){
            string word;
            cin >> word;
            if(synonyms.count(word) == 0){
                cout << 0 << endl;
            }else{
                cout << synonyms[word].size() << endl;
            }
        }else if(s == "CHECK"){
            string word, synonym;
            cin >> word >> synonym;
            if(synonyms.count(word) == 0){
                cout << "NO" << endl;
            }else{
                if(synonyms[word].count(synonym) == 0){
                    cout << "NO" << endl;
                }else{
                    cout << "YES" << endl;
                }
            }
        }
    }


    return 0;
}

