#include <iostream>
#include <cstring>

using namespace std;

/*
 * Scrie in enc criptarea lui m, folosind cheia key
 * */
void vigenere_encrypt(char enc[200], char m[200], int key[200], int key_len)
{
    int i;
    for (i = 0; m[i] != '\0'; i++)
    {
        enc[i] = ((m[i] - 'A') + key[i % key_len]) % 26 + 'A';
    }
    enc[i] = '\0';
}

/*
 * Scrie in m decriptarea lui enc, folosind cheia key
 * */
void vigenere_decrypt(char m[200], char enc[200], int key[200], int key_len)
{
    int i;
    for (i = 0; enc[i] != '\0'; i++)
    {
        m[i] = ((enc[i] - 'A') - key[i % key_len] + 26) % 26 + 'A';
    }
    m[i] = '\0';
}

/*
 * Functia gasita de echipa de interventie
 * */
void ransom_encrypt(char m[200], int key2[200], int key2_len)
{
    int key1[7] = {20, 20, 20, 20, 20, 20, 20}; // Asta nu este cheia reala
    char aux[200];

    vigenere_encrypt(aux, m, key1, 7);
    vigenere_encrypt(m, aux, key2, key2_len);
}

void ransom_solve(char enc[200])
{
    // This was found with bruteforce_first_key()
    int key1[7] = {20, 11, 15, 17, 19, 9, 0};
    int key2[4];

    for (int i1 = 0; i1 < 26; i1++) {
    for (int i2 = 0; i2 < 26; i2++) {
    for (int i3 = 0; i3 < 26; i3++) {
    for (int i4 = 0; i4 < 26; i4++) {
        key2[0] = i1;
        key2[1] = i2;
        key2[2] = i3;
        key2[3] = i4;
        char msg1[200];
        char msg2[200];
        vigenere_decrypt(msg1, enc, key2, 4);
        vigenere_decrypt(msg2, msg1, key1, 7);
        if (msg2[0] == 'A' && msg2[1] == 'C' && msg2[2] == 'A' && msg2[3] == 'D' && msg2[4] == 'N' && msg2[5] == 'E' && msg2[6] == 'T') {
            cout << msg2 << '\n';
        }
    }}}}
}
int main (int argc, char *argv[])
{
    char c[200];
    cin >> c;
    ransom_solve(c);

    return 0;
}
