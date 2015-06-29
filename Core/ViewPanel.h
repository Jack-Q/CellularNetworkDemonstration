#pragma once
#include "UIBase.h"
namespace CellularNetworkDemonstration {
    class ViewPanel :
        public UIBase {
    public:
        ViewPanel(SDL_Renderer *renderer)
            :UIBase(renderer, 800, 450) {
            //��ʼ����Ԫ��

        }
        ~ViewPanel() {
            // ������Ԫ�غ���Դ
        }

    private:

        // ���ƽ���Ԫ��
        virtual void renderUI() {
            SDL_SetRenderDrawColor(m_pRenderer, SDL_GetTicks() / 40 % 255, SDL_GetTicks() / 60 % 255, SDL_GetTicks() / 70 % 255, SDL_GetTicks() / 10 % 255);
            SDL_RenderClear(m_pRenderer);
        }
    };
}


