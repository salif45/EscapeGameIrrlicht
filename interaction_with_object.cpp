#include "interaction_with_object.h"


//variable pour le temps
std::chrono::time_point<std::chrono::system_clock> start;
std::chrono::time_point<std::chrono::system_clock> end;
int elapsed_seconds =0;

bool interaction_perso_QMark (is::IAnimatedMeshSceneNode *QMark,  is::IAnimatedMeshSceneNode *perso, bool *visible,
                              bool *fenetre, bool *cpt,ig::IGUIImage *timer_10,
                                                                ig::IGUIImage *timer_1,
                              ig::IGUIWindow *window_enigme, iv::IVideoDriver  *driver)
{
    iv::ITexture *digits[10];
    digits[0] = driver->getTexture("data/0.png");
    digits[1] = driver->getTexture("data/1.png");
    digits[2] = driver->getTexture("data/2.png");
    digits[3] = driver->getTexture("data/3.png");
    digits[4] = driver->getTexture("data/4.png");
    digits[5] = driver->getTexture("data/5.png");
    digits[6] = driver->getTexture("data/6.png");
    digits[7] = driver->getTexture("data/7.png");
    digits[8] = driver->getTexture("data/8.png");
    digits[9] = driver->getTexture("data/9.png");
    // Interaction entre perso et QMark
    if(abs(perso->getPosition().X - QMark->getPosition().X)<=15 && abs(perso->getPosition().Z - QMark->getPosition().Z)<=15 && visible)
    {

        if(!(*fenetre))
        {
            // Une fenêtre pour différents réglages
            window_enigme->setVisible(true); //Affiche la fenêtre
            *fenetre = true;
            *cpt= true;
            start = std::chrono::system_clock::now();
        }


        if(*cpt )
        {
            end = std::chrono::system_clock::now();

            //Chrono pour le temps de répondre à la question
            elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
                                          (end- start).count();

            if(elapsed_seconds == 15)
            {
                // Si fin du temps et pas de réponse: ferme fenêtre et enlève l'objet

                *fenetre = false;
                *cpt = false;
                *visible = false;
                window_enigme->setVisible(*visible);
                QMark->setVisible(*visible);
                timer_10->setImage(digits[(0 / 1000) % 10]);
                timer_1->setImage(digits[(0 / 100) % 10]);

            }

            else
            {
                timer_10->setImage(digits[((15 -elapsed_seconds)/ 10) % 10]);
                timer_1->setImage(digits[((15 -elapsed_seconds)) % 10]);
            }

        }
    }

  return *visible;

}





