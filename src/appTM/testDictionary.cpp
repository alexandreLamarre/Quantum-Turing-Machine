#include "dictionary.h";

template <typename T>
int printError(std::string message, T error_obj){
    std::cout << "Expected: \n"<< message+"\n";
    if(&error_obj != NULL) std::cout <<"Got: \n"<< error_obj;
    std::cout << "\n";
    return -1;
}


int testDict(){

    // ==============  Declaration ===========
    Dictionary<int,int> new_dict = Dictionary<int,int>();

    // ============== Adding/Has ====================

    new_dict.add(5,6);
    new_dict.add(7,8);
    new_dict.add(8,9);

    if(!new_dict.has(5)) return printError("Key 5 exists in dict", new_dict.has(5));
    if(new_dict.has(6)) return printError("Key 6 does not exist in dict", new_dict.has(6));
    if(!new_dict.has(7)) return printError("Key 7 exists in dict", new_dict.has(7));
    if(!new_dict.has(8)) return printError("Key 8 exists in dict", new_dict.has(8));
    if(new_dict.has(9)) return printError("Key 9 does not exist in dict", new_dict.has(9));

    // =============== Get =======================

    if(new_dict.get(5) != 6) return printError("Value at key 5 (6)", new_dict.get(5));
    if(new_dict.get(7) != 8) return printError("Value at key 7 (8)", new_dict.get(7));
    if(new_dict.get(8) != 9) return printError("Value at key 8 (9)", new_dict.get(8));

    try{
        new_dict.get(6);
        return printError("Non-existant key should raise invalid error", NULL);
    }
    catch(const char* msg){

    }
    // ===================== Add(replace) ===========
    new_dict.add(5,7);
    if(!new_dict.has(5)) return printError("Key 5 exists in dict", new_dict.has(5));
    if(new_dict.get(5) != 7) return printError("Value at key 5(7)", new_dict.get(5));

    // ===================== Clear ==========================
    new_dict.clear();
    try{
        new_dict.get(5);
        return printError("Non-existant key should raise invalid error", NULL);
    }
    catch(const char* msg){

    }
    try{
        new_dict.get(7);
        return printError("Non-existant key should raise invalid error", NULL);
    }
    catch(const char* msg){

    }
    try{
        new_dict.get(8);
        return printError("Non-existant key should raise invalid error", NULL);
    }
    catch(const char* msg){

    }
    if(new_dict.has(5)) return printError("dictionary should not contain key 5", new_dict.has(5));
    if(new_dict.has(7)) return printError("dictionary should not contain key 7", new_dict.has(7));
    if(new_dict.has(8)) return printError("dictionary should not contain key 8", new_dict.has(8));

    // ====================== Remove ===================================

    new_dict.add(5,6);
    new_dict.remove(5);
    if(new_dict.has(5)) return printError("dictionary should not contain key 5", new_dict.has(5));
    try{
        new_dict.get(5);
        return printError("Non-existant key should raise invalid error", NULL);
    }
    catch(const char* msg){

    }

    return 0;
}

