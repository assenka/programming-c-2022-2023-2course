#include<iostream>
#include<fstream>
#include<map>
#include <vector>


using namespace std;

class Dictionary{
private:
    map <string, string> dict;
    map <char, vector<string>> firstChar;
public:
    ~Dictionary(){

    }

    void print(){
        map<string, string>::iterator it = dict.begin();
        while (it != dict.end())
        {
            cout << it->first << " " << it->second << endl;
            ++it;
        }
    }
    void AddWord(string orig, string trans){
        ofstream fin("Dictionary.txt", ios::app);
        fin << orig << " " << trans << endl;
        dict[orig] = trans;
        fin.close();
    }

    void GetDict(string adr){
        ifstream file(adr);
        while(!file.eof()){
            string orig, trans;
            getline(file, orig, ' ');
            getline(file, trans);
            dict[orig] = trans;
        }
        print();
        file.close();
    }

    void EngCharSearch(char c){
        map <string, string>::iterator it = dict.begin();
        while(it != dict.end()){
            if (it->first[0] == c){
                cout << it->first << " " << it->second << endl;
            }
            ++it;
        }
    }

    void EspCharSearch(char c){
        map <string, string>::iterator it = dict.begin();
        while(it != dict.end()){
            if (it->second[0] == c){
                cout << it->second << " " << it->first << endl;
            }
            ++it;
        }
    }

    void EngWordSearch(string word){
        map<string, string>::iterator it = dict.begin();
        while(it != dict.end()){
            if (it->first == word) {
                cout << it->first << " " << it-> second << endl;
                break;
            }
            ++it;
        }
    }

    void EspWordSearch(string word){
        map<string, string>::iterator it = dict.begin();
        while(it != dict.end()){
            if (it->second == word) {
                cout << it->second << " " << it-> first << endl;
                break;
            }
            ++it;
        }
    }
};

int main(){
    Dictionary d;
    cout << "изначально:" << endl;
    d.GetDict("Dictionary.txt");
    d.AddWord("apple", "manzana");
    d.AddWord("allocated", "asignar");
    d.AddWord("box", "cuadro");
    cout << "поиск:" << endl;
    d.EngCharSearch('a');
    d.EspCharSearch('c');
    d.EngWordSearch("allocated");
    d.EspWordSearch("manzana");
    cout << "after:" << endl;
    d.GetDict("Dictionary.txt");

    return 0;
}