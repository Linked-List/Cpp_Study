#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

class WordList{
private:
    vector<string> dictionary;
    list<string> wordlist;
public:
    WordList(); // dic.txt로부터 모든 단어들을 불러와 dictionary에 저장
    void CheckDictionary(string str); // str이 dictionary 존재 여부 확인
    void CheckDuplication(string str); // str이 wordlist 중복 여부 확인
    void CheckConfirm(string str); // str의 첫글자와 기존 리스트의 마지막 단어의 끝 글자 동일 여부 확인
    void add(string str); // 위 3가지 check 후 wordlist.push_back
    void startGame(); // 게임시작
};

int main(){
    WordList wl;
    wl.startGame();

    return 0;
}

WordList::WordList(){
    ifstream in("dict.txt");
    string tmp;
    if(!in.is_open()){
        cout << "[ERROR] File not Found" << endl;
        exit(0);
    }
    while(in >> tmp)
        dictionary.push_back(tmp);
    in.close();
}

void WordList::CheckDictionary(string str){
    vector<string>::iterator f = find(dictionary.begin(), dictionary.end(), str);
    if(f == dictionary.end())
        throw string("Not exitst word in dictionary");
}

void WordList::CheckDuplication(string str){
    list<string>::iterator f = find(wordlist.begin(), wordlist.end(),str);
    if(f != wordlist.end())
        throw string("It's Duplication");
}

void WordList::CheckConfirm(string str){
    if(!wordlist.empty()){
        string last = *(--wordlist.end()); // 마지막 단어 가져오기
        if(last[last.length()-1] != str[0]) // 마지막 단어의 마지막글자와 넣은 단어의 첫글자 일치여부확인
            throw string("Not same as the previous word alphabet");
    }
}

void WordList::add(string str){
    static ofstream out("result.txt");

    try{
        for(int i=0;i<str.length();i++)
            if(!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
                throw string("It is not English");
        CheckDictionary(str);
        CheckDuplication(str);
        CheckConfirm(str);
    }catch(string err){
        out.close();
        throw err;
    }
    wordlist.push_back(str);
    out << str << " ";
}

void WordList::startGame(){
    string word;
    cout << "Game Start" << endl;
    while(1){
        cout << "Input word : ";
        cin >> word;
        try{
            add(word);
        }catch(string err){
            cout << "You Lose. " + err << endl;
            return;
        }
        for(list<string>::iterator i = wordlist.begin() ; i != wordlist.end() ; i++)
            cout << *i << " ";
        cout << endl;
    }
}