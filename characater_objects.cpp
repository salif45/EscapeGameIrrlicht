#include "characater_objects.h"


is::IAnimatedMeshSceneNode *create_cadenas(is::ISceneManager *smgr, iv::IVideoDriver  *driver, ic::vector3df pos)
{
    //Cadenas
    is::IAnimatedMesh *meshCadenas = smgr->getMesh("data/padlock.obj");
    is::IAnimatedMeshSceneNode *cadenas = smgr->addAnimatedMeshSceneNode(meshCadenas);
    cadenas->setMaterialFlag(iv::EMF_LIGHTING, false);
    cadenas->setMD2Animation(is::EMAT_STAND);
    cadenas->setMaterialTexture(0, driver->getTexture("data/yellow_padlock.png"));
    cadenas->setScale(ic::vector3df(15,15,15));
    cadenas->setPosition(pos);
    is::ISceneNodeAnimator *anim_cadenas =
              smgr->createFlyStraightAnimator(ic::vector3df(75,-20,-50),
                                              ic::vector3df(75,-15,-50), 2500, true,true);
    cadenas->addAnimator(anim_cadenas);
    return cadenas;
}

is::IAnimatedMeshSceneNode *create_Qmark(is::ISceneManager *smgr, iv::IVideoDriver  *driver, ic::vector3df pos)
{
    //Point d'interrogation 1
    is::IAnimatedMesh *meshQMark1 = smgr->getMesh("data/QMark.obj");
    is::IAnimatedMeshSceneNode *QMark = smgr->addAnimatedMeshSceneNode(meshQMark1);
    QMark->setMaterialFlag(iv::EMF_LIGHTING, false);
    QMark->setMD2Animation(is::EMAT_STAND);
    QMark->setMaterialTexture(0, driver->getTexture("data/red_QMark.png"));
    QMark->setScale(ic::vector3df(50,50,50));
    QMark->setPosition(pos);
    QMark->setRotation(ic::vector3df(0,-150,0));
    is::ISceneNodeAnimator *anim_QMark =
              smgr->createRotationAnimator(ic::vector3df(0,1,0));
    QMark->addAnimator(anim_QMark);

    return QMark;
}


is::IAnimatedMeshSceneNode *create_perso (is::ISceneManager *smgr, iv::IVideoDriver  *driver,ic::vector3df pos)
{
    // Chargement de notre personnage
    is::IAnimatedMesh *mesh = smgr->getMesh("data/tris.md2");
    // Attachement de notre personnage dans la scène
    is::IAnimatedMeshSceneNode *perso = smgr->addAnimatedMeshSceneNode(mesh);
    perso->setMaterialFlag(iv::EMF_LIGHTING, false);
    perso->setMD2Animation(is::EMAT_STAND);
    perso->setMaterialTexture(0, driver->getTexture("data/blue_texture.pcx"));
    perso->setPosition(pos); //ic::vector3df(60, -30, 0)
    perso->setRotation(ic::vector3df(0,90,0));

    return perso;
}


