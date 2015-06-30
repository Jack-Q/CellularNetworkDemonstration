#pragma once
#include "Include.h"
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
        // ��Ԫ��
        

        // ���ƽ���Ԫ��
        virtual void renderUI() {
            SDL_SetRenderDrawColor(m_pRenderer, getContiniousValue(4023), getContiniousValue(6732), getContiniousValue(9114), getContiniousValue(7333));
            SDL_RenderClear(m_pRenderer);
        }

        inline int getContiniousValue(int interval) {
            int tick = SDL_GetPerformanceCounter()  / interval % 512;
            if (tick > 255) {
                return 512 - tick;
            } else {
                return tick;
            }
        }
    };
}


