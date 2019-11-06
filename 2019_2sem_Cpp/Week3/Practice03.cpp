#define _CRT_SECURE_NO_WARNINGS // strtok 보안미흡으로 인한 VS 컴파일 에러 방지. 본인은 gcc컴파일러사용

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

enum my_exception{NO_FILE, NO_WORD};

class Dictionary{
private:
    // 각각의 속담을 저장해놓을 배열과, 몇개 저장되어있는지에 대한 수치
    int size;
    int maxSize;
    string* proverbs;

    // 단어별로 짤라놓은 문자열들을 저장해놓은 배열
    string* wordTable;
    // wordTable[i]의 단어 등장횟수
    int* wordCount;
    // WordTable에 몇개의 단어가 들어가있는가?
    int numOfWords;
    int maxWords;

    void increaseProverbs(){
        string* temp = new string[maxSize*2];
        for(int i=0;i<size;i++)
            temp[i] = proverbs[i];
        delete[] proverbs;
        proverbs = temp;
        maxSize*=2;
    }
    void increaseWords(){
        string* temp = new string[maxWords*2];
        int* temp2 = new int[maxWords*2];
        for(int i=0;i<maxWords*2;i++)
            temp2[i] = 0;
        for(int i=0;i<numOfWords;i++){
            temp[i] = wordTable[i];
            temp2[i] = wordCount[i];
        }
        delete[] wordTable;
        delete[] wordCount;
        wordTable = temp;
        wordCount = temp2;
        maxWords *= 2;
    }

public:
    Dictionary(){
        size = 0;
        maxSize = 70;
        numOfWords = 0;
        maxWords = 250;
        proverbs = new string[maxSize];
        wordTable = new string[maxWords];
        wordCount = new int[maxWords];
        for(int i=0;i<maxWords;i++)
            wordCount[i] = 0;
    }
    ~Dictionary(){
        delete[] proverbs;
        delete[] wordCount;
        delete[] wordTable;
    }
    void addProverb(string w){
        if(size>=maxSize)
            increaseProverbs();
        
        proverbs[size++] = w;

        char str[200];
        strcpy(str,w.c_str());
        char* ptr = strtok(str,"[ ,.;]"); // 정규표현식을 이용해서 단어 분할

        while(ptr != nullptr){
            string word = ptr;
            int j;
            for(j=0;j<numOfWords;j++){ // wordTable에서 찾기
                if(wordTable[j] == word){
                    wordCount[j]++;
                    break;
                }
            }
            if(j==numOfWords){ // wordTable에서 찾지 못한 경우 Table에 추가
                if(numOfWords>=maxWords)
                    increaseWords();
                wordTable[numOfWords] = word;
                wordCount[numOfWords++]++;
            }
            ptr = strtok(nullptr,"[ ,.;]");
        }
    }

    // 만들어놓은 WordTable을 버블정렬하여 내림차순으로 정렬후 앞에부터 5개 출력
    void printMax5(){
        for(int i=0;i<numOfWords-1;i++){
            for(int j=0;j<numOfWords-i-1;j++){
                if(wordCount[j]<wordCount[j+1]){
                    int temp = wordCount[j];
                    wordCount[j] = wordCount[j+1];
                    wordCount[j+1] = temp;

                    string temp2 = wordTable[j];
                    wordTable[j] = wordTable[j+1];
                    wordTable[j+1] = temp2;
                }
            }
        }
        cout << "[Top 5 Words]" << endl;
        for(int i=0;i<5;i++)
            cout << i+1 << ". " << wordTable[i] << endl;
    }

    // 정규식을 이용해서 단어를 기준짓는것 단위로 자른다. (기준은 ' ', '.', ',', ';' 4개)
    int findAlgorithm(string from, string finding){
        char str[200];
        strcpy(str,from.c_str());
        char* ptr = strtok(str,"[ .,;]");

        while(ptr != nullptr){
            if(strcmp(ptr,finding.c_str())==0)
                return 1;
            ptr = strtok(nullptr,"[ .,;]");
        }
        return 0;
    }

    void findByWord(string w){
        int count=0;
        cout << ">Print Proverbs containing the word [" << w << "]" << endl;
        for(int i=0;i<size;i++)
            if(findAlgorithm(proverbs[i],w))
                cout << "[" << ++count << "]" << proverbs[i] << endl;
        if(count == 0)
            throw NO_WORD;
        cout << endl;
    }
    void findByWord(string w1, string w2){
        int count=0;
        cout << ">Print Proverbs containing the words [" << w1 << "] or [" << w2 << "]" << endl;
        for(int i=0;i<size;i++)
            if(findAlgorithm(proverbs[i],w1) || findAlgorithm(proverbs[i],w2))
                cout << "[" << ++count << "]" << proverbs[i] << endl;
        if(count == 0)
            throw NO_WORD;
        cout << endl;
    }
};

void fileopen(ifstream& ifs, string name){
    ifs.open("text.txt");
    if(!ifs.is_open())
        throw NO_FILE;
}

int main(){
    Dictionary dic; // 속담을 담을 사전
    string temp; // 매줄 입력받는 문자열
    ifstream ifs;
    try{
        fileopen(ifs,"text.txt");
    }catch(my_exception e){
        cout << "[ERROR] File not Found" << endl;
        return 0;
    }
    
    while(getline(ifs,temp)) // 파일의 끝까지 한줄씩 입력받기
        dic.addProverb(temp);
    dic.printMax5();

    while(true){
        int num;
        cout << "-----[Main]-----" << endl;
        cout << "1. Find Proverb by Word" << endl;
        cout << "2. Find Proverb by 2 Words" << endl;
        cout << "3. Exit" << endl;
        cin >> num;
        try{
            if(num == 1){
                string str;
                cout << "Enter Your word to find : ";
                cin >> str;
                dic.findByWord(str);
            }else if(num == 2){
                string str1, str2;
                cout << "Enter Your 2 words to find : ";
                cin >> str1 >> str2;
                dic.findByWord(str1,str2);
            }else if(num == 3){
                cout << "Bye." << endl;
                break;
            }else
                cout << "Wrong input" << endl;
        }catch(my_exception e){
            cout << "[ERROR] No Proverb Found" << endl;
        }
    }
    ifs.close();
    return 0;
}