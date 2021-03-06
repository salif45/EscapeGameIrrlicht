// events.cpp

#include <irrlicht.h>
#include <iostream>
#include <stdlib.h>

#include "events.h"
#include "gui_ids.h"
#include "create_window.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;
namespace ig = irr::gui;






/**************************************************************************\
 * EventReceiver::EventReceiver                                           *
\**************************************************************************/
EventReceiver::EventReceiver()
  : code(0),code_cp(0),gui(nullptr),node(nullptr), button_pressed(false),Fenetres_visible(0),
    item1Value(0),item2Value(0),item3Value(0),item4Value(0)
{
}

/*------------------------------------------------------------------------*\
 * EventReceiver::keyboard                                                *
\*------------------------------------------------------------------------*/
bool EventReceiver::keyboard(const SEvent &event)
{
  static int isMoving = 0;

  if (event.KeyInput.PressedDown)
  {
//    if(Fenetres_visible[0] || Fenetres_visible[1] || Fenetres_visible[2] || Fenetres_visible[3] || Fenetres_visible[4] || Fenetres_visible[5])
//    {
//        ic::vector3df position = node->getPosition();
//        ic::vector3df rotation = node->getRotation();
//        node->setPosition(position);
//        node->setRotation(rotation);
//    }
//    else
//    {
        ic::vector3df position = node->getPosition();
        ic::vector3df rotation = node->getRotation();

        switch (event.KeyInput.Key)
        {
          case KEY_ESCAPE:
            exit(0);
        case KEY_UP: // Avance
          if  (position.X < -215 || position.X > 380) //coordonnés des portes dans les chambres annexes
          {
              if(position.Z > 35 || position.X < -620) //position des bords
              {
                  position.X += 0.5;  //evite de tomber dans le vide
                  position.Z += -0.5;
              }
              else if (position.Z < -150)//position des bords
              {
                  position.Z += 0.5;
              }
              else if (position.X > 727) //position des bords
              {
                  position.X += -0.5;
              }
              else
              {
                  position.X += 2 * cos(rotation.Y * M_PI / 180.0);
                  position.Z += -2 * sin(rotation.Y * M_PI / 180.0);
                  isMoving +=1;
              }
          }
          else
          {
              if (position.Z > 130) //Ne s'echappe pas par les escaliers
              {
                  position.Z += -0.5;

              }
              else if (position.Z < -260) //Ne s'echappe pas par les escaliers
              {
                  position.Z += 0.5;
              }
              else
              {
                  position.X += 2 * cos(rotation.Y * M_PI / 180.0);
                  position.Z += -2 * sin(rotation.Y * M_PI / 180.0);
                  isMoving +=1;
              }

          }
          break;
        case KEY_DOWN: // Recule
          if  (position.X < -215 || position.X > 380)//condition pour ne pas tomber dans les chambres annexes
          {
              if(position.Z > 35 || position.X < -620)
              {
                  position.X += 0.5;
                  position.Z += -0.5;
              }
              else if (position.Z < -150)
              {
                  position.Z += 0.5;
              }
              else if (position.X > 727)
              {
                  position.X += -0.5;
              }
              else
              {
                  position.X += -1 * cos(rotation.Y * M_PI / 180.0);
                  position.Z += 1 * sin(rotation.Y * M_PI / 180.0);
                  isMoving +=1;
              }
          }
          else
          {
              if (position.Z > 130)
              {
                  position.Z += -0.5;
              }
              else if (position.Z < -260)
              {
                  position.Z += 0.5;
              }
              else
              {
                  position.X += -1 * cos(rotation.Y * M_PI / 180.0);
                  position.Z += 1 * sin(rotation.Y * M_PI / 180.0);
                  isMoving +=1;
              }
          }
          break;
          case KEY_RIGHT: // Tourne à droite
            rotation.Y += 10;
            break;
          case KEY_LEFT: // Tourne à gauche
            rotation.Y -= 10;
            break;
          default:;
        }
        node->setPosition(position);
        node->setRotation(rotation);
//    }

  }
  if (!event.KeyInput.PressedDown)
      isMoving = 0;

  // Condition pour le mouvement du personnage
  if (isMoving == 0)
      node->setMD2Animation(is::EMAT_STAND);
  if (isMoving == 1)
      node->setMD2Animation(is::EMAT_RUN);

  return false;
}


