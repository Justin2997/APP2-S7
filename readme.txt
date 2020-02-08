		README - APP2 S7 Sécurité Informatique - Université de Sherbrooke

######################################################################################
################################### VERSION SIMPLE ###################################
######################################################################################

1) Dans le fichier /Architecture-Finale/CryptoAPP2/include/studentscode.h : 
	- Remplacer la DECLARATION des fonctions d'exemple par la DECLARATION de
	  vos propres fonctions d'encryption et de decryption (gardez le même nom)
	  
	  L'IMPLEMENTATION DE LA FONCTION D'ENCRYPTION EST LIBRE, MAIS CELLE-CI
          DOIT ENCRYPTER LE FICHIER "OverusedJoke.mp4" DANS UN FICHIER AYANT 
	  EXACTEMENT LE MÊME NOM. 

          Le nom du fichier reçu encrypté est "OverusedJokeRecu.mp4" pour les besoins 
	  de votre système de décryption. 


2) Dans le fichier /Architecture-Finale/CryptoAPP2/src/studentscode.cpp :
	- Remplacer la DEFINITION des fonctions d'exemple par la DEFINITION de 
	  vos propres fonctions d'encryption et de decryption (gardez le même nom)

			      ----AVANT DE POURSUIVRE----

	Assurez-vous que la compilation et l'édition des liens de vos fonctions passe. 
	Le premier processus de build des containers Docker est assez long, il serait
 	dommage de perdre du temps inutilement. 



		/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\
3.a)		/!\ CETTE ETAPE N'EST A FAIRE QUE LA PREMIERE FOIS /!\
		/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\/!\


	Lancer le script "firsttime.sh". 
	Le résultat de performance sera affiché à la fin.


./s
3.b) 		TOUTES LES FOIS SUIVANTES, APRES AVOIR LANCÉ LE SCRIPT firsttime.sh
		AU MOINS UNE FOIS.  
	
	Lancer le script "setup.sh". 
	Le résultat de performance sera affiché à la fin.


#######################################################################################
############################# POUR VERIFIER VOS RESULTATS #############################
#######################################################################################

	
1) Lancer le script "checkresults.sh" (après avoir fait les étapes précédentes...) 

   À partir de là, vous êtes dans la nouvelle image comitée à partir du container 
   client. Un simple "ls -l" vous permettra de vérifier que le fichier est transmis et
   qu'il fait bien la même taille. Pour vérifier si votre encryption et votre 
   décryption se sont bien passés... À vous de voir ! ;) 



 