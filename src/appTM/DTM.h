#ifndef DTM_H
#define DTM_H

#endif // DTM_H
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <exception>

class StateException: public std::exception{
    virtual const char* what() const throw(){
        return "Invalid State Defintion";
    }
};

class Action{
public:
    std::string action;
    explicit Action(const std::string &input_action){
        action = input_action;
    }
};


class State{
public:
    int initial;
    int accept;
    int reject;
    std::string name;
    State(const std::string &input_name,int is_initial, int is_accept, int is_reject){
        name = input_name;
        initial = is_initial;
        accept = is_accept;
        reject = is_reject;
    }
    std::string getName() const{
        return name;
    }

    int is_initial() const{
        return initial;
    }

    int is_accepting() const{
        return accept;
    }

    int is_rejecting() const{
        return reject;
    }

    int is_malformed() const{
        return accept == 1 && reject==1;
    }

    bool operator == (const State &m){
        if(name == m.getName() && initial == m.is_initial() && accept == m.is_accepting() && reject == m.is_rejecting()){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator != (const State &m){
        if(!(name == getName() && initial == m.is_initial() && accept == m.is_accepting() && reject == m.is_rejecting())){
            return true;
        }
        else{
            return false;
        }
    }

};

std::ostream& operator<<(std::ostream& os, const State& s){
    os << s.getName() << "/" << "initial:"<<s.is_initial()<<"/"<<"accepting:"<<
          s.is_accepting()<<"/"<<"rejecting:"<<s.is_rejecting()<<"/"<<"malformed:"<<s.is_malformed();
    return os;
}

class States{
public:
    std::vector<State> states;
    States()= default;

    std::vector<State> getStates(){
        return states;
    }

    void addState(const State &q){
        if(q.is_malformed() == 0) states.push_back(q);
    }

    int removeState(const State &remove_state){
        int index = 0;
        for(auto &state: states){
            if(state == remove_state){
                states.erase(states.begin()+index);
                return 0;
            }
            index++;
        }
        return -1;
    }

    void clearStates(){
        states.clear();
    }

    int contains_initial(){
        for(auto &state: states){
            if(state.is_initial() == 1) return 1;
        }
        return 0;
    }

    int contains_accept(){
        for(auto &state: states){
            if(state.is_accepting() == 1) return 1;
        }
        return 0;
    }

    int contains_reject(){
        for(auto &state: states){
            if(state.is_rejecting() == 1) return 1;
        }
        return 0;
    }


};

class DTM{
public:
    States states;
    std::vector<char> tape;
    std::vector<char> alphabet;
    char blank_symbol;
    int head;
    DTM(const States &input_states, const std::string &input_alphabet, char blank){
        states = input_states;
        for(int i = 0; i < input_alphabet.length(); i++){
            alphabet.push_back(input_alphabet[i]);
        }
        blank_symbol = blank;
        head = 0;
    }

    int malformed_alphabet(){
        for(auto &character: alphabet){
            if(character == blank_symbol) return 1;
        }
        return 0;
    }

    void clearAlphabet(){
        std::vector<char> empty_alphabet;
        alphabet = empty_alphabet;
    }

    void setAlphabet(std::vector<char> new_alphabet){
        alphabet = new_alphabet;
    }

    void setBlankSymbol(char new_blank_symbol){
        blank_symbol = new_blank_symbol;
    }

    void addState(const State &q){
        states.addState(q);
        //Set up trivial transitions for state q
    }

    int removeState(const State &q){
        //Delete all transitions starting at state q
        return states.removeState(q);
    }

    bool isValidTM(){
       if(states.contains_initial() == 1 && states.contains_accept() == 1
               && states.contains_reject() == 1){
           return true;
       }
       return false;
    }

    char read(){
        if(tape.size() == 0) return blank_symbol;
        return 'a';
    }

    void write(){

    }

    void copyInputToTape(){

    }

    int addTransition(){
       return 0;
    }

    int removeTransition(){
        return 0;
    }

};
