====================== TEMPLATES (static polymorphism) ========================
Template Meta-programming

///////////////////////////// CLASS TEMPLATES //////////////////////////////////////
template < typename T >
class Birdie
{
   T data;
   
public:
   void sayHoot()
   {
      std::cout << "Hoot with " << data << "!" << std::endl;
   }
};

class Test {
   double stuff;
};

friend ostream& operator << ( ostream& os, const Test& t )
{
   os << "stuff: " << t.stuff;
   return os;
}
/////////////////////////////////////// function templates ////////////////////////
template < typename T >
void func( const T& obj )
{
  // do something with obj
}

typedef unsigned long long size_t;

template< typename T, size_t SIZE >
void doSomethingWithArray( T(&)[ SIZE ] arr )
{
   for ( size_t ii = 0; ii < SIZE; ++ ii )
   {
      std::cout << arr[ ii ];
   } 
}

void main()
{
   Birdie< int > b1;  // specializing Birdie template for integers
   Birdie< double > b2();  // specializing Birdie template for doubles
   Birdie< Test > b3; 
  
   func< int >( 5 ); // to explicitly call func with ints
   func( 5 );
   func( Test() ); // Test() creates temporary object on stack
  
   int arr[ 50 ];		// stack allocated array
   doSomethingWithArray( arr );
  
   
   int * arr2 = new int[ n ];  // points to the first element of the array
   doSomethingWithArray( *arr2 );  // would not compile
}
