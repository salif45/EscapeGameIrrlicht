// events.h

#ifndef EVENTS_H
#define EVENTS_H

#include <vector>

#include <irrlicht.h>



struct EventReceiver : public irr::IEventReceiver
{
  irr::gui::IGUIEnvironment *gui;
  irr::scene::IAnimatedMeshSceneNode *node;
  //int *code;
  std::vector<int> code;
  std::vector<bool> Qmarks_visible;
  std::vector<const wchar_t*> Answers;
  bool button_pressed;
  int  old_x, old_y;
  std::vector<irr::video::ITexture*> textures;
  int current_texture;
  int *item_box;

  bool keyboard(const irr::SEvent &event);
  bool mouse(const irr::SEvent &event);
  bool gui_handler(const irr::SEvent &event);
public:
  EventReceiver();
  bool OnEvent(const irr::SEvent &event);
  void set_gui(irr::gui::IGUIEnvironment *gui);
  void set_code(std::vector<int> c);
  void set_Qmarks_visible(std::vector<bool> Q);
  void set_Answers(std::vector<const wchar_t*> A);
//  void set_node(irr::scene::IAnimatedMeshSceneNode *node);
  void set_textures(const std::vector<irr::video::ITexture *> &tex){textures=tex;}
};

#endif
