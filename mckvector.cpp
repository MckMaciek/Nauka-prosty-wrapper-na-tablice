
#include "mckvector.h"


template<typename T>
constexpr unsigned int LepszyVector<T>::size() const{

return Tsize;

}

template<typename T>
unsigned int LepszyVector<T>::iterSize(){

    unsigned int counter = 0;

    for(beg = arr;  beg != contains; ++beg) counter++;

    return counter;
}

template<typename T>
void LepszyVector<T>::CutToFit(){

    T * temp = new T[index];
    
    std::copy(arr, arr+index, temp);
    delete[] arr;
    
    arr = std::move(temp);
    end = &arr[index];
    Tsize = index;

}

template<typename T>
constexpr bool LepszyVector<T>::isEmpty()const{

if (index > 0) return false;
else return true;
}

// constructor with no arguments for type string

template <>
LepszyVector<std::string>::LepszyVector() : Tsize(10) {

arr = nullptr;
beg = nullptr;
end = nullptr;
index = 0;


arr = new std::string[Tsize];

contains = arr;
beg = arr;
end = &arr[Tsize];      

}


template <>
LepszyVector<std::string>::LepszyVector(unsigned int _size) : Tsize(std::move(_size)){

arr = nullptr;
beg = nullptr;
end = nullptr;
index = 0;


arr = new std::string[Tsize];

contains = arr;
beg = arr;
end = &arr[Tsize];      

    //for(beg = arr; end != beg; ++beg) *beg = "null-string";


}

template<typename T>
LepszyVector<T>::LepszyVector(unsigned int _size) : Tsize(std::move(_size)){

arr = nullptr;
beg = nullptr;
end = nullptr;
index = 0;

arr = new T[Tsize];

contains = arr;
beg = arr;
end = &arr[Tsize];     

}

// constructor with no arguments for type T

template<typename T>
LepszyVector<T>::LepszyVector(): Tsize(10){

arr = nullptr;
beg = nullptr;
end = nullptr;
index = 0;

arr = new T[Tsize];

contains = arr;
beg = arr;
end = &arr[Tsize];     

}



template<typename T>
std::string LepszyVector<T>::print(const unsigned indeks){

std::string  returnValue = tostring(arr[indeks]);
 
return (std::move(returnValue));
}

template<typename T>
void LepszyVector<T>::printArray(){

    end = &arr[index];

    int counter = 0;

        for(beg = arr;  beg != end; ++beg) {  std::cout << "[" << counter << "] " <<  *beg << "\n"; counter++;}

}

template<>
std::string LepszyVector<std::string>::operator[](unsigned int arr_index){

try{
if ((arr_index > Tsize)){

    std::string exception_out_of_bound = "Invalid array index\n";
    throw exception_out_of_bound;
    }
    return arr[arr_index];

} catch(std::string exception_out_of_bound){

//std::cout << exception_out_of_bound;


return static_cast<std::string>("No permisson to access this part of memory.\n");

}
}


template<typename T>
T LepszyVector<T>::operator[](unsigned int arr_index){

try{
if ((arr_index > Tsize) || (arr_index < 0)){

    std::string exception_out_of_bound = "Invalid array index\n";
    throw exception_out_of_bound;
    }
    return arr[arr_index];

} catch(std::string exception_out_of_bound){

std::cout << exception_out_of_bound;

exit(-1);

}
}

template<typename T>
constexpr T &LepszyVector<T>::front() const{

if (isEmpty()) exit(-1);
else return arr[0]; 

}

template<typename T>
constexpr T &LepszyVector<T>::last()const {

if (isEmpty()) exit(-1);
else return arr[index-1];

}
template<typename T> 
T * LepszyVector<T>::allocate(T value){
 
if (Tsize == index){
 
    T * temp = new T[Tsize * 2];
    std::copy(arr, arr+Tsize, temp);
 
    delete[] arr;
    arr = std::move(temp);
    end = &arr[Tsize];
    Tsize *= 2;
    }


arr[index] = std::move(value);
contains = &arr[index];
index++;  
return arr+index;
}

template<typename T>
T& LepszyVector<T>::at(unsigned int user_index){

unsigned int arr_element= iterSize();

if ((user_index > arr_element ) && ( user_index < 0)) exit(-1);
return arr[user_index];
} 


template <typename T>
LepszyVector<T>::~LepszyVector(){

delete [] arr;
beg = nullptr;
end = nullptr;
arr = nullptr;
contains = nullptr;

delete beg;
delete end;
}

int main(){

LepszyVector<std::string>Arr(3);
LepszyVector<int>Arr2(3); 
LepszyVector<int>Arr3; 
Arr3.allocate(33);
Arr3.allocate(44);
Arr3.allocate(33);
Arr3.allocate(44);
Arr3.allocate(44);
Arr3.allocate(44);

std::cout << Arr3.at(1) << "\n";
//std::cout << Arr2.front();
//std::cout << Arr2.last();

return 0;
}
