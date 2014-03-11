
#include "LOC_test.hpp""

#include <string.h>
#include <stdlib.h>

#define BOOST_TEST_MODULE MyTest
#include <boost/test/minimal.hpp>


int test_main( int, char *[] )             // note the name!
{
    // six ways to detect and report the same error:
    //    BOOST_CHECK( add( 2,2 ) == 4 );        // #1 continues on error
    LOC_test lt;
    //lt.check_file_type("fskl.cpp");
    BOOST_CHECK(lt.check_file_type("fs.cpp") == 1 );
    return 0;

//    cout << "Continued" << endl;
//    BOOST_REQUIRE( add( 2,2 ) ==  4);      // #2 throws on error
//    cout << "Again Continued" << endl;
//    if( add( 2,2 ) != 4 )
//        BOOST_ERROR( "Ouch..." );          // #3 continues on error
//    if( add( 2,2 ) != 4 )
//        BOOST_FAIL( "Ouch..." );           // #4 throws on error
//    if( add( 2,2 ) != 4 ) throw "Oops..."; // #5 throws on error
//
//    return add( 2, 2 )?0:1;
}

