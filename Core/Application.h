#pragma once
#include "Include.h"
#include "MenuPanel.h"
#include "ViewPanel.h"

namespace CellularNetworkDemonstration {

    const static char* ApplaicationName = "Cellular Network Demo";

    class Application {
    public:
        Application();
        ~Application();

        // �����ʼ��
        bool init() {
            // ��ʼ������
            SDL_log("��ʼ������...");
            if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
                return false;
            }


            // ��ʼ�� TTF ��
            if (TTF_Init() != 0) {
                return false;
            }

            // ��������
            SDL_log("��������");
            m_pWindow = SDL_CreateWindow(ApplaicationName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                800, 600, SDL_WINDOW_BORDERLESS);
            if (m_pWindow == nullptr) {
                return false;
            }

            // ������Ⱦ��
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            SDL_SetRenderDrawBlendMode(m_pRenderer, SDL_BLENDMODE_BLEND);
            if (m_pRenderer == nullptr) {
                return false;
            }
            // ������Ⱦ����ɫ
            SDL_SetRenderDrawColor(m_pRenderer, 210, 210, 210, 255);


            SDL_log("��ʼ�����...");
            // ��ʼ���˵�����
            m_pMenuPanel = new MenuPanel(m_pRenderer);
            m_pMenuPanelRect = new SDL_Rect();
            m_pMenuPanelRect->x = 0;
            m_pMenuPanelRect->y = 0;
            m_pMenuPanelRect->w = 800;
            m_pMenuPanelRect->h = 150;

            // ��ʼ����ͼ����
            m_pViewPanel = new ViewPanel(m_pRenderer);
            m_pViewPanelRect = new SDL_Rect();
            m_pViewPanelRect->x = 0;
            m_pViewPanelRect->y = 150;
            m_pViewPanelRect->w = 800;
            m_pViewPanelRect->h = 450;

            SDL_log("��ʼ�����");
            m_bRunning = true;
            return true;
        }

        // ��Ⱦ����
        void render() {
            if (m_bMinimized) {
                return;
            }
            static long last;
            static long now;
            now = SDL_GetTicks();
            // SDL_Delay(20);
            if (now - last > 1000 / 60) {
                if (now - last > 100) {
                    SDL_log("Low Performance!!!");
                    SDL_log(now - last);
                }
                last = now;

                // ��Ⱦ��Ԫ�ص���ͼ
                SDL_Texture* pMenuPanel = m_pMenuPanel->render();
                SDL_Texture* pViewPanel = m_pViewPanel->render();

                // ��Ⱦ�������ͼ
                SDL_RenderClear(m_pRenderer);
                SDL_RenderCopy(m_pRenderer, pMenuPanel, m_pMenuPanel->Rect(), m_pMenuPanelRect);
                SDL_RenderCopy(m_pRenderer, pViewPanel, m_pViewPanel->Rect(), m_pViewPanelRect);
                SDL_RenderPresent(m_pRenderer);
            }

        }

        // ��������
        void update() {
            if (m_bMinimized) {
                return;
            }
            //log("Update Application");
            // Handle Mouse Pointer
            SDL_Point point = MouseManager::get().getPoint();
            if (SDL_PointInRect(point, *m_pMenuPanelRect)) {
                // Hit Menu Panel
                m_pMenuPanel->update(SDL_RelationPoint(&point, m_pMenuPanelRect));
            } else {
                m_pMenuPanel->update();
            }

            if (SDL_PointInRect(point, *m_pViewPanelRect)) {
                // Hit Main View
            } else {

            }
            m_pViewPanel->setViewCode(m_pMenuPanel->getViewCode());
        }

        // �����¼�
        void handleEvents() {
            //log("�����¼�...");
            SDL_Event event;
            if (minimized()) {
                SDL_WaitEvent(nullptr);
            }
            if (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        // �����˳��¼�
                        m_bRunning = false;
                        break;
                    case SDL_USEREVENT:
                        if (event.user.code == SDL_MINIMIZE) {
                        SDL_log("��С������");
                            m_bMinimized = true;
                            SDL_MinimizeWindow(m_pWindow);
                        }
                        if (event.user.code & SDL_CHANGEVIEW) {
                            // Use bitwise operation to set catalog
                            m_pMenuPanel->setViewCode(event.user.code);
                        }
                        break;
                    case SDL_MOUSEBUTTONUP:
                        // ��갴���ͷ��¼�
                        MouseManager::get().OnMouseButtonUp(event);
                        break;
                    case SDL_WINDOWEVENT:
                        switch (event.window.event) {
                            case SDL_WINDOWEVENT_RESTORED:
                                SDL_log("�ָ�����");
                                if (m_bMinimized) {
                                    SDL_RestoreWindow(m_pWindow);
                                    m_bMinimized = false;
                                }
                                break;


                            default:
                                break;
                        }
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        // ��갴�������¼�
                        MouseManager::get().OnMouseButtonDown(event);
                        break;
                    case SDL_MOUSEMOTION:
                        // ����ƶ��¼�
                        MouseManager::get().OnMouseMotion(event);
                        break;
                    case SDL_MOUSEWHEEL:
                        // �������¼�
                        MouseManager::get().OnMouseWheel(event);
                    default:
                        break;
                }
            }
        }

        // �������ʱ������
        void clean() {
            delete  m_pMenuPanel;
            delete m_pMenuPanelRect;
            delete m_pViewPanel;
            delete m_pViewPanelRect;

            SDL_DestroyWindow(m_pWindow);
            SDL_DestroyRenderer(m_pRenderer);
            TTF_Quit();
            SDL_Quit();
        }

        inline bool running() const {
            return m_bRunning;
        }
        inline bool minimized() const {
            return m_bMinimized;
        }
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