#ifndef CHARACATER_OBJECTS_H
#define CHARACATER_OBJECTS_H


#include <irrlicht.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "events.h"
#include "gui_ids.h"
#include "create_window.h"

using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;
namespace ig = irr::gui;



is::IAnimatedMeshSceneNode *create_cadenas(is::ISceneManager *smgr, iv::IVideoDriver  *driver, ic::vector3df pos);

is::IAnimatedMeshSceneNode *create_Qmark(is::ISceneManager *smgr, iv::IVideoDriver  *driver, ic::vector3df pos);

is::IAnimatedMeshSceneNode *create_perso (is::ISceneManager *smgr, iv::IVideoDriver  *driver,ic::vector3df pos);

#endif // CHARACATER_OBJECTS_H
