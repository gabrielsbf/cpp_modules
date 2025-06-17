#include "includes/utils.hpp"

std::string change_string(int position, std::string find_txt, std::string replace_txt, std::string line)
{
    line.insert(position, replace_txt);
    line.erase(position + replace_txt.length(), find_txt.length());
    return (line);
}
void    replace_and_write(std::string find_txt, std::string replace_txt, std::string line, std::ofstream &write_file)
{
    int find_index = 0;
    int stored_index = 0;
    std::string change_str = line;

    while (line.find(find_txt) != std::string::npos)
    {
        find_index = line.find(find_txt);
        stored_index += find_index;
        line = std::string(&line.data()[find_index + find_txt.length()]);
        change_str = change_string(stored_index, find_txt, replace_txt, change_str);
        stored_index += replace_txt.length();
    }
    write_file << change_str << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
    }
    else
    {
        std::string file_name = argv[1];
        std::string new_file_name = file_name + ".replace";
        std::ifstream read_file(argv[1]);

        if (!read_file.is_open()) {
            std::cerr << "Error: Could not open read_file" << std::endl;
            return 1;
        }
        std::ofstream write_file(new_file_name.c_str());
        std::string line;

        while (std::getline(read_file, line)) {
            replace_and_write(argv[2], argv[3], line, write_file);   
        }

        read_file.close();
        write_file.close();
    }
    return (0);
     
}