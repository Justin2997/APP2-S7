#include "studentscode.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include <iostream>
using std::cout;
using std::cerr;

#include <string>
using std::string;

#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/cryptlib.h"
using CryptoPP::BufferedTransformation;
using CryptoPP::AuthenticatedSymmetricCipher;

#include "cryptopp/filters.h"
using CryptoPP::Redirector;
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::AuthenticatedEncryptionFilter;
using CryptoPP::AuthenticatedDecryptionFilter;

#include "cryptopp/aes.h"
using CryptoPP::AES;

#include "cryptopp/gcm.h"
using CryptoPP::GCM;

#include "assert.h"

#include "cryptopp/integer.h"
using namespace CryptoPP;
using namespace std;

string initial_key = "680B141334B5AF7925CCEB6C4F5BA81F82B6C4740F60DB7236F461D133CB8A31";
string initial_iv  = "46420A4D0B9D8BAB480E25208834D670E1EAF3630A96347FC0FB8EEE9A3882F6";

SecByteBlock key(reinterpret_cast<const byte*> (&initial_key[0]), initial_key.size());
SecByteBlock iv(reinterpret_cast<const byte*> (&initial_iv[0]), initial_iv.size());

// Remplacez ici le code source de cette fonction par le code de votre méthode
// servant à encrypter le fichier. Celle ci devra encrypter "OverusedJoke.mp4" dans un fichier avec le même nom.
int encrypt (int from) {
	cout << "Début de l'encryption" << endl;
	int to, ret, w;
	string cipher;
	char buffer[256];

	GCM<AES>::Encryption gcm;
	AuthenticatedEncryptionFilter finalMessage(
		gcm, new StringSink(cipher)
	);

  to = creat("OverusedJokeRecu_encrypted.mp4", 0777);
  if(to < 0){ cout << "Error creating destination file\n"; }

	gcm.SetKeyWithIV( key, sizeof(key), iv, sizeof(iv) );
	while ((ret = read(from, buffer, 256)) != 0) {
		finalMessage.Put((const byte*) &buffer, ret);
	}

	w = write(to, cipher.c_str(), cipher.size());
  cout << "Message encrypté" << endl;
	return open("OverusedJokeRecu_encrypted.mp4", O_RDONLY);
}

//Remplacez ici le code source de cette fonction par le code de votre méthode
//servant à décrypter le fichier. Le nom du fichier reçu encrypte par le serveur est "OverusedJokeRecu.mp4".
int decrypt (int to) {
  cout << "Début de l'encryption" << endl;
	int from, ret, w;
	string cipher;
	char buffer[256];

	GCM<AES>::Decryption gcm;
	AuthenticatedDecryptionFilter finalMessage(
		gcm, new StringSink(cipher)
	);

  from = creat("OverusedJokeRecu.mp4", 0777);
  if(from < 0){ cout << "Error creating destination file\n"; }

	gcm.SetKeyWithIV( key, sizeof(key), iv, sizeof(iv) );
	while ((ret = read(to, buffer, 256)) != 0) {
		finalMessage.Put((const byte*) &buffer, ret);
	}

	// On peut valider l'intégrier du message aussi avec c'est ligne vu que on utilise GCM
	// bool b = finalMessage.GetLastResult();
	// assert( true == b );

	w = write(from, cipher.c_str(), cipher.size());
  cout << "Message encrypté" << endl;
	return open("OverusedJokeRecu.mp4", O_RDONLY);
}

