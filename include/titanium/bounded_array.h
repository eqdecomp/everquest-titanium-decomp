// Fixed-size array whose operator[] checks the index and breaks into the debugger when it is out of range,
// then still returns the element. Written `if (i < N) return data[i]; __debugbreak(); return data[i];` the two
// returns merge into one store after the `int3`, and a clear loop `for (unsigned i = 0; i < N; ++i) a[i] = 0;`
// keeps the store in the loop (byte-offset induction, `cmp r,N*4`, no `rep stosd`), as the original does.
// The `if (i >= N) __debugbreak(); return data[i];` spelling lets VC split the loop into `stosd` stores plus an
// empty check loop. Proved by 0x004BE82F, 0x004BC5D2, 0x004BDC13 (src/EverQuest/tu_080_EQ_PC.cpp, probe).
#ifndef TITANIUM_BOUNDED_ARRAY_H
#define TITANIUM_BOUNDED_ARRAY_H

template <class T, unsigned int N>
struct BoundedArray_guess {
    T data[N];

    T& operator[](int index) {
        if ((unsigned int)index < N) {
            return data[index];
        }
        __debugbreak();
        return data[index];
    }
};

#endif
