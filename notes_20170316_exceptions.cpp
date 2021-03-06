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
      std::cout << "myfunc returned an error: error code = " << rc << "!" << std::endl;
     
      return rc;
  }

  useTheValueOf( out );
  
  return 0;
}

void f3()
{
  // do stuff

  int rc = f2();
  
  if ( rc != 0 )
  {
      std::cout << "f2 returned an error: error code = " << rc << "!" << std::endl;
  }
  
  // do more stuff
}


////////////////////////// c++ exceptions /////////////////////////////

int myfunc( int input )
{
   if ( someErrorCondition() )
   {
      throw std::runtime_error( "someErrorCondition() check failed!" );
      // the function will break-out here and will never return 42 //
   }

   return 42;
}

void f2()
{
  int out = myfunc( 1232 );

  useTheValueOf( out );
}

void f3() noexcept   // indicate to the callers of f3 that it will not throw any exceptions
{
  try
  {
    // do stuff
    f2();
    // do more stuff
  }
  catch ( const std::runtime_error& re )
  {
     std::cout << "runtime_error happened: " << re.what() << std::endl;
  }
  catch ( const std::exception& e )
  {
     std::cout << "generic exception happened: " << e.what() << std::endl;
     // will print out "exception happened: someErrorCondition() check failed!"
  }
  catch ( ... )
  {
     std::cout << "unknown exception happened!" << std::endl;
  }
}
