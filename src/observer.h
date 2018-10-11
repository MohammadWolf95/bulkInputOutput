#ifndef OBSERVER_H
#define OBSERVER_H

#include "subject.h"
#include <string>
#include <vector>

class Subject;

class Observer{
public:
    Observer()
        :lock(false){}
    virtual ~Observer(){}
    virtual void update(const std::string str)=0;
    virtual void switch_obs()=0;
    virtual void print_to_file(const std::string &str)=0;
    void print_obs();
    bool lock;
    //void remove_space(std::string &str);
protected:
    Subject*model_sub;
    std::vector<std::string>m_vector;
};

#endif // OBSERVER_H
