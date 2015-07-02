#pragma once
#include "UIBase.h"

namespace CellularNetworkDemonstration {
    class DemoSidebar : public UIBase {
    public:
        DemoSidebar(SDL_Renderer *renderer)
            :UIBase(renderer, 195, 440) {
        }

        ~DemoSidebar() {
                // ������Ԫ�غ���Դ

                //DELETE_IF_EXIST(m_pMenuSystemMinimize)
                //    if (m_pMenuImage) {
                //        SDL_DestroyTexture(m_pMenuImage);
                //    }
            }


    private:
        // ����

        // ��Դ
        //SDL_Texture *m_pMenuImage;

        // ��Ԫ��
        //MenuSystemClose *m_pMenuSystemClose;
        //SDL_Rect *m_pMenuSystemCloseRect;


        // ���ƽ���Ԫ��
        virtual void doRender() {
            SDL_SetRenderDrawColor_DefalutBackground(m_pRenderer);
            SDL_SetRenderDrawColor(m_pRenderer, 200, 0, 0, 200);
            SDL_RenderClear(m_pRenderer);

        }

        virtual void doUpdate() {


        }
    };
}