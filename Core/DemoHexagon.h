#pragma once
#include "ButtonBase.h"


namespace CellularNetworkDemonstration {
    class DemoHexagon :public ButtonBase {
    public:
        DemoHexagon(SDL_Renderer *renderer, int baseStationId)
            :ButtonBase(renderer, 400, 400), m_iBaseStationId(baseStationId) {


            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);


            //m_pMinimizeIcon = SDL_CreateTexture(m_pRenderer,
            //    SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 11, 10);
            //SDL_SetTextureBlendMode(m_pTexture, SDL_BLENDMODE_BLEND);
            /*SDL_SetRenderTarget(m_pRenderer, m_pTexture);
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 0);
            SDL_RenderClear(m_pRenderer);
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

            SDL_Texture *image = IMG_LoadTexture(renderer, "base-station.png");
            SDL_RenderCopy(m_pRenderer, image, nullptr, nullptr);
            SDL_DestroyTexture(image);
            SDL_RenderPresent(m_pRenderer);*/
            //m_pMinimizeIconPosition = new SDL_Rect{ 17, 5, 11, 10 };
            m_pRect = new SDL_Rect{ 0, 0, 400, 400 };

            // �ָ���Ⱦ��״̬
            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);

        }
        ~DemoHexagon() {
            DELETE_IF_EXIST(m_pRect);
        }

        int getBaseStationId()  const {
            return m_iBaseStationId;
        }

    private:

        int x;
        int y;
        SDL_Rect *m_pRect;
        const int m_iBaseStationId;
        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
            SDL_RenderClear(m_pRenderer);
            /*SDL_SetRenderDrawColor(m_pRenderer, 220, 220, 220, getRenderAlpha());
            SDL_RenderClear(m_pRenderer);*/

            SDL_RenderCopy(m_pRenderer,
                DemoTextureManager::get().getTexture(m_pRenderer, "base-station.png"),
                nullptr, m_pRect);
            if (( m_pState == BUTTON_STATE_HOVER ) || ( m_pState == BUTTON_STATE_DOWN )) {
                SDL_RenderCopy(m_pRenderer,
                    DemoTextureManager::get().getTexture(m_pRenderer, "base-station.png"),
                    nullptr, m_pRect);
                SDL_RenderCopy(m_pRenderer,
                    DemoTextureManager::get().getTexture(m_pRenderer, "base-station.png"),
                    nullptr, m_pRect);

            }
        }

        // ������϶���
        int getRenderAlpha() {

            const static int IN_DURATION = 200 / 100;//Divided by 100 percents
            const static int OUT_DURATION = 400 / 100;//Divided by 100 percents
            static int percent = 0;
            static int lastTick = 0;
            static int currentTick;

            currentTick = SDL_GetTicks();

            int alpha, delta;
            switch (m_pState) {
                case BUTTON_STATE_NORMAL:
                    delta = ( currentTick - lastTick ) / OUT_DURATION;
                    percent -= delta;
                    if (percent < 0) {
                        percent = 0;
                    }
                    // ������������Ϊ����
                    alpha = SDL_static_cast(int, 160 * SDL_sin(percent / 100.0));
                    break;
                case BUTTON_STATE_HOVER:
                    delta = ( currentTick - lastTick ) / IN_DURATION;
                    percent += delta;
                    if (percent > 100) {
                        percent = 100;
                    }
                    // ������������Ϊ����
                    alpha = SDL_static_cast(int, 160 * SDL_sin(percent / 100.0));
                    break;
                case BUTTON_STATE_DOWN:
                    alpha = 225;
                    break;
                default:
                    break;
            }
            lastTick = currentTick;
            return alpha;
        }

        virtual void doAction() {
            SDL_Event* minimize = new SDL_Event;
            minimize->type = SDL_USEREVENT;
            minimize->user.code = SDL_DEMO_SIDEBAR_BASE_STATION;
            int *id = new int(m_iBaseStationId);
            minimize->user.data1 = id;
            SDL_PushEvent(minimize);
            m_pState = BUTTON_STATE_NORMAL;
        }
    };
}