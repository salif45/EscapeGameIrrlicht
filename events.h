// events.h

#ifndef EVENTS_H
#define EVENTS_H

#include <vector>

#include <irrlicht.h>
//using namespace irr;

//namespace ic = irr::core;
//namespace is = irr::scene;
//namespace iv = irr::video;
//namespace ig = irr::gui;



struct EventReceiver : public irr::IEventReceiver
{
  irr::gui::IGUIEnvironment *gui;
  irr::scene::IAnimatedMeshSceneNode *node;
  //int *code;
  std::vector<int> *code;
  std::vector<int> code_cp;
  std::vector<bool> Fenetres_visible;
  std::vector<irr::scene::IAnimatedMeshSceneNode*> Qmarks;
  std::vector<irr::gui::IGUIWindow*> Windows;
  std::vector<irr::gui::IGUIImage*> code_images;
  std::vector<irr::video::ITexture*> digits_images;
  bool button_pressed;
  int  old_x, old_y;
  int  item1Value;
  int  item2Value;
  int  item3Value;
  int  item4Value;
  int position_it; //position iterrateur dans code_images



  bool keyboard(const irr::SEvent &event);
  bool mouse(const irr::SEvent &event);
  bool gui_handler(const irr::SEvent &event);
public:
  EventReceiver();
  bool OnEvent(const irr::SEvent &event);
  void set_gui(irr::gui::IGUIEnvironment *gui);
  void set_code(std::vector<int> *c);
  void set_code_copy(std::vector<int> *cp);
  void set_Fenetres_visible(std::vector<bool> F);
  void set_Qmarks(std::vector<irr::scene::IAnimatedMeshSceneNode*> &Q);
  void set_Windows(std::vector<irr::gui::IGUIWindow*> &W);
  void set_code_images(std::vector<irr::gui::IGUIImage*> &CI);
  void set_digits_images(std::vector<irr::video::ITexture*> &DI);

//  void set_node(irr::scene::IAnimatedMeshSceneNode *node);

};

#endif
