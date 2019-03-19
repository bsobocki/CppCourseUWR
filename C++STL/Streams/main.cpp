#include "line_reader.h"
#include <memory>

int main() {

    //stream moderator
    std::cout << std::boolalpha;

    try
    {
        //making a new intelligent pointer
        std::ifstream i("test.txt");
        std::shared_ptr<line_reader> LN = std::make_shared <line_reader> (i);
        std::shared_ptr<line_reader> LN2 = LN ;

        //check if file is good
        std::cout<<"czy wszystko ok? "<<LN->getGood()<<std::endl;

        //writting a first line
        std::cout<<LN->ReadNextLine()<<std::endl;

        //writting rest of lines
        while(true){
            std::cout<<LN2->ReadNextLine()<<std::endl;
        }
    }
    catch(EOFException & e)
    { std::cout<<"something went wrong: "<<e.what()<<std::endl; }
}