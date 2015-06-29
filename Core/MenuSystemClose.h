#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "UIBase.h"
namespace CellularNetworkDemonstration {

    class MenuSystemClose :public UIBase {
    public:
        MenuSystemClose(SDL_Renderer *renderer)
            :UIBase(renderer, 45, 20) {
            //��ʼ����Ԫ��

        }
        ~MenuSystemClose() {
            // ������Ԫ�غ���Դ
        }

    private:

        // ���ƽ���Ԫ��
        virtual void renderUI() {
            SDL_SetRenderDrawColor(m_pRenderer, 220, 60, 60, 200);
            SDL_RenderClear(m_pRenderer);
        }
    };
}
