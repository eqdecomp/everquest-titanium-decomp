// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 95: a hint from compare/tumap.py.
// Bignum and RSA code matching George Barwood's public vlong.cpp: VlongValue_guess is vlong_value (words,
// capacity, count, share count at +0xC), Vlong_guess is vlong, Monty_guess is monty (Montgomery modexp);
// tu_031's J_guess::Encrypt_guess is public_key::encrypt. The tail is unrelated: the voice macro manager
// (VoiceData.txt, VoiceFiles.txt, OP_VoiceMacroOut), a CXStr array and a 16-slot reset.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/wnd/CContainerMgr.h"

extern "C" int __cdecl strcmp(const char* string1_guess, const char* string2_guess);

#define g_state_guess EQ_GLOBAL(int, 0x009247AC)
#define g_enabled_guess EQ_GLOBAL(unsigned char, 0x00923D7C)

struct TwoFieldObject_guess {
    int unknown00_guess;
    int unknown04_guess;
    int unknown08_guess;

    // EXTERNAL: TITANIUM 0x0050F3F6 TwoFieldObject_guess::InitializeFirst_guess
    void InitializeFirst_guess();
    // EXTERNAL: TITANIUM 0x004C1715 TwoFieldObject_guess::InitializeSecond_guess
    void InitializeSecond_guess();
};

struct CompositeObject_guess {
    int unknown00_guess;
    TwoFieldObject_guess field04_guess;
    int unknown10_guess;
    TwoFieldObject_guess field14_guess;

    void Destroy_guess();
};

struct FlaggedObject_guess {
    int unknown00_guess;
    int unknown04_guess;
    int unknown08_guess;
    int unknown0C_guess;
    unsigned char flag10_guess;
    int unknown14_guess;
    int unknown18_guess;
    int unknown1C_guess;
    unsigned char flag20_guess;

    FlaggedObject_guess();
};

struct VlongValue_guess {
    int* values_guess;
    unsigned int capacity_guess;
    unsigned int count_guess;
    int share_000c_guess;

    VlongValue_guess() {
        capacity_guess = 0;
        values_guess = 0;
        count_guess = 0;
        share_000c_guess = 0;
    }

    void Reserve_guess(unsigned int capacity);
    void set_guess(unsigned int index, int value_guess);
    int GetValue_guess(unsigned int index);
    int IsBitSet_guess(unsigned int index);
    unsigned int BitLength_guess();
    int Compare_guess(VlongValue_guess* other_guess);
    void Reset_guess(int value_guess);
    void SetPair_guess(int first_guess, int second_guess);
    void CopyFrom_guess(VlongValue_guess* other_guess);
    void shl_guess();
    void shr_guess();
    void shr_by_guess(unsigned int bits_guess);
    // EXTERNAL: TITANIUM 0x004B8F50 VlongValue_guess::BeforeFree_guess
    void BeforeFree_guess();
    // EXTERNAL: TITANIUM 0x004B8F2D VlongValue_guess::Release_guess
    void Release_guess();
    void fast_mul_guess(VlongValue_guess& x_guess, VlongValue_guess& y_guess, unsigned int keep_guess);
    void Mul_guess(VlongValue_guess& x_guess, VlongValue_guess& y_guess);
    void Add_guess(VlongValue_guess& x_guess);
    void Subtract_guess(VlongValue_guess& x_guess);
    void Divide_guess(VlongValue_guess& x_guess, VlongValue_guess& y_guess, VlongValue_guess& rem_guess);
};


// vlong: a shared value (the share count is unknown0C_guess) plus a sign.
struct Vlong_guess {
    VlongValue_guess* value_guess; // 0x0
    int negative_guess;               // 0x4
    Vlong_guess(int first_guess = 0, int second_guess = 0);
    Vlong_guess(const Vlong_guess& other_guess);
    ~Vlong_guess();
    void DoCopy_guess();
    int Compare_guess(Vlong_guess other_guess);
    Vlong_guess& assign_guess(Vlong_guess other_guess);
    Vlong_guess& Add_guess(const Vlong_guess& x_guess);
    Vlong_guess& Subtract_guess(const Vlong_guess& x_guess);
};

// EXTERNAL: TITANIUM 0x00447428 VlongNotEqual_guess
int __cdecl VlongNotEqual_guess(const Vlong_guess& first_guess, const Vlong_guess& second_guess);
// EXTERNAL: TITANIUM 0x0044744E VlongLess_guess
int __cdecl VlongLess_guess(const Vlong_guess& first_guess, const Vlong_guess& second_guess);

Vlong_guess __cdecl vlong_mul_guess(const Vlong_guess& x_guess, const Vlong_guess& y_guess);
Vlong_guess __cdecl vlong_sub_guess(const Vlong_guess& x_guess, const Vlong_guess& y_guess);
Vlong_guess __cdecl Divide_guess(const Vlong_guess& x_guess, const Vlong_guess& y_guess);
Vlong_guess __cdecl modinv_guess(const Vlong_guess& a_guess, const Vlong_guess& m_guess);

struct J_guess;

struct Monty_guess {
    Vlong_guess r_guess;   // 0x00
    Vlong_guess r1_guess;  // 0x08
    Vlong_guess m_guess;   // 0x10
    Vlong_guess n1_guess;  // 0x18
    Vlong_guess t_guess;   // 0x20
    Vlong_guess k_guess;   // 0x28
    unsigned int n_guess;  // 0x30
    Monty_guess(const Vlong_guess& modulus_guess);
    ~Monty_guess();
    void Mul_guess(Vlong_guess* x_guess, Vlong_guess* y_guess);
    Vlong_guess Exp_guess(int value_guess, J_guess* first_guess);
};

struct Element_guess {
    virtual ~Element_guess();

    // EXTERNAL: TITANIUM 0x005ECCC0 Element_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005DFCC0 Element_guess::SecondCheck_guess
    char SecondCheck_guess();
};

struct SlotOwner_guess {
    unsigned char flag00_guess;
    unsigned char flag01_guess;
    int firstValues04_guess[4];
    int secondValues14_guess[4];
    Element_guess* slots24_guess[16];
    int field64_guess;

    void Reset_guess();
};

#define g_slotState_guess EQ_GLOBAL(int, 0x00905CE0)

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);
// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);
// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size);

struct LocalValues_guess : VlongValue_guess {
    ~LocalValues_guess() {
        if (values_guess != 0) {
            free(values_guess);
        }
    }
};

