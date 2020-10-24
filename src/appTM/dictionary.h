#ifndef DICTIONARY_H
#define DICTIONARY_H

#endif // DICTIONARY_H
#include <vector>
#include <iostream>
#include <utility>
#include <exception>

template<typename T, typename U>
class Dictionary{
private:
    std::vector<std::pair<T,U>> container;
public:
    Dictionary() = default;

    bool has(T key){
        for(std::pair<T,U> kv_pair: container){
            if(std::get<0>(kv_pair) == key){
                return true;
            }
        }
        return false;
    }

    T* begin(){
        return &container[0];
    }

    T* end(){
        return &(container[container.size()-1])+1;
    }

    void add(T key, U value){
        if(has(key)){
            for(std::pair<T,U> kv_pair: container){
                int index = 0;
                if(std::get<0>(kv_pair) == key){
                     container.erase(container.begin()+index);
                     break;
                }
                index ++;
            }
        }
        std::pair<T,U> new_pair = std::make_pair(key,value);
        container.push_back(new_pair);
    }

    U get(T key){
        for(std::pair<T,U> kv_pair: container){
            if(std::get<0>(kv_pair) == key){
                return std::get<1>(kv_pair);
            }
        }
        throw("Invalid key");
    }


};

int testDict();