/*------------------------------------------------------------------------*\
 * EventReceiver::mouse                                                   *
\*------------------------------------------------------------------------*/
bool EventReceiver::mouse(const SEvent &event)
{
  switch(event.MouseInput.Event)
  {
    case EMIE_LMOUSE_PRESSED_DOWN:
      button_pressed = true;
      old_x = event.MouseInput.X;
      old_y = event.MouseInput.Y;
      break;
    case EMIE_LMOUSE_LEFT_UP:
      button_pressed = false;
      break;
    default:
      ;
  }

  return false;
}

/*------------------------------------------------------------------------*\
 * EventReceiver::gui_handler                                             *
\*------------------------------------------------------------------------*/
bool EventReceiver::gui_handler(const SEvent &event)
{
  if (!node) return false;
  switch(event.GUIEvent.EventType)
  {
    // Gestion des menus de la barre de menu
    case ig::EGET_MENU_ITEM_SELECTED:
      {
        ig::IGUIContextMenu *menu = (ig::IGUIContextMenu*)event.GUIEvent.Caller;
        s32 item = menu->getSelectedItem();
        s32 id = menu->getItemCommandId(item);


        switch(id)
        {
          case MENU_NEW_GAME:
            // Faire quelque chose ici !
            break;
          case MENU_QUIT:
            exit(0);
          case MENU_ABOUT:
            gui->addMessageBox(L"Règles du jeu", L"Trouvez le code secret pour déverouiller le cadenas\nen résolvant les énigmes des points d'interrogation.");
            break;
        }
      }
      break;
      // gestion des boutons
    case ig::EGET_BUTTON_CLICKED:
      {
        s32 id = event.GUIEvent.Caller->getID();
        if (id == WINDOW_BUTTON_OK)

        {
            //if(code_cp[0]== item1Value)
                std::cout <<"id: "<<code_cp[0]<<"combo: "<< item1Value<< "Button clicked\n";

        }
        if (id == WINDOW_BUTTON_1)
        {
            std::cout <<"id:"<<id<< "Button clicked\n";
            if (Fenetres_visible[0])
            {
                Fenetres_visible[0] = false;

                Qmarks[0] -> setVisible(false);
                Windows[0] -> setVisible(false);


            }
            if (Fenetres_visible[1])
            {
                Fenetres_visible[1] = false;

                Qmarks[1] -> setVisible(false);
                Windows[1] -> setVisible(false);


            }
            if (Fenetres_visible[2])
            {
                Fenetres_visible[2] = false;

                Qmarks[2] -> setVisible(false);
                Windows[2] -> setVisible(false);


            }
            if (Fenetres_visible[3])
            {
                Fenetres_visible[3] = false;

                Qmarks[3] -> setVisible(false);
                Windows[3] -> setVisible(false);


            }
            if (Fenetres_visible[4])
            {
                Fenetres_visible[4] = false;

                Qmarks[4] -> setVisible(false);
                Windows[4] -> setVisible(false);


            }
            if (Fenetres_visible[5])
            {
                Fenetres_visible[5] = false;

                if (code->size() != 0)
                {
                    position_it = code_images.size() - code->size();
                    auto key = code->back();
                    code_cp.push_back(key);
                    code->pop_back();
                    code_images[position_it] -> setImage(digits_images[key]);
                }
                Qmarks[5] -> setVisible(false);
                Windows[5] -> setVisible(false);
                if (code->size()== 0)
                {
                    for (unsigned int i = 0 ; i < Qmarks.size();i++)
                    {
                        Qmarks[i] -> setVisible(false);
                        Windows[i] -> setVisible(false);
                        Fenetres_visible[i] = false;
                    }
                }

            }
        }

        if (id == WINDOW_BUTTON_2)
        {
            std::cout <<"id:"<<id<< "Button clicked\n";
            if (Fenetres_visible[0])
            {
                Fenetres_visible[0] = false;

                Qmarks[0] -> setVisible(false);
                Windows[0] -> setVisible(false);


            }
            if (Fenetres_visible[2])
            {
                Fenetres_visible[2] = false;

                Qmarks[2] -> setVisible(false);
                Windows[2] -> setVisible(false);

            }
            if (Fenetres_visible[3])
            {
                Fenetres_visible[3] = false;

                Qmarks[3] -> setVisible(false);
                Windows[3] -> setVisible(false);


            }
            if (Fenetres_visible[5])
            {
                Fenetres_visible[5] = false;

                Qmarks[5] -> setVisible(false);
                Windows[5] -> setVisible(false);


            }
            if (Fenetres_visible[1])
            {
                Fenetres_visible[1] = false;

                if (code->size() != 0)
                {
                    position_it = code_images.size() - code->size();
                    auto key = code->back();
                    code_cp.push_back(key);
                    code->pop_back();
                    code_images[position_it] -> setImage(digits_images[key]);
                }
                Qmarks[1] -> setVisible(false);
                Windows[1] -> setVisible(false);
                if (code->size()== 0)
                {
                    for (unsigned int i = 0 ; i < Qmarks.size();i++)
                    {
                        Qmarks[i] -> setVisible(false);
                        Windows[i] -> setVisible(false);
                        Fenetres_visible[i] = false;

                    }

                }



            }
            else if (Fenetres_visible[4])
            {
                Fenetres_visible[4] = false;

                if (code->size() != 0)
                {
                    position_it = code_images.size() - code->size();
                    auto key = code->back();
                    code_cp.push_back(key);
                    code->pop_back();
                    code_images[position_it] -> setImage(digits_images[key]);
                }

                Qmarks[4] -> setVisible(false);
                Windows[4] -> setVisible(false);
                if (code->size()== 0)
                {
                    for (unsigned int i = 0 ; i < Qmarks.size();i++)
                    {
                        Qmarks[i] -> setVisible(false);
                        Windows[i] -> setVisible(false);
                        Fenetres_visible[i] = false;

                    }
                }


            }


        }

        if (id == WINDOW_BUTTON_3)
        {
            if (Fenetres_visible[0])
            {
                Fenetres_visible[0] = false;

                Qmarks[0] -> setVisible(false);
                Windows[0] -> setVisible(false);


            }
            if (Fenetres_visible[1])
            {
                Fenetres_visible[1] = false;

                Qmarks[1] -> setVisible(false);
                Windows[1] -> setVisible(false);


            }
            if (Fenetres_visible[2])
            {
                Fenetres_visible[2] = false;

                Qmarks[2] -> setVisible(false);
                Windows[2] -> setVisible(false);


            }
            if (Fenetres_visible[3])
            {
                Fenetres_visible[3] = false;

                if (code->size() != 0)
                {
                    position_it = code_images.size() - code->size();
                    auto key = code->back();
                    code_cp.push_back(key);
                    code->pop_back();
                    code_images[position_it] -> setImage(digits_images[key]);
                }
                Qmarks[3] -> setVisible(false);
                Windows[3] -> setVisible(false);
                if (code->size()== 0)
                {
                    for (unsigned int i = 0 ; i < Qmarks.size();i++)
                    {
                        Qmarks[i] -> setVisible(false);
                        Windows[i] -> setVisible(false);
                        Fenetres_visible[i] = false;

                    }
                }



            }
            if (Fenetres_visible[4])
            {
                Fenetres_visible[4] = false;

                Qmarks[4] -> setVisible(false);
                Windows[4] -> setVisible(false);


            }
            if (Fenetres_visible[5])
            {
                Fenetres_visible[5] = false;

                Qmarks[5] -> setVisible(false);
                Windows[5] -> setVisible(false);


            }
        }

        if (id == WINDOW_BUTTON_4)
          {
            if (Fenetres_visible[1])
            {
                Fenetres_visible[1] = false;

                Qmarks[1] -> setVisible(false);
                Windows[1] -> setVisible(false);


            }
            if (Fenetres_visible[3])
            {
                Fenetres_visible[3] = false;

                Qmarks[3] -> setVisible(false);
                Windows[3] -> setVisible(false);


            }
            if (Fenetres_visible[4])
            {
                Fenetres_visible[4] = false;

                Qmarks[4] -> setVisible(false);
                Windows[4] -> setVisible(false);


            }
            if (Fenetres_visible[5])
            {
                Fenetres_visible[5] = false;

                Qmarks[5] -> setVisible(false);
                Windows[5] -> setVisible(false);



            }
            if (Fenetres_visible[0])
            {
                Fenetres_visible[0] = false;

                if (code->size() != 0)
                {
                    position_it = code_images.size() - code->size();
                    auto key = code->back();
                    code_cp.push_back(key);
                    code->pop_back();
                    code_images[position_it] -> setImage(digits_images[key]);
                }
                Qmarks[0] -> setVisible(false);
                Windows[0] -> setVisible(false);
                if (code->size()== 0)
                {
                    for (unsigned int i = 0 ; i < Qmarks.size();i++)
                    {
                        Qmarks[i] -> setVisible(false);
                        Windows[i] -> setVisible(false);
                        Fenetres_visible[i] = false;

                    }
                }

            }
            else if (Fenetres_visible[2])
            {
                Fenetres_visible[2] = false;

                if (code->size() != 0)
                {
                    position_it = code_images.size() - code->size();
                    auto key = code->back();
                    code_cp.push_back(key);
                    code->pop_back();
                    code_images[position_it] -> setImage(digits_images[key]);
                }

                Qmarks[2] -> setVisible(false);
                Windows[2] -> setVisible(false);
                if (code->size()== 0)
                {
                    for (unsigned int i = 0 ; i < Qmarks.size();i++)
                    {
                        Qmarks[i] -> setVisible(false);
                        Windows[i] -> setVisible(false);
                        Fenetres_visible[i] = false;

                    }
                }

            }
          }

      }
      break;
      // gestion des combo-box
    case ig::EGET_COMBO_BOX_CHANGED:
      {
        s32 id = event.GUIEvent.Caller->getID();
        if (id == WINDOW_COMBO_BOX_1)
        {
          ig::IGUIComboBox *cbox = (ig::IGUIComboBox*)event.GUIEvent.Caller;
          s32 item_box_1 = cbox->getSelected();
          item1Value = item_box_1;
          u32 elem_id = cbox->getItemData(item_box_1);
          std::cout << "Combo box changed: item " << item_box_1 << ", id " << elem_id << std::endl;
        }
        if (id == WINDOW_COMBO_BOX_2)
        {
          ig::IGUIComboBox *cbox = (ig::IGUIComboBox*)event.GUIEvent.Caller;
          s32 item_box2 = cbox->getSelected();
          u32 elem_id = cbox->getItemData(item_box2);
          std::cout << "Combo box changed: item " << item_box2 << ", id " << elem_id << std::endl;
        }
        if (id == WINDOW_COMBO_BOX_3)
        {
          ig::IGUIComboBox *cbox = (ig::IGUIComboBox*)event.GUIEvent.Caller;
          s32 item_box3 = cbox->getSelected();
          u32 elem_id = cbox->getItemData(item_box3);
          std::cout << "Combo box changed: item " << item_box3 << ", id " << elem_id << std::endl;
        }
        if (id == WINDOW_COMBO_BOX_4)
        {
          ig::IGUIComboBox *cbox = (ig::IGUIComboBox*)event.GUIEvent.Caller;
          s32 item_box4 = cbox->getSelected();
          u32 elem_id = cbox->getItemData(item_box4);
          std::cout << "Combo box changed: item " << item_box4 << ", id " << elem_id << std::endl;
        }
      }
      break;
    default:;
  }
  return false;
}

