#include "dynamicobserver.h"

void DynamicObserver::update(const std::string str){
    if(str == "{"){

        controle_str += str;
    }
    else if(str == "}"){
        controle_str = controle_str.substr(0, controle_str.size()-1);
        if(controle_str==""){
            print_obs();
            model_sub->notyfy();
        }
    }
    else{
        m_vector.emplace_back(str);
    }
}

void DynamicObserver::init(){
    controle_str = "{"; //Здесь я сохраняю скобку, потому что, когда мы вводим знак "{", то
                            //Subject::Observer*obs будет типа DynamicObserver, и поэтому мы заранее
                            //сохраняем эту скобку
}

void DynamicObserver::print_to_file(const std::string &str){
    auto &file = model_sub->_outfile;
    std::string tab = "\t\t|\n";
    file<<"{"+tab;
    for(auto i:m_vector){
        file<<i+tab;
    }
    file<<"}"+tab;
    file<<"\t\t|"<<" "<<str<<std::endl;
}
