#define DEBUG

#include <SDL.h>
#include "Application.h"
using namespace CellularNetworkDemonstration;

static Application* app = nullptr;

int main(int argc, char* args []) {
    // ��ʼ���������ʵ��
    app = new Application();
    if (!app->init()) {
        SDL_log("�����ʼ��ʧ�ܣ��볢���������С�");
    }
        
    // �����¼���ͼѭ��
    while (app->running()) {
        app->handleEvents();
        app->update();
        app->render();
    }

    // �����Ƴ�����
    app->clean();
    return 0;
}
