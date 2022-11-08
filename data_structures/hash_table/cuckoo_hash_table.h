#ifndef CUCKOO_HASH_TABLE_H
#define CUCKOO_HASH_TABLE_H

#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

#include "../uniform_random.h"

using namespace std;

/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime( int n )
{
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime( int n )
{
    if( n % 2 == 0 )
        ++n;

    for( ; !isPrime( n ); n += 2 )
        ;

    return n;
}

/**
 * A hash routine for string objects.
 */
int hashCode( const string & key )
{
    int hashVal = 0;

    for( auto ch : key )
        hashVal = 37 * hashVal + ch;

    return hashVal;
}

/**
 * A hash routine for ints.
 */
int hashCode( int key )
{
    return key;
}

template <typename AnyType>
class CuckooHashFamily
{
    public:
        size_t hash( const AnyType & x, int which ) const;
        int getNumberOfFunctions( );
        void generateNewFunctions( );
};

template <int count>
class StringHashFamily {
    public:
        StringHashFamily( );
        int getNumberOfFunctions( ) const;
        void generateNewFunctions( );
        size_t hash( const string & x, int which ) const;
    
    private:
        vector<int> MULTIPLIERS;
        UniformRandom r;
};

#define MAX_LOAD 0.40  /* g++ 4.6 does not support static const double */

// CuckooHashing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hashCode( string str ) --> Global method to hash strings

template <typename AnyType, typename HashFamily>
class HashTable {
    public:
        explicit HashTable( int size = 101 );

        bool contains( const AnyType & x ) const;
        void makeEmpty( );
        bool insert( const AnyType & x );
        bool insert( AnyType && x );
        int size( );
        int capacity( );
        bool remove( const AnyType & x );

    private:
        struct HashEntry
        {
            AnyType element;
            bool isActive;

            HashEntry( const AnyType & e = AnyType( ), bool a = false )
            : element{ e }, isActive{ a } { }    

            HashEntry( AnyType && e, bool a = false )
            : element{ std::move( e ) }, isActive{ a } { }
        };

        vector<HashEntry> array;
        int currentSize;
        int numHashFunctions;
        int rehashes;
        UniformRandom r;
        HashFamily hashFunctions;

        static const int ALLOWED_REHASHES = 5;

        /* Internal Methods */
        bool insertHelper( const AnyType & xx );
        bool insertHelper( AnyType && x);

        bool isActive( int currentPos ) const;
        void expand( );
        void rehash( );
        void rehash( int newSize );
        size_t myhash( const AnyType & x, int which ) const;
};

#endif
