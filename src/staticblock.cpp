#include "blockobserver.h"

void BlockObserver::update(const std::string str){
    if(str == "{"){
        print_obs();
        model_sub->createFile(std::to_string(model_sub->get_fixed_time())+".log");
        model_sub->notyfy();
    }
    /*else if(count==0){
        model_sub->createFile(std::to_string(model_sub->get_fixed_time())+".log");
    }*/
    else if(str == "}")
        return;
    else{
        if(count==0)
            model_sub->createFile(std::to_string(model_sub->get_fixed_time())+".log");
        m_vector.emplace_back(str);
        ++count;
        if(count==n_arg){
            count = 0;
            print_obs();
            /*if(model_sub->_outfile.is_open()){
                model_sub->closeFile();
            }
            model_sub->createFile(std::to_string(model_sub->get_fixed_time())+".log");*/
        }
    }
}

void BlockObserver::init(){
    count = 0;
}

void BlockObserver::print_to_file(const std::string &str){
    auto &file = model_sub->_outfile;
    std::string tab = "\t\t|\n";
    for(auto i:m_vector){
        file<<i+tab;
    }
    file<<"\t\t|"<<" "<<str<<std::endl;
}
