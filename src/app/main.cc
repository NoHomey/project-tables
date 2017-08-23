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
#include "../Parsers/StringParser/StringParser.h"

int main() {
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

    {
        auto res = StringParser::parse("  \"text\\\\\\\\ t \\\"\\\\\\\"b\" a  d");
        auto string = std::move(res.moveParsed());
        const auto&  rest = res.getRest();
        std::cout << string.length() << ' ' << string.cString() << std::endl;
        std::cout << rest.length() << ' ' << rest.cString() << std::endl;
    }

    {
        try {
            auto res = StringParser::parse("  text\\\\\\ t \\\"\\\\\\\"b\" a  d");
        } catch(const StringParser::MissingQuotesInTheBeginng& error) {
            auto string = error.getToken();
            std::cout << "Error: " << string.length() << ' ' << string.cString() << std::endl;
        } 
    }

    {
        try {
            auto res = StringParser::parse("  \"text\\\\\\ t \\\"\\\\\\\"b\" a  d");
        } catch(const StringParser::UnEscapedBackslash& error) {
            auto string = error.getToken();
            std::cout << "Error: " << error.getPosition() << ' ' << error.getSymbol()
                << ' ' << string.length() << ' ' << string.cString() << std::endl;
        } 
    }

    {
        try {
            auto res = StringParser::parse("  \"text\\\\\\\\ t \\\"\\\\\\\"b a  d");
        } catch(const StringParser::MissingQuotesInTheEnd& error) {
            auto string = error.getToken();
            std::cout << "Error: " << string.length() << ' ' << string.cString() << std::endl;
        } 
    }

    return 0;
}