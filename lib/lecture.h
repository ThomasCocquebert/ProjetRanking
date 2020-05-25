#ifndef LECTURE_H
#define LECTURE_H

/*
Get the number of arcs
fichier : the graph file open
*/
int NBarcs(FILE* fichier);

/*
Get the number of summits
fichier : the graph file open
*/
int NBsommets(FILE* fichier);

/*
Get the graph
fichier : the graph file open
NombreSommets : The number of summits
*/
Liste* LectureFichier(FILE* fichier, int NombreSommets);


#endif
