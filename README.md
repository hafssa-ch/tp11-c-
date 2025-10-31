# Exercice 1 : Formes géométriques
## Objectif :
Implémenter une hiérarchie de formes géométriques avec une méthode virtuelle pure.

## Description :
Classe abstraite Forme avec la méthode pure double aire() const.
Classes dérivées :
Cercle (attribut rayon)
Rectangle (attributs longueur et largeur)
L’utilisateur saisit les dimensions des formes, elles sont stockées dans un vecteur de pointeurs vers Forme.
Le programme affiche l’aire de chaque forme.

<img width="909" height="594" alt="image" src="https://github.com/user-attachments/assets/6ba71954-6764-41f0-9f6d-1a6d6e2b8152" />


# Exercice 2 : Interface de paiement
## Objectif :
Simuler une interface abstraite pour différents moyens de paiement.

## Description :
Classe abstraite Paiement avec la méthode pure effectuerPaiement(double montant).
Classes dérivées :
PaiementCarte : affiche "Paiement de X DH par carte bancaire."
PaiementEspece : affiche "Paiement de X DH en espèces."
Un vecteur de pointeurs vers Paiement est utilisé pour stocker différentes instances et simuler plusieurs paiements via polymorphisme.

<img width="930" height="617" alt="image" src="https://github.com/user-attachments/assets/618a5a4d-f547-4049-be0f-c96adc96768d" />


# Exercice 3 : Gestion d’animaux
## Objectif :
Utiliser des classes abstraites pour généraliser les comportements animaux.

## Description :
Classe abstraite Animal :
Méthode pure void crier() const
Méthode concrète void info() const affichant "Je suis un animal."
Classes concrètes :
Chien : affiche "Wouf !"
Chat : affiche "Miaou !"
Vache : affiche "Meuh !"
Les objets sont stockés dans un vecteur de pointeurs vers Animal, et les méthodes sont appelées pour chaque animal.


<img width="707" height="345" alt="image" src="https://github.com/user-attachments/assets/f8fe1d9d-28d8-4efa-a462-56a538983a46" />


# Exercice 4 : Système de fichiers virtuel

## Objectif :
Simuler une interface de gestion de fichiers avec abstraction.

## Description :
Classe abstraite NoeudFichier :
Méthode pure int taille() const
Méthode std::string nom() const
Classes concrètes :
Fichier : possède un nom et une taille
Dossier : contient une liste de NoeudFichier* (fichiers et sous-dossiers) et calcule sa taille comme la somme de ses enfants
L’utilisateur peut créer une hiérarchie de fichiers et dossiers, et afficher la taille totale d’un dossier sélectionné.

<img width="676" height="116" alt="image" src="https://github.com/user-attachments/assets/a33930d4-2264-4bef-a42c-6fc5a3b359a2" />
