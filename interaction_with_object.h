#ifndef INTERACTION_WITH_OBJECT_H
#define INTERACTION_WITH_OBJECT_H

#include <irrlicht.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "events.h"
#include "gui_ids.h"
#include "create_window.h"
#include <ctime>
#include <chrono>

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;
namespace ig = irr::gui;




/*******************************************
 *
 * Interaction entre personnage et les points d'interrogation
 * *****************************************/
bool interaction_perso_QMark (is::IAnimatedMeshSceneNode *QMark,  is::IAnimatedMeshSceneNode *perso, bool *visible,
                              bool *fenetre, bool *cpt,ig::IGUIImage *timer_10,
                                                                ig::IGUIImage *timer_1,
                              ig::IGUIWindow *window_enigme,iv::IVideoDriver  *driver);




#endif // INTERACTION_WITH_OBJECT_H
