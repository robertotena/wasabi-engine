/* 
 * File:   SuperFastHash.h
 * Author: Paul Hsieh
 * This code is under de LGPL 2.1 License. http://www.azillionmonkeys.com/qed/hash.html For more info.
 * Created on 9 de diciembre de 2010, 18:14
 */

#ifndef SUPERFASTHASH_H
#define	SUPERFASTHASH_H

#include <stdint.h>
#include <cstdio>
#include <string>

#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                       +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif

namespace {

    uint32_t SuperFastHash(const char * data, int len) {
        uint32_t hash = len, tmp;
        int rem;

        if (len <= 0 || data == NULL) return 0;

        rem = len & 3;
        len >>= 2;

        /* Main loop */
        for (; len > 0; len--) {
            hash += get16bits(data);
            tmp = (get16bits(data + 2) << 11) ^ hash;
            hash = (hash << 16) ^ tmp;
            data += 2 * sizeof (uint16_t);
            hash += hash >> 11;
        }

        /* Handle end cases */
        switch (rem) {
            case 3: hash += get16bits(data);
                hash ^= hash << 16;
                hash ^= data[sizeof (uint16_t)] << 18;
                hash += hash >> 11;
                break;
            case 2: hash += get16bits(data);
                hash ^= hash << 11;
                hash += hash >> 17;
                break;
            case 1: hash += *data;
                hash ^= hash << 10;
                hash += hash >> 1;
        }

        /* Force "avalanching" of final 127 bits */
        hash ^= hash << 3;
        hash += hash >> 5;
        hash ^= hash << 4;
        hash += hash >> 17;
        hash ^= hash << 25;
        hash += hash >> 6;

        return hash;
    }
}

namespace WasabiEngine {

    class WasabiHash {
    public:

        static unsigned int hash(const char * data, int len) {
            return SuperFastHash(data, len);
        }

        static unsigned int hash(const std::string& data) {
            return SuperFastHash(data.c_str(), data.length());
        }
    };
}
#endif	/* SUPERFASTHASH_H */

