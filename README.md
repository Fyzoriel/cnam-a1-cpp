# cnam-a1-cpp

**Tableau comparatif**

|                | Benoît | leo |
|----------------|--------|-----|
| S              | Oui    | Oui |
| O              | Oui    | Oui |
| L              | x      | Non |
| I              | Oui    | Non |
| D              | Non    | Non |
| déméter        | Oui    | Oui |
| Tell don't ask | Oui    | Oui |

S: Dans les deux projets, chaque classe s'occupe de la seule responsabilité qu'elle a et ne fait pas le travail d'une autre

O: Il n'y a pas de redéfinition de méthode, on ne fait qu'en ajouter des supplémentaires

L: Dans le projet de Benoît, il n'y a pas d'héritage, on ne peut donc évaluer ce principe. Dans le projet de leo, la classe enfant ne peut pas faire ce que fait la classe mère (Il y a besoin d'une vérification sur le type de la classe)

I: Dans le projet de Benoît, il n'y a pas de méthodes implémentées inutilement, ou qui prennent en parramètre des objets de valeur null. Dans le projet de leo, la méthode d'ajout de jeton prends en paramètre y = 0 pour la grille de puissance 4

D: La modification d'une classe de bas niveau entraine une modification de la classe de haut niveau, il n'y a pas d'abstraction entre les deux niveaux

Déméter: Dans les deux projets, on accède aux méthodes des classes sans utilisé de classe intermédiaire qui servent de "pont"

Tell don't ask: Dans aucun des projets, un objet demande une information sur son propre état à un autre objet

**conclusion**

Le projet de benoît respecte le plus de principes. Néanmois ce projet n'étant pas fonctionnel, nous choisissons de prendre le projet de leo, et de retravailler celui-ci de manière à respecter les principes manquants.