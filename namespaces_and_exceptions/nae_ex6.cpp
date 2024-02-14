//пример Exception
#include <iostream>

namespace Exception{
    int no_of_errors;
    struct Zero_divide{
        Zero_divide(){no_of_errors++;}
    };
    struct Syntax_error{
        const char* p;
        Syntax_error(const char* q) {p = q; no_of_errors++;}
    };
}

int main(){
    try{

    }catch (Exception::Zero_divide){

    }catch (Exception::Syntax_error e){
        std::cerr << "syntax error" << e.p << "\n";
    }
    //...........................
}