// Shift-and-subtract long division: *this = x / y, rem = x % y.
// FUNCTION: TITANIUM 0x004CA85B
void VlongValue_guess::Divide_guess(VlongValue_guess& x_guess, VlongValue_guess& y_guess, VlongValue_guess& rem_guess) {
    Reset_guess(0);
    rem_guess.CopyFrom_guess(&x_guess);
    LocalValues_guess divisor_guess;
    LocalValues_guess power_guess;
    divisor_guess.CopyFrom_guess(&y_guess);
    power_guess.count_guess = 0;
    power_guess.set_guess(0, 1);
    while (rem_guess.Compare_guess(&divisor_guess) > 0) {
        divisor_guess.shl_guess();
        power_guess.shl_guess();
    }
    while (rem_guess.Compare_guess(&y_guess) >= 0) {
        while (rem_guess.Compare_guess(&divisor_guess) < 0) {
            divisor_guess.shr_guess();
            power_guess.shr_guess();
        }
        rem_guess.Subtract_guess(divisor_guess);
        Add_guess(power_guess);
    }
}

struct CXStrVectorData_guess {
    // EXTERNAL: TITANIUM 0x004056CE CXStrVectorData_guess::VectorDeletingDestructor_guess
    void VectorDeletingDestructor_guess(unsigned int flags_guess);
};

struct CXStrArray_guess {
    int count00_guess;          // 0x00
    CXStr* data04_guess;        // 0x04
    int capacity08_guess;       // 0x08
    unsigned char flag0C_guess; // 0x0C

    void Reserve_guess(int size_guess);
    void SetAt_guess(int index_guess, const CXStr& value_guess);
};

// Deletes the 16 items held at +0x24, first closing (and freeing) the window of any that is an open bag
// (container manager 0x004FAA17); then zeroes the two 4-dword arrays, both flags, +0x64 and the global
// at 0x00905CE0.
// FUNCTION: TITANIUM 0x004CA176
void SlotOwner_guess::Reset_guess() {
    for (int i = 0; i < 16; ++i) {
        if (slots24_guess[i] != 0) {
            if (slots24_guess[i]->GetItemClass_guess() == 1) {
                if (slots24_guess[i]->SecondCheck_guess() != 0) {
                    pinstCContainerMgr_guess->CloseContainer_guess(slots24_guess[i], 1);
                }
            }
            delete slots24_guess[i];
            slots24_guess[i] = 0;
        }
    }
    for (int j = 0; j < 4; ++j) {
        firstValues04_guess[j] = 0;
        secondValues14_guess[j] = 0;
    }
    flag00_guess = 0;
    flag01_guess = 0;
    g_slotState_guess = 0;
    field64_guess = 0;
}

// Word `index`, 0 past the top.
// FUNCTION: TITANIUM 0x004CA1E6
int VlongValue_guess::GetValue_guess(unsigned int index) {
    if (index >= count_guess) {
        return 0;
    }
    return values_guess[index];
}

// Grows the int array to exactly `capacity` entries, copying the used ones and freeing the old block;
// smaller or equal requests do nothing.
// FUNCTION: TITANIUM 0x004CA1FB
void VlongValue_guess::Reserve_guess(unsigned int capacity) {
    if (capacity <= capacity_guess) {
        return;
    }
    int* newValues_guess = (int*)operator new(capacity << 2);
    unsigned int index_guess = 0;
    while (index_guess < count_guess) {
        newValues_guess[index_guess] = values_guess[index_guess];
        ++index_guess;
    }
    free(values_guess);
    values_guess = newValues_guess;
    capacity_guess = capacity;
}

// Keeps the count normalised: the top word is never zero.
// FUNCTION: TITANIUM 0x004CA23F
void VlongValue_guess::set_guess(unsigned int index, int value_guess) {
    if (index < count_guess) {
        values_guess[index] = value_guess;
        if (value_guess == 0) {
            while (count_guess != 0 && values_guess[count_guess - 1] == 0) {
                --count_guess;
            }
        }
        return;
    }
    if (value_guess == 0) {
        return;
    }
    unsigned int newCount_guess = index + 1;
    Reserve_guess(newCount_guess);
    unsigned int fill_guess = count_guess;
    while (fill_guess < index) {
        values_guess[fill_guess] = 0;
        ++fill_guess;
    }
    values_guess[index] = value_guess;
    count_guess = newCount_guess;
}

// vlong_value: whether bit `index` is set.
// FUNCTION: TITANIUM 0x004CA424
int VlongValue_guess::IsBitSet_guess(unsigned int index) {
    return (GetValue_guess(index >> 5) & (1 << (index & 0x1f))) != 0;
}

// Bit length: one past the top set bit (the library's bits()).
// FUNCTION: TITANIUM 0x004CA448
unsigned int VlongValue_guess::BitLength_guess() {
    unsigned int bitIndex_guess = count_guess << 5;
    while (bitIndex_guess != 0 && !IsBitSet_guess(bitIndex_guess - 1)) {
        --bitIndex_guess;
    }
    return bitIndex_guess;
}

// Unsigned magnitude compare: -1, 0 or 1.
// FUNCTION: TITANIUM 0x004CA470
int VlongValue_guess::Compare_guess(VlongValue_guess* other_guess) {
    if (count_guess > other_guess->count_guess) {
        return 1;
    }
    if (count_guess < other_guess->count_guess) {
        return -1;
    }
    unsigned int index_guess = count_guess;
    while (index_guess != 0) {
        --index_guess;
        if ((unsigned int)GetValue_guess(index_guess) >
            (unsigned int)other_guess->GetValue_guess(index_guess)) {
            return 1;
        }
        if ((unsigned int)GetValue_guess(index_guess) <
            (unsigned int)other_guess->GetValue_guess(index_guess)) {
            return -1;
        }
    }
    return 0;
}

// Doubles the value; `i` runs to the count inclusive so a carry out gets a new word.
// FUNCTION: TITANIUM 0x004CA4D4
void VlongValue_guess::shl_guess() {
    unsigned int count = count_guess;
    unsigned int carry = 0;
    for (unsigned int i = 0; i <= count; ++i) {
        unsigned int value = GetValue_guess(i);
        set_guess(i, value * 2 + carry);
        carry = value >> 31;
    }
}

// Halves the value.
// FUNCTION: TITANIUM 0x004CA506
void VlongValue_guess::shr_guess() {
    unsigned int count = count_guess;
    unsigned int carry = 0;
    while (count != 0) {
        --count;
        unsigned int value = GetValue_guess(count);
        set_guess(count, (value >> 1) + carry);
        carry = value << 31;
    }
}

// Shifts right by `bits` (the divide by R in Montgomery reduction).
// FUNCTION: TITANIUM 0x004CA539
void VlongValue_guess::shr_by_guess(unsigned int bits_guess) {
    unsigned int wordOffset_guess = bits_guess >> 5;
    bits_guess &= 0x1f;
    for (unsigned int i = 0; i < count_guess; ++i) {
        unsigned int value = GetValue_guess(i + wordOffset_guess);
        if (bits_guess != 0) {
            value = (value >> bits_guess) +
                    (GetValue_guess(i + wordOffset_guess + 1) << (32 - bits_guess));
        }
        set_guess(i, value);
    }
}

