#pragma once
#include "UIBase.h"
#include "ViewBase.h"

#include "ViewWelcome.h"
#include "ViewIntroduce.h"
#include "ViewDemonstration.h"
#include "ViewAbout.h"

namespace CellularNetworkDemonstration {
    class ViewPanel :
        public UIBase {
    public:
        ViewPanel(SDL_Renderer *renderer)
            :UIBase(renderer, 800, 450) {
            // ��ʼ����Ԫ��

            // ��������
            m_iViewIndex = 0;
        }
        ~ViewPanel() {
            // ������Ԫ�غ���Դ
        }
        void setViewCode(int indexCode) {
            //TODO: Do page changing.
            for (int i = 0; i < 4; i++) {
                if (m_pViews[i]->getViewCode() == indexCode) {
                    this->m_iViewIndex = i;
                    break;
                }
            }
        }
    private:
        // ����
        int m_iViewIndex;

        // ��Ԫ��
        ViewBase *m_pViews[4];


        // ���ƽ���Ԫ��
        virtual void doRender() {
            //SDL_SetRenderDrawColor(m_pRenderer, getContiniousValue(4023), getContiniousValue(6732), getContiniousValue(9114), getContiniousValue(7333));
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


