#include <iostream>

using namespace std;

class OPair
{
    float p1, p2;

public:
    OPair(float f1 = 0.0, float f2 = 0.0)
    {
        p1 = f1;
        p2 = f2;
    }
    bool operator==(const OPair &);
};

bool OPair::operator==(const OPair &s)
{
    return (p1 == s.p1) && (p2 == s.p2);
}

int main()
{
    OPair s1(1, 2), s2(2, 1);

    if (s1.operator==(s2))
        cout << "same" << endl;
    else
        cout << "Not same" << endl;
    return 0;
}