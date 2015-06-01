#include <iostream>

class Birdie
{
 
public:
    
    Birdie()
    {
        std::cout << "entered constructor" << std::endl;
    }
            
    ~Birdie()
    {
        std::cout << "entered destructor" << std::endl;
    }
};

int main ( int argc, const char * argv[] )
{
    
    Birdie b;
    
    std::cout << "HOOT HOOT";

}
