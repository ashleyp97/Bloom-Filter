#include "BloomFilter.h"
int main() {
    BloomFilter bf;

    bf.getDictionary("dictionary.txt");
    string word = bf.getUserInput();

    while (!bf.contains(word)){
        cout << "The word " << word << " is not spelled correctly, try again" << endl;
        word = bf.getUserInput();
    }

    cout << "The word " << word << " is spelled correctly." << endl;
    
    return 0;

}
