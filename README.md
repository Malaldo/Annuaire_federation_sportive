# Projet Annuaire d'une fédération sportive

## Description

Ce projet est une application en langage C qui gère un annuaire de joueurs, de clubs et de compétitions pour une fédération sportive.

## Compilation

Le projet utilise un `Makefile` pour compiler l'application.

Depuis le dossier racine du dépôt, exécutez :

```sh
make
```

Cette commande compile les fichiers sources et génère l'exécutable `annuaire_federation_sportive`.

Si `make` n'est pas disponible sur Windows, vous pouvez compiler manuellement avec GCC :

```sh
gcc -Wall -Wextra -Werror -std=c99 main.c club.c joueur.c util.c competition.c -o annuaire_federation_sportive
```

## Exécution

Après compilation, lancez l'application depuis le dossier racine :

```sh
./annuaire_federation_sportive
```

Sur Windows, utilisez :

```sh
annuaire_federation_sportive.exe
```

L'application affiche un menu principal avec les options :

- Menu joueurs
- Menu clubs
- Menu compétitions
- Aller à l'accueil
- Quitter

Chaque section propose des sous-menus pour ajouter, afficher, rechercher, supprimer, mettre à jour et trier les données.

## Organisation du dépôt

- `Makefile` : instructions de compilation et nettoyage.
- `main.c` : point d'entrée de l'application et menu principal.
- `club.c`, `club.h` : gestion des clubs et des joueurs associés aux clubs.
- `joueur.c`, `joueur.h` : gestion des joueurs.
- `competition.c`, `competition.h` : gestion des compétitions et des participants.
- `util.c`, `util.h` : fonctions utilitaires partagées, comme le nettoyage de l'écran.
- `structures.h` : définitions des structures `Joueur`, `Club`, `Competition`, `Date`, `Adresse`.
- `Manuel_utilisateur.md` : guide d'utilisation de l'application.
- `obj/` : dossier réservé aux fichiers objets générés.
- `src/` et `include/` : dossiers pouvant contenir des sources et en-têtes supplémentaires.

## Remarques

- Assurez-vous d'avoir GCC installé pour compiler le projet.
- Le projet est conçu pour être compilé en C99 avec les options `-Wall -Wextra -Werror`.
- Le manuel utilisateur contient des détails sur les menus et les règles de saisie.
