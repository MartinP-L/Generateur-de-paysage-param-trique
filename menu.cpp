#include "menu.h"
#include <stdlib.h> //pour les system pause et cls


//- - - - - - - - - - - - - - - - - -

void affichage_entete_menu()
{
    int n = 29; //variable nbr espaces pour tabulation du texte

    //en_tete menu
    std::cout << std::endl << std::string(n, ' ') << "                ______" << std::endl
              << std::string(n, ' ')              << "               |      |" << std::endl
              << std::string(n, ' ')              << " - - -- -- --- | MENU | --- -- -- - - " << std::endl
              << std::string(n, ' ')              << " |             |______|             |" << std::endl ;

}

//- - - - - - - - - - - - - - - - - -

///_______________________________________
///CODE MENU CONSOLE
///_______________________________________

void menu_console()
{
    int n = 30; //variable nbr espaces pour tabulation du texte
    Console console; //objet de Console pour changer couleurs affichage console
    int choix_1, choix_2; //variables pour choix du menu
    bool sortie_1(false), sortie_2(false); //variables sorties boucles menus



    do //boucle de menu
    {
        affichage_entete_menu(); //affichage de l'en-tete du menu
        //affichage du menu 1
        std::cout << std::string(n, ' ')<< "|                                  |"<<std::endl
                  << std::string(n, ' ')<< "|  0 - Quitter                     |"<<std::endl
                  << std::string(n, ' ')<< "|  1 - Creer un nouveau paysage    |"<<std::endl
                  << std::string(n, ' ')<< "|__________________________________|"<<std::endl <<std::endl << std::string(n+10, ' ')<< " votre choix : ";

        console.setColor(COLOR_RED); //saisie en rouge
        std::cin>>choix_1;//saisie du choix du menu
        console.setColor(COLOR_WHITE);

        if(choix_1 == 0) //quitter
            sortie_1 = true;

        if(choix_1 == 1) //creer un nouveau paysage
        {
            do
            {


                system("cls"); //effaçage de l'écran
                std::cout << std::endl << std::endl;
                affichage_entete_menu(); //affichage de l'en-tete du menu
                //affichage du menu 2
                std::cout << std::string(n, ' ')<< "|    PARAMETRES DE LA CREATION     |"<<std::endl
                          << std::string(n, ' ')<< "|                                  |"<<std::endl
                          << std::string(n, ' ')<< "|  0 - revenir au menu precedent   |"<<std::endl
                          << std::string(n, ' ')<< "|                                  |"<<std::endl
                          << std::string(n, ' ')<< "|  1 - Paramètres d'arbres         |"<<std::endl
                          << std::string(n, ' ')<< "|  2 - Paramètre 2                 |"<<std::endl
                          << std::string(n, ' ')<< "|  3 - nia nia                     |"<<std::endl
                          << std::string(n, ' ')<< "|  4 - test 1.0.00.000             |"<<std::endl
                          << std::string(n, ' ')<< "|  5 - test 2.1.00.000             |"<<std::endl
                          << std::string(n, ' ')<< "|                                  |"<<std::endl
                          << std::string(n, ' ')<< "|  10 - CREER                      |"<<std::endl
                          << std::string(n, ' ')<< "|__________________________________|"<<std::endl <<std::endl << std::string(n+10, ' ')<< " votre choix : ";

                console.setColor(COLOR_RED); //saisie en rouge
                std::cin>>choix_2;//saisie du choix du menu
                console.setColor(COLOR_WHITE);

                switch(choix_2)
                {
                case 0: //revenir au menu précédent
                    sortie_2 = true;
                    break;
                case 1: //..

                    break;
                case 2: //..

                    break;
                case 3: //..

                    break;
                ///______________________________________ _ _ _ _ _ _ _ _ _ _ _ _ _
                case 4: //..TEST 1

                {
                    // Déclaration locale d'un nouvel accès fichier, ceci écrasera l'ancien !
                    Svgfile svgout;

                    // Dessin du repère cartésien (ou pas, à vous de voir)
                    svgout.addGrid();

                    // Appel de la fonction de dessin de tous les astres
                    svgout.addDisk(100,100,50,"red");

                    // On est dans un switch, ne pas oublier le break de fin de case
                    break;
                    // L'accolade fermante marque la fin du scope : l'objet svgout est détruit, le fichier est fermé !
                }

                case 5: //test 2
                {
                    // Déclaration locale d'un nouvel accès fichier, ceci écrasera l'ancien !
                    Svgfile svgout;
                    // Dessin du repère cartésien (ou pas, à vous de voir)
                    svgout.addGrid();
                    // Appel de la fonction de dessin de tous les astres
                    svgout.addDisk(200,200,50,"red");

                    // On est dans un switch, ne pas oublier le break de fin de case
                    break;
                    // L'accolade fermante marque la fin du scope : l'objet svgout est détruit, le fichier est fermé !
                }
                ///______________________________________ _ _ _ _ _ _ _ _ _ _ _ _ _
                default:
                    std::cout<<std::endl<<"saisie incorrecte, reessayer"<<std::endl; //si choix non prévu redemander saisie
                    break;

                }
            }
            while(sortie_2 != true);
            system("cls");
        }

        else //si ni 0 ni 1 choisi lors du choix_1, saisie incorrecte
            std::cout<<std::endl<<"saisie incorrecte, reessayer"<<std::endl;
    }
    while(sortie_1 != true);  //si sortie "true" -> quitter la boucle et donc arriver au return 0 -> quitter programme



}




///________________________________
///code en tete menu

void affichage_entete()
{
    int n = 10; //variable nbr espaces pour tabulation du texte
    Console console; //création d'un objet Console pour changer la couleur de l'affichage dans la console

    console.setColor(COLOR_GREEN);//couleur affichage console en rouge
    //créé avec l'aide de    http://www.messletters.com/en/
    std::cout << std::string(n, ' ') <<  "    ____    ___   _____   _   _  __     __  _____   _   _   _   _   _____  "<< std::endl
              << std::string(n, ' ') <<  "   | __ )  |_ _| | ____| | \\ | | \\ \\   / / | ____| | \\ | | | | | | | ____| "<< std::endl
              << std::string(n, ' ') <<  "   |  _ \\   | |  |  _|   |  \\| |  \\ \\ / /  |  _|   |  \\| | | | | | |  _|   "<< std::endl
              << std::string(n, ' ') <<  "   | |_) |  | |  | |___  | |\\  |   \\ V /   | |___  | |\\  | | |_| | | |___  "<< std::endl
              << std::string(n, ' ') <<  "   |____/  |___| |_____| |_| \\_|    \\_/    |_____| |_| \\_|  \\___/  |_____| "<< std::endl << std::endl;
    console.setColor(COLOR_WHITE);
    std::cout << std::string(n+18, ' ') <<  " GENERATEUR PARAMETRIQUE DE PAYSAGE " << std::endl
              << std::string(n+18, ' ') <<  "                  par " << std::endl
              << std::string(n+9, ' ') <<  "Remi Fiorenza & Guillaume Marie & Martin Puyou-Lascassies " << std::endl;
    console.setColor(COLOR_YELLOW);
    std::cout << "    _ _ __ __ ___ ____ _______________________________________________ ____ ___ ___ __ __ _ _ " << std::endl << std::endl;
    console.setColor(COLOR_WHITE);
}




