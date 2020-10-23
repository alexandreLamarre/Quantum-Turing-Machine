#include <iostream>
#include <vector>
#include <string>
#include <tuple>

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
        if(accept == 1 && reject == 1) throw("A state cannot be initial and accepting");
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

    bool operator == (const State &m){
        if(name == getName() && initial == m.is_initial() && accept == m.is_accepting() && reject == m.is_rejecting()){
            return true;
        }
        else{
            return false;
        }
    }

};

class States{
public:
    std::vector<State> states;
    std::vector<int> transitions;
    States()= default;

    void addState(const State &q){
        states.push_back(q);
    }

    int addTransition(const State& input_state, const State &transition_state, const Action &action){
        if(getTransitionIndex(transition_state) == -1) return -1;
        else{
            
        }
        return 0;
    }

private:
    int getTransitionIndex(const State &q){
        for(int i = 0; i < states.size(); i++){
            if(states[i] == q){
                return i;
            }
        }
        return -1;
    }

};

class DTM{
public:
    std::vector<int> states;
    std::vector<int> tape;
    std::vector<std::string> alphabet;
    char blankSymbol;
    int head;
    DTM(std::vector<int> states, std::string input_alphabet, char blank){
        states = states;
        blankSymbol = blank;
        head = 0;
    }
};
