#include "Model.h"
#include <windows.h>

void Model::DrawModel() {
    tLoad.Bind(tex);
    glTranslatef(transform.position.x(), transform.position.y(), transform.position.z());
    glRotatef(transform.rotation.x(), 1, 0, 0);
    glRotatef(transform.rotation.y(), 0, 1, 0);
    glRotatef(transform.rotation.z(), 0, 0, 1);

    glutSolidTeapot(transform.scale.y());


    /*Vector3 spoonPosition = transform.position + Vector3::up() * 2;

    glRotatef(-transform.rotation.x(), 1, 0, 0);
    glRotatef(transform.rotation.y(), 0, 1, 0);
    glRotatef(-transform.rotation.z(), 0, 0, 1);
    glTranslatef(spoonPosition.x(), spoonPosition.y(), spoonPosition.z());

    glutSolidTeaspoon(transform.scale.y());*/
}

void Model::Update() {
    using namespace InputSystem;
    if (Inputs::GetKeyDown(VK_UP))
        transform.rotation -= Vector3::right() * 90;

    if (Inputs::GetKeyDown(VK_DOWN))
        transform.rotation += Vector3::right() * 90;

    if (Inputs::GetKeyDown(VK_LEFT))
        transform.rotation -= Vector3::up() * 90;

    if (Inputs::GetKeyDown(VK_RIGHT))
        transform.rotation += Vector3::up() * 90;

        Vector2 mouse = Inputs::GetMousePosition();
        transform.position = Vector3(mouse.x() / 100, -mouse.y() / 100, transform.position.z());
    

    if (Inputs::GetKeyDown(0x53))//S
        transform.position = Vector3::zero();

    //if (Inputs::GetKeyDown(0x57))//W
    //    transform.position.Set(transform.position.x(), transform.position.y() + 1, transform.position.z());

    //if (Inputs::GetKeyDown(0x53))//S
    //    transform.position.Set(transform.position.x(), transform.position.y() - 1, transform.position.z());

    //if (Inputs::GetKeyDown(0x41))//A
    //    transform.position.Set(transform.position.x() - 1, transform.position.y(), transform.position.z());

    //if (Inputs::GetKeyDown(0x44))//D
    //    transform.position.Set(transform.position.x() + 1, transform.position.y(), transform.position.z());

    if (Inputs::GetKeyDown(VK_OEM_PLUS))
        transform.position.Set(transform.position.x(), transform.position.y(), transform.position.z() + 1);

    if (Inputs::GetKeyDown(VK_OEM_MINUS))
        transform.position.Set(transform.position.x(), transform.position.y(), transform.position.z() - 1);

    if (InputSystem::Inputs::GetKeyDown(VK_F1)) {
        ApplicationManager::TryToggleFullScreen();
    }
}

void Model::Initialize() {
    tLoad.Load((char*)"Googleplex.jpg", tex);
}
