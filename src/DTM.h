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
    std::vector<std::tuple<int, std::vector<std::tuple<char,int>>>> transitions; //index of current state -> symbol transition,index of next state
    States()= default;

    void addState(const State &q){
        states.push_back(q);
        std::vector<std::tuple<char, int>> empty;
        std::tuple<int, std::vector<std::tuple<char, int>>> new_transition_index = std::make_tuple(states.size()-1, empty );
        transitions.push_back(new_transition_index);
    }

    int addTransition(const State &input_state, const State &transition_state, const char symbol){
        int startIndex = getTransitionIndex(input_state);
        int endIndex = getTransitionIndex(transition_state);
        if(endIndex == -1 || startIndex == -1) return -1;
        else{
            for(auto & transition : transitions){
                if(std::get<0>(transition) == startIndex){
                    std::vector<std::tuple<char,int>> input_state_transitions = std::get<1>(transition);
                    input_state_transitions.emplace_back(symbol,endIndex);
                    return 0;
                }
            }
        }
        return -1;
    }

    int removeState(const State &remove_state){
        for(auto &state : states){

        }
        return -1;
    }

    int removeTransition(const State &start_state, const State &end_state, const char symbol){
        int startIndex = getTransitionIndex(start_state);
        int endIndex = getTransitionIndex(end_state);
        if(startIndex == -1 || endIndex == -1) return -1;
        for(auto &transition_index: transitions){
            if(std::get<0>(transition_index) == startIndex){
                std::vector<std::tuple<char, int>> state_transitions = std::get<1>(transition_index);
                for(int i =0; i < state_transitions.size(); i++){
                    if(std::get<1>(state_transitions[i]) == endIndex && std::get<0>(state_transitions[i]) == symbol){
                        state_transitions.erase(state_transitions.begin()+i);
                        return 0;
                    }
                }
            }
        }
        return -1;
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
    States states;
    std::vector<int> tape;
    std::vector<std::string> alphabet;
    char blankSymbol;
    int head;
    DTM(const States &input_states, const std::string &input_alphabet, char blank){
        states = input_states;
        blankSymbol = blank;
        head = 0;
    }
};

