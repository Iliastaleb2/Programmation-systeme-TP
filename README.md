# COMPTE RENDU DES TPs

## Introduction

Comme son nom l'indique, l'objectif de ce TP est de mettre en place un micro shell personnalisé. Chaque fichier sera la réponse de chaque question du sujet, on veillera à la lisibilité et à la clareté du code.

## Déroulé des séances

Dans un permier temps, on cherchera à mettre en place un message d'accueil lors du démarrage du shell, ensuite, on prendra en compte la commande tapée par l'utilisateur en affichant le code de retour du prompt de ce dernier ainsi que le temps d'exécution de la commande, puis on tentera d'implémenter des commandes plus complexes notamment avec des arguments supplémentaires et mettant en oeuvre des redirections (avec > et <).

# Première fonction :

Cette première fonction avait pour objectif d'afficher un message d'accueil suivi d'un prompt face auquel l'utilisateur pourra taper sa commande.

Pour ce faire, il nous suffit d'écrire deux fonctions, l'une gérant l'affichage du message d'accueil, l'autre affichant "enseaSH", par conséquent on utilise la fonction write (car on rappelle qu'on ne veut utiliser que des appels systèmes, malgré quelques exceptions ultérieures).

<img width="1133" height="111" alt="image" src="https://github.com/user-attachments/assets/ab3bd0ea-c710-449b-ac01-788ce1dce7cc" />

# Deuxième fonction :

Pour cette seconde fonction, on cherche à permettre à l'utilisateur d'exécuter des commandes (sans arguments pour le moment).

Pour ce faire, on se servira principalement de la fonction fork afin de créer un nouveau processus et exécuter la commande; ainsi il est nécessaire de modifier le main.c tel que si l'utilisateur écrit une commande, on l'exécute.

<img width="1017" height="245" alt="image" src="https://github.com/user-attachments/assets/c5810aed-db38-4a82-ae8c-cc26a620d18f" />

D'autre part, si l'on presse juste entrée, le système ne plante pas (c'était le cas avant les dernières corrections) :

<img width="1002" height="231" alt="image" src="https://github.com/user-attachments/assets/f39f2215-fac4-49ff-9f7c-26cefd88b338" />

# Fonction 3 :

L'objectif de cette troisième fonction réside simplement en la gestion de la sortie du shell par l'appui simultanée de ctrl+d ou par la saisie de "exit".

La difficultée principale pour le ctrl+d résidait principalement dans le fait que ctrl+d n'est pas une commande Enf Of File et que donc il faut s'assurer de lire correctement les bits du buffer pour le détecter.

(on a testé si les commandes comme ls ou pwd marche toujours, si le enter marche toujours et si le exit et le ctrl d fonctionne)

<img width="1146" height="262" alt="image" src="https://github.com/user-attachments/assets/0120402b-a3dd-426e-a6cf-85052f68c770" />

Lorsque j'ai fait ces quelques test, j'avais omis d'essayer mon code pour une fonction inexistante et de prendre en compte ce cas. J'y ai donc pallié :

<img width="1142" height="338" alt="image" src="https://github.com/user-attachments/assets/e90165f4-9237-46ac-9295-d2392e82fef6" />

# Fonction 4

L'objectif de cette fonction est de retourner le code de retour ou du signal de la commande précédente, pour ce faire, on se permettra l'utilisation de la commande snprintf afin d'afficher le code de retour ainsi que l'utilisation du statut précédent.

J'ai donc vérifié son fonctionnement pour une commande existante, une commande non existante puis pour un arrêt brutal du process avec "kill -9" (en l'occurence, cowsay).

<img width="1073" height="236" alt="image" src="https://github.com/user-attachments/assets/f4ccf1ef-ce21-42e5-93bb-d8ce804fae43" />

Voici 

<img width="1467" height="372" alt="image" src="https://github.com/user-attachments/assets/ec085140-cefc-4f63-a4a8-ab6ac6fd65fc" />

# Fonction 5

L'objectif de cette 5ème fonction est de mesurer le temps d'exécution de la commande en utilisant clock_gettime.

Dans cette optique, on veillera à convertir correctement le temps en ms et de la même manière que la fonction précédente, on se permettra l'utilisation de snprintf.

<img width="1336" height="212" alt="image" src="https://github.com/user-attachments/assets/addb5d99-1763-467f-9c96-b996010c3e8d" />

# Fonction 6

Pour cette sixième fonction, on souhaite cette fois-ci exécuter une fonction complexe, il nous a été suggérer d'utiliser la fonction strtok qui permet de séparer la commande en token et par conséquent détecter les arguments qui suivent la commande de l'utlisateur

<img width="1172" height="407" alt="image" src="https://github.com/user-attachments/assets/db3c0349-e880-4184-ae02-94d650e69a44" />

# Fonction 7

Pour finir ce TP, on cherche maintenant à gérer la redirection vers stdin et stdout, j'ai donc opté pour la même stratégie que la question 6, c'est àa dire, l'usage de la fonction strtok ensuite on cherche dans la chaîne de caractère un ">" ou "<" (c'est pour cela qu'on s'est permis l'usage de strcmp) puis si on repère un ">" on créé ou ouvre le fichier avec les bonnes permissions et pour le "<", l'ouvrir en lecture seule suffit.

<img width="1275" height="366" alt="image" src="https://github.com/user-attachments/assets/7ac40045-229f-40b8-8e46-a22c50e09692" />











