#pragma once
#include "UIBase.h"

namespace CellularNetworkDemonstration {
    class DemoSidebar : public UIBase {
    public:
        DemoSidebar(SDL_Renderer *renderer)
            :UIBase(renderer, 600, 440) {
            // ���ñ�������ʾ���Ϊ195px����Ϊ������ʾ
            // �������������ذ�ť��ÿһ����Ŀ��Ϊ
            // 195px���Լ�5px�߿���ת������ʱֱ��ת��
            // �����������꼴�ɡ�
            this->m_pRect->w = 195;



            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);


            //m_pMinimizeIcon = SDL_CreateTexture(m_pRenderer,
            //    SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 11, 10);
            //SDL_SetTextureBlendMode(m_pTexture, SDL_BLENDMODE_BLEND);
            SDL_SetRenderTarget(m_pRenderer, m_pTexture);
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 0);
            SDL_RenderClear(m_pRenderer);
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            SDL_RenderDrawLine(renderer, 0, 8, 110, 80);
            SDL_RenderDrawLine(renderer, 0, 9, 110, 9);

            int w, h;
            SDL_Color color{ 80, 75, 70, 255 };
            // �������
            m_pTitleText = TTF_RenderTextTexture(renderer, "��ʾԪ��", 22, &color);
            SDL_QueryTexture(m_pTitleText, nullptr, nullptr, &w, &h);
            m_pTitleTextRect = new SDL_Rect{ 10, -5, w, h };
            
            // ��վ�б����
            m_pBaseStationListTitle = TTF_RenderTextTexture(renderer, "��վ", 16, &color);
            SDL_QueryTexture(m_pBaseStationListTitle, nullptr, nullptr, &w, &h);
            m_pBaseStationListTitleRect = new SDL_Rect{ 15, 26, w, h };

            // �ƶ�̨�б����             
            m_pMobileClientListTitle = TTF_RenderTextTexture(renderer, "�ƶ�̨", 16, &color);
            SDL_QueryTexture(m_pMobileClientListTitle, nullptr, nullptr, &w, &h);
            m_pMobileClientListTitleRect = new SDL_Rect{ 15, 230, w, h };
            
            // �ָ���Ⱦ��״̬
            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);


        }

        ~DemoSidebar() {
            // ������Ԫ�غ���Դ

            //DELETE_IF_EXIST(m_pMenuSystemMinimize)
            //    if (m_pMenuImage) {
            //        SDL_DestroyTexture(m_pMenuImage);
            //    }
            DELETE_IF_EXIST(m_pBaseStationListTitleRect)
            DELETE_IF_EXIST(m_pTitleTextRect)
            DELETE_IF_EXIST(m_pMobileClientListTitleRect)
            if (m_pTitleText) {
                SDL_DestroyTexture(m_pTitleText);
            }            
            if (m_pBaseStationListTitle) {
                SDL_DestroyTexture(m_pBaseStationListTitle);
            }            
            if (m_pMobileClientListTitle) {
                SDL_DestroyTexture(m_pMobileClientListTitle);
            }
        }


    private:
        // ����

        // ��Դ
        SDL_Texture *m_pTitleText;
        SDL_Rect *m_pTitleTextRect;
        SDL_Texture *m_pBaseStationListTitle;
        SDL_Rect *m_pBaseStationListTitleRect;
        SDL_Texture *m_pMobileClientListTitle;
        SDL_Rect *m_pMobileClientListTitleRect;
        // ��Ԫ��
        //MenuSystemClose *m_pMenuSystemClose;
        //SDL_Rect *m_pMenuSystemCloseRect;


        // ���ƽ���Ԫ��
        virtual void doRender() {
            SDL_SetRenderDrawColor_DefalutBackground(m_pRenderer);
            SDL_RenderClear(m_pRenderer);
            SDL_RenderCopy(m_pRenderer, m_pTitleText, nullptr, m_pTitleTextRect);
            SDL_RenderCopy(m_pRenderer, m_pBaseStationListTitle, nullptr, m_pBaseStationListTitleRect);
            SDL_RenderCopy(m_pRenderer, m_pMobileClientListTitle, nullptr, m_pMobileClientListTitleRect);
        }

        virtual void doUpdate() {


        }
    };
}