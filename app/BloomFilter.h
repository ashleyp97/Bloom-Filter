#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <bitset>
#include <string>
#include <functional>
#include <cmath>
#include <cctype>
using namespace std;

class BloomFilter {
    private:
    bitset<10000000> bit;
    size_t hash (const string& str, string salt);
    
    public:
    BloomFilter();
    string getUserInput();
    void getDictionary(string filename);
    void insertBloomFilter(string& line);
    bool contains(string word);

};
