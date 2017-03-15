#include <iostream>
#include <string>
#include <stdexcept>

// ssh birdie hi
// ssh birdie again
class Bearee; // forward declare Bearee

class Birdie
{
private:

    // member variables
    const int       m_identifier;
    std::string     m_name;

public:

    // defauilt constructor
    Birdie()
      : m_identifier ( 0 )
      , m_name       ()
    {
        std::cout << m_name << " :: " << m_identifier << ": entered default constructor!" << std::endl;
    }

    
    // constructor
    Birdie( const int identifier, const std::string& name ) // const arguments will not be modified
      : m_identifier ( identifier )
      , m_name       ( name )
    {
        std::cout << m_name << " :: " << m_identifier << ": entered constructor!" << std::endl;
    }

    // destructor
    ~Birdie()
    {
        std::cout << m_name << " :: " << m_identifier << ": entered destructor!" << std::endl;
    }

    // a public method
    void sayHoot() const // const at the end of method means method will not modify any member variables
    {
          std::cout << "I'm a '" << m_name << "/" << m_identifier << "' hoot!" << std::endl;
    }
};

int main( int argc, const char * argv[] )
{
    try
    {
        Birdie b1( 1, "good" );
        Birdie b2( 2, "bad" );

        b1.sayHoot();

        throw std::runtime_error( "oh no!" ); // interrupts the flow - caught by try/catch

        b2.sayHoot();    // will never run

        std::cout << "HOOT HOOT" << std::endl;    // will never print

        // b2 will be destroyed first
        // b1 will be destroyed second
    }
    catch ( const std::exception& e )
    {
        // exception is caught after all the objects on the stack have been destroyed
        std::cout << "exception in main: " << e.what() << std::endl;
    }
}
