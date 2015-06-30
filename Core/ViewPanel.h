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

            // ��������
            m_iViewIndex = 0;
        }
        ~ViewPanel() {
            // ������Ԫ�غ���Դ
        }
        void setViewIndex(int index) {
            //TODO: Do page changing.
            m_iViewIndex = index;
        }
    private:
        // ����
        int m_iViewIndex;

        // ��Ԫ��
        

        // ���ƽ���Ԫ��
        virtual void doRender() {
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


