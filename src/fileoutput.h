#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include <iostream>
#include <fstream>

class Fileoutput
{
public:
    Fileoutput();
    size_t& get_time();
    const size_t&get_fixed_time();
    void createFile(std::string name);
    void closeFile();
private:
    size_t _fixedTime;
    std::ofstream _outfile;
};

#endif // FILEOUTPUT_H
