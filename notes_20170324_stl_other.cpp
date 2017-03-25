std::map< K, V >          // sorted by the key    O( log( N ) ) in Red-Black tree
std::multimap< K, V >     // sorted by the key
std::unordered_map< K, V >               //   O( 1 ) in hashmap
std::unordered_multimap< K, V >

typedef std::unordered_multimap< int, std::string > MyMapType;
typedef MyMapType::iterator MyMapIter;

MyMapType mymap;
MyMapIter found_it = mymap.find( 42 );

if ( found_it != mymap.end() )
{
   std::cout << found_it->first << " :: " << found_it->second << std::endl;
}


============================== Fastest Performance to find a specific KEY ==============================
  
 fewer than ~15 elements: std::vector< std::pair< K, V > >   // O( n )
 fewer than ~1000 elements: std::map< K, V >                 // O( log(N) )
 otherwise: std::unordered_map< K, V >                       // O( 1 )

template < typename T >
class Node
{
   T data;
   Node * left;
   Node * right;
}

CACHELINE ~64 or ~128 bytes
Cache Hit - the thing is in cache (very fast)
Cache Miss - the thing is NOT in cache (10x for evry jump to L1 -> L2 -> L3 -> Main Memory)
  
std::vector< Birdie > birdies;
std::sort( birdies.begin(), birdies.end(), birdieComparator );


====================================== std::string =======================================
roughly equivalent to std::vector< char >
  
 std::string str;
 for ( std::string::iterator it = str.begin(); it != str::end(); ++ it )
 {
    std::cout << *it;
 }
  
// convert to c style array
// http://www.cplusplus.com/reference/string/string/
// http://www.cplusplus.com/reference/array/array/begin/
// http://www.cplusplus.com/reference/queue/queue/

const char * arr = str.c_str();
