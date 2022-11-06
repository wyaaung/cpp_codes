#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) {
            return false;
        }
    return true;
}

int nextPrime(int n)
{
    for (; !isPrime(n); n++);
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
                    : element{ std::move( e ) }, info{ i}{}
            };

            vector<HashEntry> array;
            int currentSize;

            bool isActive( int currentPos ) const;
            int findPos( const HashedObj & x ) const;
            void rehash();
            size_t myhash( const HashedObj & x ) const;
    };
