#include "Hasher.h"
#include <openssl/sha.h>
#include <sstream>


using namespace std;

Hasher::Hasher() = default;

Hasher::~Hasher() = default;

string Hasher::hashString(const string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.length());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        ss << hex << (int)hash[i];
    }
    return ss.str();
}
