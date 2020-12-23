# Journal de Bord

- Installation de la Bibliothèque SDL réussie. 
- Création de la Fenètre et mise en place d'une image de fond (2 Warning à traiter)
- Design de 1 Map, Plaquettes Perso faites et batiment


## Explication

Le but de ``` fight for Domination ``` est de capturer toutes les villes de son adversaire. Pour ce faire, le joueur dispose de batiments lui permettant de former des unités. Cela se joue au tour par tour en local.

### Début de Partie

Le joueur dispose d'une ville (sa capitale),de 2 ouvriers et de 25 de monnaie

### Construction des batiments

Vous pouvez construire les batiments sur votre territoire uniquement (Autour des villes et/ou des bunkers). Un batiment prend une case. Les unités peuvennt être sur la même case qu'un batiment, mais il ne peut y avoir deux batiments sur la même case. Vous pouvez à tout moment détuire un batiment mais cela ne vous rembourse pas son prix. Les batiments ne donnent pas de vision sur les cases adjacentes !


- **Mine Niv 1**, nécéssite : RIEN | Coût : 10 | Temps de construction : 1 tour
La mine est le batiment de base pour la production de monnaie. La mine LV1 peut contenir 4 ouvriers au maximum travaillant en simultanée. Chaque ouvrier raporte 5 minerai par tour

- **Caserne Niv 1** , nécéssite : RIEN | Coût : 15 | Temps de construction : 1 tour
La caserne est le batiment de base pour la formation d'unité de combat. Elle débloque la formation des guerriers et des Archers. On peut former une unité à la fois.

- **Tour de guet**, nécéssite : Caserne Niv 1 | Coût : 10 | Temps de construction : 1 tour
La tour de guet permet d'aggrandir la vision du monde lorsqu'il y a une unité dedans. elle double la vision qui passe à 2 cases autour du batiments.

- **Tentes**, nécéssite : Caserne Niv 1 | Coût : 20 | Temps de construction : 2 tours
La tentes permet de débloquer des améliorations pour les unités. Vous pouvez améliorez un type d'unité à la fois. Voir section ```Améliorations```.

- **Caserne Niv 2**, nécéssite : Tentes | Coût : 25 | Temps d'amélioration : 2 tours
Améliorer sa caserne va permettre de débloquer les défenseurs et de former deux unités en simultanées, uniquement dans la caserne améliorée.

- **Mines Niv 2**, nécéssite : Caserne Niv 2 | Coût : 15 | Temps d'amélioration : 1 tour
Améliorer sa mine va permettre de faire travailler jusqu`à 6 ouvriers dans la mine. Chaque ouvrier raporte 7 minerai par tour

- **Usine**, nécéssite : Caserne niv 2 et mines niv 2 | Coût : 30 | Temps de construction : 2 tour
L'usine permet la formation des unités les plus puissantes : le vindicateur. On peut former 1 unité à la fois.

- **Bunker**, nécéssite : Caserne niv 2 et mines niv 2 | Coût : 40 | Temps de construction : 2 tour
Le Bunker permet de "capturer" du territoire et construire dans sur le terrain situé 1 case autour du bunker.


### Unitée

Les unités de combats ont toutes 2 niveaux (niveau 0 (base), niveau 1 (amélioré)). Les unités de combat ont un rayon de vision de 1 case autour d'elle.

(A = attaque (+ amélioration), D = défense (+ amélioration), M = case de déplacement)

- **Ouvrier** | A = 0 | D = 0 | M = 0 | Coût de Formation : 10 | Temps de formation : Immédiat
L'ouvrier est une unité que le joueur forme depuis l'hotel de ville. Le joueur sélectionne la mine à laquelle l'ouvrier va travailler. L'ouvrier peut à tout moment être changé dans une autre mine. Chaque ouvrier récole 5 minerai (mine lv 1), 7 minerai (mine lv 2) à chaque tour. 

- **Guerrier** | A = 15 (+5) | D = 20 (+8) | M = 2 | Coût Formation : 15 | Temps de formations : 1 tour
Le Guerrier est l'unité de base. Il peut attaquer dans un rayon de 1 case autour de lui, juste après s'être déplacé. 

- **Archer** | A = 10 (+5) | D = 15 (+10) | M = 2 | Coût Formation : 18 | Temps de formation : 1 tour
L'archer est une troupe à distance. Il peut attaquer dans un rayon de 3 cases autour de lui à condition d'avoir la vision

- **Defenseur** | A = 5 (+8) | D = 35 + (10) | M = 1 | Coût Formation : 20 | Temps de formation : 2 tours
Le défenseur est la troupe de défense par excellence. Elle est peu mobile mais fournit une protection aux troupes derrière

- **Vindicateur** | A = 25 (+8) | D = 32 (+10) | M = 2 | Coût Formation : 30 | Temps de formation : 2 tours
Le vindicateur est la troupe avec le plus d'attaque. Parfait pour créer une brèche dans les défenses ennemies.

### Amélioration

Dans la tente, vous pouvez améliorer chaque unitée :

- Guerrier niv 0 --> niv 1 : Temps 2 tours, coût 40
- Archer niv 0 --> niv 1 : temps 2 tours, coût 40
- Defenseur niv 0 --> niv 1 : temps 3 tours, coût 50
- Vindicateur niv 0 --> niv 1 : temps 3 tours, coût 60

### Combat

L'unité à le choix de se déplacer ou non, puis elle a le choix d'attquer ou de se soigner.

Le combat se fait au tour par tour. L'unité qui attaque inflige son montant d'attaque directement dans la vie de l'unité qui reçoit le coût. Si cette dernière est toujours vivante elle inflige en vengeance 1/3 de sa valeur d'attaque (en cas de décimal, on arrondit à l'entier du dessus). 

L'unité qui se soigne gagne +5 HP