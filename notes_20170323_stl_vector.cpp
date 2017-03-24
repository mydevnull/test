================ STL (standard template? library) =====================

//////////////// 1. vectors ///////////////////
  
[...............                      ................ vec      .............]

namespace std
{
  template < typename T >
  class vector
  {
    struct iterator {};
     T * ptr;   // pointer to array of T
  }
}

a) contiguous
b) internally an array allocated on the heap

std::vector< int > intvec;	// create a vecror
intvec.reserve( 3 );        // reserve 3 spaces for the vector
intvec.push_back( 1 );		  // adds a value at the end (possibly resize the vector)
intvec.push_back( 2 );
intvec.push_back( 3 );

int * c_arr = &intvec[ 0 ]; // before c++11
int * c_arr = intvec.data(); // c++11

std::vector< int >::iterator intvec.begin(); // points to the first element in the vector
std::vector< int >::iterator intvec.end(); // points to the element after the last in the vector

  intvec.begin()
   |           | intvec.end();
[  1 | 2 | 3 ] . ]
   ^
   it
// before c++11
for ( std::vector< int >::const_iterator it  = intvec.begin();  // notice const_iterator
                                         it != intvec.end();
                                      ++ it )
{
   int val = *it;
   std::cout << val;
}

for ( size_t ii = 0; ii < intvec.size(); ii++ )
{
   int val = intvec[ ii ];
   std::cout << val;
}

// C++11
for ( int val : intvec )  // equivalent to const_iterator
{
   std::cout << val;
}

// int& is a reference type
for ( int& val : intvec ) // equivalent to std::vector< int >::iterator
{
   val = val * 2;         // multiply every value by 2
}
