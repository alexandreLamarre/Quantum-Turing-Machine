#include "DTM.h"
#include <iostream>
#include <vector>

int printError(std::string message, void *error_obj){
    std::cout << message+" ";
    if(error_obj != NULL) std::cout << error_obj;
    std::cout << "\n";
    return -1;
}


int testState(){
    State new_state = State("q0", 1, 0, 0);

    if(new_state.getName() != "q0") return -1;
    if(new_state.is_initial() != 1) return -1;
    if(new_state.is_accepting()!= 0) return -1;
    if(new_state.is_rejecting() != 0) return -1;

    State next_state = State("any_name_here", 1, 1, 0);
    if(next_state.getName() != "any_name_here") return -1;
    if(next_state.is_initial() != 1) return -1;
    if(next_state.is_accepting() != 1) return -1;
    if(next_state.is_rejecting() != 0) return -1;

    State reject_state = State("stop", 0,0,1);
    if(reject_state.getName() != "stop") return -1;
    if(reject_state.is_initial()!= 0) return -1;
    if(reject_state.is_accepting()!= 0) return -1;
    if(reject_state.is_rejecting()!= 1) return -1;

    State malformed_input_state = State("invalid", 0,1,1);
    if(next_state.is_malformed()!= 0) return -1;
    return 0;
}

int testStates(){
    //============State Declaration=============
    States tm_states = States();
    if(tm_states.getStates().size() != 0) return -1;

    //============Adding States==================
    State initial_state = State("q0", 1, 0,0);
    tm_states.addState(initial_state);
    if(tm_states.getStates().size() != 1) return -1;

    std::vector<State> get_states = tm_states.getStates();
    if(get_states[0] != initial_state) return -1;
    if(get_states[0].is_initial()!= 1) return -1;

    State intermediate_state = State("q1", 0, 0, 0);
    tm_states.addState(intermediate_state);
    std::vector<State> get_next_states = tm_states.getStates();
    if(get_next_states.size() != 2) return -1;
    if(get_next_states[0] != initial_state || get_next_states[1] != intermediate_state) return -1;
    State check = get_next_states[1];
    if(check.is_initial() != 0 || check.is_accepting() != 0 || check.is_rejecting()!= 0 || check.getName() != "q1") return -1;

    State intermediate_state2 = State("q2", 0, 0 ,0);
    tm_states.addState(intermediate_state2);
    get_next_states = tm_states.getStates();
    if(get_next_states.size() != 3) return -1;
    if(get_next_states[0] != initial_state || get_next_states[1] != intermediate_state ||
            get_next_states[2] != intermediate_state2) return -1;


    //================Removing States==============

    int success = tm_states.removeState(intermediate_state);
    if(success != 0) return -1;
    get_next_states = tm_states.getStates();
    if(get_next_states.size() != 2) return -1;
    if(get_next_states[0] != initial_state) return -1;
    if(get_next_states[1] != intermediate_state2) return printError("Element at index 1 should be", &intermediate_state2);
    success = tm_states.removeState(intermediate_state);
    std::cout << success << "\n";
    if(success != -1) return printError("Removing non-existent element should return -1", &intermediate_state2);

//    success = tm_states.removeState(initial_state);
//    if(success != 0) return -1;
//    get_next_states = tm_states.getStates();
//    if(get_next_states.size()!= 1) return -1;
//    if(get_next_states[0] != intermediate_state2) return  -1;
//    success = tm_states.removeState(initial_state);
//    if(success != -1) return -1;
//    success = tm_states.removeState(intermediate_state2);
//    if(success != 0) return -1;
//    get_next_states = tm_states.getStates();
//    if(get_next_states.size()!= 0) return -1;


    return 0;
}

int testAction(){
    return 0;
}

int testDTM(){
    return 0;
}

int main(){
    if(testState() == -1) std::cout << "Tests failed for State object\n";
    else std::cout << "Tests passed for State object\n";

    if(testStates() == -1) std::cout << "Tests failed for States object\n";
    else std::cout << "Tests passed for States Object\n";

    if(testAction() == -1) std::cout << "Tests failed for Action object\n";
    else std::cout << "Tests passed for Action Object\n";

    if(testDTM() == -1) std::cout << "Tests failed for DTM object\n";
    else std::cout << "Tests passed for DTM Object\n";
    return 0;
}
