//
// Created by Bartosz Sobocki on 2018-10-15.
//

#include "line_reader.h"

void line_reader::reload(const std::string & src) {
    istr.open(src, std::ios::in);
    good = istr.good();
}

std::string line_reader::ReadNextLine() throw (EOFException) {
    std::string tmp;
    if(!std::getline(istr, tmp))
        throw EOFException();
    return tmp;
}

bool line_reader::getGood () {
    return good;
}

void line_reader::close(){
    istr.close();
    std::cout<<"line reader has been closed."<<std::endl;
}
