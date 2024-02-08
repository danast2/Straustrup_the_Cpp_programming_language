#include "tem_ex1.cpp"
//шаблоны могут иметь как параметры обычных фиксированных типов(int), так и шаблонных типов (один шаблон может иметь несколько параметров)
template<class T, T def_val> class Cont{/**/};


/*  Простые, ограниченные контейнеры, вроде Buffer, полезны в задачах,
требующих высочайшей эффективности и компактности кода (так что там не подходят
универсальные контейнеры типа string и vector). Передача размера в виде аргумента
шаблона Buffer позволяет избежать затратных операций динамического выделения
свободной памяти.*/
template<class T, int max> class Buffer{
    T v[max];
public:
    Buffer();
    //........
};

Buffer<char, 128> cbuf;
Buffer<int, 5000> ibuf;
//Buffer<Record, 8> rbuf;

