#include "ScalarConverter.hpp"

// TODO:
ScalarConverter::ScalarConverter(void)
{
}

static void instantiate_float(double expr, int freq);
static void instantiate_float(std::string expr, int freq);
static void instantiate_double(double expr, int freq);
static void instantiate_double(std::string expr, int freq);
static void instantiate_int(int expr, int freq);
static void instantiate_int(std::string expr, int freq);
static void instantiate_char(double expr, int freq);
static void instantiate_char(std::string expr, int freq);

// Float
static void instantiate_float(double expr, int freq)
{
    std::cout << "float: " << static_cast<float>(expr) << std::endl;
    freq += 1;
    if (freq == 3)
        return;
    instantiate_double(expr, freq);
}

static void instantiate_float(std::string expr, int freq)
{
    if (freq == 0 && (expr[expr.length() - 1] == 'f' || expr[expr.length() - 1] == 'F'))
    {
        try
        {
            std::cout << "float: " << static_cast<float>(std::atof(expr.c_str())) << std::endl;
            freq += 1;
            instantiate_double(static_cast<double>(std::atof(expr.c_str())), freq);
        }
        catch (...)
        {
            
        }
    }
    instantiate_double(expr, freq);
}


// Double

static void instantiate_double(double expr, int freq)
{

    std::cout << "double: " << static_cast<double>(expr) << std::endl;
    freq += 1;
    if (freq == 3)
        return;
    instantiate_int(expr, freq);
}

static void instantiate_double(std::string expr, int freq)
{
    if (freq == 0 && expr.find('.') != std::string::npos && (expr[expr.length() - 1] != 'f' || expr[expr.length() - 1] != 'F'))
    {
        try
        {
            std::cout << "double: " << static_cast<double>(std::atoll(expr.c_str())) << std::endl;
            freq += 1;
            instantiate_int(static_cast<double>(std::atoll(expr.c_str())), freq);
        }
        catch (...)
        {
            
        }
    }
    instantiate_int(expr, freq);
}

//int
static void instantiate_int(double expr, int freq)
{

    std::cout << "int: " << static_cast<int>(expr) << std::endl;
    freq += 1;
    if (freq == 3)
        return;
    instantiate_char(expr, freq);
}

static void instantiate_int(std::string expr, int freq)
{
    if (freq == 0 && expr.find('.') == std::string::npos && (expr[expr.length() - 1] != 'f' || expr[expr.length() - 1] != 'F'))
    {
        try
        {
            std::cout << "int: " << static_cast<int>(std::atoi(expr.c_str())) << std::endl;
            freq += 1;
            instantiate_char(static_cast<double>(std::atoi(expr.c_str())), freq);
        }
        catch (...)
        {
            
        }
    }
    instantiate_char(expr, freq);
}

// Char
static void instantiate_char(double expr, int freq)
{
    std::cout << "char: " << static_cast<char>(expr) << std::endl;
    freq += 1;
    if (freq == 3)
        return;
    instantiate_float(expr, freq);
}

static void instantiate_char(std::string expr, int freq)
{
    if (freq == 0 && expr.length() == 1 && !((expr.at(0) >= 0 && expr.at(0) <= 31) || expr.at(0) == 127))
    {
        try
        {
            std::cout << "char: " << static_cast<char>(expr.at(0)) << std::endl;
            freq += 1;
            instantiate_float(static_cast<double>(atol(expr.c_str())), freq);
        }
        catch (...)
        {
            
        }
    }
    instantiate_float(expr, freq);
}


void ScalarConverter::convert(std::string expr)
{
    if (expr.length() == 0)
    {
        std::cerr << "[ERROR]: Expression Declared doesn't exists.";
        return;
    }
    instantiate_float(expr, 0);
}