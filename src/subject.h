#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"
#include <vector>
#include <string>
#include <fstream>

class Observer;

class Subject{
public:
    friend class StaticBlock;
    friend class DynamicBlock;
    void attach(Observer*obs){
        _views.emplace_back(obs);
    }
    void set_str(std::string &str);
    size_t& get_time();
    const size_t&get_fixed_time();
    void createFile(std::string name);
    void closeFile();

private:
    std::vector<Observer*>_views;
    Observer*obs;
    void notyfy();
    size_t _fixedTime;
    std::ofstream _outfile;
    void switch_obs();
};

#endif // SUBJECT_H
