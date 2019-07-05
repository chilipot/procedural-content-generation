#include <iostream>
#include <ctime>
#include <cmath>

//--------------------------------------------------------------------------------------------------
using namespace std;

//--------------------------------------------------------------------------------------------------
class LCG
{
public:
    void seed( unsigned long s ) { _seed = s; }

protected:
    LCG() : _seed( 0 ), _a( 0 ), _c( 0 ), _m( 2147483648 ) {}
    long rnd() { return( _seed = ( _a * _seed + _c ) % _m ); }

    long _a, _c;
    unsigned long _m, _seed;
};

//--------------------------------------------------------------------------------------------------
class MS_RND : public LCG
{
public:
    MS_RND()  { _a = 214013; _c = 2531011; }
    long rnd() { return LCG::rnd() >> 16; }
};

//--------------------------------------------------------------------------------------------------
class BSD_RND : public LCG
{
public:
    BSD_RND() { _a = 1103515245; _c = 12345; }
    long rnd() { return LCG::rnd(); }
};

//--------------------------------------------------------------------------------------------------
class POSIX_RND : public LCG
{
public:
  POSIX_RND() { _a = 25214903917; _c = 11; _m = pow( 2, 48 ); }
  long rnd() { return LCG::rnd(); }
};

//--------------------------------------------------------------------------------------------------
class RND : public LCG
{
public:
  RND() { _a = 1103515245; _c = 2531011; _seed = time( 0 ); }
  long rnd() { return LCG::rnd(); }
};

//--------------------------------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
    BSD_RND bsd_rnd;
    MS_RND ms_rnd;
    POSIX_RND posix_rnd;
    RND def_rnd;

    bsd_rnd.seed( time(0) );
    ms_rnd.seed( time(0) );

    cout << "MS RAND:" << endl << "========" << endl;
    for( int x = 0; x < 10; x++ )
	   cout << ms_rnd.rnd() << endl;

    cout << endl  << "BSD RAND:" << endl << "=========" << endl;
    for( int x = 0; x < 10; x++ )
	   cout << bsd_rnd.rnd() << endl;

    cout << endl  << "POSIX RAND:" << endl << "=========" << endl;
    for( int x = 0; x < 10; x++ )
	   cout << posix_rnd.rnd() << endl;

    cout << endl  << "TIME RAND:" << endl << "=========" << endl;
    for( int x = 0; x < 10; x++ )
	   cout << def_rnd.rnd() << endl;

    cout << endl << endl;
    return 0;
}
