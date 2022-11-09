#include "cuckoo_hash_table.h"

template <int count>
    StringHashFamily<count>::StringHashFamily( )
    : MULTIPLIERS( count ) { }

template <int count>
    int StringHashFamily<count>::getNumberOfFunctions( ) const {
        return count;
    }

template <int count>
    void StringHashFamily<count>::generateNewFunctions( ) {
        for (auto & mult : MULTIPLIERS ){
            mult = r.nextInt( );
        }
    }

template <int count>
    size_t StringHashFamily<count>::hash( const string & x, int which ) const {
        const int multiplier = MULTIPLIERS[ which ];
        size_t hashVal = 0;

        for( auto ch : x )
            hashVal = multiplier * hashVal + ch;

        return hashVal;
    }

template <typename AnyType, typename HashFamily>
    HashTable< AnyType, HashFamily>::HashTable( int size ) : array( nextPrime( size ) ) {
        numHashFunctions = hashFunctions.getNumberOfFunctions( );
        rehashes = 0;
        makeEmpty( );
     }

template <typename AnyType, typename HashFamily>
    bool HashTable< AnyType, HashFamily>:: contains( const AnyType & x ) const {
        return findPos( x ) != -1;
    }

template <typename AnyType, typename HashFamily>
    bool HashTable< AnyType, HashFamily>::insert( const AnyType & x ) {
        if( contains( x ) ) 
            return false;
        
        if( currentSize >= array.size( ) * MAX_LOAD )
            expand( );
        
        return insertHelper1( x );
    }

template <typename AnyType, typename HashFamily>
    bool HashTable< AnyType, HashFamily>::insert( AnyType && x ) {
        if( contains( x ) ) 
            return false;
        
        if( currentSize >= array.size( ) * MAX_LOAD )
            expand( );
        
        return insertHelper1( move( x ) );
    }

template <typename AnyType, typename HashFamily>
    int HashTable< AnyType, HashFamily>::size( ) const {
        return currentSize;
    }

template <typename AnyType, typename HashFamily>
    int HashTable< AnyType, HashFamily>::capacity( ) const {
        return array.size( );
    }

template <typename AnyType, typename HashFamily>
    bool HashTable< AnyType, HashFamily>::remove( const AnyType & x ) {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].isActive = false;
        return true;
    }

template <typename AnyType, typename HashFamily>
    bool HashTable< AnyType, HashFamily>::insertHelper( const AnyType & xx ) {
        const int COUNT_LIMIT = 100;
        AnyType x = xx;
        
        while( true )
        {
            int lastPos = -1;
            int pos;
            
            for( int count = 0; count < COUNT_LIMIT; ++count )
            {
                for( int i = 0; i < numHashFunctions; ++i )
                {
                    pos = myhash( x, i );
                    
                    if( !isActive( pos ) )
                    {
                        array[ pos ] = move( HashEntry{ move( x ), true } );
                        ++currentSize;
                        return true;
                    }
                }
                
                // None of the spots are available. Kick out random one
                int i = 0;
                do
                {
                    pos = myhash( x, r.nextInt( numHashFunctions ) );
                } while( pos == lastPos && i++ < 5 );
              
                lastPos = pos;
                swap( x, array[ pos ].element );
            }
            
            if( ++rehashes > ALLOWED_REHASHES )
            {
                expand( );     // Make the table bigger
                rehashes = 0;
            }
            else
                rehash( );
        }
    }

template <typename AnyType, typename HashFamily>
    bool HashTable< AnyType, HashFamily>::insertHelper( AnyType && xx ) {
        const int COUNT_LIMIT = 100;
        
        while( true )
        {
            int lastPos = -1;
            int pos;
            
            for( int count = 0; count < COUNT_LIMIT; ++count )
            {
                for( int i = 0; i < numHashFunctions; ++i )
                {
                    pos = myhash( xx, i );
                    
                    if( !isActive( pos ) )
                    {
                        array[ pos ] = move( HashEntry{ move( xx ), true } );
                        ++currentSize;
                        return true;
                    }
                }
                
                // None of the spots are available. Kick out random one
                int i = 0;
                do
                {
                    pos = myhash( xx, r.nextInt( numHashFunctions ) );
                } while( pos == lastPos && i++ < 5 );
              
                lastPos = pos;
                swap( xx, array[ pos ].element );
            }
            
            if( ++rehashes > ALLOWED_REHASHES )
            {
                expand( );     // Make the table bigger
                rehashes = 0;
            }
            else
                rehash( );
        }
    }

template <typename AnyType, typename HashFamily>
    bool HashTable< AnyType, HashFamily>::isActive( int currentPos ) const {
          return currentPos != -1 &&  array[ currentPos ].isActive; 
    }

/**
 * @brief Method that search all hash function places
 */
template <typename AnyType, typename HashFamily>
    int HashTable< AnyType, HashFamily>::findPos( const AnyType & x ) const {
        for( int i = 0; i < numHashFunctions; ++i )
        {
            int pos = myhash( x, i );
            
            if( isActive( pos ) && array[ pos ].element == x )
                return pos;
        }

        return -1;
    }

template <typename AnyType, typename HashFamily>
    void HashTable< AnyType, HashFamily>::expand( ) {
        rehash( static_cast<int>( array.size( ) / MAX_LOAD ) );
    }

template <typename AnyType, typename HashFamily>
    void HashTable< AnyType, HashFamily>::rehash( ) {
        hashFunctions.generateNewFunctions( );
        rehash( array.size( ) );
    }

template <typename AnyType, typename HashFamily>
    void HashTable< AnyType, HashFamily>::rehash( int newSize ) {
        vector<HashEntry> oldArray = array;

        // Create new double-sized, empty table
        array.resize( nextPrime( newSize ) );
        for( auto & entry : array )
            entry.isActive = false;
        
        // Copy table over
        currentSize = 0;
        for( auto & entry : oldArray )
            if( entry.isActive )
                insert( move( entry.element ) );
    }

template <typename AnyType, typename HashFamily>
    size_t HashTable< AnyType, HashFamily>::myhash( const AnyType & x, int which ) const {
        return hashFunctions.hash( x, which ) % array.size( );
    }

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
