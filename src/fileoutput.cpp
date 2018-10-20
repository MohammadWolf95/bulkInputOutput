#include "fileoutput.h"

Fileoutput::Fileoutput()
{

}

size_t &Fileoutput::get_time(){
    return _fixedTime = clock();
}

const size_t&Fileoutput::get_fixed_time(){
    return _fixedTime;
}

void Fileoutput::createFile(std::string name){
    closeFile();
    _outfile.open(name, std::fstream::in | std::fstream::out | std::fstream::app);
    _outfile<<"input | output"<<std::endl;
    _outfile<<"------|-------"<<std::endl;
}

void Fileoutput::closeFile(){
    if(_outfile.is_open())
        _outfile.close();
}
