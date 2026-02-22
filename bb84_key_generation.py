import numpy as np

N = 400

alice_bits = np.random.randint(0, 2, N)
alice_bases = np.random.randint(0, 2, N)
bob_bases = np.random.randint(0, 2, N)

final_key = []

for i in range(N):
    if alice_bases[i] == bob_bases[i]:
        final_key.append(alice_bits[i])

if len(final_key) < 128:
    print("Not enough key bits generated. Increase N.")
else:
    key_str = ''.join(map(str, final_key[:128]))

    print("128-bit Key:")
    print(key_str)

    hex_key = []
    for i in range(0, 128, 8):
        byte = key_str[i:i+8]
        hex_key.append("0x{:02X}".format(int(byte,2)))

    print("\nAES Format:")
    print(", ".join(hex_key))

#Sample output
#128-bit Key: 00000101101010100101101101110010010000011101111011001100100111110010110000010011110100001011011010010100100001110101001111101001
#AES Format: 0x05, 0xAA, 0x5B, 0x72, 0x41, 0xDE, 0xCC, 0x9F, 0x2C, 0x13, 0xD0, 0xB6, 0x94, 0x87, 0x53, 0xE9
