#include "DTM.h"
#include <iostream>
#include <vector>


template <typename T>
int printError(std::string message, T error_obj){
    std::cout << "Expected: \n"<< message+"\n";
    if(&error_obj != NULL) std::cout <<"Got: \n"<< error_obj;
    std::cout << "\n";
    return -1;
}


int testState(){
    //======== Constructor =============
    State new_state = State("q0", 1, 0, 0);

    //=========== Getters ===============
    if(new_state.getName() != "q0") return printError("q0", new_state.getName());
    if(!new_state.is_initial()) return printError("state to be initial", new_state.is_initial());
    if(new_state.is_accepting()) return printError("state to not be accepting", new_state.is_accepting());
    if(new_state.is_rejecting()) return printError("state to not be rejecting", new_state.is_rejecting());
    if(new_state.is_malformed()) return printError("state to not be malformed", new_state.is_malformed());
    State next_state = State("any_name_here", 1, 1, 0);
    if(next_state.getName() != "any_name_here") return printError("any_name_here", next_state.getName());
    if(!next_state.is_initial()) return printError("state to be initial", next_state.is_initial());
    if(!next_state.is_accepting()) return printError("state to be accepting", new_state.is_accepting());
    if(next_state.is_rejecting()) return printError("state to not be rejecting", new_state.is_rejecting());

    State reject_state = State("stop", 0,0,1);
    if(reject_state.getName() != "stop") return printError("stop", reject_state.getName());
    if(reject_state.is_initial()) return printError("state to not be initial", reject_state.is_initial());
    if(reject_state.is_accepting()) return printError("state to not be accepting", reject_state.is_accepting());
    if(!reject_state.is_rejecting()) return printError("state to be rejecting", reject_state.is_rejecting());

    State malformed_input_state = State("invalid", 0,1,1);
    if(!malformed_input_state.is_malformed()) return printError("state to be malformed", next_state.is_malformed());

    // ================== Operators ==================
    if(new_state == next_state || new_state == reject_state || new_state == malformed_input_state) return printError("states to be distinct", NULL);
    if(new_state != new_state) return printError("state to be the same", NULL);

    State copy_state("q00", 1, 0 ,0);
    if(new_state == copy_state) return printError("state to be different", NULL);
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

    State intermediate_state3 = State("q3", 0, 1, 1); //malformed state
    if(intermediate_state3.is_malformed()!= 1) return printError("Malformed state value 1", intermediate_state3);
    tm_states.addState(intermediate_state3);
    get_next_states = tm_states.getStates();
    if(get_next_states.size() != 3) return printError("size 3", get_next_states.size());


    //================Removing States==============

    int success = tm_states.removeState(intermediate_state);
    if(success != 0) return -1;
    get_next_states = tm_states.getStates();
    if(get_next_states.size() != 2) return -1;
    if(get_next_states[0] != initial_state) return -1;
    if(get_next_states[1] != intermediate_state2) return printError("Element at index 1 should be", &intermediate_state2);
    success = tm_states.removeState(intermediate_state);
    if(success != -1) return printError("Removing non-existent element should return -1", &success);

    success = tm_states.removeState(initial_state);
    if(success != 0) return -1;
    get_next_states = tm_states.getStates();
    if(get_next_states.size()!= 1) return -1;
    if(get_next_states[0] != intermediate_state2) return  -1;
    success = tm_states.removeState(initial_state);
    if(success != -1) return -1;
    success = tm_states.removeState(intermediate_state2);
    if(success != 0) return -1;
    get_next_states = tm_states.getStates();
    if(get_next_states.size()!= 0) return -1;

    //============= Clear States =======================

    tm_states = States();
    State state1 = State("q0", 1, 0,0);
    State state2 = State("q1", 0, 0, 0);
    State state3 = State("q2", 0, 1, 0);
    State state4 = State("q3", 0 ,0 , 1);
    tm_states.addState(state1);
    tm_states.addState(state2);
    tm_states.addState(state3);
    tm_states.addState(state4);
    get_next_states = tm_states.getStates();
    if(get_next_states.size() != 4) return printError("size 4", get_next_states.size());
    tm_states.clearStates();
    get_next_states = tm_states.getStates();
    if(get_next_states.size() != 0) return printError("size 0", get_next_states.size());
    tm_states.addState(state1);
    tm_states.addState(state2);
    get_next_states = tm_states.getStates();
    if(get_next_states.size() != 2) return printError("size 2", get_next_states.size());
    tm_states.clearStates();
    get_next_states = tm_states.getStates();
    if(get_next_states.size() != 0) return printError("size 0", get_next_states.size());

    // =================== State Configurations (initial,accept,reject) ==============

    if(tm_states.contains_initial() != 0) return printError("tm_states to not contain an initial state(0)", tm_states.contains_initial());
    state1 = State("q0", 1, 0,0);
    state2 = State("q1", 0, 0, 0);
    state3 = State("q2", 0, 1, 0);
    state4 = State("q3", 0 ,0 , 1);
    tm_states.addState(state1);
    if(tm_states.contains_initial() != 1) return printError("tm_states to contain an intial state(1)", tm_states.contains_initial());
    if(tm_states.contains_accept() != 0) return printError("tm_states to not contain an accept state(0)", tm_states.contains_accept());
    if(tm_states.contains_reject() != 0) return printError("tm_states to not contain a reject state(0)", tm_states.contains_reject());
    tm_states.addState(state2);
    if(tm_states.contains_initial() != 1) return printError("tm_states to contain an intial state(1)", tm_states.contains_initial());
    if(tm_states.contains_accept() != 0) return printError("tm_states to not contain an accept state(0)", tm_states.contains_accept());
    if(tm_states.contains_reject() != 0) return printError("tm_states to not contain a reject state(0)", tm_states.contains_reject());
    tm_states.addState(state3);
    if(tm_states.contains_initial() != 1) return printError("tm_states to contain an intial state(1)", tm_states.contains_initial());
    if(tm_states.contains_accept() != 1) return printError("tm_states to contain an accept state(1)", tm_states.contains_accept());
    if(tm_states.contains_reject() != 0) return printError("tm_states to not contain a reject state(0)", tm_states.contains_reject());
    tm_states.addState(state4);
    if(tm_states.contains_initial() != 1) return printError("tm_states to contain an intial state(1)", tm_states.contains_initial());
    if(tm_states.contains_accept() != 1) return printError("tm_states to contain an accept state(1)", tm_states.contains_accept());
    if(tm_states.contains_reject() != 1) return printError("tm_states to contain a reject state(1)", tm_states.contains_reject());
    tm_states.removeState(state1);
    if(tm_states.contains_initial() != 0) return printError("tm_states to not contain an intial state(0)", tm_states.contains_initial());
    if(tm_states.contains_accept() != 1) return printError("tm_states to contain an accept state(1)", tm_states.contains_accept());
    if(tm_states.contains_reject() != 1) return printError("tm_states to contain a reject state(1)", tm_states.contains_reject());
    tm_states.removeState(state3);
    if(tm_states.contains_initial() != 0) return printError("tm_states to not contain an intial state(0)", tm_states.contains_initial());
    if(tm_states.contains_accept() != 0) return printError("tm_states to not contain an accept state(0)", tm_states.contains_accept());
    if(tm_states.contains_reject() != 1) return printError("tm_states to contain a reject state(1)", tm_states.contains_reject());
    tm_states.removeState(state4);
    if(tm_states.contains_initial() != 0) return printError("tm_states to not contain an intial state(0)", tm_states.contains_initial());
    if(tm_states.contains_accept() != 0) return printError("tm_states to not contain an accept state(0)", tm_states.contains_accept());
    if(tm_states.contains_reject() != 0) return printError("tm_states to not contain a reject state(0)", tm_states.contains_reject());


    return 0;
}

int testAction(){
    return 0;
}

int testDTM(){
    return 0;
}

int testTransitions(){

    return 0;
}


