#ifndef _MCKVECTOR_H_
#define _MCKVECTOR_H_

#include <string>
#include <iostream>
#include <algorithm>

template<typename T> 
class LepszyVector{

private:

T * beg;
T * end;
T * arr;
T * contains;

unsigned int index;
unsigned int Tsize;

public:
constexpr T& front() const;
constexpr T& last() const;
T& at(unsigned int user_index); 
LepszyVector();
LepszyVector(unsigned int _size);
void CutToFit();
constexpr bool isEmpty()const;
T operator[](unsigned int arr_index);
T * allocate(T value);
constexpr unsigned int size() const;
unsigned int iterSize();
std::string print (unsigned indeks);
void printArray();


~LepszyVector();

private:
};


#endif