  i  i  i  i  d  d  d  d  d  d  d  d  c  c       p  p      
|__|__|__|__|__|__|__|__|__|__|__|__|__|__|_________________|
0  1  2  3  4  

/****** RAII / Guard Object *******/
class DatabaseConnection
{
   void open();
   void write( const int[] data );
   void close();
}
 
class ConnectionGuard
{
private:

     DatabaseConnection * m_db;

public:
    
    ConnectionGuard ( const DatabaseConnection * db )
       : m_db( db )
    {
       m_db->open();
    }
    
    ~ConnectionGuard()
    {
       m_db->close();
    }
}

void workWithDatabase()
{
   DatabaseConnection dbconn;
   ConnectionGuard guard( &dbconn );
   throw runtime_error("basdasd");
   dbconn.write( .... );
} // connection closed here


int i = 5;
int i( 5 );

sizeof( C )
struct Record
{
   
   int area_code;
   int phone_number;
   std::string persons_name;
   
   Record()
   		: area_code( 0 ), phone_number( 0 ), persons_name( "" )
   {
   }
   
   Record( int a, int p, const std::string& pn )
   		: area_code( a ), phone_number( p ), persons_name( pn )
   {
   }

   ~Record()
   {
   	  // destructor
      r.phone_number= 5;



   }
};

// "less than" operator for Record
bool compareRecordsByName( const Record& p1, const Record& p2 )
{
   return p1.persons_name < p2.persons_name;
}

// "less than" operator for Record
bool compareRecordsByPhoneNumber( const Record& p1, const Record& p2 )
{
   return p1.phone_number < p2.phone_number;
}

struct RecordsByPhoneNumberComparator
{
    bool operator( const Record& p1, const Record& p2 )
    {
       return p1.phone_number < p2.phone_number;
    }
};
_________
|    f   |
|    f1  | <- stack pointer 
|    f2  | 
|     i(4)|
|     d(8)|
|     r(16)|
|-----------


void f2()
{ 
   int i = 0;
   double d = 6;
   Record r;
   r.phone_number= 5;



}

void f1()
{
  f2();
}

void f()
{
  f1();
}




RecordsByPhoneNumberComparator comparator;

void main()
{
  Record r;			// default constructor
  Record r2();  // defualt constructor
  Record r3( 5, 512, "asdas" );	 // 3 params consturctor
  
  Record * rp = new Record();
  // use rp
  rp->phone_number = 123;
  
  
  
  
  delete rp;
  
  
	std::vector< Record > vec; //create instance of vector
  vec.push_back( r );
  vec.push_back( r2 );
  vec.push_back( r3 );
  vec.push_back( Record() );
  vec.push_back( Record( 1, 2, "blah" ) );
  vec.push_back( Record( 2, 2123, "asd" ) );
  vec.push_back( Record( 1, 255, "1234" ) );
  vec.push_back( Record( 3, 21, "234" ) );
  vec.push_back( Record( 6, 25, "asd" ) );
  
  Record * arr = &vec[ 0 ];

	std::sort( vec.begin(), vec.end(), comparator );
}


class C
{
   int i; // member / instnace var
   double d;
   char c;
   
   void * p;
   
   
   
   
   void foo()
   {
    int j = 1; // local
    
      j = i + 5;  // 
   } 
}



void hi()
{
	 int i = 0; // local
   
   Birdie b;   // create an object 
}
