#include <iostream>
#include "Srep.h"
#include "Cref.h"

class String{
    //struct Srep; // представление
    Srep* rep;
    //class Cref; // ссылка на char
public:

    class Range{}; // для исключений
    String();
    String(const char*);
    String(const String&);
    String& operator=(const char*);
    String& operator=(const String&);
    ~String();

    void check(int i) const {
        if (i < 0 || rep->sz <= i) throw Range();
    }
    char read (int i) const {return rep->s [i] ; }
    void write (int i, char c) {rep=rep->get_own_copy(); rep->s [i]=c; }

    Cref operator[] (int i)
    {
        check (i);
        //return Cref(*this , i); // todo не ищет почему-то ?конструктор?
        return Cref();
    }
    char operator[] (int i) const
    {
        check (i) ; return rep->s[i];
    }
    int size () const
    {
        return rep->sz;
    }
};

String::String()
{
    rep = new Srep(0, "");
}

String::String(const String& x) {
    x.rep->n++;
    rep = x.rep; //разделяемое представление
}

String::~String(){
    if(--rep->n == 0) delete rep;
};

String& String::operator=(const String& x) {
    x.rep->n++; // защита от st = st
    if(--rep->n==0) delete rep;
    rep = x.rep; //разделяемое представление
    return *this;
}

String::String(const char * s) {
    rep = new Srep(strlen(s), s);
}


String& String::operator=(const char * s) {
    if(rep->n == 1){
        rep->assign(strlen(s),s); //используем старый Srep
    } else{
        rep->n--;
        rep = new Srep(strlen(s), s); // используем новый Srep
    }
    return *this;
}


