/*#include "Application/Application.h"

int main() {
    Application::run();

    return 0;
}*/

#include <iostream>
#include <iomanip>
#include "../Parsers/IntegerParser/IntegerParser.h"
#include "../Parsers/ColumnNumberParser/ColumnNumberParser.h"
#include "../Parsers/FractionalNumberParser/FractionalNumberParser.h"

int main() {
    //Application::run();

    {
        auto res = IntegerParser::parse("  -0000000000000000000000000000000000000000000000000000   ");
        std::cout << res.getParsed() << std::endl;
    }

    {
        auto res = ColumnNumberParser::parse("  000000000000000000000000000000000009999   ");
        std::cout << res.getParsed() << std::endl;
    }

    {
        auto res = FractionalNumberParser::parse("  0000000000000000000000200000.000009999   ");
        std::cout << std::setprecision(15) << res.getParsed() << std::endl;
    }

    return 0;
}