#include "DTM.h"
#include <iostream>

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
    States tm_states = States();
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
