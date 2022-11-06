#include "separate_chaining.h"

template <typename HashedObj>
    HashTable<HashedObj>::HashTable( int size ) : currentSize{ 0 }
        { theLists.resize( 101 ); }

template <typename HashedObj>
    bool HashTable<HashedObj>::contains( const HashedObj & x ) const {
        auto & whichList = theLists[ myhash( x ) ];
        return find( begin( whichList ), end( whichList ), x ) != end( whichList );
    }

template <typename HashedObj>
    void HashTable<HashedObj>::makeEmpty() {
        for( auto & thisList : theLists ) {
            thisList.clear( );
        }
    }

/**
 * @brief Insert x as active
 * we enlarge the hash table if the load factor exceeds 0.5
 */
template <typename HashedObj>
    bool HashTable<HashedObj>::insert( const HashedObj & x ) {
        auto & whichList = theLists[ myhash( x ) ];

        if( find( begin( whichList ), end( whichList ), x ) != end( whichList) ) {
            return false;
        }

        whichList.push_back( x );


        if( ++currentSize > theLists.size( ) ) {
            rehash( );
        }

        return true;
    }

template <typename HashedObj>
    bool HashTable<HashedObj>::insert( HashedObj && x ) {
        auto & whichList = theLists[ myhash( x ) ];

        if( find( begin( whichList ), end( whichList ), x ) != end( whichList) ) {
            return false;
        }

        whichList.push_back( move( x ) );


        if( ++currentSize > theLists.size( ) ) {
            rehash( );
        }

        return true;
    }

template <typename HashedObj>
    bool HashTable<HashedObj>::remove( const HashedObj & x ) {
        auto & whichList = theLists[ myhash( x ) ];
        auto itr = find( begin( whichList ), end( whichList ), x );

        if( itr == end( whichList ) ) {
            return false;
        }

        whichList.erase( itr );
        --currentSize;

        return true;
    }

/****************** Internal Methods ******************/

template <typename HashedObj>
    void HashTable<HashedObj>::rehash() {
        vector<list<HashedObj>> oldLists = theLists;

        // Create new double-sized, empty table
        theLists.resize( nextPrime( 2 * theLists.size( ) ) );

        for( auto & thisList : theLists ) {
            thisList.clear( );
        }

            // Copy table over
        currentSize = 0;
        for( auto & thisList : oldLists ) {
            for( auto & x : thisList ) {
                insert( std::move( x ) );
            }
        }
    }

template <typename HashedObj>
    size_t HashTable<HashedObj>::myhash( const HashedObj & x ) const {
        static hash<HashedObj> hf;
        return hf( x ) % array.size( );
    }
