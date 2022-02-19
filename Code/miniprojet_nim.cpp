#include <iostream>
#include <limits.h>
#include <string.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(int argc, char **argv)
{
    cout << "Quel sera le nom des joueurs ?" << endl ;
    string nom[2];
    int score[2]={0,0};
    cin >> nom[0];
    cin >> nom[1];
    char perdu;
    char rejouer;
    int max;
    //Initialisation du generateur aléatoire
    srand(time(NULL));

    int num_joueur = 0;

    do
    {

    cout << nom[0] << " quel sera le nombre maximun de batonnets ?" << endl;
    cin >> max;
    cout << endl;
    }

    while(max<=0);

    do
    {

        bool gagne = false;
        //Géneration de trois valeurs aléatoires dans un tableau
        int tas[3] = { rand()%max+1,rand()%max+1, rand()%max+1};

        while(!gagne)
        {

            for (int i = 0; i < 3 ; i++)
            {
                cout << (char) ('A'+i)  << ": ";
                for (int nba = 0; nba<tas[i] ; nba++)
                {
                    cout << "|" ;
                }
                cout << endl;
            }

            int numtas;
            do
            {
                cout << endl;
                cout << nom[num_joueur] << " Saisie le tas A,B ou C: ";
                char numtaschar;
                cin >> numtaschar ;
                numtas = numtaschar - 'A';
            }
            while (numtas>2 || numtas<0 );

            if(tas[numtas] == 0)
            {
                cout << nom[num_joueur] << " a perdu car il souhaitais piocher dans un tas vide" << endl;
                gagne=true;
                continue;
            }
            int numenlev ;

            do
            {
                cout << "Combien souhaitez vous en enlever ?" << endl;
                cin >> numenlev;
                cout << endl;
            }
            while (numenlev <=0 || numenlev > tas[numtas]);

            tas[numtas]-=numenlev;

            if(tas[0]==0 && tas[1]==0 && tas[2]==0)
            {
                gagne = true;
                cout << nom[num_joueur] << " vien de remporter la partie car il ne reste plus aucun baton" << endl;
            }
            num_joueur = !num_joueur;
        }

        score[!num_joueur]++;

        do
        {
        cout << endl;
        cout << nom[0] << " et " << nom[1] << " , souhaiter vous rejouer ?"<< endl;
        cin >> rejouer;
        }
        while(rejouer != 'o' && rejouer != 'O' && rejouer != 'n' && rejouer != 'N');
    }
    while(rejouer == 'o' || rejouer == 'O');

            cout << "Fin de Partie, " << nom[0] << " a remporter " << score[0] << " points et " << nom[1] << " a remporter " << score[1] << " points." << endl;
}