#include "subject.h"
#include "utils.h"

void Subject::set_str(std::string& str){
    remove_space(str);
    if(str!="")
        obs->update(str);
}

void Subject::notyfy(){ //такой метод я просто скопировал из этой ссылки
                        //http://cpp-reference.ru/patterns/behavioral-patterns/observer/
                        //Пытался использовать паттерн observer. Но потом я что-то никак не
                        //могу понять как такой паттерн использовать здесь
    /*if(_outfile.is_open()){
        closeFile();
    }*/
    //createFile(std::to_string(get_fixed_time())+".log");
    /*for(auto&i:_views){
        i->switch_obs();    //опять же я пытался использовать этот паттерн observer как по ссылке
                            //выше. Для blockobserver он count делает равным 0,
                            //а для dynamicobserver controle_str делает равным "{"
        if(i->lock)
            obs = i;
    }*/
    switch_obs();
    obs->init();
}

size_t &Subject::get_time(){
    return _fixedTime = clock();
}

const size_t&Subject::get_fixed_time(){
    return _fixedTime;
}

void Subject::createFile(std::string name){
    closeFile();
    _outfile.open(name, std::fstream::in | std::fstream::out | std::fstream::app);
    _outfile<<"input | output"<<std::endl;
    _outfile<<"------|-------"<<std::endl;
}

void Subject::closeFile(){
    if(_outfile.is_open())
        _outfile.close();
}

void Subject::switch_obs(){
    if(obs==_views.at(0))
        obs = _views.at(1);
    else
        obs = _views.at(0);
}

