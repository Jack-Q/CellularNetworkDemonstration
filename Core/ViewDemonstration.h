#pragma once
#include "ViewBase.h"

namespace CellularNetworkDemonstration {
    class ViewDemonstration :public ViewBase {
    public:
        ViewDemonstration(SDL_Renderer* renderer, int viewCode)
            :ViewBase(renderer, viewCode) {
            m_pDemonstrationImage = IMG_LoadTexture(m_pRenderer, "view-demonstration.png");

        }

        ~ViewDemonstration() {
            if (m_pDemonstrationImage) {
                SDL_DestroyTexture(m_pDemonstrationImage);
            }
        }

    private:
        // ����

        // ��Դ
        SDL_Texture *m_pDemonstrationImage;

        // ��Ԫ��

        // ���ƽ���Ԫ��
        virtual void doRender() {
            //m_pMenuSystemCloseRect->x = m_sMousePosition.x - m_pMenuSystemCloseRect->w/2;
            //m_pMenuSystemCloseRect->y = m_sMousePosition.y - m_pMenuSystemCloseRect->h / 2;

            SDL_SetRenderDrawColor_DefalutBackground(m_pRenderer);
            SDL_RenderClear(m_pRenderer);

            SDL_RenderCopy(m_pRenderer, m_pDemonstrationImage, nullptr, nullptr);

            /*SDL_Texture *closeTexture = m_pMenuSystemClose->render();
            SDL_Texture *minimizeTexture = m_pMenuSystemMinimize->render();
            SDL_Texture *selectorHubTexture = m_pMenuViewSelectorHub->render();
            SDL_RenderCopy(m_pRenderer, closeTexture, m_pMenuSystemClose->Rect(), m_pMenuSystemCloseRect);
            SDL_RenderCopy(m_pRenderer, minimizeTexture, m_pMenuSystemMinimize->Rect(), m_pMenuSystemMinimizeRect);
            SDL_RenderCopy(m_pRenderer, selectorHubTexture, m_pMenuViewSelectorHub->Rect(), m_pMenuViewSelectorHubRect);
            */
        }

        virtual void doUpdate() {
            //if (SDL_PointInRect(m_sMousePosition, *m_pMenuSystemCloseRect)) {
            //    m_pMenuSystemClose->update(SDL_RelationPoint(&m_sMousePosition, m_pMenuSystemCloseRect));
            //} else {
            //    m_pMenuSystemClose->update(SDL_Point{ -1, -1 });
            //}

        }
    };


}