// vlong addition: this += x, 32-bit word by word with carry, through one word past the longer operand.
// FUNCTION: TITANIUM 0x004CA592
void VlongValue_guess::Add_guess(VlongValue_guess& x_guess) {
    unsigned int carry = 0;
    unsigned int max = count_guess;
    if (max < x_guess.count_guess) {
        max = x_guess.count_guess;
    }
    Reserve_guess(max);
    for (unsigned int i = 0; i < max + 1; i += 1) {
        unsigned int u = GetValue_guess(i);
        u = u + carry;
        carry = (u < carry);
        unsigned int ux = x_guess.GetValue_guess(i);
        u = u + ux;
        carry += (u < ux);
        set_guess(i, u);
    }
}

// Magnitude subtract; needs *this >= x.
// FUNCTION: TITANIUM 0x004CA5FC
void VlongValue_guess::Subtract_guess(VlongValue_guess& x_guess) {
    unsigned int count = count_guess;
    unsigned int borrow = 0;
    for (unsigned int i = 0; i < count; ++i) {
        unsigned int b = x_guess.GetValue_guess(i);
        unsigned int t = b + borrow;
        // When b + borrow wraps, subtracting 2^32 leaves the word as is and the borrow carries on
        // (library code).
        if (t >= borrow) {
            unsigned int a = GetValue_guess(i);
            unsigned int r = a - t;
            borrow = a < r;
            set_guess(i, r);
        }
    }
}

// vlong_value: becomes the single word `value`.
// FUNCTION: TITANIUM 0x004CA646
void VlongValue_guess::Reset_guess(int value_guess) {
    count_guess = 0;
    set_guess(0, value_guess);
}

// A 64-bit value from two words, low first.
// FUNCTION: TITANIUM 0x004CA658
void VlongValue_guess::SetPair_guess(int first_guess, int second_guess) {
    count_guess = 0;
    set_guess(0, first_guess);
    set_guess(1, second_guess);
}

// vlong_value: copies every word of `other`.
// FUNCTION: TITANIUM 0x004CA67B
void VlongValue_guess::CopyFrom_guess(VlongValue_guess* other_guess) {
    count_guess = 0;
    unsigned int index_guess = other_guess->count_guess;
    while (index_guess != 0) {
        --index_guess;
        set_guess(index_guess, other_guess->GetValue_guess(index_guess));
    }
}

// x * y kept to the low `keep` bits, from 16x16-bit partial products (the library's fast_mul).
// FUNCTION: TITANIUM 0x004CA2AA
// @early-stop: budget, structural ndiff=138
void VlongValue_guess::fast_mul_guess(VlongValue_guess& x_guess, VlongValue_guess& y_guess,
                                        unsigned int bits_guess) {
    unsigned int words_guess = (bits_guess + 0x1f) >> 5;
    Reserve_guess(words_guess);
    unsigned int z_guess = 0;
    if (words_guess != 0) {
        do {
            values_guess[z_guess] = 0;
            z_guess = z_guess + 1;
        } while (z_guess < words_guess);
    }
    unsigned int xCount_guess = x_guess.count_guess;
    if (words_guess < xCount_guess) {
        xCount_guess = words_guess;
    }
    unsigned int i_guess = 0;
    if (xCount_guess != 0) {
        do {
            unsigned int xv_guess = x_guess.values_guess[i_guess];
            unsigned int carry_guess = 0;
            unsigned int end_guess = y_guess.count_guess + i_guess;
            if (words_guess < end_guess) {
                end_guess = words_guess;
            }
            if (i_guess < end_guess) {
                unsigned int xl_guess = xv_guess & 0xffff;
                unsigned int xh_guess = xv_guess >> 16;
                unsigned int j_guess = 0;
                unsigned int k_guess = i_guess;
                do {
                    unsigned int yv_guess = y_guess.values_guess[j_guess];
                    unsigned int sum_guess = values_guess[k_guess] + carry_guess;
                    unsigned int s1_guess = sum_guess + xl_guess * (yv_guess & 0xffff);
                    unsigned int s2_guess = s1_guess + xh_guess * (yv_guess & 0xffff) * 0x10000;
                    unsigned int s3_guess = s2_guess + (yv_guess >> 16) * xl_guess * 0x10000;
                    j_guess = j_guess + 1;
                    values_guess[k_guess] = s3_guess;
                    k_guess = k_guess + 1;
                    carry_guess = (yv_guess >> 16) * xh_guess +
                                  (unsigned int)(sum_guess < carry_guess) +
                                  (unsigned int)(s1_guess < xl_guess * (yv_guess & 0xffff)) +
                                  ((xh_guess * (yv_guess & 0xffff)) >> 16) +
                                  (unsigned int)(s2_guess < xh_guess * (yv_guess & 0xffff) * 0x10000) +
                                  (((yv_guess >> 16) * xl_guess) >> 16) +
                                  (unsigned int)(s3_guess < (yv_guess >> 16) * xl_guess * 0x10000);
                } while (k_guess < end_guess);
                for (; carry_guess != 0 && k_guess < words_guess; k_guess = k_guess + 1) {
                    values_guess[k_guess] = values_guess[k_guess] + carry_guess;
                    carry_guess = (unsigned int)(values_guess[k_guess] < carry_guess);
                }
            }
            i_guess = i_guess + 1;
        } while (i_guess < xCount_guess);
    }
    if ((bits_guess & 0x1f) != 0) {
        values_guess[words_guess - 1] &= (1U << (bits_guess & 0x1f)) - 1U;
    }
    if (words_guess != 0) {
        int* p_guess = values_guess + words_guess - 1;
        do {
            if (*p_guess != 0) {
                break;
            }
            words_guess = words_guess - 1;
            p_guess = p_guess - 1;
        } while (words_guess != 0);
    }
    count_guess = words_guess;
}

// Full product: keep = bits(x) + bits(y).
// FUNCTION: TITANIUM 0x004CA6A9
void VlongValue_guess::Mul_guess(VlongValue_guess& x_guess, VlongValue_guess& y_guess) {
    fast_mul_guess(x_guess, y_guess, x_guess.BitLength_guess() + y_guess.BitLength_guess());
}

// Copy on write: gives this vlong its own value if the current one is shared.
// FUNCTION: TITANIUM 0x004CA6D8
void Vlong_guess::DoCopy_guess() {
    if (value_guess->share_000c_guess != 0) {
        --value_guess->share_000c_guess;
        VlongValue_guess* copy_guess = new VlongValue_guess();
        copy_guess->CopyFrom_guess(value_guess);
        value_guess = copy_guess;
    }
}

