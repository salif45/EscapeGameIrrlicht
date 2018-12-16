// create_window.cpp

#include <irrlicht.h>
#include <irrMap.h>
#include <irrList.h>

#include "create_window.h"


using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;
namespace ig = irr::gui;

/*===========================================================================*\
 * create_window                                                             *
\*===========================================================================*/
ig::IGUIWindow * create_window(ig::IGUIEnvironment *gui,const wchar_t *Question,
                               const wchar_t *Answers_1, const wchar_t *Answers_2,
                               const wchar_t *Answers_3,const wchar_t *Answers_4) //ajouter parametres pour texte et reponses
{
  // La fenêtre
  ig::IGUIWindow *window = gui->addWindow(ic::rect<s32>(80,50, 560,360), true,L"Questions"); //(420,25, 620,460)

  // Question

  gui->addStaticText(Question, ic::rect<s32>(22,48, 560,460), false, false, window);//(22,48, 65,66)
  // Réponses
  gui->addButton(ic::rect<s32>(70,100, 170,150), window, WINDOW_BUTTON_1, Answers_1); //(40,74, 140,92)
  gui->addButton(ic::rect<s32>(300,100, 400,150), window, WINDOW_BUTTON_2, Answers_2);
  gui->addButton(ic::rect<s32>(70,200, 170,250), window, WINDOW_BUTTON_3, Answers_3);
  gui->addButton(ic::rect<s32>(300,200, 400,250), window, WINDOW_BUTTON_4, Answers_4);

  window->setVisible(false);

  return window;
}

/*===========================================================================*\
 * create_menu                                                               *
\*===========================================================================*/
void create_menu(ig::IGUIEnvironment *gui)
{
  ig::IGUIContextMenu *submenu;

  // Les trois entrées principales :
  ig::IGUIContextMenu *menu = gui->addMenu();
  menu->addItem(L"File", -1, true, true);
  menu->addItem(L"Help", -1, true, true);

  // Le contenu du menu File :
  submenu = menu->getSubMenu(0);
  submenu->addItem(L"New game...", MENU_NEW_GAME);
  submenu->addSeparator();
  submenu->addItem(L"Quit", MENU_QUIT);

  // Le contenu du menu Help :
  submenu = menu->getSubMenu(1);
  submenu->addItem(L"Règles du jeu", MENU_ABOUT);
}

