#ifndef UNIFROM_RANDOM_H
#define UNIFROM_RANDOM_H

#include <chrono>
#include <random>
#include <functional>

typedef unsigned int uint;

using namespace std;

class UniformRandom {
    public:
        UniformRandom( int seed = currentTimeSeconds( ) )
        : generator{ seed } {}

        // Return a pseudorandom int
        int nextInt( ) {
            static uniform_int_distribution< uint > distribution;
            return distribution( generator );
        }

        // Return a pseudorandom int in range [0...high)
        int nextInt( int high ) {
            return nextInt( 0, high );
        }

        // Return a pseudorandom int in range [low...high)
        int nextInt( int low, int high ) {
            uniform_int_distribution< uint > distribution( low, high );
            return distribution( generator );
        }

        // Return a pseudorandom double in the range [0....1)
        double nextDouble( ) {
            static uniform_real_distribution< double > distribution( 0, 1 );
            return distribution( generator );
        }


    private:
        mt19937 generator;
};

int currentTimeSeconds( ) {
    auto now = chrono::high_resolution_clock::now( ).time_since_epoch( );
    return ( chrono::duration_cast<chrono::seconds>( now )).count( );
}

#endif
