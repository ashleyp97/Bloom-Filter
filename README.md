## Walkthrough Video

Here is the link to the walkthrough video - https://www.loom.com/share/b3ec0db882fd473a8a34fe6f8225d96c?sid=bd2df08c-fe83-4d3a-af34-563286aef098

If the file does not work work for you, this project is very easy to test just run the file as normal and test any English word.

## What Are Bloom Filters? How Does It Work?

A Bloom filter is a space-efficient probabilistic data structure. It’s used to test whether certain elements are part of a set. Unlike other data structures we’ve worked with, Bloom filters will always say yes if an item is in the set. However, there are cases where it might say yes even if the item is not in the set — this is known as a false positive. Fortunately, there are never false negatives with a Bloom filter.

A Bloom filter works by using multiple hash functions to map elements to positions in a bit array. This allows the structure to determine whether an element might be in the set.

## My Objective

For my project I wanted to use a Bloom filter as a spellchecker. My idea was that a user would input an English word and the Bloom filter would then check the dictionary to see if the word is present. If the word is present in the dictionary, it's spelled correctly. If the word is not, then it's spelled incorrectly and would loop until the user spells the word correctly. 

## Challenges Faced: How Many Hash Functions?

One of the most commonly known issues with Bloom filters are false positives. This happens when the Bloom filter believes an item is present in the set when it's not actually there. 

As we add elements to our Bloom filter, each item is hashed multiple times and the bits associated with the item is set to 1. As more items are added, some these new item bits might already be set from previous items added to the Bloom filter. This overlap confuses the data structure because it assumes the new item is already present if all bits it hashes to are already set. 

Though it's unlikely to eliminate all risk of false positives from a Bloom filter, one of the most common ways to reduce it is by using multiple hash functions. 

For my code I chose to use this approach and found great success so far in using multiple hash functions. Originally I had written the hash functions individually as show in the GeeksforGeeks article "Bloom Filters – Introduction and Implementation", but chose to instead combine all of them into one function. 

After thorough research on how to create multiple hash functions I realized I needed to salt each one individually. A salt added to a hash function is essentially a string that makes each hash function have a unique output. 

An additional smaller challenge I faced was refering to the proper way to import and read through a file. This was a task we worked on last semester in our Introduction to Computer Science class. This challenge was much smaller in comparison to writing out my hash functions and ensuring it has unique outputs. 

## My Implementation

For this project I refered back to our lecture on planning our code. I found this incredibly useful as this data structure was brand new to me and I had no idea how to get from beginning to end. Once I wrote out my goals with inputs and outputs, as well as all the smaller steps to get to the output, I was ready to start.

I began by creating my class. For both my private and public function I followed a similar format to how I completed the assignments. I determined a function I needed to write, did necessary research on that function if necessary, defined it in my header file then wrote the actual function in my cpp file. 

For my hash functions I wrote each one out individually, then went back several times to figure out how to make it more efficient. My hash functions also required the most amount of testing to ensure my salts were working properly. 

Each function I tested with a cout statement to ensure the necessary outputs were coming through. Once I finished the project, I considered other edge cases besides false positives that might come to play. 

The one that really stood out was the possibility of someone typing in a word in capital letters vs. lowercase. The dictionary I imported only uses lowercase words. Originally, I thought about just adding to the original question to only use lowercase, but decided to challenge myself to figure out a way to ensure each character in a word from a user is converted to lowercase.

Fortunately, there's a C++ function for just that! Once I figured out how to properly use this in my user input function I was ready to do my final tests.

## Resources 

Below are resources I reviewed to write my code and understand my data structure. 

- https://systemdesign.one/bloom-filters-explained/
- https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/
- https://www.geeksforgeeks.org/cpp-bitset-and-its-application/
- https://www.geeksforgeeks.org/read-a-file-line-by-line-in-cpp/
- https://www.geeksforgeeks.org/setting-bits-in-cpp/
- Dictionary imported: https://github.com/dolph/dictionary
