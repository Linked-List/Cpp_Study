#include <iostream>
#include <string>
#include <cstring> // memcpy

using namespace std;

const int MaxFrames = 4;
const int DataSize = 128;

class Frame{
public:
    Frame() { name = "NoName" ; print(); }
    Frame(const char* n) {name = n; print();}
    Frame(const string& n){name = n; print();}
    Frame(const string&, const void*, unsigned);
    void print() const;
    void* operator new(size_t);
private:
    string name;
    unsigned char data[DataSize];
};

unsigned char framePool[MaxFrames*sizeof(Frame)];

Frame* allFrames=0;

bool alloc[MaxFrames];
// if alloc[i] is true ith storage
// cell is allocated

Frame::Frame(const string& n, const void* d, unsigned bsize){
    name = n;
    memcpy(data, d, bsize);
    print();
}
void Frame::print() const{
    cout << name << "created.\n";
}

void* Frame::operator new(size_t size){
    // allocationg a new Frame?
    if(size != sizeof(Frame))
        throw string("Not a Frame");

    // storage not allocated yet?
    if(allFrames == 0){
        allFrames = reinterpret_cast<Frame*>(framePool);
        for(int i=0;i<MaxFrames;i++)
            alloc[i] = false;
    }

    // finding a free storage cell
    for(int i=0;i<MaxFrames;i++){
        if(!alloc[i]){
            alloc[i] = true;
            return allFrames + i;
        }
    }

    throw string("Out of Storage");
    //return 0;
}

int main(){
    Frame* a[5];
    string names[4] = {"f1","f2","f3","f4"};
    try{
        a[0] = new Frame;
        // the 1st Frame with NoName

        for(int i=0;i<4;i++)
            a[i+1] = new Frame(names[i]);
            // allocates Frames: the 1st
            // frame is already occupide
    }catch(string s){
        cerr << s << '\n';
        exit(EXIT_FAILURE);
    }
    return 0;
}