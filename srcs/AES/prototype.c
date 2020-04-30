void	aes_encrypt(uint8_t msg[16], uint8_t key[16], uint8_t cypher[16]);
void	aes_decrypt(uint8_t cypher[16], uint8_t key[16], uint8_t msg[16]);

//init_aes();

void	key_expansion(byte key[16], word w[44]);

add_round_key();

void	sub_bytes(uint8_t state[4][4]);

void	shift_rows(uint8_t state[4][4]);

void	mix_columns(uint8_t state[4][4]);

print();

clean_aes();
