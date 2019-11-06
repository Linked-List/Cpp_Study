#include <iostreamm>
#include <string>

using namespace std;

class animal{
    string species;
public:
    Animal(){species = "Animal";}
    Animal(const char* s){ species = s; }
};

class Primat : public Animal{
public:
    Primate() : Animal("Primate"){}
    Primate(int n) : Animal("Primate"){
        heart_cham = n;
    }
private:
    int heart_cham;
};

int main(){
    Animal slug;
    Animal tweety("canary");
    Primate godzilla;
    Primate human(4);
}