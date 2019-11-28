#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

void print(const char* msg, char a[], int len){
    cout << msg;
    copy(a, a+len, ostream_iterator<char>(cout, " "));
}

int main(){
    const int len = 27;
    const int med = len/2;

    vector<char> alpha;
    char alph[] = "abcdefghijklmnopqrstuvwxyz{";
    //insert alphabet in vector
    for(int i=0;i<len;i++){
        alpha.push_back(alph[i]);
        // a++;
    }

    //print
    cout << "Original" << endl;
    for(int i=0;i<len;i++)
        cout << alpha[i] << " ";
    cout << endl;

    //random shuffle
    shuffle(begin(alpha), end(alpha), default_random_engine());
    cout << "Random Shuffle" << endl;
    for(int i=0;i<len;i++)
        cout << alpha[i] << " ";
    cout << endl;

    nth_element(alph, alph+med, alph+len);
    print("\n\nAfter nth_element:\n", alph,len);
    print("\n\t < median : ", alph, med);
    print("\n\t median : ", alph+med, 1);
    print("\n\t > median : ", alph+med+1, med);
    cout << endl;
    return 0;
}