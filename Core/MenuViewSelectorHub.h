#pragma once
#include "Include.h"
#include "UIBase.h"
#include "MenuViewSelector.h"

namespace CellularNetworkDemonstration {
    class MenuViewSelectorHub : public UIBase {

    public:
        MenuViewSelectorHub(SDL_Renderer *renderer)
            :UIBase(renderer, 800, 450) {
            //��ʼ����Ԫ��

            // ��������
            m_iViewIndex = 0;
        }
        ~MenuViewSelectorHub() {
            // ������Ԫ�غ���Դ
        }
        inline void setViewIndex(int index) {
            //TODO: Do page changing.
            m_iViewIndex = index;
        }

        inline int getViewIndex() const{
            return m_iViewIndex;
        }
    private:
        // ����
        int m_iViewIndex;

        // ��Ԫ��


        // ���ƽ���Ԫ��
        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 0);
            SDL_RenderClear(m_pRenderer);
        }
    };
}