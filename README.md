# simple-web-scraper
Un web scraper modeste écrit en C++ permettant de récupérer l'intégralité du code source d'un site ainsi que tout les liens figurant dans ce dernier.
Peut être utiliser pour écrire un web crawler.

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
Sortie attendue :
```URL extraite: gnu.org => domaine: gnu.org
Domaine extrait: gnu.org
Tentative de création du dossier: "/simple-web-scraper/gnu.org"
[+] Dossier déjà existant : "/simple-web-scraper/gnu.org"
[+] Contenu HTML récupéré avec succès
[+] 119 liens ont été extraits
[+] Fichiers sauvegardés avec succès dans "/simple-web-scraper/gnu.org"
[+] Opération réussie!
Temps d'exécution total : 0.635116 secondes
```