// vlong constructor from two words (low `first`, high `second`): a fresh vlong_value, not negative.
// FUNCTION: TITANIUM 0x004CA70F
Vlong_guess::Vlong_guess(int first_guess, int second_guess) {
    value_guess = new VlongValue_guess();
    negative_guess = 0;
    value_guess->SetPair_guess(first_guess, second_guess);
}

// Shares the value (share count + 1).
// FUNCTION: TITANIUM 0x004CA749
Vlong_guess::Vlong_guess(const Vlong_guess& other_guess) {
    negative_guess = other_guess.negative_guess;
    value_guess = other_guess.value_guess;
    ++value_guess->share_000c_guess;
}

// Drops a share; frees the value when it was the last.
// FUNCTION: TITANIUM 0x004CA75F
Vlong_guess::~Vlong_guess() {
    VlongValue_guess* value = value_guess;
    if (value_guess->share_000c_guess != 0) {
        --value_guess->share_000c_guess;
        return;
    }
    if (value_guess != 0) {
        value->BeforeFree_guess();
        free(value);
    }
}

// operator*.
// FUNCTION: TITANIUM 0x004CA781
Vlong_guess __cdecl vlong_mul_guess(const Vlong_guess& x_guess, const Vlong_guess& y_guess) {
    Vlong_guess result_guess(0, 0);
    result_guess.value_guess->Mul_guess(*x_guess.value_guess, *y_guess.value_guess);
    result_guess.negative_guess = x_guess.negative_guess ^ y_guess.negative_guess;
    return result_guess;
}

// Empty monty destructor; its vlong members release themselves.
// FUNCTION: TITANIUM 0x004CA7F3
Monty_guess::~Monty_guess() {
}

// Signed compare. Two negatives still compare by magnitude, so -5 > -3: the library's own quirk, harmless
// for RSA where nothing is negative.
// FUNCTION: TITANIUM 0x004CA954
int Vlong_guess::Compare_guess(Vlong_guess other_guess) {
    int thisHasValues_guess;
    if (negative_guess != 0 && value_guess->count_guess != 0) {
        thisHasValues_guess = 1;
    } else {
        thisHasValues_guess = 0;
    }
    int otherHasValues_guess;
    if (other_guess.negative_guess != 0 && other_guess.value_guess->count_guess != 0) {
        otherHasValues_guess = 1;
    } else {
        otherHasValues_guess = 0;
    }
    if (thisHasValues_guess == otherHasValues_guess) {
        return value_guess->Compare_guess(other_guess.value_guess);
    }
    if (thisHasValues_guess != 0) {
        return -1;
    }
    return 1;
}

// operator=: shares x's value.
// FUNCTION: TITANIUM 0x004CA9C3
Vlong_guess& Vlong_guess::assign_guess(Vlong_guess other_guess) {
    VlongValue_guess* old_guess = value_guess;
    if (value_guess->share_000c_guess != 0) {
        --value_guess->share_000c_guess;
    } else if (value_guess != 0) {
        old_guess->Release_guess();
        free(old_guess);
    }
    value_guess = other_guess.value_guess;
    ++value_guess->share_000c_guess;
    negative_guess = other_guess.negative_guess;
    return *this;
}

// operator+=: equal signs add; otherwise the smaller magnitude is subtracted, swapping when x is bigger.
// FUNCTION: TITANIUM 0x004CAA20
Vlong_guess& Vlong_guess::Add_guess(const Vlong_guess& x_guess) {
    if (negative_guess == x_guess.negative_guess) {
        DoCopy_guess();
        value_guess->Add_guess(*x_guess.value_guess);
    } else if (value_guess->Compare_guess(x_guess.value_guess) >= 0) {
        DoCopy_guess();
        value_guess->Subtract_guess(*x_guess.value_guess);
    } else {
        Vlong_guess tmp_guess = *this;
        assign_guess(x_guess);
        Add_guess(tmp_guess);
    }
    return *this;
}

// operator-=, the mirror of Add_guess.
// FUNCTION: TITANIUM 0x004CAABF
Vlong_guess& Vlong_guess::Subtract_guess(const Vlong_guess& x_guess) {
    if (negative_guess != x_guess.negative_guess) {
        DoCopy_guess();
        value_guess->Add_guess(*x_guess.value_guess);
    } else if (value_guess->Compare_guess(x_guess.value_guess) >= 0) {
        DoCopy_guess();
        value_guess->Subtract_guess(*x_guess.value_guess);
    } else {
        Vlong_guess tmp_guess = *this;
        assign_guess(x_guess);
        Subtract_guess(tmp_guess);
        negative_guess = 1 - negative_guess;
    }
    return *this;
}

// operator-.
// FUNCTION: TITANIUM 0x004CAB67
Vlong_guess __cdecl vlong_sub_guess(const Vlong_guess& x_guess, const Vlong_guess& y_guess) {
    Vlong_guess result_guess = x_guess;
    result_guess.Subtract_guess(y_guess);
    return result_guess;
}

// operator/.
// FUNCTION: TITANIUM 0x004CABCC
Vlong_guess __cdecl Divide_guess(const Vlong_guess& x_guess, const Vlong_guess& y_guess) {
    Vlong_guess result_guess(0, 0);
    LocalValues_guess rem_guess;
    result_guess.value_guess->Divide_guess(*x_guess.value_guess, *y_guess.value_guess, rem_guess);
    result_guess.negative_guess = x_guess.negative_guess ^ y_guess.negative_guess;
    return result_guess;
}

// operator%: the remainder takes x's sign.
// FUNCTION: TITANIUM 0x004CAC66
Vlong_guess __cdecl Mod_guess(const Vlong_guess& x_guess, const Vlong_guess& y_guess) {
    Vlong_guess rem_guess(0, 0);
    LocalValues_guess quotient_guess;
    quotient_guess.Divide_guess(*x_guess.value_guess, *y_guess.value_guess, *rem_guess.value_guess);
    rem_guess.negative_guess = x_guess.negative_guess;
    return rem_guess;
}

