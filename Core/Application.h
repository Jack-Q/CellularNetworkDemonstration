#pragma once
#include "Include.h"
#include "MenuPanel.h"
#include "ViewPanel.h"

namespace CellularNetworkDemonstration {

    const static char* ApplaicationName = "Cellular Network Demonstration";

    class Application {
    public:
        Application();
        ~Application();

        // �����ʼ��
        bool init();

        // ��Ⱦ����
        void render();

        // ��������
        void update();

        // �����¼�
        void handleEvents();

        // �������ʱ������
        void clean();

        bool running() const;
        bool minimized() const;
    private:
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
        bool m_bRunning;
        bool m_bMinimized;

        MenuPanel* m_pMenuPanel;
        SDL_Rect* m_pMenuPanelRect;
        ViewPanel* m_pViewPanel;
        SDL_Rect* m_pViewPanelRect;
    };
}