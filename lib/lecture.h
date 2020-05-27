#ifndef LECTURE_H
#define LECTURE_H

/*
Get the number of arcs
fichier : the graph file open
Return the number of edge in the graph
*/
int NBarcs(FILE* fichier);

/*
Get the number of summits
fichier : the graph file open
Return the number of Sommet in the graph
*/
int NBsommets(FILE* fichier);

/*
Get the graph
fichier : the graph file open
NombreSommets : The number of summits
Return the strcuture List read from the file
*/
Liste* LectureFichier(FILE* fichier, int NombreSommets);


#endif
