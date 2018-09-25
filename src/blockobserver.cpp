#include "blockobserver.h"

void BlockObserver::update(const std::string str){
    if(str == "{"){
        print_obs();
        model_sub->notyfy();
    }
    else if(str == "}")
        return;
    else{
        m_vector.emplace_back(str);
        ++count;
        if(count>=n_arg){
            count = 0;
            print_obs();
        }
    }
}

void BlockObserver::switch_obs(){
    lock=!lock;
    count = 0;
}

void BlockObserver::print_to_file(const std::string &str){
    auto &file = model_sub->outfile;
    std::string tab = "\t\t|\n";
    for(auto i:m_vector){
        file<<i+tab;
    }
    file<<"\t\t|"<<" "<<str<<std::endl;
}
