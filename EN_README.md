# simple-web-scraper

![C++17](https://img.shields.io/badge/C%2B%2B-17-blue)
![CLI](https://img.shields.io/badge/Type-CLI-informational)
![libcurl](https://img.shields.io/badge/Uses-libcurl-success)
![Build](https://img.shields.io/badge/Build-Make-brightgreen)
![OS](https://img.shields.io/badge/OS-Linux%20%7C%20Unix-lightgrey)

## Description

`simple-web-scraper` is a lightweight and efficient C++ CLI application designed for web content extraction. It can retrieve the full source code of a web page as well as all the links it contains, providing a solid foundation for web crawler development.

## Features

- Full HTML code extraction of a web page
- Automatic identification and parsing of links
- Simple and efficient command-line interface
- Optimized implementation for high performance

## Requirements

Developing and using this library requires the following dependencies:

- C++ compiler with C++17 support (g++ recommended)
- Make
- Git
- libcurl

## Installation

### Installing dependencies

On Debian/Ubuntu-based systems:

```sh
sudo apt install g++ make git libcurl4-openssl-dev
```

### Cloning the source code
```sh
git clone https://github.com/elias-utf8/simple-web-scraper.git
cd simple-web-scraper
```
### Compilation

```sh
make
```

If the compilation succeeds, you should see output similar to:

```
g++ -std=c++17 -Wall -I include -c src/CScraper.cpp -o src/CScraper.o
g++ -std=c++17 -Wall -I include -c src/utils.cpp -o src/utils.o
g++ -std=c++17 -Wall -I include -o scrapx src/main.o src/CScraper.o src/utils.o -lcurl
```

## Usage

Run the program by specifying the target URL:

```sh
./scrapx <URL>
```

### Example

```sh
./scrapx gnu.org
```

Expected output:
```
URL extraite: gnu.org => domaine: gnu.org
Domaine extrait: gnu.org
Tentative de création du dossier: "/simple-web-scraper/gnu.org"
[+] Dossier déjà existant : "/simple-web-scraper/gnu.org"
[+] Contenu HTML récupéré avec succès
[+] 119 liens ont été extraits
[+] Fichiers sauvegardés avec succès dans "/simple-web-scraper/gnu.org"
[+] Opération réussie! Temps d'exécution total : 0.635116 secondes
```

## Contribution

Contributions are welcome.
