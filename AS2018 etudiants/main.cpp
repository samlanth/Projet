/*
Le programme principal (main)

	Est partiellement écrit pour vous
	Des commentaires dans le code vous indiquent ce que vous devez y ajouter
	Créez des monstres au hasard (Brute ou Voleur) à des endroits valides choisis au hasard à l’aide de l’opérateur new et ajoutez-les au tableau de monstres;
	Créez des sous à des endroits valides choisis au hasard à l’aide de l’opérateur new et les ajouter au tableau d’objets;
	Créez des objets au hasard (Pain ou Bouclier) à des endroits valides choisis au hasard à l’aide de l’opérateur new et ajoutez-les au tableau d’objets;
	Modifiez la boucle d’affichage de façon à :
	Déplacer le héros et tous les monstres;
	Le personnage doit tenter de prendre tous les objets;
	Tous les monstres doivent tenter d’attaquer le personnage;
	Si un objet est ramassé, sa mémoire est libérée et son pointeur est affecté à nullptr;
	La condition de fin de la boucle doit permettre de terminer une partie dès qu’une de ces conditions est vraie :
	Le Héros est mort
	Le Héros a ramassé suffisamment de sous (constante NbSousVictoire)
	Il est impossible de ramasser suffisamment de sous pour gagner (parce que les Voleurs en ont trop pris)
	Le joueur a demandé de quitter en appuyant sur Esc ou en fermant la fenêtre de jeu
	Lorsque l’on quitte la boucle, un message approprié indiquant ce qui s’est passé doit être affiché à la console.
	En fin de programme, il faut libérer les monstres et les objets restants.

*/
////////////////////////////////////////////////////////////
// main.cpp
// 
// Programme principal de jeu de Treasure Hunter
// Activité Synthèse 420-KAB-LG
// Etienne Forest
// Création: 27 avril 2018
// Version 1.0
// 
////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib> // pour le rand et le srand
#include <ctime> // pour le time dans le srand
#include "Constantes.h"
#include "Carte.h"
#include "Heros.h"
#include "Brute.h"
#include "Voleur.h"
using namespace std;
using namespace sf;

int main(int argc, char *argv[])
{
	bool bQuitter = true; // Vrai s'il faut continuer la partie
	bool bHeros = true;	  // Vrai si le héros est vivant

	// Tableau de monstres
	CMonstre* Mechants[NbMonstres];

	// Tableau d'objets 
	CObjet* Objets[NbObjets];
	
	srand(static_cast<unsigned int>(time(0)));

	try
	{
		// Création des objets
		// Fenêtre
		RenderWindow Fenetre(VideoMode(Largeur, Hauteur), "Treasure Hunter");

		// Carte
		Texture MondeText;
		MondeText.loadFromFile("Res\\lemonde.png");
		Image MondeMasque;
		MondeMasque.loadFromFile("Res\\MasqueDuMonde.png");
		CCarte Monde(MondeText, MondeMasque);

		// Heros
		Texture HerosText;
		HerosText.loadFromFile("Res\\Heros.png");
		CHeros Heros(HerosText, CPosition(1000, 1000), "Heros", 3, 0);

		// Monstres
		Texture BruteText;
		BruteText.loadFromFile("Res\\brute.png");
		Texture VoleurText;
		VoleurText.loadFromFile("Res\\voleur.png");

		// Initialisation du tableau de Monstres
		// Choisir entre une Brute et un Voleur au hasard pour chaque Monstre
		// Le placer à une position VALIDE aléatoire dans le monde.
		
		// Objets
		Texture PainText;
		PainText.loadFromFile("Res\\pain.png");
		Texture BouclierText;
		BouclierText.loadFromFile("Res\\bouclier.png");
		Texture SouText;
		SouText.loadFromFile("Res\\sou.png");

		// Initialisation des sous (le nombre de sous est déterminé par la constante NbSous
		// et les sous sont placés en premier dans le tableau d'objets)
		// Choisir une position aléatoire VALIDE pour chaque sou dans le monde.
		
		// Initialisation des autres objets dans le tableau d'objets
		// Pour chacun d'eux, choisir au hasard entre un pain et un bouclier
		// Leur choisir une position aléatoire VALIDE dans le monde.
		

		// Boucle d'affichage et de jeu
		do
		{
			// Déplacer le héros et déterminer si le joueur a demandé de quitter le jeu
			//bQuitter = Heros.Deplacer(Monde, Heros.getPosition());
            Direction d = Haut; // Get keyboard
            bQuitter = Heros.Deplacer(Monde, d);

			// Déplacer tous les monstres
			
			// Le héros essaie de prendre tous les objets
			// S'il arrive à prendre un sou : afficher le nombre de sous restant dans le monde
			
			// Tous les monstres essaient d'attaquer le héros
			
			// Affichage
			// Fenêtre
			View Vue = Fenetre.getView();
			Vue.setCenter(Heros.getPosition());
			Fenetre.setView(Vue);

			// Afficher la carte
			Monde.Afficher(Fenetre);

			// Afficher tous les objets
			
			// Afficher tous les monstres
			
			// Afficher le héros
			if (bHeros)
				Heros.Afficher(Fenetre);

			// Rafraichir la fenêtre
			Fenetre.display();

			// On inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
			Event event;
			while (Fenetre.pollEvent(event))
			{
				// événement "fermeture demandée" : on ferme la fenêtre
				if (event.type == Event::Closed)
					Fenetre.close();
			}

			// Attendre 30 millisecondes pour ralentir le jeu
			sleep(milliseconds(30));

		} while (!bQuitter && bHeros && Fenetre.isOpen());
		// Continuer tant que la fin de la partie n'est pas atteinte
		// Une partie finit si : le héros est mort, le héros a ramassé assez de sous, il n'est plus possible de ramasser assez de sous, 
		// le joueur a demandé de quitter, le joueur a fermé la fenêtre
	}
	catch (string s)
	{
		cout << s;
	}

	if (!bHeros)
	{
		cout << "Tu es mort!" << endl;
	}

	// Effacer les monstres et les objets
	
	return 0;
}