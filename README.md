# simple-web-scraper

## Description

`simple-web-scraper` est une application CLI C++ légère et performante conçue pour l'extraction de contenu web. Elle permet de récupérer le code source complet d'une page web ainsi que tous les liens qu'elle contient, fournissant une base solide pour le développement de crawlers web.

## Fonctionnalités

- Extraction complète du code HTML d'une page web
- Identification et analyse automatique des liens
- Interface en ligne de commande simple et efficace
- Implémentation optimisée pour des performances élevées

## Prérequis

Le développement et l'utilisation de cette bibliothèque nécessitent les dépendances suivantes :

- Compilateur C++ avec support C++17 (g++ recommandé)
- Make
- Git
- libcurl

## Installation

### Installation des dépendances

Sur les systèmes basés sur Debian/Ubuntu :

```sh
sudo apt install g++ make git libcurl4-openssl-dev
```

### Récupération du code source

```sh
git clone https://github.com/elias-utf8/simple-web-scraper.git
cd simple-web-scraper
```

### Compilation

```sh
make
```

Lors d'une compilation réussie, vous devriez observer une sortie similaire à :

```
g++ -std=c++17 -Wall -I include -c src/CScraper.cpp -o src/CScraper.o
g++ -std=c++17 -Wall -I include -c src/utils.cpp -o src/utils.o
g++ -std=c++17 -Wall -I include -o scrapx src/main.o src/CScraper.o src/utils.o -lcurl
```

## Utilisation

L'exécution du programme se fait en spécifiant l'URL cible :

```sh
./scrapx <URL>
```

### Exemple

```sh
./scrapx gnu.org
```

Sortie attendue :

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

Les contributions sont les bienvenues.