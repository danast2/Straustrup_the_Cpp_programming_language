/*Пространства имен являются механизмом логического группирования
программных объектов. Если некоторые объявления согласно определенному
критерию логически близки друг другу, то для отражения этого факта их можно
поместить в одно и то же пространство имен. Например, все объявления из программы
калькулятора (§6.1.1), относящиеся к синтаксическому анализатору (парсеру),
можно поместить в одно пространство имен Parser:*/
#include <string>


/*Пространство имен формирует свою собственную область видимости. Таким
        образом, пространство имен является одновременно и фундаментальной, и
        достаточно простой концепцией. Чем больше размер программы, тем большую пользу
приносят пространства имен, помогая четко разделять программу на логические части.
Обычные локальные и глобальные области видимости, а также классы, формируют
свои пространства имен*/

namespace Parser {
    double expr(bool);

    double prim(bool get);

    double term(bool get);

}

/*Функция expr () должна быть сначала объявлена, а определена потом из-за
необходимости как-то разорвать порочный круг зависимостей, рассмотренный
Часть программы калькулятора, отвечающая за обработку ввода, также может
быть помещена в свое собственное пространство имен:*/

//вынос реализации из пр-ва имен
double Parser::expr(bool) {/*.....*/}
double Parser::prim(bool get) {/*.....*/}
//double Parser::term(bool get) {/*.....*/}

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