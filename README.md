# BB84-Simulation-ESP32-Nano
BB84 Based Quantum Secure Communication System Using ESP32 and Arduino Nano
# Quantum-Secure Communication using ESP32 and Arduino Nano

This project demonstrates a quantum-inspired secure communication system using:
- ESP32 (AES-128 encryption engine)
- Arduino Nano (LCD monitoring system)
- BB84 Quantum Key Distribution simulation

The system simulates quantum secure communication where encrypted data modification results in detectable decryption mismatch.

## System Architecture

Quantum Key Generation (BB84 Simulation)
        ↓
AES-128 Encryption (ESP32)
        ↓
Tamper Simulation
        ↓
AES Decryption
        ↓
Security Verification
        ↓
Status Display (Nano + I2C LCD)

## Features

- AES-128 CBC encryption
- Proper IV handling
- Tamper detection (attack simulation)
- Quantum key compatibility
- Hardware-based monitoring
- I2C LCD status display
- Serial debugging support

## Hardware Used

- ESP32 Dev Module
- Arduino Nano
- 16x2 LCD with I2C module
- Jumper wires
- Push button (optional for attack simulation)

## How It Works

1. BB84 simulation generates a 128-bit quantum key.
2. Key is converted into AES format.
3. ESP32 encrypts a 16-byte message.
4. Encrypted data can be tampered (attack simulation).
5. ESP32 decrypts and compares.
6. If mismatch → ALERT.
7. If match → SECURE.
8. Arduino Nano displays system status.

## Attack Simulation

Setting:

bool attack_mode = true;

Simulates data tampering by flipping a cipher byte.

Output:
- Secure Mode → LCD shows SECURE
- Attack Mode → LCD shows ALERT
