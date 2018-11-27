//
// Created by Bartosz Sobocki on 2018-10-15.
//

#include <iostream>
#include <fstream>
#include <exception>

#ifndef STREAMS_LINE_READER_H
#define STREAMS_LINE_READER_H


class EOFException : public std::exception {

public:
    EOFException() = default;
    ~EOFException() = default;

public :
    virtual std::string what(){
        return "End Of File!";
    }
};

class line_reader {

private:
    //reference to file stream
    std::ifstream& istr;
    //variable saying if file is okay
    bool good;

public:
    //constructors
    line_reader() = delete;
    line_reader( std::ifstream &i): istr(i) {}
    ~line_reader();

    //functions
    std::string ReadNextLine() throw (EOFException);
    void reload(const std::string & src);
    void close();

    //getters
    bool getGood();
};


#endif //STREAMS_LINE_READER_H
