#include<bits/stdc++.h>
#include "MFA-SJR.h"

uint8_t affine_transform(uint8_t x) {
    uint8_t result = 0;
    uint8_t c = 0x63;

    // Perform bitwise affine transformation
    for (int i = 0; i < 8; i++) {
        // XOR of 5 rotated bits of x
        uint8_t bit = ((x >> i) & 1)
                    ^ ((x >> ((i + 4) % 8)) & 1)
                    ^ ((x >> ((i + 5) % 8)) & 1)
                    ^ ((x >> ((i + 6) % 8)) & 1)
                    ^ ((x >> ((i + 7) % 8)) & 1)
                    ^ ((c >> i) & 1);
        result |= (bit << i);
    }

    return result;
}


int main() {
    uint8_t x = 0x53;
    uint8_t inv = gf_inv(x);
    cout << hex << (int)inv << endl;
    uint8_t SBox[256];

    for (int i = 0; i < 256; i++) {
        uint8_t inv = (i == 0) ? 0 : gf_inv(i);  // 0 has no inverse
        SBox[i] = affine_transform(inv);
    }

    cout << "AES S-box:\n";
    for (int i = 0; i < 256; i++) {
        cout << hex << setw(2) << setfill('0') << (int)SBox[i] << " ";
        if ((i + 1) % 16 == 0) cout << endl;
    }


    return 0;
}
