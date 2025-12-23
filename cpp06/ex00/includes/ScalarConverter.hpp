#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <cstdlib>
#include <string>
#include <iostream>

#define DOUBLE_BOOL 'd'
#define FLOAT_BOOL 'f'
#define INT_BOOL 'i'
#define CHAR_BOOL 'c'

class ScalarConverter {
    private:
        ScalarConverter(void);
    public:
        static void convert(std::string expr);
};

#endif
