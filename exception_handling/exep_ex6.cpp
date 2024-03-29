#include <fstream>

void use_file_0(const char* fn){
    FILE* f = fopen(fn, "r");
    //используем f;
    fclose(f);
}

//1 попытка сделать ф-цию use_file устойчивой к исключениям:

void use_file_1(const char* fn){
    FILE *f = fopen(fn, "r");
    try {
        //используем fn
    }catch (...){
        fclose(f);
        throw ;
    }
    fclose(f);
}

/*Проблема с этим решением состоит в том, что оно слишком многословное,
        утомительное и потенциально дорогостоящее. Более того, любое многословное и
утомительное решение подвержено ошибкам, ибо программисту оно надоедает. Но
        к счастью, существует более элегантное решение. Представим общую постановку
        проблемы в следующем виде:*/
void acquire ()
{
// выделяем ресурс 1
// выделяем ресурс п
// используем ресурсы
// освобождаем ресурс п
//...
// освобождаем ресурс 1
}

//Проблему получения и освобождения ресурсов можно решить с помощью объектов классов,
// располагающих надлежащими конструкторами и деструкторами

class File_ptr{
    FILE* p;
public:
    File_ptr(const char* n, const char* a) {p = fopen(n,a);}
    File_ptr(FILE* pp) {p = pp;}
    //подходящие операции копирования
    ~File_ptr(){if(p) fclose(p);}

    operator FILE *(){return p;}
};

void use_file(const char * fn){
    File_ptr(fn, "r");
    //как-то используем f
}

/*Деструктор будет вызван независимо от того, завершается ли функция
нормальным образом или по исключению. Таким образом, механизм обработки
исключений позволил нам удалить код обработки ошибок из реализации основного
алгоритма задачи. Результирующий код проще и менее подвержен внесению случайных
ошибок, чем традиционный вариант.*/