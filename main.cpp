#include <irrlicht.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <ctime>
#include<vector>
#include<map>
#include <chrono>
#include <irrArray.h>
#include "events.h"
#include "gui_ids.h"
#include "create_window.h"
#include "characater_objects.h"
#include "interaction_with_object.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;
namespace ig = irr::gui;



int main()
{
  // Le gestionnaire d'événements
  EventReceiver receiver;

  // Création de la fenêtre et du système de rendu.
  IrrlichtDevice *device = createDevice(iv::EDT_OPENGL,
                                        ic::dimension2d<u32>(640, 480),
                                        16, false, false, false, &receiver);

  iv::IVideoDriver  *driver = device->getVideoDriver();
  is::ISceneManager *smgr = device->getSceneManager();
  ig::IGUIEnvironment *gui  = device->getGUIEnvironment();


  // Ajout de l'archive qui contient entre autre un niveau complet
  device->getFileSystem()->addFileArchive("data/map-20kdm2.pk3");

  // On charge un bsp (un niveau) en particulier :
  is::IAnimatedMesh *map = smgr->getMesh("20kdm2.bsp");
  is::IMeshSceneNode *node = smgr->addOctreeSceneNode(map->getMesh(0));
  node->setPosition(core::vector3df(-1350, -130, -1400));

  // Création du triangle selector
  scene::ITriangleSelector *selector;
  selector = smgr->createOctreeTriangleSelector(node->getMesh(), node);
  node->setTriangleSelector(selector);

 //Cadenas
  is::IAnimatedMeshSceneNode *cadenas = create_cadenas(smgr, driver, ic::vector3df(145, 20, 37));

  //Questions mark
  is::IAnimatedMeshSceneNode *QMark1 = create_Qmark(smgr,driver, ic::vector3df(265, -20, -176));
  bool *visible_QMark1 = new bool; //visibilté du point d'interrogation
  *visible_QMark1 = true;
  QMark1->setVisible(visible_QMark1);

  is::IAnimatedMeshSceneNode *QMark2 = create_Qmark(smgr,driver, ic::vector3df(600, -20, -7));
  bool *visible_QMark2 = new bool;
  *visible_QMark2 = true;
  QMark2->setVisible(visible_QMark2);

  is::IAnimatedMeshSceneNode *QMark3 = create_Qmark(smgr,driver, ic::vector3df(212, -20, 11));
  bool *visible_QMark3 = new bool;
  *visible_QMark3 = true;
  QMark3->setVisible(visible_QMark3);

  is::IAnimatedMeshSceneNode *QMark4 = create_Qmark(smgr,driver, ic::vector3df(-147, -20, 70));
  bool *visible_QMark4 = new bool;
  *visible_QMark4 = true;
  QMark4->setVisible(visible_QMark4);

  is::IAnimatedMeshSceneNode *QMark5 = create_Qmark(smgr,driver, ic::vector3df(-520, -20, -1));
  bool *visible_QMark5 = new bool;
  *visible_QMark5 = true;
  QMark5->setVisible(visible_QMark5);

  is::IAnimatedMeshSceneNode *QMark6 = create_Qmark(smgr,driver, ic::vector3df(-59, -20, -116));
  bool *visible_QMark6 = new bool;
  *visible_QMark6 = true;
  QMark6->setVisible(visible_QMark6);






 //personnage
 is::IAnimatedMeshSceneNode *perso = create_perso (smgr, driver,ic::vector3df(60, -30, 0));


  receiver.node = perso;
  receiver.set_gui(gui);



  // Et l'animateur/collisionneur
  scene::ISceneNodeAnimator *anim;
  anim = smgr->createCollisionResponseAnimator(selector,
                                               perso,  // Le noeud que l'on veut gérer
                                               ic::vector3df(10, 20, 10), // "rayons" de l'objet
                                               ic::vector3df(0, -10, 0),  // gravité
                                               ic::vector3df(0, 20, 0));  // décalage du centre
  perso->addAnimator(anim);
  // Chargement des textures pour le code
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
  digits[10] = driver->getTexture("data/cross.png");
  std::vector<iv::ITexture*> digits_images;
  digits_images.push_back(digits[0]), digits_images.push_back(digits[1]),digits_images.push_back(digits[2]),digits_images.push_back(digits[3]),
   digits_images.push_back(digits[4]),digits_images.push_back(digits[5]),digits_images.push_back(digits[6]),digits_images.push_back(digits[7]),
   digits_images.push_back(digits[8]),digits_images.push_back(digits[9]);
  receiver.set_digits_images(digits_images);
  // Création des places pour les chiffres du code et du timer
  ig::IGUIImage *code_1000  = gui->addImage(ic::rect<s32>(430,10,  470,50)); code_1000->setScaleImage(true);
  ig::IGUIImage *code_100   = gui->addImage(ic::rect<s32>(470,10,  510,50)); code_100->setScaleImage(true);
  ig::IGUIImage *code_10    = gui->addImage(ic::rect<s32>(510,10, 550,50)); code_10->setScaleImage(true);
  ig::IGUIImage *code_1     = gui->addImage(ic::rect<s32>(550,10, 590,50)); code_1->setScaleImage(true);


  std::vector<ig::IGUIImage*> code_images;
  code_images.push_back(code_1000), code_images.push_back(code_100),
          code_images.push_back(code_10),code_images.push_back(code_1);
  // variables des images du codes à passer à la fonction event.cpp
  receiver.set_code_images(code_images);

  ig::IGUIImage *timer_10    = gui->addImage(ic::rect<s32>(50,10, 90,50)); timer_10->setScaleImage(true);
  ig::IGUIImage *timer_1     = gui->addImage(ic::rect<s32>(90,10, 130,50)); timer_1->setScaleImage(true);


  // variables des images du timer à passer à la fonction event.cpp
  std::vector<ig::IGUIImage*> timer_images;
  timer_images.push_back(timer_10),  timer_images.push_back(timer_10);
  receiver.set_timer_images(timer_images);

  //Initialisation de la caméra
  is::ICameraSceneNode *cam = smgr->addCameraSceneNode(perso, ic::vector3df(-60, 30, 0), ic::vector3df(0, 5, 0));
  smgr -> setActiveCamera(cam);

  // Création de notre Gui
  // Choix de la police de caractères
  ig::IGUISkin* skin = gui->getSkin();
  ig::IGUIFont* font = gui->getFont("data/fontlucida.png");
  skin->setFont(font);

  // La barre de menu
  create_menu(gui);

  // Génération du code clé (4 chiffres entre 1 et 9)
  srand(time(0));
  int code_1000_key =rand()%(10-1) +1;
  int code_100_key =rand()%(10-1) +1;
  int code_10_key =rand()%(10-1) +1;
  int code_1_key =rand()%(10-1) +1;
  std::vector<int> code;

  code.push_back(code_1_key),code.push_back(code_10_key),
  code.push_back(code_100_key),code.push_back(code_1000_key);
  receiver.set_code(code);
  std::cout<<code_1000_key<<code_100_key<<code_10_key<<code_1_key<<std::endl;


  //flag pour verifier l'affichage de la fenêtre des questions
  bool *fenetre_QMark1 = new bool,*fenetre_QMark2 = new bool,*fenetre_QMark3 = new bool,
          *fenetre_QMark4 = new bool,*fenetre_QMark5 = new bool, *fenetre_QMark6 = new bool;

      *fenetre_QMark1 = false, *fenetre_QMark2 = false,*fenetre_QMark3 = false,
      *fenetre_QMark4 = false,*fenetre_QMark5 = false,*fenetre_QMark6 = false;


  //flag pour commencer le décompte du temps
  bool *cpt_QMark1 = new bool, *cpt_QMark2 = new bool, *cpt_QMark3 = new bool,
        *cpt_QMark4 = new bool,*cpt_QMark5 = new bool,*cpt_QMark6 = new bool  ;

      *cpt_QMark1 =false,*cpt_QMark2 =false,*cpt_QMark3 =false,
      *cpt_QMark4 =false,*cpt_QMark5 =false,*cpt_QMark6 =false;


  //flag pour verifier l'affichage de la fenêtre du cadenas
  bool fenetreC = false;




  ic::array<const wchar_t* > Questions;
  ic::array<const wchar_t *> Answers_Q1,Answers_Q2,Answers_Q3,Answers_Q4,Answers_Q5,Answers_Q6;

  Questions.push_back(L"                        La mère de Lucie a 3 filles.\n"
                      "   Ses deux premières filles se nomment Marie et Anna.\n"
                      "               Comment s'appelle sa troisième fille ?");

  Questions.push_back(L"  Vous entrez dans une pièce une allumette à la main.\n"
                      "  Il fait noir et les seuls producteurs de lumière sont :\n"
                      "une bougie, une cuisinière à gaz et une lampe à pétrole.\n"
                      "                     Qu'allumez-vous en premier ?");


  Questions.push_back(L"\n                 Quel est le plus grand département\n"
                      "                         de France métropolitaine ?");

  Questions.push_back(L"            Dans une étable avec des vaches, il y a :"
                      "\n                116 oreilles, 232 pieds et 58 têtes."
                      "\n                     Combien y a-t-il de vaches ?");

  Questions.push_back(L"                                      713705"
                      "\n                    Quel est le mot qui est écrit ici ?");

  Questions.push_back(L"              A quoi équivaut la moitié de 4 plus 4 ?");

  Answers_Q1.push_back(L"Julie"),Answers_Q1.push_back(L"Sarah"),
  Answers_Q1.push_back(L"Maëva"),Answers_Q1.push_back(L"Lucie");

  Answers_Q2.push_back(L"La bougie"),Answers_Q2.push_back(L"L'allumette"),
  Answers_Q2.push_back(L"La cuisinière à gaz"),Answers_Q2.push_back(L"La lampe à pétrole");

  Answers_Q3.push_back(L"La Dordogne"),Answers_Q3.push_back(L"Paris"),
  Answers_Q3.push_back(L"La Guyane"),Answers_Q3.push_back(L"La Gironde");

  Answers_Q4.push_back(L"56"),Answers_Q4.push_back(L"232"),
  Answers_Q4.push_back(L"58"),Answers_Q4.push_back(L"116");

  Answers_Q5.push_back(L"713705"),Answers_Q5.push_back(L"Soleil"),
  Answers_Q5.push_back(L"173705"),Answers_Q5.push_back(L"La réponse D" );

  Answers_Q6.push_back(L"6"),Answers_Q6.push_back(L"2"),
  Answers_Q6.push_back(L"4"),Answers_Q6.push_back(L"3");

  // differents flags de visibilité du QMark et reponsses pour la verification de la réponse
  std::vector<bool> Fenetres_visible;
  Fenetres_visible.push_back(*fenetre_QMark1),Fenetres_visible.push_back(*fenetre_QMark2),Fenetres_visible.push_back(*fenetre_QMark3),
  Fenetres_visible.push_back(*fenetre_QMark4),Fenetres_visible.push_back(*fenetre_QMark5),Fenetres_visible.push_back(*fenetre_QMark6);
  receiver.set_Fenetres_visible(Fenetres_visible);



  std::vector<is::IAnimatedMeshSceneNode*> Qmarks;
  Qmarks.push_back(QMark1), Qmarks.push_back(QMark2),Qmarks.push_back(QMark3),
  Qmarks.push_back(QMark4), Qmarks.push_back(QMark5),Qmarks.push_back(QMark6);
  receiver.set_Qmarks(Qmarks);


  //Créations des fenêtres pour les questions
  ig::IGUIWindow *window_enigme_QMark1;
  window_enigme_QMark1 = create_window(gui,Questions[0],Answers_Q1[0],
                                        Answers_Q1[1],Answers_Q1[2],Answers_Q1[3]);
  window_enigme_QMark1->setVisible(false);

  ig::IGUIWindow *window_enigme_QMark2;
  window_enigme_QMark2 = create_window(gui,Questions[1],Answers_Q2[0],
                                        Answers_Q2[1],Answers_Q2[2],Answers_Q2[3]);
  window_enigme_QMark2->setVisible(false);

  ig::IGUIWindow *window_enigme_QMark3;
  window_enigme_QMark3 = create_window(gui,Questions[2],Answers_Q3[0],
                                        Answers_Q3[1],Answers_Q3[2],Answers_Q3[3]);
  window_enigme_QMark3->setVisible(false);

  ig::IGUIWindow *window_enigme_QMark4;
  window_enigme_QMark4 = create_window(gui,Questions[3],Answers_Q4[0],
                                        Answers_Q4[1],Answers_Q4[2],Answers_Q4[3]);
  window_enigme_QMark4->setVisible(false);

  ig::IGUIWindow *window_enigme_QMark5;
  window_enigme_QMark5 = create_window(gui,Questions[4],Answers_Q5[0],
                                          Answers_Q5[1],Answers_Q5[2],Answers_Q5[3]);
  window_enigme_QMark5->setVisible(false);

  ig::IGUIWindow *window_enigme_QMark6;
  window_enigme_QMark6 = create_window(gui,Questions[5],Answers_Q6[0],
                                        Answers_Q6[1],Answers_Q6[2],Answers_Q6[3]);
  window_enigme_QMark6->setVisible(false);

  std::vector<ig::IGUIWindow *> Windows;
  Windows.push_back(window_enigme_QMark1), Windows.push_back(window_enigme_QMark2), Windows.push_back(window_enigme_QMark3),
  Windows.push_back(window_enigme_QMark4), Windows.push_back(window_enigme_QMark5), Windows.push_back(window_enigme_QMark6);
  receiver.set_Windows(Windows);


  ig::IGUIWindow *window_cadenas;


  // Initialisation timer
  timer_10->setImage(digits[(0 / 1000) % 10]);
  timer_1->setImage(digits[(0 / 100) % 10]);

  // Initialisation du code :
  code_1000->setImage(digits[10]);
  code_100->setImage(digits[10]);
  code_10->setImage(digits[10]);
  code_1->setImage(digits[10]);



  //flags affichage de la fenêtre aprés fin du temps imparti
  bool check1 = true, check2 = true,check3 = true,
        check4 = true, check5 = true, check6 = true;


  while(device->run())
  {
    driver->beginScene(true, true, iv::SColor(100,150,200,255));


    // 

    // Mise à jour de la position de la caméra
    cam->setTarget(perso -> getPosition() + ic::vector3df(0,0,0));
    //
    //std::cout << perso->getPosition().X << "  "<<perso ->getPosition().Z<<std::endl;




    // Si perso entre dans cadenas
    if(abs(perso->getPosition().X - (cadenas->getPosition().X - 5))<=15 && abs(perso->getPosition().Z - cadenas->getPosition().Z)<=12)
    {
        // Besoin d'un offset de 5 car centre de gravité du cadenas n'est pas en son centre mais sur le côté
        if(!fenetreC)
        {
            // Une fenêtre pour différents réglages
            window_cadenas = create_window_Cadenas(gui);
            window_cadenas->setVisible(true); //Affiche la fenêtre
            fenetreC = true;
        }
    }
    // Si perso sort du cadenas et qu'il n'a pas le bon code,jeu continu
    if(abs(perso->getPosition().X - (cadenas->getPosition().X - 5))>15 && abs(perso->getPosition().Z - cadenas->getPosition().Z)>12)
    {
        if(fenetreC)
        {
            fenetreC = false;
            window_cadenas->setVisible(false);
        }
    }

    Fenetres_visible[0] = *cpt_QMark1, Fenetres_visible[1] = *cpt_QMark2, Fenetres_visible[2] = *cpt_QMark3,
    Fenetres_visible[3] = *cpt_QMark4, Fenetres_visible[4] = *cpt_QMark5, Fenetres_visible[5] = *cpt_QMark6;
    receiver.set_Fenetres_visible(Fenetres_visible);

    timer_images.push_back(timer_10),  timer_images.push_back(timer_10);
    receiver.set_timer_images(timer_images);

    //Si le temps imparti n'est pas terminé
    if (*visible_QMark1)
    {
        check1 = interaction_perso_QMark (QMark1, perso,visible_QMark1,
                                 fenetre_QMark1, cpt_QMark1,timer_10,timer_1,
                                  window_enigme_QMark1, driver);
    }


    if (*visible_QMark2)
    {
        check2 = interaction_perso_QMark (QMark2, perso,visible_QMark2,
                                 fenetre_QMark2, cpt_QMark2,timer_10,timer_1,
                                  window_enigme_QMark2, driver);
    }

    if (*visible_QMark3)
    {
        check3 = interaction_perso_QMark (QMark3, perso,visible_QMark3,
                                 fenetre_QMark3, cpt_QMark3,timer_10,timer_1,
                                  window_enigme_QMark3, driver);
    }

    if (*visible_QMark4)
    {
        check4 = interaction_perso_QMark (QMark4, perso,visible_QMark4,
                                 fenetre_QMark4, cpt_QMark4,timer_10,timer_1,
                                  window_enigme_QMark4, driver);
    }

    if (*visible_QMark5)
    {
        check5 = interaction_perso_QMark (QMark5, perso,visible_QMark5,
                                 fenetre_QMark5, cpt_QMark5,timer_10,timer_1,
                                  window_enigme_QMark5, driver);
    }

    if (*visible_QMark6)
    {
        check6 = interaction_perso_QMark (QMark6, perso,visible_QMark6,
                                 fenetre_QMark6, cpt_QMark6,timer_10,timer_1,
                                  window_enigme_QMark6, driver);
    }





    // Dessin de la scène :
    smgr->drawAll();
    // Dessin de la GUI :
    gui->drawAll();
    //

    driver->endScene();
  }
  device->drop();

  return 0;
}
