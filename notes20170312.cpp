HEAP
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
  Birdie * b;

  b = &mybirdie;		// b points to the stack object
  b = new Birdie(); // b points to a heap object (new Birdie() returns a pointer)
  delete b;

} // destructor called on mybirdie object
  // b pointer will be gone but destructor not called

Stack of func():
|-------------|
| func (4)    | pointer
| mybirdie(20)|
| b (4) ----^ | pointer (b = &mybirdie)
_________|____|
         |
         --------->_______________ (b = new Birdie())
                  |  new Birdie |
                  |--------------
b2 = new Birdie();


class Container
{
   Birdie stackobj;  // DEFINITELY doesn't need a destructor
   Birdie * p; 			 // will be cleaned up by default destructor
   Container()
   {
      p = new Birdie();
   }
   ~Container()
   {
     if ( p != NULL )
     { 
       delete p;	// if you declare a destructor, delete the pointer p
     }
   }
}