// modinv: a^-1 mod m by the extended Euclidean algorithm.
// FUNCTION: TITANIUM 0x004CAD26
// @early-stop: budget, structural ndiff=30
Vlong_guess __cdecl modinv_guess(const Vlong_guess& a_guess, const Vlong_guess& m_guess) {
    Vlong_guess j_guess = 1, i_guess = 0, b_guess = m_guess, c_guess = a_guess, x_guess, y_guess;
    while (VlongNotEqual_guess(c_guess, Vlong_guess(0))) {
        x_guess.assign_guess(Divide_guess(b_guess, c_guess));
        y_guess.assign_guess(vlong_sub_guess(b_guess, vlong_mul_guess(x_guess, c_guess)));
        b_guess.assign_guess(c_guess);
        c_guess.assign_guess(y_guess);
        y_guess.assign_guess(j_guess);
        j_guess.assign_guess(vlong_sub_guess(i_guess, vlong_mul_guess(j_guess, x_guess)));
        i_guess.assign_guess(y_guess);
    }
    if (VlongLess_guess(i_guess, Vlong_guess(0))) {
        i_guess.Add_guess(m_guess);
    }
    return i_guess;
}

// operator>=.
// FUNCTION: TITANIUM 0x004CACF8
int __cdecl VlongGreaterEqual_guess(Vlong_guess* first_guess,
                                   Vlong_guess* other_guess) {
    return first_guess->Compare_guess(*other_guess) >= 0;
}

struct VoiceMacroManager_guess {
    char padding_0000_guess[0x10];
    unsigned char flag10_guess;

    // EXTERNAL: TITANIUM 0x004FF9C9 VoiceMacroManager_guess::FindThing_guess
    int* FindThing_guess(int key);
    int CheckState_guess();
    bool HasMacro_guess(int key);
    int GetMacroName_guess(int key);
    int GetPlayerVoiceSet_guess();
    void LoadVoice_guess(int key, int index);
    void HandleVoiceMacroOut_guess(int code_guess, struct VoiceMacroOut_guess* request_guess);
};

struct VoiceMacroOut_guess {
    char name_guess[0x40];
    int unknown40_guess;
    int unknown44_guess;
    int value48_guess;
    int value4C_guess;
};

struct NameRoot_guess {
    char padding_0000_guess[0x120];
    char name_120_guess[1];
};

struct Validation_guess {
    // EXTERNAL: TITANIUM 0x0049297B Validation_guess::BeingIgnored_guess
    int BeingIgnored_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x004982C6 Validation_guess::dsp_chat
    void dsp_chat(const char* message_guess, int code_guess, bool flags_guess);
};

#define g_requestNameRoot_guess EQ_GLOBAL(NameRoot_guess*, 0x00905CE4)
#define g_validation_guess EQ_GLOBAL(Validation_guess*, 0x00988DF0)

// EXTERNAL: TITANIUM 0x00467AD1 AddNameToTellList_guess
void __cdecl AddNameToTellList_guess(VoiceMacroOut_guess* request_guess);

// EXTERNAL: TITANIUM 0x0046DA4A BuildRequestMessage_guess
void __cdecl BuildRequestMessage_guess(char* message_guess, int messageId_guess,
                                       VoiceMacroOut_guess* request_guess,
                                       int value_guess, int zero1_guess,
                                       int zero2_guess, int zero3_guess,
                                       int zero4_guess, int zero5_guess,
                                       int zero6_guess, int zero7_guess);

struct VoiceArray_guess {
    int count_guess;
    int unknown04_guess;
    int unknown08_guess;
    int unknown0C_guess;

    // EXTERNAL: TITANIUM 0x004EB924 VoiceArray_guess::GetAt_guess
    void* GetAt_guess(int index);
};

struct VoiceList_guess {
    int unknown00_guess;
    VoiceArray_guess names04_guess;
    VoiceArray_guess ids14_guess;
};

struct SoundManager_guess {
    char padding_0000_guess[0x1004];

    // EXTERNAL: TITANIUM 0x0044A5AE SoundManager_guess::HasVoice_guess
    int HasVoice_guess(int id);
    // EXTERNAL: TITANIUM 0x0044B6D9 SoundManager_guess::WaveLoad_guess
    void WaveLoad_guess(const char* path, int id, int flags);
    // EXTERNAL: TITANIUM 0x0044A537 SoundManager_guess::WavePlay_guess
    void WavePlay_guess(int id, int flags);
};

#define g_soundManager_guess EQ_GLOBAL(SoundManager_guess*, 0x00851390)

// EXTERNAL: TITANIUM 0x00576670 FileExists_guess
char __cdecl FileExists_guess(const char* path);

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

#include "titanium/layouts/core.h"

struct LookupRoot_guess {
    int unknown00_guess;
    int unknown04_guess;
    VBTable* holder08_guess;
};

struct LookupResult_guess {
    char padding_0000_guess[0x1194];
    unsigned char gender_1194_guess;
    unsigned int race_1198_guess;
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    LookupResult_guess* GetCharInfo2();
};

struct LookupOwner_guess {
    int unknown00_guess;
    EQ_CharacterProfileView_guess accessor04_guess;
};

struct CheckRoot_guess {
    char padding_0000_guess[0x260];
    int value_260_guess;
    // EXTERNAL: TITANIUM 0x00479E02 CheckRoot_guess::LegalPlayerRace_guess
    int LegalPlayerRace_guess(int value_guess);
};

#define g_lookupRoot_guess EQ_GLOBAL(LookupRoot_guess*, 0x00905D00)
#define g_checkRoot_guess EQ_GLOBAL(CheckRoot_guess*, 0x00905CE4)

// EXTERNAL: TITANIUM 0x004167B2 MapLookupValue_guess
int __cdecl MapLookupValue_guess(int value_guess);

// R = the smallest power of two >= m (N bits); R1 = R^-1 mod m, taken as (R - m)^-1 (the same residue);
// n1 = R - (m^-1 mod R).
// FUNCTION: TITANIUM 0x004CAFB2
Monty_guess::Monty_guess(const Vlong_guess& modulus_guess) {
    m_guess.assign_guess(modulus_guess);
    n_guess = 0;
    r_guess.assign_guess(1);
    while (VlongLess_guess(r_guess, modulus_guess)) {
        r_guess.Add_guess(r_guess);
        ++n_guess;
    }
    r1_guess.assign_guess(modinv_guess(vlong_sub_guess(r_guess, m_guess), m_guess));
    n1_guess.assign_guess(vlong_sub_guess(r_guess, modinv_guess(m_guess, r_guess)));
}

// Montgomery multiply: x = x * y / R mod m.
// FUNCTION: TITANIUM 0x004CB0ED
void Monty_guess::Mul_guess(Vlong_guess* x_guess, Vlong_guess* y_guess) {
    t_guess.value_guess->fast_mul_guess(*x_guess->value_guess, *y_guess->value_guess, n_guess << 1);
    k_guess.value_guess->fast_mul_guess(*t_guess.value_guess, *n1_guess.value_guess, n_guess);
    x_guess->value_guess->fast_mul_guess(*k_guess.value_guess, *m_guess.value_guess, n_guess << 1);
    x_guess->Add_guess(t_guess);
    x_guess->value_guess->shr_by_guess(n_guess);
    if (VlongGreaterEqual_guess(x_guess, &m_guess) != 0) {
        x_guess->Subtract_guess(m_guess);
    }
}

