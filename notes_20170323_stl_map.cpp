

//////////////// 2. unordered_map ///////////////////
ref: http://www.cplusplus.com/reference/utility/pair/
ref: http://www.cplusplus.com/reference/unordered_map/unordered_map/


ASSOSIATIVE CONTAINER

c++ hashtable

  struct myhashfunction{
  		int operator()
      {
      }
   };
  
std::unordered_map< std::string, Birdie, myhashfuncion > str_to_birdie_map;

/* www.cplusplus.com/reference/utility/pair/
 pair
 {
     std::string first;
     Birdie      second;
 }
*/
str_to_birdie_map.insert( std::make_pair( "good_birdie", Birdie( "good", 123 ) ); // using temporaries

// using non-temporary stack values
Birdie b1( "hi", 23423 );
Birdie b2;

str_to_birdie_map.insert( std::make_pair( "b1", b1 ) );
str_to_birdie_map.insert( std::make_pair( "b2", b2 ) );

"b1" -> b1
"b2" -> b2
"good_birdie" -> Birdie( "good", 123 )
                         
// iterate through all the values
// before c++11
typedef std::unordered_map< std::string, Birdie, myhashfuncion > BirdieMap;
for ( BirdieMap::const_iterator pair_it  = str_to_birdie_map.begin();
     														pair_it != .end();
     											   ++ pair_it )
{
   const std::string& key = pair_it->first;	// why not std::string key = it->first;
   const Birdie& value = pair_it->second;    // so that we *don't* make a copy of the object!
   std::cout << key << " -> " << value;
   std::cout << pair_it->first << " -> " << pair_it->second;  // same thing but inline
}
                         
// c++11 syntax:
for ( auto pair : str_to_birdie_map )
{
   std::cout << pair.first << " -> " << pair.second;
}

// access / set a value
                         
const Birdie& birdie =  str_to_birdie_map[ "b1" ];   // 
str_to_birdie_map[ "b1" ] = Birdie( "new birdie", 123 );
str_to_birdie_map[ "non_existing_value123" ] = Birdie();  // equivalent to str_to_birdie_map.insert( std::make_pair( "non_existing_value123", Birdie() )
