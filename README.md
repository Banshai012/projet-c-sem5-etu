# projet-c-sem5-etu — Mandelbrot

Projet de C (semestre 5, ENSEEIHT) : rendu graphique **interactif et multi-threadé** de la fractale de Mandelbrot en C avec SDL2.

Le squelette du projet (sujet, structure des modules, fichiers de test) a été fourni par l'enseignant G. Dupont (`sujet.pdf`) ; l'implémentation des modules ci-dessous est mon travail.

## Fonctionnalités

- Navigation interactive dans la fractale (zoom, déplacement) via `viewport`
- Rendu parallélisé sur plusieurs threads avec un pool de tâches (`pool.c`, `task_queue.c`)
- Palettes de couleurs configurables (`gradient.c`, `mosaic.c`)
- Options en ligne de commande et fichier de configuration (`options.c`, `config.c`)
- Arithmétique complexe dédiée (`complexe.c`)

## Compiler et exécuter

```bash
make            # compile la cible mandelbrot + lance les tests
./mandelbrot
```

Autres cibles utiles :

```bash
make test          # tests unitaires (complexe, options, pool, queue, viewport)
make debug         # build avec symboles de debug
make doc           # documentation Doxygen (voir Doxyfile)
```

## Dépendances

- SDL2 + SDL2_ttf
