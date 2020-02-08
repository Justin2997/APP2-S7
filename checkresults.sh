#!/bin/bash

docker commit client checkresult
docker run -it checkresult /bin/sh

