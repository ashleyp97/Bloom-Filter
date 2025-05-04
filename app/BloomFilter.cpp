#include "BloomFilter.h"
#include <string>
#include <functional>

BloomFilter::BloomFilter(){
}

//This function takes in users input, converts it to lowercase if necessary, and outputs the result. 
string BloomFilter::getUserInput(){
    string word;
    cout << "Enter a word to check for spelling errors";
    cin >> word;

    for(char& c: word){ //For each character we convert it to lowercase
        c = tolower(c);
    }

    return word;
}

//This function takes in a dictionary and reads each line
void BloomFilter::getDictionary(string filename){
    const int BUFFER_SIZE = 1000; //Maximum number of words to buffer (or to store)
    vector <string> words;
    ifstream file("dictionary.txt"); //We take in the dictionary we want our Bloom filter to read through
    string line;
    
    if(file.is_open()){ 
        while(getline(file,line)){ //We read each line (word) in our dictionary
            words.push_back(line);
            if(words.size()== BUFFER_SIZE){
                for(int i = 0; i < words.size(); i++){
                    insertBloomFilter(words[i]); //Insert each word into the Bloom filter
                }
                words.clear();
            }
        }
        if(!words.empty()){ //We handle the remaining words left in the buffer
            words.clear();
        }
    }
}

//This function generates a hash value with a  string and a salt.
//Multiple hash functions are required for Bloom filters
size_t BloomFilter::hash (const string& str,string salt){ 
    std::hash<std::string> hasher;
    return hasher(str + salt);
}

//This function inserts a string into the Bloom filter by hashing it.
//We use multiple salts and assign bits to each hashed value so this can be checked later.
void BloomFilter::insertBloomFilter(string& line){

    string salts[] = {"salt1","salt2","salt3","salt4"}; //Array of salt values for multiple hash functions

    for(int i = 0; i < 4; i++){ //For each salt we hash it and take the modulo using the bit size
        int index = hash(line,salts[i]) % bit.size();
        bit.set(index);
        }
}

//This function checks the user input (word), hashes it and then determines if all the corresponding bits are changed to 1 indicating its present.
bool BloomFilter::contains(string word) { 

//Compute hashes with different salts to stimulate independent hash functions lowering the risk of false positives.
    int a = hash(word,"salt1") % bit.size();
    int b = hash(word,"salt2") % bit.size();
    int c = hash(word,"salt3") % bit.size();
    int d = hash(word,"salt4") % bit.size();

//True indicates a word is probably in the set, False indicates it is not.
    if (bit[a] && bit[b] && bit[c] && bit[d]){
        return true;
    } 
    else{
        return false;
    }
    
}



