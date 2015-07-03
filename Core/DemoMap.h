#pragma once
#include "UIBase.h"
#include "DemoHexagon.h"

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
            SDL_Color color = { 255, 255, 20, 100 };
            hexagon = new DemoHexagon(renderer, &color);

        }

        ~DemoMap() {
            // ������Ԫ�غ���Դ
            DELETE_IF_EXIST(hexagon);

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
        DemoHexagon *hexagon;

        // ���ƽ���Ԫ��
        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 20, 220, 120, 255);
            SDL_RenderClear(m_pRenderer);
            SDL_Texture *hexagonTexture = hexagon->render();
            SDL_Rect r = { 0, 0, 200, 200 };
            for (int i = 0; i < 5; i++) {
                r.y = 150 * i - 100;
                for (int j = 0; j < 5; j++) {
                    r.x = -( i % 2 == 0 ? 100 : 14 ) + j * 172;
                    SDL_RenderCopy(m_pRenderer, hexagonTexture, nullptr, &r);

                }
            }
        }

        virtual void doUpdate() {


        }
    };
}