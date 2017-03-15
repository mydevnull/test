
: stackobj( 1, "blah" )
, p (NULL)HEAP
  ________________________________________________________________
  |    |  40    |                                                |
  ----------------------------------------------------------------
b----^

      Birdie * b;  // modifiable pointer
const Birdie * b2;  // modifiable pointer, const Object
      Birdie * const b3; // modifiable object, const pointer
const Birdie * const b4; // both const

void func()
{
  Birdie mybirdie;
  Birdie birdie2( 1, 2, "asdasd" );
  Birdie * b;

  b = &mybirdie;		// b points to the stack object
  b = new Birdie(); // b points to a heap object (new Birdie() returns a pointer)
  Birdie * c = b;
  c->sayHoot();   // ok
  delete b;
  c->sayHoot();   // seg fault
  
} // destructor called on mybirdie & birdie2 object
  // b pointer will be gone but destructor not called

Stack of func():
|-------------|
| func (4)    | pointer
| mybirdie(20)|
| birdie2(20) |
| b (4) ----^ | pointer (b = &mybirdie)
| c (4) --    |
_________|____|
         |
         --------->_______________ (b = new Birdie())
                  |  new Birdie |
                  |--------------
b2 = new Birdie();


class Container
{
   Birdie stackobj;  // DEFINITELY doesn't need a destructor
   Birdie * p; 			 // if you OWN this pointer (i.e. allocating it), be sure to clean it up in the destructor
   Container()
     : stackobj( 1, "blah" )
     , p (NULL)
   {
      p = new Birdie();
   }
   ~Container()
   {
     if ( p != NULL )
     { 
       delete p;	// make sure to delete the pointer p
     }
   }   // destructor called for stackobj
}


void f2()
{
     Container c();
}   // destructor for container called
