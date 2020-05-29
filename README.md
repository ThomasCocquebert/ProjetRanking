# ProjetRanking
Sujet numéro 3 : Utilisation du PageRank précédent pour initialiser un nouveau calcul-sous graphe

## Compilation des fichiers binaires

Un Makefile est à votre disposition, vous pouvez compiler tout les exécutables avec la commande :
```bash
make
```

Ou seulemnt l'exécutable du main avec :
```bash
make main
```
Pour supprimer les fichiers otenue lors de la compilation : 
```bash
make clean
```
ou pour windows 
```bash
make cleanW
```
## Format de fichier de graphe
Les fichiers de graphes doivent **IMPERATIVEMENT** commencer par le nombre d'éléments non-nuls puis le nombre de sommets du graphe pour être acceptés et traités correctement par le programme.

Exemple de graphe accepté :
<pre><code>
6
4
1 1 3 1
2 0
3 3 2 0.3 3 0.3 4 0.6
4 2 1 0.5 4 0.5
</code></pre>

## Utilisation du programme
Notre programme charge graphe et exécute plusieurs calcul sur celui ci :
* Un premier PageRank à l'isue duquel nous stockerons le vecteur x obtenue lors de la convergence du PageRank
* Une suppression d'éléments de ce graphe
* Un deuxième PageRank sur le graphe modifié
* Un troisième PageRank sur le graphe modifié mais cette fois ci initialisé à l'aide du vectuer x obtenu précédement

L'argument `-dA` indique que le programme va modifier le graphe en supprimant uniquement des arcs indépendament de leurs numéro de ligne ou de colonne

L'argument `-dCA` indique que le programme va modifier le graphe en supprimant à la fois des sommets du graphes mais également va égalemnt des arcs en plus

L'absence d'un de ces deux arguments signifie que le programme va supprimer des sommets du graphe lors de la modification de celui ci

Voici les façons possible d'utiliser le programme 
* `./main nom_du_graphe` : effectur les calcul sur le graphe nom_du_graphe avec une probabilité de suppression des sommets lors de la modification du graphe de 5 %
* `./main nom_du_graphe proba` : effectur les calcul sur le graphe nom_du_graphe avec une probabilité de suppression des sommets lors de la modification du graphe de proba%
* `./main nom_du_graphe -dA proba` : effectue les calculs sur le graphe nom_du_graphe avec une probabilité de suppression des arcs lors de la modification du graphe de proba%
* `./main nom_du_graphe -dCA probaSommet probaArc` : effectue les calculs sur le graphe nom_du_graphe avec une probabilité de suppression des sommets de probaSommet% et une probabilité de suppression des arcs de probaArc% lors de la modification du graphe
