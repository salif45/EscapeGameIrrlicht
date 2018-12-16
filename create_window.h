// create_window.h

#ifndef CREATE_WINDOW_H
#define CREATE_WINDOW_H

#include <irrlicht.h>
#include <string>
#include<map>
#include <vector>
#include "gui_ids.h"
using namespace irr;

namespace ic = irr::core;
namespace is = irr::scene;
namespace iv = irr::video;
namespace ig = irr::gui;

ig::IGUIWindow * create_window(ig::IGUIEnvironment *gui,const wchar_t *Question,
                               const wchar_t *Answers_1, const wchar_t *Answers_2,
                               const wchar_t *Answers_3,const wchar_t *Answers_4);

ig::IGUIWindow * create_window_Cadenas(ig::IGUIEnvironment *gui);

ig::IGUIWindow * create_window_not_leaving(ig::IGUIEnvironment *gui);

void create_menu(ig::IGUIEnvironment *gui);

#endif
