#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

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

template <typename HashedObj>
    class HashTable {
        public:
            explicit HashTable( int size = 101 );

            bool contains( const HashedObj & x ) const;

            void makeEmpty( );
            bool insert( const HashedObj & x );
            bool insert( HashedObj && x );
            bool remove( const HashedObj & x );

            enum EntryType { ACTIVE, EMPTY, DELETED };

        private:
            struct HashEntry {
                HashedObj element;
                EntryType info;

                HashEntry( const HashedObj & e = HashedObj{ }, EntryType i = EMPTY )
                    : element{ e }, info{ i }{}

                HashEntry( HashedObj && e, EntryType i = EMPTY )
                    : element{ move( e ) }, info{ i }{}
            };

            vector<HashEntry> array;
            int currentSize;

            bool isActive( int currentPos ) const;
            int findPos( const HashedObj & x ) const;
            void rehash();
            size_t myhash( const HashedObj & x ) const;
    };

#endif
