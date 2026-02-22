#include <AESLib.h>

AESLib aesLib;

byte aes_key[16] = {
  // your AES key here
};

HardwareSerial SerialNano(2);

bool attack_mode = true;

void setup() {

  Serial.begin(115200);

  SerialNano.begin(9600, SERIAL_8N1, 16, 17);

  Serial.println("Quantum Secure Communication Started");
}

void loop() {

  byte encrypted[128];
  byte decrypted[128];

  byte aes_iv_enc[16] = {
    0x00,0x01,0x02,0x03,
    0x04,0x05,0x06,0x07,
    0x08,0x09,0x0A,0x0B,
    0x0C,0x0D,0x0E,0x0F
  };

  // 16-byte padded message
  char message_fixed[17] = "RETREAT       ";

  uint16_t cipherLength = aesLib.encrypt(
    (byte*)message_fixed,
    16,
    encrypted,
    aes_key,
    128,
    aes_iv_enc
  );

  if (attack_mode) {
    encrypted[5] ^= 0xFF;   // flip one byte
    Serial.println("Attack Simulated!");
  }

  byte aes_iv_dec[16] = {
    0x00,0x01,0x02,0x03,
    0x04,0x05,0x06,0x07,
    0x08,0x09,0x0A,0x0B,
    0x0C,0x0D,0x0E,0x0F
  };

  aesLib.decrypt(
    encrypted,
    cipherLength,
    decrypted,
    aes_key,
    128,
    aes_iv_dec
  );

  decrypted[16] = '\0';

  Serial.println("Original:");
  Serial.println(message_fixed);

  Serial.println("Decrypted:");
  Serial.println((char*)decrypted);

  if (strcmp(message_fixed, (char*)decrypted) == 0) {
    Serial.println("Communication SECURE");
    SerialNano.println("SECURE");
  } else {
    Serial.println("SECURITY BREACH DETECTED");
    SerialNano.println("ALERT");
  }

  delay(4000);
}