// x^e mod m by square-and-multiply in Montgomery form; `value_guess` is really x and `first_guess` e.
// An e of 0 never reaches the break (library quirk).
// FUNCTION: TITANIUM 0x004CB169
Vlong_guess Monty_guess::Exp_guess(int value_guess, J_guess* first_guess) {
    Vlong_guess a_guess = vlong_sub_guess(r_guess, m_guess);
    Vlong_guess b_guess = Mod_guess(vlong_mul_guess(*reinterpret_cast<Vlong_guess*>(value_guess), r_guess), m_guess);
    unsigned int bits_guess = reinterpret_cast<Vlong_guess*>(first_guess)->value_guess->BitLength_guess();
    value_guess = 0;
    while (true) {
        if (reinterpret_cast<Vlong_guess*>(first_guess)->value_guess->IsBitSet_guess(value_guess)) {
            Mul_guess(&a_guess, &b_guess);
        }
        ++value_guess;
        if ((unsigned int)value_guess == bits_guess) {
            break;
        }
        Mul_guess(&b_guess, &b_guess);
    }
    return Mod_guess(vlong_mul_guess(a_guess, r1_guess), m_guess);
}

// modexp(x, e, m).
// FUNCTION: TITANIUM 0x004CB264
Vlong_guess __cdecl ModExp_guess(int value_guess, J_guess* first_guess, J_guess* second_guess) {
    Monty_guess monty_guess(*reinterpret_cast<Vlong_guess*>(second_guess));
    return monty_guess.Exp_guess(value_guess, first_guess);
}

// VoiceMacroManager_guess is the voice macro manager. 1 when 0x9247AC and 0x923D7C are both set (probably sound
// and voice macros on).
// FUNCTION: TITANIUM 0x004CB2B7
int VoiceMacroManager_guess::CheckState_guess() {
    int result = 0;
    if (g_state_guess != 0 && g_enabled_guess != 0) {
        ++result;
    }
    return result;
}

// True when a voice macro exists for `key`; the voice macro window and /vplay check it.
// FUNCTION: TITANIUM 0x004CB2CB
bool VoiceMacroManager_guess::HasMacro_guess(int key) {
    return FindThing_guess(key) != 0;
}

// The macro's name (+0x24 of its record), or 0.
// FUNCTION: TITANIUM 0x004CB2DD
int VoiceMacroManager_guess::GetMacroName_guess(int key) {
    int* found = FindThing_guess(key);
    return found != 0 ? *found + 0x24 : 0;
}

// The player's voice set: MapLookupValue_guess(race) * 2 + gender, with the illusion's race when
// LegalPlayerRace_guess(-1) finds one (+0x1198 and +0x1194 are probably race and gender).
// FUNCTION: TITANIUM 0x004CB2F6
int VoiceMacroManager_guess::GetPlayerVoiceSet_guess() {
    LookupOwner_guess* owner_guess = reinterpret_cast<LookupOwner_guess*>(
        reinterpret_cast<char*>(g_lookupRoot_guess) +
        g_lookupRoot_guess->holder08_guess->vbase_offset + 8);
    LookupResult_guess* first_guess = owner_guess->accessor04_guess.GetCharInfo2();
    unsigned int value_guess = first_guess->race_1198_guess;
    if (g_checkRoot_guess->LegalPlayerRace_guess(-1) != 0) {
        value_guess = g_checkRoot_guess->value_260_guess;
    }
    LookupOwner_guess* second_owner_guess = reinterpret_cast<LookupOwner_guess*>(
        reinterpret_cast<char*>(g_lookupRoot_guess) +
        g_lookupRoot_guess->holder08_guess->vbase_offset + 8);
    LookupResult_guess* second_guess = second_owner_guess->accessor04_guess.GetCharInfo2();
    return second_guess->gender_1194_guess + MapLookupValue_guess(value_guess) * 2;
}

// Grows to 2n + 8 entries.
// FUNCTION: TITANIUM 0x004CB35E
void CXStrArray_guess::Reserve_guess(int size_guess) {
    int newCapacity_guess;
    CXStr* fresh_guess = 0;
    if (size_guess != 0 && (size_guess > capacity08_guess || data04_guess == 0)) {
        newCapacity_guess = size_guess * 2 + 8;
        fresh_guess = new CXStr[newCapacity_guess];
        if (fresh_guess != 0) {
            if (data04_guess != 0) {
                for (int i = 0; i < count00_guess; ++i) {
                    fresh_guess[i] = data04_guess[i];
                }
            }
            if (data04_guess != 0) {
                ((CXStrVectorData_guess*)data04_guess)->VectorDeletingDestructor_guess(3);
            }
            data04_guess = fresh_guess;
            capacity08_guess = newCapacity_guess;
        } else {
            if (data04_guess != 0) {
                ((CXStrVectorData_guess*)data04_guess)->VectorDeletingDestructor_guess(3);
            }
            data04_guess = 0;
            capacity08_guess = 0;
            flag0C_guess = 0;
        }
    }
}

// Plays voice `index` of macro `key` (-1: the player's own voice set), loading it on first use from
// voice\user\ with voice\default\ as the fallback. WavePlay_guess probably plays it.
// FUNCTION: TITANIUM 0x004CB42F
void VoiceMacroManager_guess::LoadVoice_guess(int key, int index) {
    char path_guess[512];
    if (g_state_guess == 0 || g_enabled_guess == 0 || !HasMacro_guess(key) ||
        flag10_guess != 0) {
        return;
    }
    int selection_guess = index;
    if (selection_guess == -1) {
        selection_guess = GetPlayerVoiceSet_guess();
    }
    int* found_guess = FindThing_guess(key);
    if (found_guess == 0) {
        return;
    }
    VoiceList_guess* list_guess = (VoiceList_guess*)*found_guess;
    VoiceArray_guess* names_guess = &list_guess->names04_guess;
    if (selection_guess >= names_guess->count_guess) {
        return;
    }
    key = *(int*)list_guess->ids14_guess.GetAt_guess(selection_guess);
    if (g_soundManager_guess->HasVoice_guess(key) == 0) {
        sprintf(path_guess, "%s%s", "voice\\user\\",
                (char*)*((CXStr*)names_guess->GetAt_guess(selection_guess)));
        if (FileExists_guess(path_guess) == 0) {
            sprintf(path_guess, "%s%s", "voice\\default\\",
                    (char*)*((CXStr*)names_guess->GetAt_guess(selection_guess)));
        }
        g_soundManager_guess->WaveLoad_guess(path_guess, key, 0);
    }
    if (key != -1) {
        g_soundManager_guess->WavePlay_guess(key, 0);
    }
}

