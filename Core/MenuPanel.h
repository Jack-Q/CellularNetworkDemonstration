#pragma once
#include "Include.h"
#include "UIBase.h"
#include "MenuSystemClose.h"
#include "MenuSystemMinimize.h"
namespace CellularNetworkDemonstration {

    class MenuPanel :public UIBase {
    public:
        MenuPanel(SDL_Renderer *renderer)
            :UIBase(renderer, 800, 150) {
            // ������Դ
            m_pMenuImage = IMG_LoadTexture(m_pRenderer,"menubar.png");

            //��ʼ����Ԫ��
            m_pMenuSystemClose = new MenuSystemClose(m_pRenderer);
            m_pMenuSystemCloseRect = new SDL_Rect();
            m_pMenuSystemCloseRect->x = getWidth() - 50;
            m_pMenuSystemCloseRect->y = 0;
            m_pMenuSystemCloseRect->w = 45;
            m_pMenuSystemCloseRect->h = 20;
            m_pMenuSystemMinimize = new MenuSystemMinimize(m_pRenderer);
            m_pMenuSystemMinimizeRect = new SDL_Rect();
            m_pMenuSystemMinimizeRect->x = getWidth() - 100;
            m_pMenuSystemMinimizeRect->y = 0;
            m_pMenuSystemMinimizeRect->w = 45;
            m_pMenuSystemMinimizeRect->h = 20;

        }

        ~MenuPanel() {
            // ������Ԫ�غ���Դ

            DELETE_IF_EXIST(m_pMenuSystemMinimize)
            DELETE_IF_EXIST(m_pMenuSystemClose)
            DELETE_IF_EXIST(m_pMenuSystemMinimizeRect)
            DELETE_IF_EXIST(m_pMenuSystemCloseRect)
            if (m_pMenuImage)
            {
                SDL_DestroyTexture(m_pMenuImage);
            }
        }


        int getViewIndex()const {
            return m_iViewIndex;
        }
    private:
        // ����
        int m_iViewIndex;

        // ��Դ
        SDL_Texture *m_pMenuImage;

        // ��Ԫ��
        MenuSystemClose *m_pMenuSystemClose;
        SDL_Rect *m_pMenuSystemCloseRect;

        MenuSystemMinimize *m_pMenuSystemMinimize;
        SDL_Rect *m_pMenuSystemMinimizeRect;

        // ���ƽ���Ԫ��
        virtual void doRender() {
            //m_pMenuSystemCloseRect->x = m_sMousePosition.x - m_pMenuSystemCloseRect->w/2;
            //m_pMenuSystemCloseRect->y = m_sMousePosition.y - m_pMenuSystemCloseRect->h / 2;

            SDL_SetRenderDrawColor(m_pRenderer, 20, 120, 220, 255);
            SDL_RenderClear(m_pRenderer);
            SDL_RenderCopy(m_pRenderer, m_pMenuImage, nullptr, nullptr);
            SDL_Texture *closeTexture = m_pMenuSystemClose->render();
            SDL_Texture *minimizeTexture = m_pMenuSystemMinimize->render();
            SDL_RenderCopy(m_pRenderer, closeTexture, m_pMenuSystemClose->Rect(), m_pMenuSystemCloseRect);
            SDL_RenderCopy(m_pRenderer, minimizeTexture, m_pMenuSystemMinimize->Rect(), m_pMenuSystemMinimizeRect);
        }

        virtual void doUpdate() {
            if (SDL_PointInRect(m_sMousePosition, *m_pMenuSystemCloseRect)) {
                m_pMenuSystemClose->update(SDL_RelationPoint(&m_sMousePosition, m_pMenuSystemCloseRect));
            } else {
                m_pMenuSystemClose->update(SDL_Point{ -1, -1 });
            }


            if (SDL_PointInRect(m_sMousePosition, *m_pMenuSystemMinimizeRect)) {
                m_pMenuSystemMinimize->update(SDL_RelationPoint(&m_sMousePosition, m_pMenuSystemMinimizeRect));
            } else {
                m_pMenuSystemMinimize->update(SDL_Point{ -1, -1 });
            }
        }
    };
}
