//////////////////////// c-style error handling //////////////////////

/// f3 -> f2 -> myfunc() //

int myfunc( int * out, int input )
{
   if ( someErrorCondition() )
   {
      return -1;
   }
  

   *out = 42; 
  
   return 0;
}

int f2()
{
  int out;
  int rc = myfunc( &out, 1232 );
  
  if ( rc != 0 )
  {
      // handle error
      // print error
      return rc;
  }

  useTheValueOf( out );
  
  return 0;
}

int f3()
{
  // do stuff

  int rc = f2();
  
  if ( rc != 0 )
  {
      return rc;
  }
  
  // do more stuff
  return 0;
}


////////////////////////// c++ exceptions /////////////////////////////

int myfunc( int input )
{
   if ( someErrorCondition() )
   {
      throw exception();
   }

   return 42;
}

void f2()
{
  int out = myfunc( 1232 );

  useTheValueOf( out );
}

void f3()
{
  try
  {
    // do stuff
    f2();
    // do more stuff
  }
  catch ( const exception& e )
  {
     std::cout << "exception happened!" << e.what() << std::end;
  }
}