// OP_VoiceMacroOut: another player's macro. Played and printed unless it is our own or the sender is
// filtered (BeingIgnored_guess, probably the ignore list): type 1 tell (string 0x1788), 2 group (0x1789),
// 3 raid (0x178A).
// FUNCTION: TITANIUM 0x004CB562
void VoiceMacroManager_guess::HandleVoiceMacroOut_guess(int code_guess, VoiceMacroOut_guess* request_guess) {
    VoiceMacroManager_guess* manager_guess = this;
    int messageId_guess;
    int* found_guess;
    char message_guess[1024];

    if (code_guess == 0x2ec6 &&
        strcmp(request_guess->name_guess, g_requestNameRoot_guess->name_120_guess) != 0 &&
        g_validation_guess->BeingIgnored_guess(request_guess->name_guess) == 0) {
        manager_guess->LoadVoice_guess(request_guess->value4C_guess, request_guess->value48_guess);
        found_guess = manager_guess->FindThing_guess(request_guess->value4C_guess);
        if (found_guess != 0) {
            switch (request_guess->unknown40_guess) {
            case 1:
                messageId_guess = 0x1788;
                code_guess = 0x101;
                AddNameToTellList_guess(request_guess);
                break;
            case 2:
                messageId_guess = 0x1789;
                code_guess = 0x102;
                break;
            case 3:
                messageId_guess = 0x178a;
                code_guess = 0x147;
                break;
            default:
                return;
            }
            BuildRequestMessage_guess(message_guess, messageId_guess, request_guess,
                                      *found_guess + 0x24, 0, 0, 0, 0, 0, 0, 0);
            g_validation_guess->dsp_chat(message_guess, code_guess, 1);
        }
    }
}

// SetElementIdx for strings: assigns `value` at `index`, first growing the array to 2n + 8 (0x004CB35E)
// and the length to index + 1 when needed. Negative indexes are ignored, and so is the store when the
// allocation failed.
// FUNCTION: TITANIUM 0x004CB65F
void CXStrArray_guess::SetAt_guess(int index_guess, const CXStr& value_guess) {
    if (index_guess >= 0) {
        if (index_guess >= count00_guess) {
            Reserve_guess(index_guess + 1);
            if (data04_guess != 0) {
                count00_guess = index_guess + 1;
            }
        }
        if (data04_guess != 0) {
            data04_guess[index_guess] = value_guess;
        }
    }
}

// Destroys a macro record's two arrays (InitializeFirst_guess / InitializeSecond_guess are probably their
// destructors, misnamed).
// FUNCTION: TITANIUM 0x004CB69A
void CompositeObject_guess::Destroy_guess() {
    field14_guess.InitializeFirst_guess();
    return field04_guess.InitializeSecond_guess();
}

// Zeroes the dwords +4..+0xC and +0x14..+0x1C and sets the flags at +0x10 and +0x20.
// FUNCTION: TITANIUM 0x004CB6AE
FlaggedObject_guess::FlaggedObject_guess() {
    unknown08_guess = 0;
    unknown04_guess = 0;
    unknown0C_guess = 0;
    flag10_guess = 1;
    unknown18_guess = 0;
    unknown14_guess = 0;
    unknown1C_guess = 0;
    flag20_guess = 1;
}

struct Bucket_guess {
    int* values_guess;
    int count_guess;
    int field08_guess;
    int field0c_guess;

    // EXTERNAL: TITANIUM 0x0042F092 Bucket_guess::Bucket_guess
    Bucket_guess(int capacity_guess);
    // EXTERNAL: TITANIUM 0x004C9745 Bucket_guess::~Bucket_guess
    ~Bucket_guess();
    // EXTERNAL: TITANIUM 0x00447C66 Bucket_guess::Insert_guess
    void Insert_guess(void** value_guess, int key_guess);
    // EXTERNAL: TITANIUM 0x004FF9C9 Bucket_guess::FindThing_guess
    int* FindThing_guess(int key_guess);
    // EXTERNAL: TITANIUM 0x004466FA Bucket_guess::First_guess
    CompositeObject_guess** First_guess();
    // EXTERNAL: TITANIUM 0x0042EC1A Bucket_guess::Next_guess
    CompositeObject_guess** Next_guess(CompositeObject_guess** entry_guess);
    // EXTERNAL: TITANIUM 0x0048F513 Bucket_guess::Clear_guess
    void Clear_guess();
};

struct VoiceMacroTable_guess : Bucket_guess {
    unsigned char flag10_guess; // 0x10
    int field14_guess;          // 0x14

    // EXTERNAL: TITANIUM 0x004CB6CD VoiceMacroTable_guess::Load_guess
    void Load_guess(const char* data_guess, const char* files_guess);
    VoiceMacroTable_guess();
    ~VoiceMacroTable_guess();
};

struct VoiceFile_guess {
    // EXTERNAL: TITANIUM 0x00576BD0 VoiceFile_guess::Open_guess
    VoiceFile_guess* Open_guess(const char* path_guess, int delimiter_guess);
    // EXTERNAL: TITANIUM 0x00576D10 VoiceFile_guess::IsOpen_guess
    char IsOpen_guess();
    // EXTERNAL: TITANIUM 0x00576C60 VoiceFile_guess::GetLineCount_guess
    int GetLineCount_guess();
    // EXTERNAL: TITANIUM 0x00576CF0 VoiceFile_guess::ReadLine_guess
    void ReadLine_guess(char* line_guess, int size_guess);
    // EXTERNAL: TITANIUM 0x00576C50 VoiceFile_guess::Close_guess
    void Close_guess();
};

struct VoiceIndexMap_guess {
    int default_guess;
    // EXTERNAL: TITANIUM 0x0050319B VoiceIndexMap_guess::SetAt_guess
    void SetAt_guess(int key_guess, int* value_guess);
};

struct VoiceMacroRecord_guess : FlaggedObject_guess {
    char padding_guess[64];
};

// EXTERNAL: TITANIUM 0x00574830 HasVoiceLine_guess
int __cdecl HasVoiceLine_guess(const char* line_guess, int flags_guess);
// EXTERNAL: TITANIUM 0x00576D80 ReadVoiceNumber_guess
int __cdecl ReadVoiceNumber_guess(char** line_guess, int delimiter_guess);
// EXTERNAL: TITANIUM 0x00576D20 ReadVoiceField_guess
void __cdecl ReadVoiceField_guess(char* output_guess, int size_guess,
                                  char** line_guess, int delimiter_guess);