/*===========================================================================*\
 * create_window                                                             *
\*===========================================================================*/
// static indique que le fonction n'est visible que par ce .cpp
ig::IGUIWindow * create_window_not_leaving(ig::IGUIEnvironment *gui) //ajouter parametres pour texte et reponses
{
  // La fenêtre
  ig::IGUIWindow *window = gui->addWindow(ic::rect<s32>(80,50, 560,360), true, L"MESSAGE"); //(420,25, 620,460)

  // Texte
  gui->addStaticText(L"Please enter the code first", ic::rect<s32>(200,48, 560,460), false, false, window);//(22,48, 65,66)


  window->setVisible(false);

  return window;
}
ig::IGUIWindow * create_window_Cadenas(ig::IGUIEnvironment *gui)
{
  // La fenêtre
  ig::IGUIWindow *window = gui->addWindow(ic::rect<s32>(80,50, 560,360), true, L"Déverouille le cadenas"); //(420,25, 620,460)

  // Question
  // Texte
  gui->addStaticText(L"Quel est le code?", ic::rect<s32>(190,48, 560,460), false, false, window);//(22,48, 65,66)
  // Réponses
  // boites combo (listes déroulantes)
  ig::IGUIComboBox *cbox_1000 = gui->addComboBox(ic::rect<s32>(100,126, 150,142), window, WINDOW_COMBO_BOX_1);
  cbox_1000->addItem(L"0", WINDOW_COMBO_CHOICE_0);
  cbox_1000->addItem(L"1", WINDOW_COMBO_CHOICE_1);
  cbox_1000->addItem(L"2", WINDOW_COMBO_CHOICE_2);
  cbox_1000->addItem(L"3", WINDOW_COMBO_CHOICE_3);
  cbox_1000->addItem(L"4", WINDOW_COMBO_CHOICE_4);
  cbox_1000->addItem(L"5", WINDOW_COMBO_CHOICE_5);
  cbox_1000->addItem(L"6", WINDOW_COMBO_CHOICE_6);
  cbox_1000->addItem(L"7", WINDOW_COMBO_CHOICE_7);
  cbox_1000->addItem(L"8", WINDOW_COMBO_CHOICE_8);
  cbox_1000->addItem(L"9", WINDOW_COMBO_CHOICE_9);
  ig::IGUIComboBox *cbox_100 = gui->addComboBox(ic::rect<s32>(180,126, 230,142), window, WINDOW_COMBO_BOX_2);
  cbox_100->addItem(L"0", WINDOW_COMBO_CHOICE_0);
  cbox_100->addItem(L"1", WINDOW_COMBO_CHOICE_1);
  cbox_100->addItem(L"2", WINDOW_COMBO_CHOICE_2);
  cbox_100->addItem(L"3", WINDOW_COMBO_CHOICE_3);
  cbox_100->addItem(L"4", WINDOW_COMBO_CHOICE_4);
  cbox_100->addItem(L"5", WINDOW_COMBO_CHOICE_5);
  cbox_100->addItem(L"6", WINDOW_COMBO_CHOICE_6);
  cbox_100->addItem(L"7", WINDOW_COMBO_CHOICE_7);
  cbox_100->addItem(L"8", WINDOW_COMBO_CHOICE_8);
  cbox_100->addItem(L"9", WINDOW_COMBO_CHOICE_9);
  ig::IGUIComboBox *cbox_10 = gui->addComboBox(ic::rect<s32>(260,126, 310,142), window, WINDOW_COMBO_BOX_3);
  cbox_10->addItem(L"0", WINDOW_COMBO_CHOICE_0);
  cbox_10->addItem(L"1", WINDOW_COMBO_CHOICE_1);
  cbox_10->addItem(L"2", WINDOW_COMBO_CHOICE_2);
  cbox_10->addItem(L"3", WINDOW_COMBO_CHOICE_3);
  cbox_10->addItem(L"4", WINDOW_COMBO_CHOICE_4);
  cbox_10->addItem(L"5", WINDOW_COMBO_CHOICE_5);
  cbox_10->addItem(L"6", WINDOW_COMBO_CHOICE_6);
  cbox_10->addItem(L"7", WINDOW_COMBO_CHOICE_7);
  cbox_10->addItem(L"8", WINDOW_COMBO_CHOICE_8);
  cbox_10->addItem(L"9", WINDOW_COMBO_CHOICE_9);
  ig::IGUIComboBox *cbox_1 = gui->addComboBox(ic::rect<s32>(340,126, 390,142), window, WINDOW_COMBO_BOX_4);
  cbox_1->addItem(L"0", WINDOW_COMBO_CHOICE_0);
  cbox_1->addItem(L"1", WINDOW_COMBO_CHOICE_1);
  cbox_1->addItem(L"2", WINDOW_COMBO_CHOICE_2);
  cbox_1->addItem(L"3", WINDOW_COMBO_CHOICE_3);
  cbox_1->addItem(L"4", WINDOW_COMBO_CHOICE_4);
  cbox_1->addItem(L"5", WINDOW_COMBO_CHOICE_5);
  cbox_1->addItem(L"6", WINDOW_COMBO_CHOICE_6);
  cbox_1->addItem(L"7", WINDOW_COMBO_CHOICE_7);
  cbox_1->addItem(L"8", WINDOW_COMBO_CHOICE_8);
  cbox_1->addItem(L"9", WINDOW_COMBO_CHOICE_9);
  gui->addButton(ic::rect<s32>(200,200, 280,230), window, WINDOW_BUTTON_OK, L"OK");

  window->setVisible(false);

  return window;
}
