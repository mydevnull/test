
void f()
{
    Birdie a;
    
    // pointer
    Birdie * pointer = &a;
    pointer->sayHoot();
    pointer->name() = "bird-bird";
    pointer ++;				// cannot do with references!
    pointer = null;   // cannot do with references!

    // const reference 
    const Birdie& ref = a;  // think of it as alias with const restriction
    ref.sayHoot();
    
    // non-const reference
    Birdie& ref2 = a;       		// an alias without const restriction
    ref2.sayHoot();				  		// can run const functions
    ref2.name() = "bird-bird";  // can modify a through the refernce;
}


//////////////////// with references ///////////////////////
void f2( const Birdie& b )
{
   b.sayHoot();
}

// to call f2()
Birdie mybirdie;
f2( mybirdie ); // const Birdie& b = mybirdie;


//////////////////// with pointers ///////////////////////
void f2( const Birdie * b )
{
   b->sayHoot();
}

// to call f2()
Birdie mybirdie;
f2( &mybirdie );    // note the dereferencing operator

/////////////////// pass by copy *** USUALLY VERY SLOW!!!! **** /////////////////////
void f2( const Birdie b )
{
   b.sayHoot();
}

// to call f2()
Birdie mybirdie;
f2( mybirdie ); // const Birdie b = mybirdie;






void f3( int i )
{
   i = 50;
}

int j = 10;
f3( j );
// j == 10
