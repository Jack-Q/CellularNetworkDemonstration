#pragma once
#include "UIBase.h"

namespace CellularNetworkDemonstration {
    class DemoMap : public UIBase {
    public:
        DemoMap(SDL_Renderer *renderer)
            :UIBase(renderer, 600, 440) {

            // ������Դ

            //��ʼ����Ԫ��
            //m_pMenuSystemClose = new MenuSystemClose(m_pRenderer);
            //m_pMenuSystemCloseRect = new SDL_Rect();
            //m_pMenuSystemCloseRect->x = getWidth() - 50;
            //m_pMenuSystemCloseRect->y = 0;
            //m_pMenuSystemCloseRect->w = 45;
            //m_pMenuSystemCloseRect->h = 20;


        }

        ~DemoMap() {
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
            SDL_SetRenderDrawColor(m_pRenderer, 20, 220, 120, 255);
            SDL_RenderClear(m_pRenderer);
            
        }

        virtual void doUpdate() {


        }
    };
}