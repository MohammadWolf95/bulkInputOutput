#ifndef BLOCKOBSERVER_H
#define BLOCKOBSERVER_H

#include "subject.h"

class BlockObserver:public Observer{
public:
    BlockObserver(Subject*model, size_t N)
        :n_arg(N), count(0){
        model_sub = model;
        lock = true;
        model_sub->obs = this;
        model_sub->attach(this);
    }
    size_t n_arg, count;
    void update(const std::string str);
    void switch_obs();
    void print_to_file(const std::string &str);
};

#endif // BLOCKOBSERVER_H
