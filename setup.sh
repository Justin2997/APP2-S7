#!/bin/bash

cd Architecture-Finale
docker build -t app2secu .
cd ../
cd ComposeBuild
docker-compose up --build
docker rmi $(docker images -q -f dangling=true)

