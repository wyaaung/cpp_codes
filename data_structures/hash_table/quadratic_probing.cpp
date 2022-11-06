#include "quadratic_probing.h"

template <typename HashedObj>
    HashTable<HashedObj>::HashTable( int size ) : array( nextPrime( size ) )
        { makeEmpty(); }

template <typename HashedObj>
    bool HashTable<HashedObj>::contains( const HashedObj & x ) const {
        return isActive( findPos( x ) );
    }

template <typename HashedObj>
    void HashTable<HashedObj>::makeEmpty() {
        currentSize = 0;
        for( auto & entry : array ) {
            entry.info = EMPTY;
        }
    }

/**
 * @brief Insert x as active
 * we enlarge the hash table if the load factor exceeds 0.5
 */
template <typename HashedObj>
    bool HashTable<HashedObj>::insert( const HashedObj & x ) {
        int currentPos = findPos( x );

        if (isActive( currentPos )) {
            return false;
        }

        array[ currentPos ].element = x;
        array[ currentPos ].info = ACTIVE;

        if( ++currentSize > array.size( ) / 2 ) {
            rehash();
        }

        return true;
    }

template <typename HashedObj>
    bool HashTable<HashedObj>::insert( HashedObj && x ) {
        int currentPos = findPos( x );

        if (isActive( currentPos )) {
            return false;
        }

        array[ currentPos ].element = move( x );
        array[ currentPos ].info = ACTIVE;

        if( ++currentSize > array.size( ) / 2 ) {
            rehash();
        }

        return true;
    }

template <typename HashedObj>
    bool HashTable<HashedObj>::remove( const HashedObj & x ) {
        int currentPos = findPos( x );

        if (!isActive( currentPos )) {
            return false;
        }

        array[ currentPos ].info = DELETED;
        return true;
    }

/****************** Internal Methods ******************/

template <typename HashedObj>
    bool HashTable<HashedObj>::isActive( int currentPos ) const {
        return array[ currentPos ].info == ACTIVE;
    }

/**
 * @brief Quadratic Probing is used to find the position to put the object
 */
template <typename HashedObj>
    int HashTable<HashedObj>::findPos( const HashedObj & x ) const {
        int offset = 1;
        int currentPos = myhash( x );

        while( array[ currentPos ].info != EMPTY &&
            array[ currentPos ].element != x ) {
                currentPos += offset;  // Compute ith probe
                offset += 2;
                if( currentPos >= array.size( ) ) {
                    currentPos -= array.size( );
                }
            }

        return currentPos;
    }

template <typename HashedObj>
    void HashTable<HashedObj>::rehash() {
        vector<HashEntry> oldArray = array;

        // Create new double-sized, empty table
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        for( auto & entry : array ) {
            entry.info = EMPTY;
        }

        currentSize = 0;
        for( auto & entry : oldArray ) {
            if( entry.info == ACTIVE ) {
                insert( move( entry.element ) );
            }
        }
    }

template <typename HashedObj>
    size_t HashTable<HashedObj>::myhash( const HashedObj & x ) const {
        static hash<HashedObj> hf;
        return hf( x ) % array.size( );
    }

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
