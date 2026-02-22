import numpy as np

N = 200  # number of qubits

# Step 1: Alice generates random bits and bases
alice_bits = np.random.randint(0, 2, N)
alice_bases = np.random.randint(0, 2, N)

# Step 2: Bob randomly chooses bases
bob_bases = np.random.randint(0, 2, N)

# Step 3: Measurement
bob_results = []

for i in range(N):
    if alice_bases[i] == bob_bases[i]:
        bob_results.append(alice_bits[i])
    else:
        bob_results.append(np.random.randint(0, 2))

# Step 4: Key sifting
final_key = []
for i in range(N):
    if alice_bases[i] == bob_bases[i]:
        final_key.append(alice_bits[i])

# Convert to string
final_key_str = ''.join(map(str, final_key))

# Calculate QBER
errors = sum([1 for i in range(len(final_key))
              if final_key[i] != bob_results[i]])
qber = errors / len(final_key)

print("Generated Key:", final_key_str[:128])
print("QBER:", qber)
