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
