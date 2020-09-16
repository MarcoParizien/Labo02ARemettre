//But: Écrire un programme pour calculer le montant qu’un individu devra débourser pour faire un voyage dans une
//automobile louée
//Auteur: Marc-Olivier Parisien
//Date: 14-09-2020

#include <iostream>


int main()
{
	setlocale(LC_ALL, "");

		//Declaration des variables

		int nbJrs; //Nombre de jours pour le voyage
		int nbKm; //Nombre de kilomètre pour le voyage
		int prixNbJrs; //Coût total pour le nombre de jour que la voiture sera louée. 45$/jour
		float coutTotal; // Coût total de la location
		float prixEss; // Variable ou sera stocké le prix total de l'essence selon la distance paracourue. 7.6L/100km
		float supKm; // Surplus du kilometrage. Ici on doit utiliser un float car le surplus de KM est multiplié par un chiffre a virgule. (0.05)
		float coutKm; //Le prix total du killométrage dépassé

		//Demander à l'utilisateur d'entrer le nombre de jours de vacances
		std::cout << "Veuillez entrer le nombre de jours prévus pour le voyage. ";
		//Stock la valeur dans la variable nbJrs (nombre de jours)
		std::cin >> nbJrs;

		//Demander à l'utilisateur le nombre de kilomètres qu'il parcoura pendant le voyage.
		std::cout << "Veuillez entrer le nombre (entier) de kilomètres qui sera pacourus. ";
		//Stock la valeur dans la variable nbKM pour le nombre de kilomètres
		std::cin >> nbKm;

		// Si une des deux variables entrée est négative ou égale à 0 alors on affiche un message d'erreur. 
		if (nbJrs <= 0 || nbKm <= 0 )
		{
			std::cout << "ERREUR. La distance ou le nombre de jours est plus petit ou égal à 0. ";
		}

		//Si les deux valeurs sont plus grandes que 0 alors le programme éxecute le calcul du prix. 
		else
		{
			//Le programme calcul le coût total pour le nombre de jours et le stock dans la variable prixNbJrs. 45$/jours
			prixNbJrs = nbJrs * 45;
		
			//Le programme doit calculer si les voyageurs devront débourser de l'argent pour chaque km dépassé. 

			supKm = (nbKm - (250 * nbJrs)); // Ici, le programme calcul le nombre de km gratuit et si ça dépasse

			if (supKm <= 0.0) //Dans le cas où le calcul serait négatif, il met la valeur à 0 puisqu'on ne peut pas avoir de surplus négatif
			{
				supKm = 0.0;
			}
			else 
			{
				supKm = supKm * 0.05; //Le programme calcul le coût de surplus de kilommètre
			}

			//Le programme doit calculer la consommation d'essance de la voiture selon la distance parcourue. 
				prixEss = ((7.6 * nbKm) / 100);
				prixEss = (prixEss * 1.25);

				//Le programme calcul le coût total
				coutTotal = prixEss + supKm + prixNbJrs;
		
				//Le programme affiche les différents coût total pour donner plus d'information à l'utilisateur
				std::cout << "Le coût total pour l'essence utilisé sera de "; std::cout << prixEss;  std::cout << "$." << std::endl;
				std::cout << "Le coût total pour les killomètre dépassés sera de "; std::cout << supKm; std::cout << "$." << std::endl;
				std::cout << "Le coût total pour la location de la voiture sera de "; std::cout << prixNbJrs; std::cout << "$." << std::endl;

				//Le programme affiche le coût total
				std::cout << "Le coût total de vos vancances sera de "; std::cout << coutTotal; std::cout << "$." << std::endl;
				std::cout << "Merci et bon voyage!";
		}

	return 0;
}

//Plan test

/*
nombre de jours		nombre de kilomètres		Résultat

-10					-586						ERREUR. La distance ou le nombre de jours est plus petit ou égal à 0.

10					-250						ERREUR. La distance ou le nombre de jours est plus petit ou égal à 0.

-1					500							ERREUR. La distance ou le nombre de jours est plus petit ou égal à 0.

0					250							ERREUR. La distance ou le nombre de jours est plus petit ou égal à 0.

2					0							ERREUR. La distance ou le nombre de jours est plus petit ou égal à 0.

1					250							Le coût total pour l'essence utilisé sera de 23.75$
												Le coût total pour les killomètre dépassés sera de 0$
												Le coût total pour la location de la voiture sera de 45$
												Le coût total de vos vacances sera de 68.75$. 
												Merci et bon voyage!

2					1000						Le coût total pour l'essence utilisé sera de 95$
												Le coût total pour les killomètre dépassés sera de 25$
												Le coût total pour la location de la voiture sera de 90$
												Le coût total de vos vacances sera de 210$. 
												Merci et bon voyage!

2					501							Le coût total pour l'essence utilisé sera de 47.595$
												Le coût total pour les killomètre dépassés sera de 0.05$
												Le coût total pour la location de la voiture sera de 90$
												Le coût total de vos vacances sera de 137.645$. 
												Merci et bon voyage!

*/