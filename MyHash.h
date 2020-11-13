#include<iostream>
using namespace std;
#ifndef MYHASH
#define MYHASH

template<class T>
class myHash {
public:

	T **hashArray;
	const static int HASHSIZE = 133168;
	long int size = 0;
    long long int foundCompare = 0;
    long long int notFoundCompare = 0;
    long long int compares = 0;

	myHash() {
		hashArray = new T*[27];
		size = 0;
		for (int i = 0; i < 27; i++) {
			hashArray[i] = new T[HASHSIZE];
		}
	}

	int findHash(T word) {
		long int val = 0;
		for (int i = 0; i <= word.size(); i++) {
			val += (int)word[i] * (i*i);
		}
		return val % HASHSIZE;
	}

	void insert(T x) {
		if (x[0] == 'a') {
			insert(x, hashArray[0]);
		}
		else if (x[0] == 'b') {
			insert(x, hashArray[1]);
		}
		else if (x[0] == 'c') {
			insert(x, hashArray[2]);
		}
		else if (x[0] == 'd') {
			insert(x, hashArray[3]);
		}
		else if (x[0] == 'e') {
			insert(x, hashArray[4]);
		}
		else if (x[0] == 'f') {
			insert(x, hashArray[5]);
		}
		else if (x[0] == 'g') {
			insert(x, hashArray[6]);
		}
		else if (x[0] == 'h') {
			insert(x, hashArray[7]);
		}
		else if (x[0] == 'i') {
			insert(x, hashArray[8]);
		}
		else if (x[0] == 'j') {
			insert(x, hashArray[9]);
		}
		else if (x[0] == 'k') {
			insert(x, hashArray[10]);
		}
		else if (x[0] == 'l') {
			insert(x, hashArray[11]);
		}
		else if (x[0] == 'm') {
			insert(x, hashArray[12]);
		}
		else if (x[0] == 'n') {
			insert(x, hashArray[13]);
		}
		else if (x[0] == 'o') {
			insert(x, hashArray[14]);
		}
		else if (x[0] == 'p') {
			insert(x, hashArray[15]);
		}
		else if (x[0] == 'q') {
			insert(x, hashArray[16]);
		}
		else if (x[0] == 'r') {
			insert(x, hashArray[17]);
		}
		else if (x[0] == 's') {
			insert(x, hashArray[18]);
		}
		else if (x[0] == 't') {
			insert(x, hashArray[19]);
		}
		else if (x[0] == 'u') {
			insert(x, hashArray[20]);
		}
		else if (x[0] == 'v') {
			insert(x, hashArray[21]);
		}
		else if (x[0] == 'w') {
			insert(x, hashArray[22]);
		}
		else if (x[0] == 'x') {
			insert(x, hashArray[23]);
		}
		else if (x[0] == 'y') {
			insert(x, hashArray[24]);
		}
		else if (x[0] == 'z') {
			insert(x, hashArray[25]);
		}
		else {
			insert(x, hashArray[26]);
		}

	}
	
	void insert(T x, T *&head) {
		if (x == "") return;
		int key = findHash(x);
		if (head[key] == "") {
			head[key] = x;
			size++;
		}
		else {
			bool entered = false;
			while (!entered) {
				if(key < HASHSIZE) {
					key++;
				}
				else {
					key = 0;
				}
				if (head[key] == "") {
					head[key] = x;
					size++;
					entered = true;
				}
			}
		}
		
	}

	bool find(T x) {
		compares = 0;
		if (x[0] == 'a') {
			return find(x, hashArray[0]);
		}
		else if (x[0] == 'b') {
			return find(x, hashArray[1]);
		}
		else if (x[0] == 'c') {
			return find(x, hashArray[2]);
		}
		else if (x[0] == 'd') {
			return find(x, hashArray[3]);
		}
		else if (x[0] == 'e') {
			return find(x, hashArray[4]);
		}
		else if (x[0] == 'f') {
			return find(x, hashArray[5]);
		}
		else if (x[0] == 'g') {
			return find(x, hashArray[6]);
		}
		else if (x[0] == 'h') {
			return find(x, hashArray[7]);
		}
		else if (x[0] == 'i') {
			return find(x, hashArray[8]);
		}
		else if (x[0] == 'j') {
			return find(x, hashArray[9]);
		}
		else if (x[0] == 'k') {
			return find(x, hashArray[10]);
		}
		else if (x[0] == 'l') {
			return find(x, hashArray[11]);
		}
		else if (x[0] == 'm') {
			return find(x, hashArray[12]);
		}
		else if (x[0] == 'n') {
			return find(x, hashArray[13]);
		}
		else if (x[0] == 'o') {
			return find(x, hashArray[14]);
		}
		else if (x[0] == 'p') {
			return find(x, hashArray[15]);
		}
		else if (x[0] == 'q') {
			return find(x, hashArray[16]);
		}
		else if (x[0] == 'r') {
			return find(x, hashArray[17]);
		}
		else if (x[0] == 's') {
			return find(x, hashArray[18]);
		}
		else if (x[0] == 't') {
			return find(x, hashArray[19]);
		}
		else if (x[0] == 'u') {
			return find(x, hashArray[20]);
		}
		else if (x[0] == 'v') {
			return find(x, hashArray[21]);
		}
		else if (x[0] == 'w') {
			return find(x, hashArray[22]);
		}
		else if (x[0] == 'x') {
			return find(x, hashArray[23]);
		}
		else if (x[0] == 'y') {
			return find(x, hashArray[24]);
		}
		else if (x[0] == 'z') {
			return find(x, hashArray[25]);
		}
		else {
			return find(x, hashArray[26]);
		}
	}

	bool find(T x, T *head) {
		compares++;
		int key = findHash(x);
		if(head[key].compare("") == 0) {
            notFoundCompare += compares;
            return false;
        }
		else if (head[key].compare(x) == 0) {
			foundCompare += compares;
			return true;
		}
		else {
			bool found = false;
			while (!found) {
				if(key < HASHSIZE) {
					key++;
				}
				else {
					key = 0;
				}
				compares++;
				if (head[key].compare(x) == 0) {
					foundCompare += compares;
					return true;
				}
				else if (head[key].compare("") == 0) {
					notFoundCompare += compares;
					return false;
				}
			}
			return false;
		}
	}

	~myHash() {
	    delete[] hashArray;
	}

	int getSize() {
		return size;
	}

};
#endif