// EXTERNAL: TITANIUM 0x00574310 CopyVoiceField_guess
void __cdecl CopyVoiceField_guess(char* output_guess, const char* input_guess,
                                  int size_guess);
// EXTERNAL: TITANIUM 0x00574110 VoiceError_guess
void __cdecl VoiceError_guess(const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory_guess);

// VoiceData.txt: macro id ^ name, ids under 1000. VoiceFiles.txt: macro id ^ voice index ^ file name;
// names are stored per voice index (up to 1024) and each file gets a sound id counting up from 4000.
// FUNCTION: TITANIUM 0x004CB6CD
// @early-stop: budget, structural ndiff=169
void VoiceMacroTable_guess::Load_guess(const char* data_guess,
                                  const char* files_guess) {
    int macroCount_guess = 0;
    VoiceFile_guess* dataFile_guess =
        (VoiceFile_guess*)operator new(0x1000c);
    if (dataFile_guess != 0) {
        dataFile_guess = dataFile_guess->Open_guess(data_guess, 0x5e);
    }
    if (dataFile_guess->IsOpen_guess() != 0) {
        int linesLeft_guess = dataFile_guess->GetLineCount_guess();
        while (linesLeft_guess > 0) {
            char line_guess[0x1000];
            dataFile_guess->ReadLine_guess(line_guess, 0x1000);
            if (HasVoiceLine_guess(line_guess, 0) != 0) {
                char* cursor_guess = line_guess;
                int macroId_guess = ReadVoiceNumber_guess(&cursor_guess, 0x5e);
                VoiceMacroRecord_guess* record_guess =
                    new VoiceMacroRecord_guess;
                // The record allocated above is leaked when the id is rejected.
                if (macroId_guess < 1000) {
                    record_guess->unknown00_guess = macroId_guess;
                    char name_guess[0x100];
                    ReadVoiceField_guess(name_guess, 0x100,
                                         &cursor_guess, 0x5e);
                    CopyVoiceField_guess(record_guess->padding_guess,
                                         name_guess, 0x40);
                    Insert_guess((void**)&record_guess, macroId_guess);
                    ++macroCount_guess;
                } else {
                    VoiceError_guess(
                        "ERROR: Voice macro id %d is too large, max allowed is %d.",
                        macroId_guess, 999);
                }
            }
            linesLeft_guess = dataFile_guess->GetLineCount_guess();
        }
    }
    if (dataFile_guess != 0) {
        dataFile_guess->Close_guess();
        operator delete(dataFile_guess);
    }
    VoiceError_guess("Voice Manager loaded %d macros from %s.",
                     macroCount_guess, data_guess);

    int nextIndex_guess = 4000;
    VoiceFile_guess* filesFile_guess =
        (VoiceFile_guess*)operator new(0x1000c);
    if (filesFile_guess != 0) {
        filesFile_guess = filesFile_guess->Open_guess(files_guess, 0x5e);
    }
    if (filesFile_guess->IsOpen_guess() != 0) {
        int linesLeft_guess = filesFile_guess->GetLineCount_guess();
        while (linesLeft_guess > 0) {
            char line_guess[0x1000];
            filesFile_guess->ReadLine_guess(line_guess, 0x1000);
            if (HasVoiceLine_guess(line_guess, 0) != 0) {
                char* cursor_guess = line_guess;
                int macroId_guess = ReadVoiceNumber_guess(&cursor_guess, 0x5e);
                int* found_guess = FindThing_guess(macroId_guess);
                if (found_guess == 0) {
                    VoiceError_guess(
                        "ERROR: Voice macro id %d referred to in VoiceFiles.txt does not exist.",
                        macroId_guess);
                } else {
                    VoiceMacroRecord_guess* record_guess =
                        (VoiceMacroRecord_guess*)*found_guess;
                    int voiceId_guess = ReadVoiceNumber_guess(&cursor_guess, 0x5e);
                    if (voiceId_guess <= 0x400) {
                        char voiceName_guess[0x100];
                        ReadVoiceField_guess(voiceName_guess, 0x100,
                                             &cursor_guess, 0x5e);
                        CXStrArray_guess* names_guess =
                            (CXStrArray_guess*)&record_guess->unknown04_guess;
                        VoiceIndexMap_guess* indexMap_guess =
                            (VoiceIndexMap_guess*)&record_guess->unknown14_guess;
                        if (names_guess->count00_guess <= voiceId_guess) {
                            int fillCount_guess =
                                voiceId_guess - names_guess->count00_guess + 1;
                            int defaultIndex_guess = 0;
                            do {
                                {
                                    CXStr empty_guess(
                                        EQ_ARRAY(char, 0x0063F53F));
                                    names_guess->SetAt_guess(
                                        names_guess->count00_guess,
                                        empty_guess);
                                }
                                indexMap_guess->SetAt_guess(
                                    indexMap_guess->default_guess,
                                    &defaultIndex_guess);
                                --fillCount_guess;
                            } while (fillCount_guess != 0);
                        }
                        {
                            CXStr voiceNameString_guess(voiceName_guess);
                            names_guess->SetAt_guess(voiceId_guess,
                                                     voiceNameString_guess);
                        }
                        int voiceIndex_guess = nextIndex_guess;
                        ++nextIndex_guess;
                        indexMap_guess->SetAt_guess(voiceId_guess,
                                                    &voiceIndex_guess);
                    } else {
                        VoiceError_guess(
                            "ERROR: Simple safety check, voice ID %d > 1024, seems unreasonable.",
                            voiceId_guess);
                    }
                }
            }
            linesLeft_guess = filesFile_guess->GetLineCount_guess();
        }
    }
    if (filesFile_guess != 0) {
        filesFile_guess->Close_guess();
        operator delete(filesFile_guess);
    }
}

// Voice macro table constructor: 0x80 buckets, nothing selected (+0x14 = -1), then VoiceData.txt and
// VoiceFiles.txt loaded.
// FUNCTION: TITANIUM 0x004CBA68
VoiceMacroTable_guess::VoiceMacroTable_guess() : Bucket_guess(0x80) {
    field14_guess = -1;
    flag10_guess = 0;
    Load_guess("VoiceData.txt", "VoiceFiles.txt");
}

// Destructor: destroys and frees every voice entry in the table, then clears the table.
// FUNCTION: TITANIUM 0x004CBAAF
// @early-stop: tiebreak, structural ndiff=1
VoiceMacroTable_guess::~VoiceMacroTable_guess() {
    for (CompositeObject_guess** entry_guess = First_guess(); entry_guess != 0;
         entry_guess = Next_guess(entry_guess)) {
        CompositeObject_guess* value_guess = *entry_guess;
        if (value_guess != 0) {
            value_guess->Destroy_guess();
            free(value_guess);
        }
    }
    Clear_guess();
}

