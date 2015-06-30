#pragma once
#include "Include.h"
#include "UIBase.h"
namespace CellularNetworkDemonstration {

    class MenuSystemMinimize :public UIBase {
    public:
        MenuSystemMinimize(SDL_Renderer *renderer)
            :UIBase(renderer, 45, 20) {
            //��ʼ����Ԫ��

        }
        ~MenuSystemMinimize() {
            // ������Ԫ�غ���Դ
        }

    private:

        // ���ƽ���Ԫ��
        virtual void renderUI() {
            SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
            SDL_RenderClear(m_pRenderer);
        }
    };
}
