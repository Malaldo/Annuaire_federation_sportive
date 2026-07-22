# Manuel utilisateur de l'application Annuaire d'une fédération sportive

L'application commence par une configuration du système :

- Saisir le nombre maximal de joueurs.
- Saisir le nombre maximal de clubs.
- Saisir le nombre maximal de compétitions.

Après cette configuration, le menu principal apparaît.

## Menu principal

Le menu principal propose 5 options :

- 1 - Menu joueurs
- 2 - Menu clubs
- 3 - Menu compétitions
- 4 - Aller à l'accueil
- 5 - QUITTER

## Menu Joueurs

Dans ce menu, vous pouvez gérer les joueurs. Il contient 7 options.

- 1 - Ajouter un joueur
- 2 - Afficher tous les joueurs
- 3 - Rechercher un joueur
- 4 - Supprimer un joueur
- 5 - Mettre à jour un joueur
- 6 - Trier les joueurs par id
- 7 - Trier les joueurs par nom

### Ajouter un joueur

Cette fonctionnalité permet d'enregistrer un nouveau joueur.

- Les informations demandées sont : identifiant, prénom, nom, date de naissance, nationalité, catégorie, poste et club actuel.
- La date de naissance doit être saisie au format `jj mm aaaa`.
- Après ajout, un message de confirmation s'affiche.

### Afficher tous les joueurs

Cette option affiche tous les joueurs enregistrés.

- Si aucun joueur n'est enregistré, le message suivant s'affiche :

  _"Liste vide. Aucun joueur à afficher."_
- Sinon, la liste complète des joueurs enregistrés est affichée.

### Rechercher un joueur

Cette option permet de rechercher un joueur par identifiant.

- Si aucun joueur n'est enregistré, le message suivant s'affiche :

  _"Aucun joueur enregistré."_
- Si le joueur n'existe pas, le message suivant s'affiche :

  _"Aucun joueur enregistré avec cette identifiant."_
- Si le joueur existe, ses informations sont affichées.

### Supprimer un joueur

Cette option permet de supprimer un joueur enregistré.

- Si aucun joueur n'est enregistré, le message suivant s'affiche :

  _"Aucun joueur enregistré."_
- Si le joueur n'existe pas, le message suivant s'affiche :

  _"Aucun joueur enregistré avec cet identifiant"_
- Si le joueur existe, il est supprimé et un message de confirmation s'affiche.

### Mettre à jour un joueur

Cette option permet de modifier les informations d'un joueur existant.

- Si aucun joueur n'est enregistré, le message suivant s'affiche :

  _"Aucun joueur enregistré."_
- Après saisie de l'identifiant du joueur, vous pouvez modifier : le prénom, le nom, la date de naissance, la catégorie, le poste ou la nationalité.
- Après modification, le message suivant s'affiche :

  _"Modification réussie !"_
- Si le joueur n'existe pas, le message suivant s'affiche :

  _"Aucun joueur enregistré avec cet identifiant"_

### Trier les joueurs par id

Cette option trie les joueurs par identifiant.

- Si aucun joueur n'est enregistré, le message suivant s'affiche :

  _"Aucun joueur enregistré"_
- Sinon, les joueurs sont triés par ordre croissant de leur identifiant.
- Pour voir le résultat, utilisez ensuite l'option _Afficher tous les joueurs_.

### Trier les joueurs par nom

Cette option trie les joueurs par nom.

- Si aucun joueur n'est enregistré, le message suivant s'affiche :

  _"Aucun joueur enregistré"_
- Sinon, les joueurs sont triés par ordre alphabétique de leur nom.
- Pour voir le résultat, utilisez ensuite l'option _Afficher tous les joueurs_.

## Menu Clubs

Ce menu permet de gérer les clubs enregistrés. Il contient 9 options.

- 1 - Ajouter un club
- 2 - Afficher tous les clubs
- 3 - Rechercher un club
- 4 - Supprimer un club
- 5 - Mettre à jour un club
- 6 - Trier les clubs par id
- 7 - Trier les clubs par nom
- 8 - Ajouter un joueur dans un club
- 9 - Afficher les joueurs d'un club

### Ajouter un club

Cette fonctionnalité permet d'enregistrer un nouveau club.

- Les informations demandées sont : identifiant, nom, date de création, siège, email, site web, nom du stade, adresse du stade, président et manager.
- La date de création doit être saisie au format `jj mm aaaa`.
- Après ajout, un message de confirmation s'affiche.

### Afficher tous les clubs

Cette option affiche tous les clubs enregistrés.

- Si aucun club n'est enregistré, le message suivant s'affiche :

  _"Liste vide. Aucun club à afficher."_
- Sinon, toutes les informations de chaque club sont affichées.

### Rechercher un club

Cette fonctionnalité permet de rechercher un club enregistré.

- Si aucun club n'est enregistré, le message suivant s'affiche :

  _"Aucun club enregistré."_
- Si le club n'existe pas, le message suivant s'affiche :

  _"Aucun club enregistré avec cet identifiant"_
- Si le club existe, ses informations sont affichées.

### Supprimer un club

Cette option permet de supprimer un club enregistré.

- Si aucun club n'est enregistré, le message suivant s'affiche :

  _"Aucun club enregistré."_
- Si le club n'existe pas, le message suivant s'affiche :

  _"Aucun club enregistré avec cet identifiant."_
- Si le club existe, il est supprimé et un message de confirmation s'affiche.

### Mettre à jour un club

