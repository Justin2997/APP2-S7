
#Remplacement de gcc par alpine
FROM alpinewithcrypto as Build

#Installation des outils gcc, make, g++ et lib-dev via apk 
COPY ./CryptoAPP2 /CryptoAPP2/
WORKDIR /CryptoAPP2/src
RUN make all 

#Copie finale
FROM alpine
COPY --from=Build /CryptoAPP2/src/client /client/
COPY --from=Build /CryptoAPP2/src/OverusedJoke.mp4 /server/
COPY --from=Build /CryptoAPP2/src/server /server/


