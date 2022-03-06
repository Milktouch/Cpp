#include <iostream>
#include <vector>
#include <sstream>
class integer{
    public:
        int val;
        integer(int value){
        val=value;
        }
};
class character{
    public:
        char val;
        character(char value){
            val=value;
        }
};
class string{
    public:
        std::string val;
        std::vector<char> array;
        string(std::string value){
            val=value;
            std::stringstream ss(value);
            
        }
};
class boolean
{
public:
    bool val;
    boolean(bool value) {
        val = value;
    }
};

int main(){
    string str = string("meow");
    std::cout<<str.val;
    return 0;
}