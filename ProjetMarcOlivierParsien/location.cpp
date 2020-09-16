//But: �crire un programme pour calculer le montant qu�un individu devra d�bourser pour faire un voyage dans une
//automobile lou�e
//Auteur: Marc-Olivier Parisien
//Date: 14-09-2020

#include <iostream>


int main()
{
	setlocale(LC_ALL, "");

		//Declaration des variables

		int nbJrs; //Nombre de jours pour le voyage
		int nbKm; //Nombre de kilom�tre pour le voyage
		int prixNbJrs; //Co�t total pour le nombre de jour que la voiture sera lou�e. 45$/jour
		float coutTotal; // Co�t total de la location
		float prixEss; // Variable ou sera stock� le prix total de l'essence selon la distance paracourue. 7.6L/100km
		float supKm; // Surplus du kilometrage. Ici on doit utiliser un float car le surplus de KM est multipli� par un chiffre a virgule. (0.05)
		float coutKm; //Le prix total du killom�trage d�pass�

		//Demander � l'utilisateur d'entrer le nombre de jours de vacances
		std::cout << "Veuillez entrer le nombre de jours pr�vus pour le voyage. ";
		//Stock la valeur dans la variable nbJrs (nombre de jours)
		std::cin >> nbJrs;

		//Demander � l'utilisateur le nombre de kilom�tres qu'il parcoura pendant le voyage.
		std::cout << "Veuillez entrer le nombre (entier) de kilom�tres qui sera pacourus. ";
		//Stock la valeur dans la variable nbKM pour le nombre de kilom�tres
		std::cin >> nbKm;

		// Si une des deux variables entr�e est n�gative ou �gale � 0 alors on affiche un message d'erreur. 
		if (nbJrs <= 0 || nbKm <= 0 )
		{
			std::cout << "ERREUR. La distance ou le nombre de jours est plus petit ou �gal � 0. ";
		}

		//Si les deux valeurs sont plus grandes que 0 alors le programme �xecute le calcul du prix. 
		else
		{
			//Le programme calcul le co�t total pour le nombre de jours et le stock dans la variable prixNbJrs. 45$/jours
			prixNbJrs = nbJrs * 45;
		
			//Le programme doit calculer si les voyageurs devront d�bourser de l'argent pour chaque km d�pass�. 

			supKm = (nbKm - (250 * nbJrs)); // Ici, le programme calcul le nombre de km gratuit et si �a d�passe

			if (supKm <= 0.0) //Dans le cas o� le calcul serait n�gatif, il met la valeur � 0 puisqu'on ne peut pas avoir de surplus n�gatif
			{
				supKm = 0.0;
			}
			else 
			{
				supKm = supKm * 0.05; //Le programme calcul le co�t de surplus de kilomm�tre
			}

			//Le programme doit calculer la consommation d'essance de la voiture selon la distance parcourue. 
				prixEss = ((7.6 * nbKm) / 100);
				prixEss = (prixEss * 1.25);

				//Le programme calcul le co�t total
				coutTotal = prixEss + supKm + prixNbJrs;
		
				//Le programme affiche les diff�rents co�t total pour donner plus d'information � l'utilisateur
				std::cout << "Le co�t total pour l'essence utilis� sera de "; std::cout << prixEss;  std::cout << "$." << std::endl;
				std::cout << "Le co�t total pour les killom�tre d�pass�s sera de "; std::cout << supKm; std::cout << "$." << std::endl;
				std::cout << "Le co�t total pour la location de la voiture sera de "; std::cout << prixNbJrs; std::cout << "$." << std::endl;

				//Le programme affiche le co�t total
				std::cout << "Le co�t total de vos vancances sera de "; std::cout << coutTotal; std::cout << "$." << std::endl;
				std::cout << "Merci et bon voyage!";
		}

	return 0;
}

//Plan test

/*
nombre de jours		nombre de kilom�tres		R�sultat

-10					-586						ERREUR. La distance ou le nombre de jours est plus petit ou �gal � 0.

10					-250						ERREUR. La distance ou le nombre de jours est plus petit ou �gal � 0.

-1					500							ERREUR. La distance ou le nombre de jours est plus petit ou �gal � 0.

0					250							ERREUR. La distance ou le nombre de jours est plus petit ou �gal � 0.

2					0							ERREUR. La distance ou le nombre de jours est plus petit ou �gal � 0.

1					250							Le co�t total pour l'essence utilis� sera de 23.75$
												Le co�t total pour les killom�tre d�pass�s sera de 0$
												Le co�t total pour la location de la voiture sera de 45$
												Le co�t total de vos vacances sera de 68.75$. 
												Merci et bon voyage!

2					1000						Le co�t total pour l'essence utilis� sera de 95$
												Le co�t total pour les killom�tre d�pass�s sera de 25$
												Le co�t total pour la location de la voiture sera de 90$
												Le co�t total de vos vacances sera de 210$. 
												Merci et bon voyage!

2					501							Le co�t total pour l'essence utilis� sera de 47.595$
												Le co�t total pour les killom�tre d�pass�s sera de 0.05$
												Le co�t total pour la location de la voiture sera de 90$
												Le co�t total de vos vacances sera de 137.645$. 
												Merci et bon voyage!

*/