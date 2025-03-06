# simple-web-scraper
Un web scraper modeste écrit en C++

# Installation

### Pré-requis
- Compilateur g++
```sh
sudo apt install g++
```
- Make
```sh
sudo apt install make
```
- Git
```sh
sudo apt install git
```
- Libcurl
```sh
sudo apt install libcurl4-openssl-dev
```
### Cloner le projet 
```sh
git clone https://github.com/elias-utf8/simple-web-scraper.git
```
```sh
cd simple-web-scraper
```

### Compiler le projet
```sh
sudo make
```
Sortie attendue : 
```
g++ -std=c++17 -Wall -I include -c src/CScraper.cpp -o src/CScraper.o
g++ -std=c++17 -Wall -I include -c src/utils.cpp -o src/utils.o
g++ -std=c++17 -Wall -I include -o scrapx src/main.o src/CScraper.o src/utils.o -lcurl
```

# Usage 
```sh
sudo ./scrapx <URL> 
```
