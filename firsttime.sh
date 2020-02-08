#!/bin/bash

cd Architecture-Finale
if git clone https://github.com/weidai11/cryptopp.git:whatever ./cryptopp-clean
then
    echo "cloning"
else
    echo "pulling"
    git -C ./cryptopp-clean/cryptopp pull
fi

docker build -f Dockerfile-AddCrypto++ -t alpinewithcrypto .
docker build -t app2secu .
cd ../
cd ComposeBuild
docker-compose up --build
docker rmi $(docker images -q -f dangling=true)
