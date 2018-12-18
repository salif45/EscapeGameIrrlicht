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
  std::vector<int> code;
  std::vector<bool> Fenetres_visible;
  std::vector<irr::scene::IAnimatedMeshSceneNode*> Qmarks;
  std::vector<irr::gui::IGUIWindow*> Windows;
  std::vector<irr::gui::IGUIImage*> code_images;
  std::vector<irr::gui::IGUIImage*> timer_images;
  std::vector<irr::video::ITexture*> digits_images;
  bool button_pressed;
  int  old_x, old_y;
  std::vector<irr::video::ITexture*> textures;
  int current_texture;
  int *item_box;
  int *position_it; //position iterrateur dans code_images



  bool keyboard(const irr::SEvent &event);
  bool mouse(const irr::SEvent &event);
  bool gui_handler(const irr::SEvent &event);
public:
  EventReceiver();
  bool OnEvent(const irr::SEvent &event);
  void set_gui(irr::gui::IGUIEnvironment *gui);
  void set_code(std::vector<int> c);
  void set_Fenetres_visible(std::vector<bool> F);
  void set_Qmarks(std::vector<irr::scene::IAnimatedMeshSceneNode*> Q);
  void set_Windows(std::vector<irr::gui::IGUIWindow*> W);
  void set_code_images(std::vector<irr::gui::IGUIImage*> CI);
  void set_timer_images(std::vector<irr::gui::IGUIImage*> TI);
  void set_digits_images(std::vector<irr::video::ITexture*> DI);

//  void set_node(irr::scene::IAnimatedMeshSceneNode *node);
  void set_textures(const std::vector<irr::video::ITexture *> &tex){textures=tex;}
};

#endif
