#include "studentscode.h"
#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "cryptopp/integer.h"
using namespace CryptoPP;
using namespace std;

//Remplacez ici le code source de cette fonction par le code de votre méthode
//servant à encrypter le fichier. Celle ci devra encrypter "OverusedJoke.mp4" dans un fichier avec le même nom.
void encrypt (int from) {
	// Read the file (https://www.thinkage.ca/gcos/expl/c/lib/read.html and https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.4.0/com.ibm.zos.v2r4.bpxbd00/rtrea.htm)
	int ret;
	char buf[1024];

	while ((ret = read(from, buf, sizeof(buf)-1)) > 0) {
		buf[ret] = 0x00;
		printf("block read: \n<%s>\n", buf);
	}
	
  Integer int_a ("2121211212");
	Integer int_b ("33");
	Integer int_c ("754865");
	for (int i = 0; i<10000; i++) {
		a_exp_b_mod_c (int_a, int_b, int_c);
	}
  cout << "Cette fonction est une fonction simple effectuant 10 000 fois un a exp b mod c." << endl;
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