/**************************************************************************\
 * EventReceiver::OnEvent                                                 *
\**************************************************************************/
bool EventReceiver::OnEvent(const SEvent &event)
{
  if (!node) return false;
  switch (event.EventType)
  {
    case EET_KEY_INPUT_EVENT:
      return keyboard(event);
    case EET_MOUSE_INPUT_EVENT:
      return mouse(event);
  case EET_GUI_EVENT:
    return gui_handler(event);
    default:;
  }

  return false;
}

/**************************************************************************\
 * EventReceiver::set_node                                                *
\**************************************************************************/
//void EventReceiver::set_node(irr::scene::IAnimatedMeshSceneNode *node)
//{
//  node = n;
//}

/**************************************************************************\
 * EventReceiver::set_gui                                                 *
\**************************************************************************/
void EventReceiver::set_gui(irr::gui::IGUIEnvironment *g)
{
  gui = g;
}

/**************************************************************************\
 * EventReceiver::set_code                                               *
\**************************************************************************/
void EventReceiver::set_code(  std::vector<int> *c)
{
  code = c ;
}


/**************************************************************************\
 * EventReceiver::set_Fenetres                                             *
\**************************************************************************/
void EventReceiver::set_Fenetres_visible(std::vector<bool> F)
{
  Fenetres_visible = F;
}

/**************************************************************************\
 * EventReceiver::set_Qmarks                                             *
\**************************************************************************/
void EventReceiver::set_Qmarks(std::vector<irr::scene::IAnimatedMeshSceneNode*> &Q)
{
  Qmarks = Q ;
}

/**************************************************************************\
 * EventReceiver::set_Windows                                            *
\**************************************************************************/
void EventReceiver::set_Windows(std::vector<irr::gui::IGUIWindow*> &W)
{
  Windows = W ;
}

/**************************************************************************\
 * EventReceiver::set_code_images                                          *
\**************************************************************************/
void EventReceiver::set_code_images(std::vector<irr::gui::IGUIImage*> &CI)
{
  code_images = CI ;
}


/**************************************************************************\
 * EventReceiver::set_digit_images                                            *
\**************************************************************************/
void EventReceiver::set_digits_images(std::vector<irr::video::ITexture*> &DI)
{
  digits_images = DI ;
}

