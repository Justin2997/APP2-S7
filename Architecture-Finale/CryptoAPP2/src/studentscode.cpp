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

// Remplacez ici le code source de cette fonction par le code de votre méthode
// servant à encrypter le fichier. Celle ci devra encrypter "OverusedJoke.mp4" dans un fichier avec le même nom.
void encrypt (int from) {
	AutoSeededRandomPool prng;
	byte key[ AES::DEFAULT_KEYLENGTH ]; // The default key length in Crypto++ is 16 bytes and specified by AES::DEFAULT_KEYLENGTH.
	prng.GenerateBlock( key, sizeof(key) );

	byte iv[ AES::BLOCKSIZE ]; // AES::BLOCKSIZE. For AES, this is always 16 bytes.
	prng.GenerateBlock( iv, sizeof(iv) );    

	const int TAG_SIZE = 12;

	GCM<AES>::Encryption gcm;

	// Plain text
	string pdata;

	// Encrypted, with Tag
	string cipher, encoded;

	// Recovered plain text
	string rpdata;

	/*********************************\
	\*********************************/

	// Pretty print
	encoded.clear();
	StringSource( key, sizeof(key), true,
			new HexEncoder(
					new StringSink( encoded )
			) 
	);
	cout << "key: " << encoded << endl;

	// Pretty print
	encoded.clear();
	StringSource( iv, sizeof(iv), true,
			new HexEncoder(
					new StringSink( encoded )
			) 
	); 
	cout << " iv: " << encoded << endl;
	cout << endl;

	/*********************************\
	\*********************************/
	
	// Read the file (https://www.thinkage.ca/gcos/expl/c/lib/read.html and https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.4.0/com.ibm.zos.v2r4.bpxbd00/rtrea.htm)
	int ret;
	char buffer[AES::DEFAULT_KEYLENGTH];
	printf("Reading the file...\n");

	while ((ret = read(from, buffer, sizeof(buffer))) > 0) {
		string pdata = buffer;
		// cout << "Donnée du fichier : " << s << endl;

		// Encrypted block from https://www.cryptopp.com/wiki/GCM_Mode
		/*********************************\
		\*********************************/
			try
			{
				gcm.SetKeyWithIV( key, sizeof(key), iv, sizeof(iv) );
				gcm.SpecifyDataLengths( 0, pdata.size(), 0 );
				StringSource( pdata, true,
						new AuthenticatedEncryptionFilter( gcm,
								new StringSink( cipher ), false, TAG_SIZE
						)
				);
			}
			catch( CryptoPP::InvalidArgument& e )
			{
					cerr << "Caught InvalidArgument..." << endl;
					cerr << e.what() << endl;
					cerr << endl;
			}
			catch( CryptoPP::Exception& e )
			{
					cerr << "Caught Exception..." << endl;
					cerr << e.what() << endl;
					cerr << endl;
			}
		/*********************************\
    \*********************************/

		/*********************************\
    \*********************************/

    // Pretty print
    encoded.clear();
    StringSource( cipher, true,
        new HexEncoder(
            new StringSink( encoded )
        ) 
    ); 
    //cout << "Block encrypté : " << encoded << endl;
    /*********************************\
    \*********************************/
	}
  cout << "Ce message ne doit s'afficher que du côté serveur" << endl;
}

//Remplacez ici le code source de cette fonction par le code de votre méthode
//servant à décrypter le fichier. Le nom du fichier reçu encrypte par le serveur est "OverusedJokeRecu.mp4".
void decrypt (int to) {
  Integer int_a ("2121211212");
	Integer int_b ("33");
	Integer int_c ("754865");
	for (int i = 0; i<10000; i++) {
		a_exp_b_mod_c (int_a, int_b, int_c);
	}
  cout << "Cette fonction est une fonction simple effectuant 10 000 fois un a exp b mod c." << endl;
  cout << "Ce message ne doit s'afficher que du côté client" << endl;
}

