#ifndef DYNAMICOBSERVER_H
#define DYNAMICOBSERVER_H

#include "subject.h"

class DynamicBlock:public Observer{
public:
    DynamicBlock(Subject*model)
        :controle_str("{"){
        model_sub = model;
        model_sub->attach(this);
    }
    void update(const std::string str);
    void init();
    void print_to_file(const std::string &str);
private:
    std::string controle_str;
};

#endif // DYNAMICOBSERVER_H
