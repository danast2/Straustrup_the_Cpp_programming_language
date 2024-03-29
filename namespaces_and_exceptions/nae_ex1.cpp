/*Пространства имен являются механизмом логического группирования
программных объектов. Если некоторые объявления согласно определенному
критерию логически близки друг другу, то для отражения этого факта их можно
поместить в одно и то же пространство имен. Например, все объявления из программы
калькулятора (§6.1.1), относящиеся к синтаксическому анализатору (парсеру),
можно поместить в одно пространство имен Parser:*/
#include <string>
#include <iostream>

/*Пространство имен формирует свою собственную область видимости. Таким
        образом, пространство имен является одновременно и фундаментальной, и
        достаточно простой концепцией. Чем больше размер программы, тем большую пользу
приносят пространства имен, помогая четко разделять программу на логические части.
Обычные локальные и глобальные области видимости, а также классы, формируют
свои пространства имен*/

namespace Exception{
    std::string message;
    std::string error(std::string msg){
        message = msg;
        return message;
    }
};

//по хорошему, именно это должно использоваться вместо Exceptions
namespace Error{
    int no_of_errors;
    double error(const char* s){
        std::cerr << "error: " << s << '\n';
        ++no_of_errors;
        return 1;
    }
}

namespace Lexer{
    enum Token_value{
        NAME, NUMBER, END,
        PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
        PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
    };
    Token_value curr_tok;
    double number_value;
    std::string string_value;
    Token_value get_token() {/*.....*/}
}


namespace Parser {
    double expr(bool);

    double prim(bool get);

    double term(bool get);

    /*Полезно локальные синонимы делать настолько локальными, насколько это
            возможно, чтобы избегать конфликта имен. Однако все функции синтаксического
    анализатора используют одни и те же наборы имен из других модулей. Поэтому мы
    можем поместить объявления using непосредственно внутрь определения
    пространства имен Parser.*/

    using Lexer::get_token;
    using Lexer::curr_tok;
    using Exception::error;
}

/*Функция expr () должна быть сначала объявлена, а определена потом из-за
необходимости как-то разорвать порочный круг зависимостей, рассмотренный
Часть программы калькулятора, отвечающая за обработку ввода, также может
быть помещена в свое собственное пространство имен:*/

//вынос реализации из пр-ва имен
//double Parser::expr(bool) {/*.....*/}
//double Parser::prim(bool get) {/*.....*/}
//double Parser::term(bool get) {/*.....*/}