Cette option permet de modifier les informations d'un club existant.

- Si aucun club n'est enregistré, le message suivant s'affiche :

  _"Aucun club enregistré."_
- Après saisie de l'identifiant du club, vous pouvez modifier : le nom, la date de création, le siège, l'email, le site web, le nom du stade, l'adresse du stade, le président ou le manager.
- Après modification, le message suivant s'affiche :

  _"Modification réussie !"_

### Trier les clubs par id

Cette option trie les clubs par identifiant.

- Si aucun club n'est enregistré, le message suivant s'affiche :

  _"Aucun club enregistré"_
- Après le tri, utilisez l'option _Afficher tous les clubs_ pour vérifier l'ordre.

### Trier les clubs par nom

Cette option trie les clubs par nom.

- Si aucun club n'est enregistré, le message suivant s'affiche :

  _"Aucun club enregistré"_
- Après le tri, utilisez l'option _Afficher tous les clubs_ pour vérifier l'ordre.

### Ajouter un joueur dans un club

Cette fonctionnalité associe un joueur existant à un club.

- Si aucun club ou aucun joueur n'est enregistré, un message d'erreur s'affiche.
- Vous devez saisir l'identifiant du club, puis l'identifiant du joueur.
- Si le joueur est déjà pensionnaire du club, un message indique que le joueur est déjà ajouté.
- Si le club et le joueur existent, le joueur est ajouté au club.

### Afficher les joueurs d'un club

Cette option affiche les joueurs affectés à un club donné.

- Si le club n'existe pas, un message d'erreur s'affiche.
- Si le club existe mais qu'il n'a aucun joueur, le message suivant s'affiche :

  _"Aucun joueur à afficher pour ce club."_
- Sinon, la liste des joueurs du club est affichée.

## Menu Compétitions

Ce menu permet de gérer les compétitions. Il contient 8 options.

- 1 - Ajouter une compétition
- 2 - Ajouter des participants à une compétition
- 3 - Afficher les compétitions
- 4 - Rechercher une compétition
- 5 - Supprimer une compétition
- 6 - Supprimer un participant
- 7 - Mettre à jour une compétition
- 8 - Trier les participants d'une compétition

### Ajouter une compétition

Cette fonctionnalité permet d'enregistrer une nouvelle compétition.

- Les informations demandées sont : identifiant, nom, saison, type et nombre maximal de participants.
- La saison doit être saisie au format `aaaa/aaaa`.
- Après ajout, un message de confirmation s'affiche.

### Ajouter des participants à une compétition

Cette option ajoute un club participant à une compétition existante.

- Vous devez saisir l'identifiant de la compétition, puis l'identifiant du club.
- Si la compétition ou le club n'existe pas, un message d'erreur s'affiche.
- Si le club est déjà participant, un message indique qu'il est déjà inscrit.
- Si l'ajout réussit, le club est ajouté avec 0 point.

### Afficher les compétitions

Cette option affiche toutes les compétitions enregistrées.

- Si aucune compétition n'est enregistrée, le message suivant s'affiche :

  _"Liste vide. Aucune compétition à afficher."_
- Sinon, chaque compétition est affichée avec ses détails et ses participants.

### Rechercher une compétition

Cette fonctionnalité permet de rechercher une compétition par identifiant.

- Si aucune compétition n'est enregistrée, le message suivant s'affiche :

  _"Aucune compétition enregistrée."_
- Si la compétition n'existe pas, le message suivant s'affiche :

  _"Aucune compétition n'est enregistrée avec cet identifiant"_
- Si la compétition existe, ses détails sont affichés.

### Supprimer une compétition

Cette option supprime une compétition existante.

- Si aucune compétition n'est enregistrée, un message d'erreur s'affiche.
- Si la compétition n'existe pas, le message suivant s'affiche :

  _"Aucune compétition n'est enregistrée avec cet identifiant."_
- Si la compétition existe, elle est supprimée et un message de confirmation s'affiche.

### Supprimer un participant

Cette option supprime un club participant d'une compétition.

- Vous devez saisir l'identifiant de la compétition, puis celui du participant.
- Si la compétition n'existe pas, un message d'erreur s'affiche.
- Si le participant n'est pas trouvé, un message d'erreur s'affiche.
- Si la suppression réussit, un message de confirmation s'affiche.

### Mettre à jour une compétition

Cette fonctionnalité permet de modifier les informations d'une compétition existante.

- Après avoir saisi l'identifiant de la compétition, vous pouvez modifier : le nom, la saison, le type, le nombre maximal de participants ou les points d'un participant.
- Après modification, le message suivant s'affiche :

  _"Modification réussie !"_

### Trier les participants d'une compétition

Cette option trie les participants par points.

- Si aucune compétition n'est enregistrée, le message suivant s'affiche :

  _"Aucune compétition enregistrée."_
- Si la compétition n'a pas de participants, un message d'erreur s'affiche.
- Si la compétition existe et contient des participants, le classement est affiché par ordre décroissant de points.

## Navigation générale

À chaque choix dans le menu principal, l'application affiche les sous-options disponibles.  

- Après chaque action, le programme propose de continuer en appuyant sur Entrée.
- Pour quitter l'application, choisissez l'option _QUITTER_ du menu principal.

## Recommandations

- Saisissez les dates au format `jj mm aaaa`.
- Respectez les identifiants pour rechercher, supprimer ou mettre à jour des éléments.
- Après un tri, utilisez l'option d'affichage correspondante pour vérifier que l'ordre est correct.

