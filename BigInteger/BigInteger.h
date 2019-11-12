#include <vector>
#include <string>

class BigInteger{
private:
    bool sign; // true == negative
    std::vector<char> value;
    BigInteger();

public:
    BigInteger(std::string);
    BigInteger(long long num);
    bool operator<(BigInteger);
    bool operator>(BigInteger);
    bool operator==(BigInteger);
    bool operator!=(BigInteger);
    BigInteger operator+(BigInteger);
    BigInteger operator-(BigInteger);
    BigInteger operator*(BigInteger);
    friend std::ostream& operator<<(std::ostream& out, BigInteger num);
};